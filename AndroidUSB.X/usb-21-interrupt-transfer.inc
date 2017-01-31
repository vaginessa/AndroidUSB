/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* File Name: usb-21-interrupt-transfer.inc
*
* Type: SOURCE
*
* Title: USB Interrupt Transfer Routine
*
* Version: 2.1
*
* Purpose: Contains the routines which implement the interrupt
*          transfer defined by the USB 2.0 Specification.
*
* Date first created: 11th October 2015
* Date last modified: 11th October 2015
*
* Author: John Scott
*
* Used by: usb-21.inc
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


.text
; ============================ CODE ==================================

; --------------------------------------------------------------------
; USB Interrupt Transfer Routine
; --------------------------------------------------------------------
; This routine performs the handling of the interrupt transfer
; protocol defined by the USB 2.0 Specification. At the moment it is
; fairly minimal with no error checking or fault recovery but it
; works relatively well. It only implements the (required)
; data0/data1 toggling on transmission.

USB.SUB.IT:

    ; Construct pointer to the endpoint register block
    MOV     #.startof.(USB.REG.EP), w0
    MOV     U1STAT, w1
    AND     #0x00F0, w1     ; w1 contains address offset
    ADD     w0, w1, w0      ; w0 contains absolute address of EP block
    MOV     w0, USB.REG.IT.CurrentRegBlockAddress

    ; Store pointer to current buffer descriptor
    MOV     USB.REG.CurrentBD, w7

    ; Test for transfer direction
    BTSS    U1STAT, #3 ; #DIR
    BRA     3f      ; go to RX processing

0:  ; TX processing --------------------------------------------------

    ; Log TX Interrupt Transfer event
.ifdecl USB.OPTION.DEBUG.SwitchOnEventLog
.ifdecl USB.OPTION.DEBUG.EventLog.DetailLevel1
    ; Write event code to w6
    MOV     #USB.DEBUG.TXInterrupt, w0
    CLR     w1
    MOV.B   [w0+1], w1
    MOV.B   [w0], w2
    SL      w2, #8, w2
    ADD     w1, w2, w6
    ; Log event
    RCALL   USB.SUB.DEBUG.LogEvent
.endif
.endif

    ; ---------------------------------------------------------------
    ; NOTE:
    ; Testing for buffer overflow at this point contains a bug
    ; because the test is only performed if a packet is actually
    ; received. If no packet is received then the buffer can overflow
    ; without being detected. In practice this is not a problem if
    ; the routine is running properly (in normal operation).
    ; ---------------------------------------------------------------
    ; Test for buffer overrun
    MOV     USB.REG.IT.TX.BUFFER.pointer_gap, w0
    MOV     #64, w1     ; Test for buffer half full
    CPSLT   w0, w1
    BRA     AppError19

    ; Log the TX pointer gap
.ifdecl USB.OPTION.DEBUG.SwitchOnEventLog
.ifdecl USB.OPTION.DEBUG.EventLog.DetailLevel1
    ; Write event code to w6
    MOV     USB.REG.IT.TX.BUFFER.pointer_gap, w6
    ; Log event
    RCALL   USB.SUB.DEBUG.LogEvent
.endif
.endif

    ; Increment the send data buffer pointer (by adding 8)
0:  RCALL   USB.SUB.IT.TX.send_pointer_increment
    ; Write the address of the next send buffer entry to the BDT
    MOV     USB.REG.IT.TX.BUFFER.pointer.send, w0
    MOV     w0, [w7+TX.EVEN.ADDRESS]

    ; Test for further data to transfer
    MOV     USB.REG.IT.TX.BUFFER.pointer_gap, w0
    MOV     #0, w1
    CPSGT   w0, w1      ; Skip if there is a pointer gap
    BRA     1f
    BRA     0f

    ; Prepear word0 for returning more data
0:  MOV     #0x0080, w1         ; Do ACK new packets
    BRA     2f

    ; Prepear word0 for disallowing further data transfer
1:  MOV     #0x0000, w1         ; Do ACK new packets
    ; Clear the interrupt transfer initialised bit
    BCLR    USB.REG.IT.TX.status, #0
    BRA     2f

    ; Toggle the data0/data1 bit
2:  MOV     USB.REG.IT.CurrentRegBlockAddress, w5
    MOV     [w5+ITword], w0
    BTG     w0, #NDT            ; Toggle next data type bit
    BTSC    w0, #NDT
    BSET    w1, #DATA01         ; Set DATA01 bit
    MOV     w0, [w5+ITword]
    ; Prepear to receive next transaction
    MOV     w1, [w7+TX.EVEN.WORD0]  ; Write buffer descriptor
    ; Return from interrupt transfer processing
    RETURN

