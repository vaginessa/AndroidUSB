/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* File Name: usb-21-reg.inc
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
* Date last modified: 11th October 2015
*
* Author: John Scott
*
* Used by: usb-21.inc
*
*
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


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

USB.REG.CT.NextTransferLength:      .word
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


; --------------------------------------------------------------------
; For use by Windows functions
; --------------------------------------------------------------------

.section USB.REG.WIN, data, near

USB.REG.WIN.WF1.value:  .word 2000
; Stores a value to be transmitted back to the Windows application
; in real time. Value modifed by buttons. Used as a test of
; interrupt transfer processing.

USB.REG.WIN.WF2.value:  .word 0x0000
; Stores a value that has been received from the host Windows
; application via an interrupt transfer

USB.REG.WIN.WF3.value:  .word 0x0000
; Stores a value that is received from the host Windows application
; and subsequently sent back. Used to test both interrupt channels
; simultaneously.

USB.REG.WIN.WF4.value:  .word 0x0000
; Stores an instantaneous pressure measurement ready to be transmitted
; to the host Windows application via an interrupt transfer.

USB.REG.WIN.WF5.value:  .word 2000
; Stores a value to be transmitted back to the Windows application
; in via a bulk transfer. Value modifed by buttons.

USB.REG.WIN.WF6.value:  .word 0x0000
; Stores a value that has been received from the host Windows
; application via a bulk transfer.

USB.REG.WIN.WF7.value:  .word 0x0000
; Stores a value that is received from the host Windows application
; and subsequently sent back. Used to test both bulk channels
; simultaneously.

USB.REG.WIN.WF8.motor_target:  .word 0x0000
; Stores a target motor position, received from the host windows
; application, which is subsequently written to the motor

USB.REG.WIN.WF8.motor_position:  .word 0x0000
; Stores the motor position, obtained from the servo drive, which is
; sent back to the host windows application

USB.REG.WIN.WF8.motor_velocity: .word 0x0000
; Stores the motor velocity, obtained from the servo drive, which is
; sent back to the host windows application

USB.REG.WIN.WF8.pressure_1:  .word 0x0000
; Stores an instantaneous pressure measurement ready to be transmitted
; to the host Windows application via a bulk transfer.

USB.REG.WIN.WF8.pressure_2:  .word 0x0000
; Stores an instantaneous pressure measurement ready to be transmitted
; to the host Windows application via a bulk transfer.

USB.REG.WIN.WF8.pressure_difference:  .word 0x0000
; Stores the instantaneous pressure difference found by subtracting
; the two pressure readings. Subsequently scaled to get a flow
; signal (scaling done by host Windows application).

; --------------------------------------------------------------------
; Windows Function 10
; --------------------------------------------------------------------

; ---------------------------------------------------- Setpoint buffer

.section USB.REG.WIN.WF10.setpoint_buffer, data, align(512)
.space 0 ; should be 512

; --------------------------------------------- Actual position buffer

.section USB.REG.WIN.WF10.position_buffer, data, align(512)
.space 0 ; should be 512

; --------------------------------------------- Actual velocity buffer

.section USB.REG.WIN.WF10.velocity_buffer, data, align(512)
.space 0 ; should be 512

; ----------------------------------------------- Pressure data buffer

.section USB.REG.WIN.WF10.pressure_buffer, data, align(512)
.space 0 ; should be 512

; -------------------------------------------- Values written to drive

.section USB.REG.WIN.WF10.written_to_drive, data, align(4096)
.space 0 ; should be 4096

USB.REG.WIN.WF10.test_pointer: 
.word .startof.(USB.REG.WIN.WF10.written_to_drive)

; ----------------------------------------------------- TX data buffer
; Each entry is four 64 byte packets long. There are 16 entries in the
; buffer.
;
; The first packet contains setpoint data; the next two packets
; contains actual position and velocity data; and the last packet
; contains pressure data and other status information.

.section USB.REG.WIN.WF10.TX_data_buffer, data, align(4096)
.space 4096

