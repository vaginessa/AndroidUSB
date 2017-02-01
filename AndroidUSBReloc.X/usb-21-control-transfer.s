/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* File Name: usb-21-transfer-control.s
*
* Type: SOURCE
*
* Title: USB Control Transfer Routine
*
* Version: 2.1
*
* Purpose: The USB 2.0 Specification defines the control transfer as
*          one of four possible transfer types. The control transfer
*          is used for setup and control operations, and is used
*          especially during the enumeration sequence. A control
*          transfer is built out of individual IN, OUT and SETUP
*          packets and comprises three stages. The first is called
*          the setup stage, which consists of the reception by the
*          device of a SETUP packet containing information about the
*          control transfer that is about to take place. Then there is
*          an optional data stage, which consists of one or more IN or
*          OUT packets which move data between the host and device.
*          The control transfer concludes with a status stage which
*          is used by both parties to verify that the transfer was
*          a success. The file contains the routine to hand a control
*          transfer.
*
* Date first created: 11th October 2015
* Date last modified: 26th January 2017
*
* Author: John Scott
*
* Used by: usb-21.s
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

.include "p33EP512MU810.inc"
.include "usb-21-const.inc"
.include "usb-21-extern.inc"
    
; =================== SUBROUTINE DECLARATIONS ==========================
.global USB.SUB.CT
    
.global USB.SUB.CT.control_read.setup
.global USB.SUB.CT.control_read.data
.global USB.SUB.CT.control_read.status
    
.global USB.SUB.CT.control_write.setup
.global USB.SUB.CT.control_write.data
.global USB.SUB.CT.control_write.status
    
.text
; ============================= CODE =================================
    
; --------------------------------------------------------------------
; USB Control Transfer Routine
; --------------------------------------------------------------------
; This routine is called every time the transaction handling routine
; determines that either a control transfer is underway or a control
; transfer must be started. The function of this routine is to
; correctly process each stage of the control transfer. The routine
; calls request routines to handle each of the different commands that
; the device might receive from the host.

USB.SUB.CT:
    MOV     #.startof.(USB.REG.EP), w0
    MOV     U1STAT, w1
    AND     #0x00F0, w1     ; w1 contains address offset
    ADD     w0, w1, w0      ; w0 contains absolute address of EP block
    MOV     w0, USB.REG.CT.CurrentRegBlockAddress
    MOV     [w0+CTword], w2        ; w2 contains CTword
    ; Determine progress through current control transfer ------------
    BTSC    w2, #CTEN
    BRA     0f
    ; Start a new control transfer
    BSET    w2, #CTEN           ; Set the control transfer bit
    MOV     w2, [w0+CTword]    ; Write to CTword
    ; Make a record of control transfer data
    ADD     w0, #8, w1          ; Point to setup data fields
    MOV     USB.REG.CurrentBD, w3
    MOV     [w3+RX.EVEN.ADDRESS], w4
    DO      #3, 1f
    MOV     [w4++], [w1++]
1:  NOP
    ; Return the RX buffer to the USB Module
    MOV     #0x0080, w4
    MOV     USB.REG.CurrentBD, w1
    MOV     w4, [w1+RX.EVEN.WORD0]
    BRA     3f
    ; Test for data stage --------------------------------------------
0:  BTSS    w2, #CTDAT
    BRA     0f
    BRA     3f
    ; Test for status stage ------------------------------------------
0:  BTSS    w2, #CTST
    BRA     AppError8
    BRA     3f

    ; Isolate bRequest field
3:  CLR     w3
    ADD     w0, #8, w0
    MOV.B   [w0+CT.SETUP.bRequest], w3
    ; Initiate request processing
    SL      w3, #3, w3                  ; Align with jump table entry
    BTSC    w2, #CTDAT
    BSET    w3, #1                      ; Set if in data stage
    BTSC    w2, #CTST
    BSET    w3, #2                      ; Set if in status stage
    ; w3 now contains jump table offset.
    MOV     #.startof.(USB.SUB.CT.RequestJumpTable), w0
    ADD     w0, w3, w3
    MOV     #0x0000, w0
    ; Modify program counter
    PUSH    w3
    PUSH    w0
.ifdecl USB.OPTION.DEBUG.SwitchOnEventLog
    ;MOV     #USB.DEBUG.CTCall, w6
    ;RCALL   USB.SUB.DEBUG.LogEvent
.endif
    RETURN                              ; Go to jump table
  
                                                      ; End of routine