3:  ; RX processing --------------------------------------------------

    ; Log RX Interrupt Transfer event
.ifdecl USB.OPTION.DEBUG.SwitchOnEventLog
.ifdecl USB.OPTION.DEBUG.EventLog.DetailLevel1
    ; Write event code to w6
    MOV     #USB.DEBUG.RXInterrupt, w0
    CLR     w1
    MOV.B   [w0+1], w1
    MOV.B   [w0], w2
    SL      w2, #8, w2
    ADD     w1, w2, w6
    ; Log event
    RCALL   USB.SUB.DEBUG.LogEvent
.endif
.endif

    ; Test for buffer overrun
    MOV     USB.REG.IT.RX.BUFFER.pointer_gap, w0
    MOV     #64, w1     ; Test for buffer half full
    CPSLT   w0, w1
    BRA     AppError20

    ; Log the RX pointer gap
.ifdecl USB.OPTION.DEBUG.SwitchOnEventLog
.ifdecl USB.OPTION.DEBUG.EventLog.DetailLevel1
    ; Write event code to w6
    MOV     USB.REG.IT.RX.BUFFER.pointer_gap, w6
    ; Log event
    RCALL   USB.SUB.DEBUG.LogEvent
.endif
.endif

    ; Increment the receive data buffer pointer (by adding 8)
0:  RCALL   USB.SUB.IT.RX.receive_pointer_increment
    ; Write the address of the next receive buffer entry to the BDT
    MOV     USB.REG.IT.RX.BUFFER.pointer.receive, w0
    MOV     w0, [w7+RX.EVEN.ADDRESS]

    ; Prepear word0 for receiving more data
    MOV     #0x0080, w1         ; Do ACK new packets
    ; Toggle the data0/data1 bit
    MOV     USB.REG.IT.CurrentRegBlockAddress, w5
    MOV     [w5+ITword], w0
    ;BTG     w0, #NDT            ; Toggle next data type bit
    ;BTSC    w0, #NDT
    ;BSET    w1, #DATA01         ; Set DATA01 bit
    MOV     w0, [w5+ITword]
    ; Prepear to receive next transaction
    MOV     w1, [w7+RX.EVEN.WORD0]  ; Write buffer descriptor
    ; Return from interrupt transfer processing
    RETURN


; ============================= DATA =================================

; --------------------------------------------------------------------
; USB Interrupt Transfer Data Buffers (TX and RX)
; --------------------------------------------------------------------
; Data to be sent to or received from the host is held a circular
; buffers which are defined below. Two pointers are associated with
; each buffer. One is used to indicate the next buffer entry to be
; sent, or the next buffer entry to receive data. The other pointer
; is used to indicate the next buffer entry to be written to, or
; read from, by the user application.

.section USB.REG.IT.TX.BUFFER, data, align(1024)
.space 1024

.section USB.REG.IT.RX.BUFFER, data, align(1024)
.space 1024


                                                 ; End of data section
; --------------------------------------------------------------------



.text
; ============================ CODE ==================================


; --------------------------------------------------------------------
; Routines for incrementing the TX buffer pointers
; --------------------------------------------------------------------
; These routines are called to modify the FIFO buffer pointers
; after either a packet has been sent or an entry has been written
; to the buffer.
; --------------------------------------------------------------------

USB.SUB.IT.TX.send_pointer_increment:

    PUSH.S
    ; Modify pointer gap
    MOV     USB.REG.IT.TX.BUFFER.pointer_gap, w0
    DEC     w0, w0      ; Decrease gap
    MOV     w0, USB.REG.IT.TX.BUFFER.pointer_gap
    ; Increment the pointer, or reset to start of FIFO
    MOV     USB.REG.IT.TX.BUFFER.pointer.send, w0
    ADD     w0, #8, w0
    AND     #0x03FF, w0
    MOV     #.startof.(USB.REG.IT.TX.BUFFER), w1
    ADD     w0, w1, w0
    ; Load new pointer into the register.
    MOV     w0, USB.REG.IT.TX.BUFFER.pointer.send
    ; Return to caller
    POP.S
    RETURN