; Offsets for use inside a buffer entry
.equiv  TXBO.setpoint_packet,       0
.equiv  TXBO.position_packet,       64
.equiv  TXBO.velocity_packet,       128
.equiv  TXBO.pressure_1,            192
.equiv  TXBO.pressure_2,            194
.equiv  TXBO.pressure_difference,   196

.section USB.REG.WIN10, data, near

USB.REG.WF10.COUNTER.PL: .word 0x0000
; Counts the number of times the pressure loop has begun execution

USB.REG.WF10.COUNTER.ML: .word 0x0000
; Counts the number of times the motor loop has begun execution

; -------------------------------------------- TX data buffer pointers

USB.REG.WIN.WF10.TX_data_buffer.ml_pointer_gap:     .word 0x0000
; Contains the pointer gap for use by the motor loop

USB.REG.WIN.WF10.TX_data_buffer.pl_pointer_gap:     .word 0x0000
; Contains the pointer gap for use by the pressure loop

USB.REG.WIN.WF10.TX_data_buffer.pointer.send:
.word .startof.(USB.REG.WIN.WF10.TX_data_buffer)
; Points to the start of the next free buffer entry for sending data.

USB.REG.WIN.WF10.TX_data_buffer.pointer.ml_fill:
.word .startof.(USB.REG.WIN.WF10.TX_data_buffer)
; Used by the motor loop when writing the next highest priority
; buffer entry.

USB.REG.WIN.WF10.TX_data_buffer.pointer.pl_fill:
.word .startof.(USB.REG.WIN.WF10.TX_data_buffer)
; Used by the pressure loop when writing the next highest priority
; buffer entry.

USB.REG.WIN.WF10.TX_data_buffer.pointer.internal:
.word 0x0000
; Contains an offset to the next entry to be written in the current
; setpoint/position/velocity packet



; ------------------------------------------- Setpoint buffer pointers

USB.REG.WIN.WF10.setpoint_buffer.pointer_gap:     .word 0x0000
; Contains the pointer gap, ie the number of buffer entries
; seperating the buffer next to be filled from the buffer last
; read. 

USB.REG.WIN.WF10.setpoint_buffer.pointer.receive:
.word .startof.(USB.REG.WIN.WF10.setpoint_buffer)
; Points to the start of the next free buffer entry for received data.

USB.REG.WIN.WF10.setpoint_buffer.pointer.read:
.word .startof.(USB.REG.WIN.WF10.setpoint_buffer)
; Used by the user application when reading the next highest priority
; buffer entry.


; ------------------------------------ Actual position buffer pointers

USB.REG.WIN.WF10.position_buffer.pointer_gap:     .word 0x0000
; Contains the pointer gap, ie the number of buffer entries
; seperating the buffer next to be filled from the buffer last
; read.

USB.REG.WIN.WF10.position_buffer.pointer.send:
.word .startof.(USB.REG.WIN.WF10.position_buffer)
; Points to the start of the next buffer entry to be sent

USB.REG.WIN.WF10.position_buffer.pointer.fill:
.word .startof.(USB.REG.WIN.WF10.position_buffer)
; Used by the user application when writing the latest data

; ------------------------------------ Actual velocity buffer pointers

USB.REG.WIN.WF10.velocity_buffer.pointer_gap:     .word 0x0000
; Contains the pointer gap, ie the number of buffer entries
; seperating the buffer next to be filled from the buffer last
; read. 

USB.REG.WIN.WF10.velocity_buffer.pointer.send:
.word .startof.(USB.REG.WIN.WF10.velocity_buffer)
; Points to the start of the next buffer entry to be sent

USB.REG.WIN.WF10.velocity_buffer.pointer.fill:
.word .startof.(USB.REG.WIN.WF10.velocity_buffer)
; Used by the user application when writing the latest data



; -------------------------------------- Pressure data buffer pointers