; --------------------------------------------------------------------





; --------------------------------------------------------------------
; USB Request Jump Table
; --------------------------------------------------------------------
; Instead of a request by request comparison of the bRequest field
; with all the different request codes, it is more efficient to store
; branch instructions to each request routine in an ordered table and
; then modify the program counter manually. The new program address
; is pushed onto the solftware stack and a RETURN instruction is
; executed to move execution to the relevent point in the table,
; which contains a branch instruction to the relavent request.

.section USB.SUB.CT.RequestJumpTable, code

    BRA USB.SUB.REQ.GET_STATUS.setup
    BRA USB.SUB.REQ.GET_STATUS.data
    BRA USB.SUB.REQ.GET_STATUS.status
    BRA AppError9

    BRA USB.SUB.REQ.CLEAR_FEATURE.setup
    BRA USB.SUB.REQ.CLEAR_FEATURE.data
    BRA USB.SUB.REQ.CLEAR_FEATURE.status
    BRA AppError9

    BRA AppError9
    BRA AppError9
    BRA AppError9
    BRA AppError9

    BRA USB.SUB.REQ.SET_FEATURE.setup
    BRA USB.SUB.REQ.SET_FEATURE.data
    BRA USB.SUB.REQ.SET_FEATURE.status
    BRA AppError9

    BRA AppError9
    BRA AppError9
    BRA AppError9
    BRA AppError9

    BRA USB.SUB.REQ.SET_ADDRESS.setup
    BRA AppError9
    BRA USB.SUB.REQ.SET_ADDRESS.status
    BRA AppError9

    BRA USB.SUB.REQ.GET_DESCRIPTOR.setup
    BRA USB.SUB.REQ.GET_DESCRIPTOR.data
    BRA USB.SUB.REQ.GET_DESCRIPTOR.status
    BRA AppError9

    BRA USB.SUB.REQ.SET_DESCRIPTOR.setup
    BRA USB.SUB.REQ.SET_DESCRIPTOR.data
    BRA USB.SUB.REQ.SET_DESCRIPTOR.status
    BRA AppError9

    BRA USB.SUB.REQ.GET_CONFIGURATION.setup
    BRA USB.SUB.REQ.GET_CONFIGURATION.data
    BRA USB.SUB.REQ.GET_CONFIGURATION.status
    BRA AppError9

    BRA USB.SUB.REQ.SET_CONFIGURATION.setup
    BRA AppError9
    BRA USB.SUB.REQ.SET_CONFIGURATION.status
    BRA AppError9

    BRA USB.SUB.REQ.GET_INTERFACE.setup
    BRA USB.SUB.REQ.GET_INTERFACE.data
    BRA USB.SUB.REQ.GET_INTERFACE.status
    BRA AppError9

    BRA USB.SUB.REQ.SET_INTERFACE.setup
    BRA USB.SUB.REQ.SET_INTERFACE.data
    BRA USB.SUB.REQ.SET_INTERFACE.status
    BRA AppError9

    BRA USB.SUB.REQ.SYNCH_FRAME.setup
    BRA USB.SUB.REQ.SYNCH_FRAME.data
    BRA USB.SUB.REQ.SYNCH_FRAME.status
    BRA AppError9

    BRA USB.SUB.REQ.GET_MS_DESCRIPTOR.setup
    BRA USB.SUB.REQ.GET_MS_DESCRIPTOR.data
    BRA USB.SUB.REQ.GET_MS_DESCRIPTOR.status
    BRA AppError9

    BRA USB.SUB.REQ.GET_MS_20_DESCRIPTOR.setup
    BRA USB.SUB.REQ.GET_MS_20_DESCRIPTOR.data
    BRA USB.SUB.REQ.GET_MS_20_DESCRIPTOR.status
    BRA AppError9

    BRA USB.SUB.REQ.TOGGLE_LED.setup
    BRA AppError9
    BRA USB.SUB.REQ.TOGGLE_LED.status
    BRA AppError9

    BRA USB.SUB.REQ.WINDOWS_COMMAND.setup
    BRA AppError9
    BRA USB.SUB.REQ.WINDOWS_COMMAND.status
    BRA AppError9
    
    BRA USB.SUB.REQ.READ_BUTTONS.setup
    BRA USB.SUB.REQ.READ_BUTTONS.data
    BRA USB.SUB.REQ.READ_BUTTONS.status
    BRA AppError9

                                                        ; End of table
; --------------------------------------------------------------------


