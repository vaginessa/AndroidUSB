/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* File Name: usb-21-interrupt.inc
*
* Type: SOURCE
*
* Title: USB Interrupt Service Routine
*
* Version: 2.1
*
* Purpose: The USB Module interacts with the CPU by an array of
*          interrupts which indicate that various events have occured.
*          If any of these events occur then a single USB interrupt
*          routine is called. The CPU must then read the USB interrupt
*          register to determine which event has occured, and modify
*          program execution accordingly. The routine for handling
*          USB interrupts is contained in this file.
*
*
* Date first created: 11th October 2015
* Date last modified: 11th October 2015
*
* Author: John Scott
*
* Used by: usb-21.inc
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

; ========================== DECLARATIONS ============================
.global __USB1Interrupt
;.global __T3Interrupt


.text
; ============================== CODE ================================

; --------------------------------------------------------------------
; USB Interrupt Service Routine
; --------------------------------------------------------------------
; This routine is called every time the interrupt controller detects
; that USB1IF in IFS5 has been raised. The routine determines which
; event has occured and processes it accordingly.

__USB1Interrupt:

    ; Set the USB system hold flag
    BSET    SYS.REG.STAT, #sys_usb_hold

    ; Back up working registers
    MOV     w0, USB.w0
    MOV     w1, USB.w1
    MOV     w2, USB.w2
    MOV     w3, USB.w3
    MOV     w4, USB.w4
    MOV     w5, USB.w5
    MOV     w6, USB.w6
    MOV     w7, USB.w7
    MOV     w8, USB.w8
    MOV     w9, USB.w9
    MOV     w10, USB.w10
    MOV     w11, USB.w11
    MOV     w12, USB.w12
    MOV     w13, USB.w13
    MOV     w14, USB.w14
    MOV     w15, USB.w15

    ; Check that the USB interrupt flag bit is set
    BTSS    IFS5, #USB1IF
    BRA     AppError1

    ; Check for an error interrupt
    BTSS    U1IR, #UERRIF
    BRA     0f

            ; Check each error interrupt source in turn
            BTSS    U1EIR, #PIDEF
            BRA     1f
            ; ------------------------ Put PIDEF routine between lines
        2:  BRA     2b
            ; --------------------------------------------------------
        1:  BTSS    U1EIR, #CRC5EF
            BRA     1f
            ; ----------------------- Put CRC5EF routine between lines
        2:  BRA     2b
            ; --------------------------------------------------------
        1:  BTSS    U1EIR, #CRC16EF
            BRA     1f
            ; ---------------------- Put CRC16EF routine between lines
        2:  BRA     2b
            ; --------------------------------------------------------
        1:  BTSS    U1EIR, #DFN8EF
            BRA     1f
            ; ----------------------- Put DFN8EF routine between lines
        2:  BRA     2b
            ; --------------------------------------------------------
        1:  BTSS    U1EIR, #BTOEF
            BRA     1f
            ; ------------------------ Put BTOEF routine between lines
            ; WARNING:
            ; This routine has been added in order to ignore an error
            ; whose origin is unknown. Program runs fine with error
            ; ignored but if further problems arise investigate
            ; these errors first
            ; --------------------------------------------------------
            ; Prepear to return from interrupt service routine
            BSET    U1EIR, #BTOEF
            NOP                     ; You seem to need this
            BSET    U1IR, #UERRIF
            NOP                     ; You seem to need this
            BCLR    IFS5, #USB1IF
            ; Go to end of interrupt processing
            BRA     USB.INT.end
            ; --------------------------------------------------------
        1:  BTSS    U1EIR, #DMAEF
            BRA     1f
            ; ------------------------ Put DMAEF routine between lines
            ; WARNING:
            ; This routine has been added in order to ignore an error
            ; whose origin is unknown. Program runs fine with error
            ; ignored but if further problems arise investigate
            ; these errors first
            ; --------------------------------------------------------
            ; Prepear to return from interrupt service routine
            BSET    U1EIR, #DMAEF
            NOP                     ; You seem to need this
            BSET    U1IR, #UERRIF
            NOP                     ; You seem to need this
            BCLR    IFS5, #USB1IF
            ; Go to end of interrupt processing
            BRA     USB.INT.end
            ; --------------------------------------------------------
        1:  BTSS    U1EIR, #BUSACCEF
            BRA     1f
            ; --------------------- Put BUSACCEF routine between lines
        2:  BRA     2b
            ; --------------------------------------------------------
        1:  BTSS    U1EIR, #BTSEF
            BRA     AppError2
            ; ------------------------ Put BTSEF routine between lines
        2:  BRA     2b
            ; --------------------------------------------------------

    ; Check the other USB interrupt sources
