/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* File Name: usb-21-reg.s
*
* Type: DATA
*
* Title: USB Register Definitions
*
* Version: 2.1
*
* Purpose: The USB Transfer Handling Framework makes use of registers
*          to store information about current processes. These are
*          defined in this file and referenced throughout the source
*          code using USB.REG.* names.
*
* Date first created: 11th October 2015
* Date last modified: 26th January 2017
*
* Author: John Scott
*
* Used by: usb-21.s
*
*
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

.include "p33EP512MU810.inc"
;.include "extern-11.inc"
    
; ===================== REGISTER DECLARATIONS ========================
    
.global USB.REG.TRN   
 
.global USB.REG.CurrentBD
    
.global USB.REG.CT.CurrentRegBlockAddress
.global USB.REG.CT.PendingAddress
.global USB.REG.CT.NextBufferAddress
.global USB.REG.CT.NextTransferLength
    
.global USB.REG.DEBUG.NextEventAddress
    
.global USB.REG.STAT.General
    
.global USB.w0
.global USB.w1
.global USB.w2
.global USB.w3
.global USB.w4
.global USB.w5
.global USB.w6
.global USB.w7
.global USB.w8
.global USB.w9
.global USB.w10
.global USB.w11
.global USB.w12
.global USB.w13
.global USB.w14
.global USB.w15
    
.global USB.REG.IT.DATA
.global USB.REG.IT.CurrentRegBlockAddress
.global USB.REG.IT.TX.status
.global USB.REG.IT.TX.BUFFER.pointer_gap
.global USB.REG.IT.TX.BUFFER.pointer.send
.global USB.REG.IT.TX.BUFFER.pointer.fill
.global USB.REG.IT.RX.status
.global USB.REG.IT.RX.BUFFER.pointer_gap
.global USB.REG.IT.RX.BUFFER.pointer.receive
.global USB.REG.IT.RX.BUFFER.pointer.read
    
.global USB.REG.BT.DATA
.global USB.REG.BT.CurrentRegBlockAddress
.global USB.REG.BT.TX.status
.global USB.REG.BT.TX.BUFFER.pointer_gap
.global USB.REG.BT.TX.BUFFER.pointer.send
.global USB.REG.BT.TX.BUFFER.pointer.fill
.global USB.REG.BT.RX.status
.global USB.REG.BT.RX.BUFFER.pointer_gap
.global USB.REG.BT.RX.BUFFER.pointer.receive
.global USB.REG.BT.RX.BUFFER.pointer.read
    

; ============================= DATA =================================

; --------------------------------------------------------------------
; Global Transaction Processing
; --------------------------------------------------------------------
.section USB.REG.TRN, data, near
USB.REG.CurrentBD:        .word 0x0000
; Stores the start address of the last buffer descriptor block

; --------------------------------------------------------------------
; Endpoint Transaction Processing
; --------------------------------------------------------------------

; First 8 bytes of each block (grouped into 4 words):
.global CTword
.equiv CTword,  0 ; word 0: CT ------------------------
.equiv CTEN,    0 ;                    Set bit 0 if CT in progress
.equiv CTDAT,   1 ;                    Set bit 1 if next stage data
.equiv CTST,    2 ;                    Set bit 2 if in status stage
.equiv NDT,     3 ;                    Set bit 3 if next trans. DATA1
.equiv READ,    4 ;                    Set bit 4 if CT is a read
.equiv GENword, 2 ; word 1: GENERAL -------------------
.equiv PPBB,    0 ;                    Set bit 0 if next TX ODD
.equiv PPBBR,   1 ;                    Set bit 1 if next RX ODD
.equiv DLword,  2 ; word 2: DATA LENGTH ---------------
                  ; Contains number of bytes to send
