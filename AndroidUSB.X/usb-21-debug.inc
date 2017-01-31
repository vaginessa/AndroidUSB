/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* File Name: usb-21-debug.inc
*
* Type: SOURCE
*
* Title: USB Debug Routines
*
* Version: 2.1
*
* Purpose: This file contains the routines for debugging and error
*          handling while the USB Module is in use. Options which
*          control the operations to be performed are contained in
*          usb-21-option-debug.inc.
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

; ============================== DATA ================================
.section USB.Log, data, align(512)
.space 512


.text
; ============================== CODE ================================

; --------------------------------------------------------------------
; Event Logger
; --------------------------------------------------------------------

USB.SUB.DEBUG.LogEvent:
    PUSH.S
    ; Store event code in first available address
    MOV     USB.REG.DEBUG.NextEventAddress, w0
    MOV     w6, [w0]            ; Event code previously in w6
    ; Increment the pointer. Wrap if outside FIFO.
    INC2    w0, w0
    AND     #0x01FF, w0
    MOV     #.startof.(USB.Log), w1
    ADD     w0, w1, w0
    ; Store updated address to first available log entry
    MOV     w0, USB.REG.DEBUG.NextEventAddress
    MOV     #USB.OPTION.DEBUG.EventCounterLimit, w1
    CPSNE   w1, w2
    NOP                     ; Put a breakpoint here when debugging
    POP.S
    RETURN


; --------------------------------------------------------------------
; Application Errors
; --------------------------------------------------------------------

AppError1:  BRA     AppError1
; This error occurs if the application enters the USB Interrupt 
; Service Routine but the USB1IF (USB interrupt flag) is not set.

AppError2:  BRA     AppError2
; This error occurs if the USB error interrupt flag has been raised
; but no USB error flags are set.

AppError3:  BRA     AppError3
; This error occurs if the application enters the USB Interrupt
; Service Routine, finds that the USB1IF flag is set, but that no
; USB interrupt flags in U1IR have been raised.

AppError4:  BRA     AppError4
; This error occurs if the application tries to load the address of
; of the BDT table and finds that the address is not aligned to a
; 512 byte boundary.

AppError5:  BRA     AppError5
; A transaction has been processed and the TRNIF interrupt has been
; raised but the CPU does not own the relevant buffer descriptor
; entry.

AppError6:  BRA     AppError6
; A control transfer is in progress but the status register is
; currupt. Application cannot determine whether control transfer is
; in setup, data or status stage.

AppError7:  BRA     AppError7
; No support for greater than 16 bit USB endpoint addresses.

AppError8:  BRA     AppError8
; Unexpected behaviour. Previous stage of control transfer failed
; to set up next stage correctly.

AppError9:  BRA     AppError9
; Attempt by application to access an unimplemented region of the
; USB Request Jump Table.

AppError10:  BRA     AppError10
; No support for data toggle synchronisation.

AppError11:  BRA     AppError11
; Too much data sent in the data stage of the control transfer

AppError12:  BRA     AppError12
; CT registry entry incorectly described current request as WRITE

AppError13:  BRA     AppError13
; USB protocol error: status stage of a read control transfer
; incorrectly reported a non-zero length data packet.

AppError14:  BRA     AppError14
; USB protocol error: status stage of a read control transfer
; incorrectly reported a DATA0 packet.

AppError15:  BRA     AppError15
; The application failed to return from processing a request.

AppError16:  BRA     AppError16
; Too little data was sent in the data stage of a control transfer

AppError17:  BRA     AppError17
; A windows command contained an undefined instruction

AppError18:  BRA     AppError18
; An interrupt transfer buffer overrun might take place on the next
; transfer

AppError19:  BRA     AppError19
; The interrupt transfer TX buffer has overflowed

AppError20:  BRA     AppError20
; The interrupt transfer RX buffer has overflowed

AppError21:  BRA     AppError21
; The bulk transfer TX buffer has overflowed

AppError22:  BRA     AppError22
; The bulk transfer RX buffer has overflowed

AppError23:  BRA     AppError23
; Application detected activity at an unused enpoint

AppError24:  BRA     AppError24
; Windows function 10 attempted to reenter the motor loop before the
; previous instance had exited. Condition arises if the motor
; loop hangs for any reason. Fatel exception.