; --------------------------------------------------------------------
; USB Control Read and Write Routines
; --------------------------------------------------------------------
; During a control transfer the microcontroller must obey the
; rules laid out in the USB 2.0 specification for packet sequences.
; The exact sequence of packets depends on whether the control
; transfer is a control read or a control write. However this packet
; sequence does not depend on the content of the message, so the
; routines to handle control reads and writes are defined here and
; then called by the request processing routines once the content
; of the message has been interpreted

USB.SUB.CT.control_read.setup:

    ; Point to current buffer descriptor table endpoint block
    MOV     USB.REG.CurrentBD, w2 ; Definitely?
    ; Load the address into the EVEN buffer
    MOV     USB.REG.CT.NextBufferAddress, w1
    MOV     w1, [w2+TX.EVEN.ADDRESS]    ; Next trans. TX EVEN
    ; Read the requested data size from the setup data
1:  MOV     [w7+CT.SETUP.wLength], w0   ; w0 contains requested size
    ; Read the amount of data to be sent
    MOV     USB.REG.CT.NextTransferLength, w4
    ; Check whether descriptor size is less than requested length
    CPBLT   w4, w0, 1f
    CPBEQ   w4, w0, 1f
    BRA     2f
1:  MOV     w4, w0
2:  MOV     w0, [w5+DLword]    ; Store total bytes to send
    ; Check whether bytes to send exceeds buffer size
    MOV     #USB.OPTION.CONFIG.EPBufferSize, w1
    CPBGT   w1, w0, 1f
    CPBEQ   w1, w0, 1f
    MOV     w1, w0                      ; Use buffer size instead.
1:  MOV     w0, [w2+TX.EVEN.BYTECOUNT]  ; Next trans. is TX EVEN
    ; Address and bytecount fields set. Write WORD0
3:  MOV     #0x00C0, w0             ; Set UOWN, use DATA1
    MOV     [w5+CTword], w1
    MOV     w1, [w5+CTword]
    MOV     w0, [w2+TX.EVEN.WORD0]         ; Next trans. TX EVEN
    ; Return to the Transaction Processing Routine
    RETURN


USB.SUB.CT.control_read.data:

    ; Retreive the amount data sent in last packet and compare it the
    ; total data to send
    MOV     USB.REG.CT.CurrentRegBlockAddress, w5
    MOV     [w5+DLword], w0   ; w0 contains total bytes left to send
    MOV     USB.REG.CurrentBD, w2
    MOV     [w2+TX.EVEN.BYTECOUNT], w1  ; w1 contains no. bytes sent
1:  CPBGT   w0, w1, 2f
    CPBEQ   w0, w1, 3f
    ; Too much information sent
    BRA     AppError11

    ; Need to send more data. Prepear the next packet
2:  SUB     w0, w1, w0  ; w0 contains quantity of data still to send
    MOV     w0, [w5+DLword]
    MOV     [w2+TX.EVEN.BYTECOUNT], w4  ; amount of data just sent
    ; Check whether bytes still to send exceeds buffer size
    MOV     #USB.OPTION.CONFIG.EPBufferSize, w1
    CPBGT   w1, w0, 1f
    CPBEQ   w1, w0, 1f
    MOV     w1, w0                      ; Use buffer size instead.
1:  MOV     w0, [w2+TX.EVEN.BYTECOUNT]  ; Next trans. is TX EVEN
    ; Construct the new address
    MOV     [w2+TX.EVEN.ADDRESS], w0
    ADD     w0, w4, w0
    MOV     w0, [w2+TX.EVEN.ADDRESS]
    ; Address and bytecount fields set. Write WORD0
    MOV     [w2+TX.EVEN.WORD0], w4  ; Old WORD0
    BTG     w4, #DATA01
    BSET    w4, #UOWN
    MOV     #0xFFC3, w3
    AND     w3, w4, w4              ; New WORD0 contained in w4
    MOV     [w5+CTword], w1
    MOV     w1, [w5+CTword]
    MOV     w4, [w2+TX.EVEN.WORD0]  ; Next trans. TX EVEN
    ; Return to the Transaction Processing Routine
    RETURN

    ; Correct quantity of data already sent
    ; Prepear the status stage. For a read this involves receiving a
    ; zero length data packet.