.equiv ITword,  4 ; word 3: IT ------------- Interrupt Transfer
.equiv ITEN,    0 ;                    Set bit 0 if IT in progress
.equiv ITDAT,   1 ;                    Set bit 1 if next stage data
.equiv ITST,    2 ;                    Set bit 2 if in status stage
.equ   NDT,     3 ;                    Set bit 3 if next trans. DATA1
.equ   READ,    4 ;                    Set bit 4 if IT is a read
.equiv TXNDT,   5 ;(for TX channel)    Set bit 5 if next trans. DATA1
.equiv RXNDT,   6 ;(for RX channel)    Set bit 6 if next trans. DATA1
.equiv BTword,  6 ; word 4: BT ------------- Bulk Transfer
.equiv BTEN,    0 ;                    Set bit 0 if BT in progress
.equiv BTDAT,   1 ;                    Set bit 1 if next stage data
.equiv BTSTA,   2 ;                    Set bit 2 if in status stage
.equ   NDT,     3 ;                    Set bit 3 if next trans. DATA1
.equ   READ,    4 ;                    Set bit 4 if BT is a read
.equ   TXNDT,   5 ;(for TX channel)    Set bit 5 if next trans. DATA1
.equ   RXNDT,   6 ;(for RX channel)    Set bit 6 if next trans. DATA1

; Second 8 bytes of each block: setup data for control transfer

.section USB.REG.EP, data, near
/* ENDPOINT 0  */      .space   16
/* ENDPOINT 1  */      .space   16
/* ENDPOINT 2  */      .space   16
/* ENDPOINT 3  */      .space   16
/* ENDPOINT 4  */      .space   16
/* ENDPOINT 5  */      .space   16
/* ENDPOINT 6  */      .space   16
/* ENDPOINT 7  */      .space   16
/* ENDPOINT 8  */      .space   16
/* ENDPOINT 9  */      .space   16
/* ENDPOINT 10 */      .space   16
/* ENDPOINT 11 */      .space   16
/* ENDPOINT 12 */      .space   16
/* ENDPOINT 13 */      .space   16
/* ENDPOINT 14 */      .space   16
/* ENDPOINT 15 */      .space   16

USB.REG.CT.CurrentRegBlockAddress:  .word 0x0000
; Contains the starting address of the 16 byte long block in the CT
; register which is currently being processed.

USB.REG.CT.PendingAddress:          .word 0x0000
; Contains the address assigned to the device by the host which
; should be set at the end of the status stage of the SET_ADDRESS
; request.

USB.REG.CT.NextBufferAddress:       .word 0x0000
; This register contains the address to be loaded into the USB
; module buffer descriptor table for use in the next USB transaction.

USB.REG.CT.NextTransferLength:      .word 0x0000
; This is used by request processing routines to define the length
; of data to be transmitted or the expected length of data to
; be received during the data stage of a control transfer.


; --------------------------------------------------------------------
; Debug Registers
; --------------------------------------------------------------------

.section USB.REG.DEBUG, data, near
USB.REG.DEBUG.NextEventAddress:      .word .startof.(USB.Log)
; contains the pointer to the next available entry in the event log


; --------------------------------------------------------------------
; Status Register
; --------------------------------------------------------------------

.section USB.REG.STAT, data, near
USB.REG.STAT.General:           .word 0x0000
; contains the status word to be returned during a GET_STATUS request.

; --------------------------------------------------------------------
; Working register backup
; --------------------------------------------------------------------
; These are used by the USB interrupt service routine to perform a
; backup of the working registers before responding to the interrupt
; event. The working registers are restored to their original
; state at the end of the interrupt service routine
USB.w0:     .word 0x0000
USB.w1:     .word 0x0000
USB.w2:     .word 0x0000
USB.w3:     .word 0x0000
USB.w4:     .word 0x0000
USB.w5:     .word 0x0000
USB.w6:     .word 0x0000
USB.w7:     .word 0x0000
USB.w8:     .word 0x0000
USB.w9:     .word 0x0000
USB.w10:    .word 0x0000
USB.w11:    .word 0x0000
USB.w12:    .word 0x0000
USB.w13:    .word 0x0000
USB.w14:    .word 0x0000
USB.w15:    .word 0x0000

; --------------------------------------------------------------------
; Interrupt Transfer
; --------------------------------------------------------------------

.section USB.REG.IT, data, near
USB.REG.IT.DATA:                .word 0x0000
; contains the next word to be sent via interrupt transfer

USB.REG.IT.CurrentRegBlockAddress:  .word 0x0000
; Contains the starting address of the 16 byte current register
; block. Used when processing interrupt transfers.