0:  BTSS    U1IR, #URSTIF
    BRA     0f
    ; ------------------------------------------------------ Reset ISR

    BSET    U1IR, #URSTIF
1:  BCLR    IFS5, #USB1IF       
    BTSC    IFS5, #USB1IF       
    BRA     1b

    ; A device moves to the default state on a Bus Reset and must
    ; respond to the default address in subsequent communication,
    ; until its address is set to a non-zero value by the
    ; SET_ADDRESS request.
    CLR     U1ADDR

    ; Log Reset event
.ifdecl USB.OPTION.DEBUG.SwitchOnEventLog
.ifdecl USB.OPTION.DEBUG.EventLog.DetailLevel1
    ; Write event code to w6
    MOV     #USB.DEBUG.ResetEvent, w0
    CLR     w1
    MOV.B   [w0+1], w1
    MOV.B   [w0], w2
    SL      w2, #8, w2
    ADD     w1, w2, w6
    ; Log event
    RCALL   USB.SUB.DEBUG.LogEvent
.endif
.endif

    ; Go to end of interrupt processing
    BRA     USB.INT.end

    ; ----------------------------------------------- End of Reset ISR

0:  BTSS    U1IR, #TRNIF
    BRA     0f
    ; --------------------------------------- Transaction Complete ISR
    ; Call the transaction processing routine
    RCALL   USB.SUB.TRN
    ; Prepear to return from interrupt service routine
    BSET    U1IR, #TRNIF
    NOP                     ; You seem to need this
    BCLR    IFS5, #USB1IF

    ; Go to end of interrupt processing
    BRA     USB.INT.end

    ; -------------------------------- End of Transaction Complete ISR

0:  BTSS    U1IR, #IDLEIF
    BRA     0f
    ; ------------------------------------------------------- Idle ISR

    BSET    U1IR, #IDLEIF
1:  BCLR    IFS5, #USB1IF
    BTSC    IFS5, #USB1IF
    BRA     1b

    ; Log Idle event
.ifdecl USB.OPTION.DEBUG.SwitchOnEventLog
.ifdecl USB.OPTION.DEBUG.EventLog.DetailLevel1
    ; Write event code to w6
    MOV     #USB.DEBUG.IdleEvent, w0
    CLR     w1
    MOV.B   [w0+1], w1
    MOV.B   [w0], w2
    SL      w2, #8, w2
    ADD     w1, w2, w6
    ; Log event
    RCALL   USB.SUB.DEBUG.LogEvent
.endif
.endif

    ; Go to end of interrupt processing
    BRA     USB.INT.end

    ; ------------------------------------------------ End of Idle ISR

0:  BTSS    U1IR, #RESUMEIF
    BRA     0f
    ; ----------------------------------------------------- Resume ISR
    NOP
    NOP
    NOP
    BSET    U1IR, #RESUMEIF
    BCLR    IFS5, #USB1IF

    ; Go to end of interrupt processing
    BRA     USB.INT.end

    ; ---------------------------------------------- End of Resume ISR

0:  BTSS    U1IR, #STALLIF
    BRA     AppError3
    ; ------------------------------------------------------ Stall ISR
    ; Clear the flag
    BSET    U1IR, #STALLIF
    NOP                     ; You seem to need this
    BCLR    IFS5, #USB1IF

    ; Log Stall event
.ifdecl USB.OPTION.DEBUG.SwitchOnEventLog
.ifdecl USB.OPTION.DEBUG.EventLog.DetailLevel1
    ; Write event code to w6
    MOV     #USB.DEBUG.StallEvent, w0
    CLR     w1
    MOV.B   [w0+1], w1
    MOV.B   [w0], w2
    SL      w2, #8, w2
    ADD     w1, w2, w6
    ; Log event
    RCALL   USB.SUB.DEBUG.LogEvent
.endif
.endif

    ; Go to end of interrupt processing
    BRA     USB.INT.end

     ; ---------------------------------------------- End of Stall ISR



USB.INT.end:

    ; Restore working registers
    MOV     USB.w0, w0
    MOV     USB.w1, w1
    MOV     USB.w2, w2
    MOV     USB.w3, w3
    MOV     USB.w4, w4
    MOV     USB.w5, w5
    MOV     USB.w6, w6
    MOV     USB.w7, w7
    MOV     USB.w8, w8
    MOV     USB.w9, w9
    MOV     USB.w10, w10
    MOV     USB.w11, w11
    MOV     USB.w12, w12
    MOV     USB.w13, w13
    MOV     USB.w14, w14
    MOV     USB.w15, w15

    ; Clear the USB system hold flag
    BCLR    SYS.REG.STAT, #sys_usb_hold

    ; Return
    RETFIE