USB.SUB.IT.TX.fill_pointer_increment:

    PUSH.S
    ; Modify pointer gap
    MOV     USB.REG.IT.TX.BUFFER.pointer_gap, w0
    INC     w0, w0      ; Increase gap
    MOV     w0, USB.REG.IT.TX.BUFFER.pointer_gap
    ; Increment the pointer, or reset to start of FIFO
    MOV     USB.REG.IT.TX.BUFFER.pointer.fill, w0
    ADD     w0, #8, w0
    AND     #0x03FF, w0
    MOV     #.startof.(USB.REG.IT.TX.BUFFER), w1
    ADD     w0, w1, w0
    ; Load new pointer into the register.
    MOV     w0, USB.REG.IT.TX.BUFFER.pointer.fill
    ; Return to caller
    POP.S
    RETURN



                                                     ; End of routines
; --------------------------------------------------------------------


; --------------------------------------------------------------------
; Routines for incrementing the RX buffer pointers
; --------------------------------------------------------------------
; These routines are called to modify the FIFO buffer pointers
; after either a packet has been received or an entry has been read
; from the buffer
; --------------------------------------------------------------------

USB.SUB.IT.RX.receive_pointer_increment:

    PUSH.S
    ; Modify pointer gap
    MOV     USB.REG.IT.RX.BUFFER.pointer_gap, w0
    INC     w0, w0      ; Increase gap
    MOV     w0, USB.REG.IT.RX.BUFFER.pointer_gap
    ; Increment the pointer, or reset to start of FIFO
    MOV     USB.REG.IT.RX.BUFFER.pointer.receive, w0
    ADD     w0, #8, w0
    AND     #0x03FF, w0
    MOV     #.startof.(USB.REG.IT.RX.BUFFER), w1
    ADD     w0, w1, w0
    ; Load new pointer into the register.
    MOV     w0, USB.REG.IT.RX.BUFFER.pointer.receive
    ; Return to caller
    POP.S
    RETURN

USB.SUB.IT.RX.read_pointer_increment:

    PUSH.S
    ; Modify pointer gap
    MOV     USB.REG.IT.RX.BUFFER.pointer_gap, w0
    DEC     w0, w0      ; Decrease gap
    MOV     w0, USB.REG.IT.RX.BUFFER.pointer_gap
    ; Increment the pointer, or reset to start of FIFO
    MOV     USB.REG.IT.RX.BUFFER.pointer.read, w0
    ADD     w0, #8, w0
    AND     #0x03FF, w0
    MOV     #.startof.(USB.REG.IT.RX.BUFFER), w1
    ADD     w0, w1, w0
    ; Load new pointer into the register.
    MOV     w0, USB.REG.IT.RX.BUFFER.pointer.read
    ; Return to caller
    POP.S
    RETURN



                                                     ; End of routines
; --------------------------------------------------------------------





; --------------------------------------------------------------------
; Routine for initialising Interrupt Transfers (EP1 TX Even)
; --------------------------------------------------------------------
; The application should call this routine every time it has written
; data to the interrupt transfer TX buffer
; --------------------------------------------------------------------

USB.SUB.IT.TX.initialise:

    PUSH.S
    ; Test whether interrupt transfers are already in progress
    BTSC    USB.REG.IT.TX.status, #0
    BRA     0f
    ; Point to the WORD0 entries of endpoint 1 TX Even
    MOV     #USB.BDT.EP1, w7
    MOV     [w7+TX.EVEN.WORD0], w0
    BSET    w0, #UOWN
    MOV     w0, [w7+TX.EVEN.WORD0]
    ; Flag the interrupt transfer initialised bit
    BSET    USB.REG.IT.TX.status, #0
    ; Return to caller
0:  POP.S
    RETURN

                                                      ; End of routine
; --------------------------------------------------------------------




; --------------------------------------------------------------------
; Routine for initialising Interrupt Transfers (EP1 RX Even)
; --------------------------------------------------------------------
; The application should call this routine when it ready to start
; receiving data. Further calls have no effect.
; --------------------------------------------------------------------

USB.SUB.IT.RX.initialise:

    PUSH.S
    ; Test whether interrupt transfers are already in progress
    BTSC    USB.REG.IT.RX.status, #0
    BRA     0f
    ; Point to the WORD0 entries of endpoint 1 RX Even
    MOV     #USB.BDT.EP1, w7
    MOV     [w7+RX.EVEN.WORD0], w0
    BSET    w0, #UOWN
    MOV     w0, [w7+RX.EVEN.WORD0]
    ; Flag the interrupt transfer initialised bit
    BSET    USB.REG.IT.RX.status, #0
    ; Return to caller
0:  POP.S
    RETURN

                                                      ; End of routine
; --------------------------------------------------------------------





