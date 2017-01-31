/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* File Name: usb-21-transaction.inc
*
* Type: SOURCE
*
* Title: USB Transaction Processing Routine
*
* Version: 2.1
*
* Purpose: The USB defines three types of USB transaction: IN; OUT;
*          and SETUP. IN refers to a transfer from the device to the
*          host. Each consists of three parts: a token packet; a data
*          packet; and a handshake packet. The reception and
*          transmission of these transactions is handled entirely
*          by the USB Module. In the case of a transmission, the CPU
*          chooses the token (IN) and loads data into the buffer. The
*          host then initiates the transaction whenever it likes, and
*          the success or failure is reported to the CPU using the
*          Transaction Complete Interrupt (TRNIF). In the case of a
*          reception, the Transaction Complete Interrupt informs the
*          CPU that the transaction has occured and the CPU reads the
*          token type (OUT or SETUP) from a register, and reads the
*          received data from the buffer.
*
*          The three types of USB transaction are the basis for the
*          more complicated transfer types: control; interrupt, bulk
*          and isochronous.
*
*          The routine in this file controls is exectuted whenever a
*          USB transaction has completed. It acts as an arbiter
*          for assigning the correct process to handle the
*          transaction, depending on what transfer type is currently
*          in progress. It also stores information about the
*          transaction in temporary registers that can be accessed
*          by various other processes.
*
*
* Date first created: 11th October 2015
* Date last modified: 11th October 2015
*
* Author: John Scott
*
* Used by: usb-21.inc
*
*
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

.text
; ============================== CODE ================================

; --------------------------------------------------------------------
; USB Transaction Processing Routine
; --------------------------------------------------------------------
; This routine is called every time the TRNIF interrupt is raised.
; The process determines the transfer type currently underway and
; hands the processing of the transaction to the relevent handling
; routine. If no transfer is is currently underway then the routine
; starts the appropriate transfer by calling the relavent transfer
; routine. The routine also processes errors which may be present in
; the transaction.

USB.SUB.TRN:
    ; Store the relevant buffer descriptor (BD) start address
    MOV     U1STAT, w2
    SL      w2, #1, w0      ; w0 is now an address offset
    MOV     #.startof.(USB.BDT), w1
    ADD     w0, w1, w0      ; w0 now points to WORD0 of the BD
    MOV     #0xFFE0, w3
    AND     w3, w0, w1      ; w1 now points to start of BD block
    MOV     w1, USB.REG.CurrentBD   ; BD block start address stored
    ; Test endpoint number
    MOV     U1STAT, w0
    AND     #0x00F0, w0
    MOV     #0x0000, w1
    CPBEQ   w0, w1, 3f      ; Test for activity at endpoint 0
    MOV     #0x0010, w1
    CPBEQ   w0, w1, 4f      ; Test for activity at endpoint 1
    MOV     #0x0020, w1
    CPBEQ   w0, w1, 5f      ; Test for activity at endpoint 2
    BRA     AppError23      ; If endpoint not in use
    ; Determine whether a control transfer is currently underway
3:  MOV     #.startof.(USB.REG.EP), w0
    AND     #0x00F0, w2     ; w2 contains address offset
    ADD     w0, w2, w2      ; w2 contains absolute address
    MOV     [w2+CTword], w4
    BTSS    w4, #CTEN
    BRA     0f
    RCALL   USB.SUB.CT      ; Call control transfer routine
    BRA     2f
    ; Determine whether a control transfer should be started
0:  MOV     USB.REG.CurrentBD, w0
    MOV     [w0+RX.EVEN.WORD0], w1        ; w1 contains WORD0
    LSR     w1, #2, w1
    AND     #0x000F, w1     ; w1 contains PID code
    MOV     #SETUP, w2
    CPBNE   w1, w2, 0f
    RCALL   USB.SUB.CT      ; Call control transfer routine
    BRA     2f              ; Go to end of transaction processing
    ; Last transaction took place at endpoint 1
4:  RCALL   USB.SUB.IT      ; Call interrupt transfer routine
    BRA     2f              ; Go to end of transaction processing
    ; Last transaction took place at endpoint 2
5:  RCALL   USB.SUB.BT      ; Call bulk transfer routine
    BRA     2f              ; Go to end of transaction processing

    ; Prepear to leave the transaction processing routine
2:  CLR     USB.REG.TRN
    BCLR    U1CON, #PKTDIS
    ; Transaction registers are now clear.
    RETURN

                                                      ; End of routine
; --------------------------------------------------------------------