; --------------------------------------------------------------------
; Interrupt transfer data buffer pointers (TX)
; --------------------------------------------------------------------

USB.REG.IT.TX.status:                 .word 0x0000
; Interrupt transfers on endpoint 1 should only be initialised once
; for real time data transfer. Once it has been initialised only the
; interrupt transfer processing routine can end the session, in
; which case the process may be reinitialised.
;
; Bit 0 is set once by the application when it initialises the
; interrupt transfers This prevents the interrupt transfer being
; initialised again.

USB.REG.IT.TX.BUFFER.pointer_gap:     .word 0x0000
; Contains the pointer gap, ie the number of buffer entries
; seperating the buffer next to be transmitted from the buffer last
; written. Application breaks if this reaches 64 (half the buffer
; size)

USB.REG.IT.TX.BUFFER.pointer.send: .word .startof.(USB.REG.IT.TX.BUFFER)
; Used by the interrupt transfer routine to point to the start of the
; next packet which should be sent to the host

USB.REG.IT.TX.BUFFER.pointer.fill:.word .startof.(USB.REG.IT.TX.BUFFER)
; Used by the user application when filling the next available
; entry in the interrupt transfer buffer.

; --------------------------------------------------------------------
; Interrupt transfer data buffer pointers (RX)
; --------------------------------------------------------------------

USB.REG.IT.RX.status:                 .word 0x0000
; Currently unimplemented

USB.REG.IT.RX.BUFFER.pointer_gap:     .word 0x0000
; Contains the pointer gap, ie the number of buffer entries
; seperating the buffer next to be filled from the buffer last
; read. Application breaks if this reaches 64 (half the buffer
; size)

USB.REG.IT.RX.BUFFER.pointer.receive: .word .startof.(USB.REG.IT.RX.BUFFER)
; Used by the interrupt transfer routine to point to the start of the
; next free buffer entry for received data.

USB.REG.IT.RX.BUFFER.pointer.read:.word .startof.(USB.REG.IT.RX.BUFFER)
; Used by the user application when reading the next highest priority
; buffer entry.

; --------------------------------------------------------------------
; Bulk Transfer
; --------------------------------------------------------------------

.section USB.REG.BT, data, near
USB.REG.BT.DATA:                .word 0x0000
; contains the next word to be sent via bulk transfer

USB.REG.BT.CurrentRegBlockAddress:  .word 0x0000
; Contains the starting address of the 16 byte current register
; block. Used when processing bulk transfers.

; --------------------------------------------------------------------
; Bulk transfer data buffer pointers (TX)
; --------------------------------------------------------------------

USB.REG.BT.TX.status:                 .word 0x0000
; Bit 0 is set if a bulk transfer has been inititialised

USB.REG.BT.TX.BUFFER.pointer_gap:     .word 0x0000
; Contains the pointer gap, ie the number of buffer entries
; seperating the buffer next to be transmitted from the buffer last
; written. Application breaks if this reaches 64 (half the buffer
; size)

USB.REG.BT.TX.BUFFER.pointer.send: .word .startof.(USB.REG.BT.TX.BUFFER)
; Used by the interrupt transfer routine to point to the start of the
; next packet which should be sent to the host

USB.REG.BT.TX.BUFFER.pointer.fill:.word .startof.(USB.REG.BT.TX.BUFFER)
; Used by the user application when filling the next available
; entry in the interrupt transfer buffer.

; --------------------------------------------------------------------
; Bulk transfer data buffer pointers (RX)
; --------------------------------------------------------------------

USB.REG.BT.RX.status:                 .word 0x0000
; Currently unimplemented

USB.REG.BT.RX.BUFFER.pointer_gap:     .word 0x0000
; Contains the pointer gap, ie the number of buffer entries
; seperating the buffer next to be filled from the buffer last
; read. Application breaks if this reaches 64 (half the buffer
; size)

USB.REG.BT.RX.BUFFER.pointer.receive: .word .startof.(USB.REG.BT.RX.BUFFER)
; Used by the interrupt transfer routine to point to the start of the
; next free buffer entry for received data.

USB.REG.BT.RX.BUFFER.pointer.read:.word .startof.(USB.REG.BT.RX.BUFFER)
; Used by the user application when reading the next highest priority
; buffer entry.