USB.REG.WIN.WF10.pressure_buffer.pointer_gap:     .word 0x0000
; Contains the pointer gap, ie the number of buffer entries
; seperating the buffer next to be filled from the buffer last
; read.

USB.REG.WIN.WF10.pressure_buffer.pointer.send:
.word .startof.(USB.REG.WIN.WF10.pressure_buffer)
; Points to the start of the next buffer entry to be sent

USB.REG.WIN.WF10.pressure_buffer.pointer.fill:
.word .startof.(USB.REG.WIN.WF10.pressure_buffer)
; Used by the user application when writing the latest data

; ---------------------------------------------------- Status register


USB.REG.WIN.WF10.status:     .word 0x0000
; Individual bits contain information about what parts of the
; routine are currently running. This ensures that none of the
; pointers are currupted when the order of execution is modified by
; interrupts.

.equiv WFEN,    0 ;     Set bit if WF10 is running
.equiv MLEN,    1 ;     Set bit if the motor loop is running
.equiv PLEN,    2 ;     Set bit if the pressure loop is running
.equiv TEN,     3 ;     Set bit to indicate that the timers are on
.equiv RDAT,    4 ;     Set bit to accept bulk data
.equiv CLEN,    5 ;     Set bit if the communication loop is running
.equiv TDAT,    6 ;     Set bit to send bulk data
.equiv PLFN,    7 ;     Set bit when pressure loop has finished
.equiv WFSC,    8 ;     Set bit when WF10 setup is complete

USB.REG.WIN.WF10.properties.data_size.target:     .word 30
; After receiving data from the windows application the device can
; define the amount of data to be sent in the next data cycle. This
; allows the device to maintain a gap of about 10 setpoints above
; what it needs to avoid motor stalls.

USB.REG.WIN.WF10.properties.data_size.position:     .word 0x0000
; This register is used to indicate the amount of position data
; being returned to the windows application by the device. This
; value must not exceed 30.

USB.REG.WIN.WF10.properties.data_size.velocity:     .word 0x0000
; This register is used to indicate the amount of velocity data
; being returned to the windows application by the device. This
; value must not exceed 30.

USB.REG.WIN.WF10.properties.data_size.pressure:     .word 0x0000
; This register is used to indicate the amount of pressure data
; being returned to the windows application by the device. The
; unit of this registers is 'number of entries' -- an entry is
; three words long. This value must not exceed 10.

; -------------------------------------------- Context store registers

.section USB.REG.WIN10.context, data, near

; Motor loop context registers
USB.REG.WIN.WF10.CONTEXT.ML.w0: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.ML.w1: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.ML.w2: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.ML.w3: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.ML.w4: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.ML.w5: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.ML.w6: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.ML.w7: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.ML.w8: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.ML.w9: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.ML.w10: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.ML.w11: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.ML.w12: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.ML.w13: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.ML.w14: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.ML.w15: .word 0x0000

; Pressure loop context registers
USB.REG.WIN.WF10.CONTEXT.PL.w0: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.PL.w1: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.PL.w2: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.PL.w3: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.PL.w4: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.PL.w5: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.PL.w6: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.PL.w7: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.PL.w8: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.PL.w9: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.PL.w10: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.PL.w11: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.PL.w12: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.PL.w13: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.PL.w14: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.PL.w15: .word 0x0000

; ----------------------------------- Pointer increment context backup


USB.REG.WIN.WF10.CONTEXT.receive_setpoint_increment.w0: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.receive_setpoint_increment.w1: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.receive_setpoint_increment.w2: .word 0x0000
USB.REG.WIN.WF10.CONTEXT.receive_setpoint_increment.w3: .word 0x0000

USB.REG.WIN.WF10.CONTEXT.read_setpoint_increment.w0:    .word 0x0000
USB.REG.WIN.WF10.CONTEXT.read_setpoint_increment.w1:    .word 0x0000
USB.REG.WIN.WF10.CONTEXT.read_setpoint_increment.w2:    .word 0x0000
USB.REG.WIN.WF10.CONTEXT.read_setpoint_increment.w3:    .word 0x0000