3:  MOV     #0x0080, w1     ; WORD0
    MOV     #64, w3         ; Bytecount
    MOV     [w2+TX.EVEN.BYTECOUNT], w1  ; w1 contains no. bytes sent
    ; Final register modification
    MOV     [w5+CTword], w0
    BCLR    w0, #CTDAT      ; End of data stage
    BSET    w0, #READ       ; Status stage expects a 0 length packet
    BSET    w0, #CTST       ; Next stage status
    MOV     w0, [w5+CTword]
    ; Return to Transaction Processing Routine
    RETURN

USB.SUB.CT.control_read.status:

    ; Check that the status stage behaviour is compatible
    ; with a read operation
    MOV     USB.REG.CT.CurrentRegBlockAddress, w5
    MOV     [w5+CTword], w0
    BTSS    w0, #READ
    BRA     AppError12
    ; Perform checks on the received packet
    MOV     USB.REG.CurrentBD, w2
    MOV     [w2+RX.EVEN.WORD0], w0
    BTSS    w0, #DATA01
    BRA     AppError14
    MOV     [w2+RX.EVEN.BYTECOUNT], w0
    MOV     #0x0000, w1
    CPSEQ   w0, w1
    BRA     AppError13
    ; Clear up registers for end of CT
    MOV     [w5+CTword], w0
    BCLR    w0, #CTEN
    BCLR    w0, #CTDAT
    BCLR    w0, #CTST
    BCLR    w0, #NDT
    BCLR    w0, #READ
    MOV     w0, [w5+CTword]
    MOV     [w5+DLword], w0
    CLR     w0
    MOV     w0, [w5+DLword]
    ; Reset all buffer descriptors
    MOV     #0x0080, w0
    MOV     #64, w1
    MOV     w0, [w2+RX.EVEN.WORD0]
    MOV     w1, [w2+RX.EVEN.BYTECOUNT]
    MOV     #0x0000, w0
    MOV     #0, w1
    MOV     w0, [w2+TX.EVEN.WORD0]
    MOV     w1, [w2+TX.EVEN.BYTECOUNT]
    ; Return to Transaction Processing Routine
    RETURN


USB.SUB.CT.control_write.setup:
; ---------------------------------------------------------
; NOTE: This routine is currently only capable of handling
; write operations which do not have a data stage.
; ---------------------------------------------------------

    ; Device must return a zero length packet in the next stage
    MOV     #0x0080, w0                     ; Reset RX
    MOV     #64, w1
    MOV     USB.REG.CurrentBD, w2
    MOV     w0, [w2+RX.EVEN.WORD0]
    MOV     w1, [w2+RX.EVEN.BYTECOUNT]
    MOV     #0x00C0, w0                     ; Prepear TX
    MOV     #0, w1
    MOV     w0, [w2+TX.EVEN.WORD0]
    MOV     w1, [w2+TX.EVEN.BYTECOUNT]
    ; Return to Transaction Processing Routine
    RETURN

USB.SUB.CT.control_write.data:

USB.SUB.CT.control_write.status:

    ; Check that the status stage behaviour is compatible
    ; with a write operation
    MOV     USB.REG.CT.CurrentRegBlockAddress, w5
    MOV     [w5+CTword], w0
    BTSC    w0, #READ
    BRA     AppError12
    ; Perform checks on the sent packet
    MOV     USB.REG.CurrentBD, w2
    MOV     [w2+TX.EVEN.WORD0], w0
    BTSS    w0, #DATA01
    BRA     AppError14
    MOV     [w2+TX.EVEN.BYTECOUNT], w0
    MOV     #0x0000, w1
    CPSEQ   w0, w1
    BRA     AppError13
    ; Clear up registers for end of CT
    MOV     [w5+CTword], w0
    BCLR    w0, #CTEN
    BCLR    w0, #CTDAT
    BCLR    w0, #CTST
    BCLR    w0, #NDT
    BCLR    w0, #READ
    MOV     w0, [w5+CTword]
    MOV     [w5+DLword], w0
    CLR     w0
    MOV     w0, [w5+DLword]
    ; Reset buffer descriptors
    MOV     #0x0080, w0
    MOV     w0, [w2+RX.EVEN.WORD0]
    MOV     #64, w0
    MOV     w0, [w2+RX.EVEN.BYTECOUNT]
    MOV     #0x0000, w0
    MOV     w0, [w2+TX.EVEN.WORD0]
    MOV     #0, w0
    MOV     w0, [w2+TX.EVEN.BYTECOUNT]
    ; Return to Transaction Processing Routine
    RETURN










                                                     ; End of routines
; --------------------------------------------------------------------