AppError25:  BRA     AppError25
; Windows function 10 attempted to reenter the pressure loop before
; the previous instance had exited. Condition arises if the pressure
; loop hangs for any reason. Fatel exception.

AppError26:  BRA     AppError26
; Windows function 10 attempted to restart the timers. The condition
; is not fatal but is not expected during normal operation.

AppError27:  RCALL     hard_stop ; AppError27
                0: BRA 0b
; Windows function 10 is being restarted. The condition is not fatal
; but is not expected during normal operation.

AppError28:  RCALL     hard_stop ; AppError28
                0: BRA 0b
; WF10 found an unexpected number of bulk transfer TX packets pending.
; Possible pointer corruption. Fatal exception.

AppError29:  RCALL     hard_stop ;AppError29
                0: BRA 0b
; The WF10 motor loop found an unacceptable setpoint buffer gap.
; Modify the 'setpoint data rate control' in the motor loop to
; determine the manner in which new data is received from the host.

AppError30:  RCALL     hard_stop ;AppError30
                0: BRA 0b
; The WF10 motor loop found an unacceptable TX data buffer gap. The
; max size of this buffer is 4 entries. This can be caused by data
; not being sent to the host on account of the pressure loop not
; updating the TX data fast enough.

AppError31:  RCALL     hard_stop ;AppError31 ; Unused
                0: BRA 0b
; The WF10 motor loop found an unacceptable velocity buffer gap
; The gap should be close to 10. WF10 will eventually be able to
; recover from this error in normal operation.

AppError32:  RCALL     hard_stop ;AppError32
                0: BRA 0b
; The WF10 pressure loop found an unacceptable TX data buffer gap. The
; max size of this buffer is 4 entries. This can be caused by data
; not being sent to the host on account of the motor loop not
; updating the TX data fast enough.

AppError33:  RCALL     hard_stop ;AppError33
                0: BRA 0b
; The WF10 motor loop found that there was insufficient data to begin
; the loop. Fatal exception

AppError34:  RCALL     hard_stop ;AppError34
                0: BRA 0b
; WF10 attempted and failed to initialise the bulk endpoint for
; receiving new data.

AppError35:  RCALL     hard_stop ;AppError35
                0: BRA 0b
; WF10 setpoint buffer pointer out of range. Fatal exception.

AppError36:  RCALL     hard_stop ;AppError36
                0: BRA 0b
; WF10 position buffer pointer out of range. Fatal exception.

AppError37:  RCALL     hard_stop ;AppError37
                0: BRA 0b
; WF10 velocity buffer pointer out of range. Fatal exception.

AppError38:  RCALL     hard_stop ;AppError38
                0: BRA 0b
; WF10 pressure buffer pointer out of range. Fatal exception.

AppError39:  RCALL     hard_stop ;AppError39
                0: BRA 0b
; Possible setpoint data corruption. Fatal exception.

AppError40:  RCALL     hard_stop ;AppError40
                0: BRA 0b
; WF10 pressure loop attempted to obtain another sample before the
; previous one had finished. Fatal exception.

AppError41:  RCALL     hard_stop ;AppError41
                0: BRA 0b
; WF10 pressure loop finished the interrupt routine with the
; interrupt flag raised, meaning that the proper interrupt timing
; has been lost. Fatel exception.

AppError42:  RCALL     hard_stop ;AppError42
                0: BRA 0b
; WF10 motor loop finished the interrupt routine with the
; interrupt flag raised, meaning that the proper interrupt timing
; has been lost. Fatel exception.

AppError43:  RCALL     hard_stop ;AppError43
                0: BRA 0b
; The pressure loop interrupt routine was not serviced fast enough.

AppError44:  RCALL     hard_stop ;AppError44
                0: BRA 0b
; The motor loop interrupt routine was not serviced fast enough.


hard_stop:

    ; disable both timers
    BCLR    T6CON, #TON     ; Turn off timer 6
    BCLR    T3CON, #TON     ; Turn off timer 3

    ; Return
    RETURN

0:  BRA     0b





; ========================== TEMPORARY ERRORS ========================

TempError1:     BRA     TempError1
; Only written routines to handle control transfers - other transfer
; type required

TempError2:     BRA     TempError2
; Request error condition. Routine not written yet.