USB.REG.WIN.WF10.CONTEXT.fill_position_increment.w0:    .word 0x0000
USB.REG.WIN.WF10.CONTEXT.fill_position_increment.w1:    .word 0x0000
USB.REG.WIN.WF10.CONTEXT.fill_position_increment.w2:    .word 0x0000
USB.REG.WIN.WF10.CONTEXT.fill_position_increment.w3:    .word 0x0000

USB.REG.WIN.WF10.CONTEXT.send_position_increment.w0:    .word 0x0000
USB.REG.WIN.WF10.CONTEXT.send_position_increment.w1:    .word 0x0000
USB.REG.WIN.WF10.CONTEXT.send_position_increment.w2:    .word 0x0000
USB.REG.WIN.WF10.CONTEXT.send_position_increment.w3:    .word 0x0000

USB.REG.WIN.WF10.CONTEXT.fill_velocity_increment.w0:    .word 0x0000
USB.REG.WIN.WF10.CONTEXT.fill_velocity_increment.w1:    .word 0x0000
USB.REG.WIN.WF10.CONTEXT.fill_velocity_increment.w2:    .word 0x0000
USB.REG.WIN.WF10.CONTEXT.fill_velocity_increment.w3:    .word 0x0000

USB.REG.WIN.WF10.CONTEXT.send_velocity_increment.w0:    .word 0x0000
USB.REG.WIN.WF10.CONTEXT.send_velocity_increment.w1:    .word 0x0000
USB.REG.WIN.WF10.CONTEXT.send_velocity_increment.w2:    .word 0x0000
USB.REG.WIN.WF10.CONTEXT.send_velocity_increment.w3:    .word 0x0000

USB.REG.WIN.WF10.CONTEXT.fill_pressure_increment.w0:    .word 0x0000
USB.REG.WIN.WF10.CONTEXT.fill_pressure_increment.w1:    .word 0x0000
USB.REG.WIN.WF10.CONTEXT.fill_pressure_increment.w2:    .word 0x0000
USB.REG.WIN.WF10.CONTEXT.fill_pressure_increment.w3:    .word 0x0000

USB.REG.WIN.WF10.CONTEXT.send_pressure_increment.w0:    .word 0x0000
USB.REG.WIN.WF10.CONTEXT.send_pressure_increment.w1:    .word 0x0000
USB.REG.WIN.WF10.CONTEXT.send_pressure_increment.w2:    .word 0x0000
USB.REG.WIN.WF10.CONTEXT.send_pressure_increment.w3:    .word 0x0000

USB.REG.WIN.WF10.CONTEXT.ml_fill_TX_data_increment.w0:  .word 0x0000
USB.REG.WIN.WF10.CONTEXT.ml_fill_TX_data_increment.w1:  .word 0x0000
USB.REG.WIN.WF10.CONTEXT.ml_fill_TX_data_increment.w2:  .word 0x0000
USB.REG.WIN.WF10.CONTEXT.ml_fill_TX_data_increment.w3:  .word 0x0000

USB.REG.WIN.WF10.CONTEXT.pl_fill_TX_data_increment.w0:  .word 0x0000
USB.REG.WIN.WF10.CONTEXT.pl_fill_TX_data_increment.w1:  .word 0x0000
USB.REG.WIN.WF10.CONTEXT.pl_fill_TX_data_increment.w2:  .word 0x0000
USB.REG.WIN.WF10.CONTEXT.pl_fill_TX_data_increment.w3:  .word 0x0000

USB.REG.WIN.WF10.CONTEXT.send_TX_data_increment.w0:     .word 0x0000
USB.REG.WIN.WF10.CONTEXT.send_TX_data_increment.w1:     .word 0x0000
USB.REG.WIN.WF10.CONTEXT.send_TX_data_increment.w2:     .word 0x0000
USB.REG.WIN.WF10.CONTEXT.send_TX_data_increment.w3:     .word 0x0000




