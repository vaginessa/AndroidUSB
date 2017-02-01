/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* File Name: usb-21-extern.inc
*
* Type: External Declartion
*
* Title: Subroutine and register declarations 
*
* Version: 2.1
*
* Purpose: To be included with all USB source files
*
* Date first created: 26th January 2017
* Date last modified: 26th January 2017
*
* Author: John Scott
*
* Used by: usb-21.s
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    
; =================== SUBROUTINE DECLARATIONS ==========================

; Transaction
.extern USB.SUB.TRN
    
; Control transfer
.extern USB.SUB.CT

.extern USB.SUB.CT.control_read.setup
.extern USB.SUB.CT.control_read.data
.extern USB.SUB.CT.control_read.status
    
.extern USB.SUB.CT.control_write.setup
.extern USB.SUB.CT.control_write.data
.extern USB.SUB.CT.control_write.status
    
; Interrupt transfer
.extern USB.SUB.IT
    
; Bulk transfer
.extern USB.SUB.BT
    
; Requests    
.extern USB.SUB.REQ.GET_STATUS.setup
.extern USB.SUB.REQ.GET_STATUS.data
.extern USB.SUB.REQ.GET_STATUS.status

.extern USB.SUB.REQ.CLEAR_FEATURE.setup
.extern USB.SUB.REQ.CLEAR_FEATURE.data
.extern USB.SUB.REQ.CLEAR_FEATURE.status

.extern USB.SUB.REQ.SET_FEATURE.setup
.extern USB.SUB.REQ.SET_FEATURE.data
.extern USB.SUB.REQ.SET_FEATURE.status

.extern USB.SUB.REQ.SET_ADDRESS.setup
.extern USB.SUB.REQ.SET_ADDRESS.status

.extern USB.SUB.REQ.GET_DESCRIPTOR.setup
.extern USB.SUB.REQ.GET_DESCRIPTOR.data
.extern USB.SUB.REQ.GET_DESCRIPTOR.status

.extern USB.SUB.REQ.SET_DESCRIPTOR.setup
.extern USB.SUB.REQ.SET_DESCRIPTOR.data
.extern USB.SUB.REQ.SET_DESCRIPTOR.status

.extern USB.SUB.REQ.GET_CONFIGURATION.setup
.extern USB.SUB.REQ.GET_CONFIGURATION.data
.extern USB.SUB.REQ.GET_CONFIGURATION.status

.extern USB.SUB.REQ.SET_CONFIGURATION.setup
.extern USB.SUB.REQ.SET_CONFIGURATION.status

.extern USB.SUB.REQ.GET_INTERFACE.setup
.extern USB.SUB.REQ.GET_INTERFACE.data
.extern USB.SUB.REQ.GET_INTERFACE.status

.extern USB.SUB.REQ.SET_INTERFACE.setup
.extern USB.SUB.REQ.SET_INTERFACE.data
.extern USB.SUB.REQ.SET_INTERFACE.status

.extern USB.SUB.REQ.SYNCH_FRAME.setup
.extern USB.SUB.REQ.SYNCH_FRAME.data
.extern USB.SUB.REQ.SYNCH_FRAME.status

.extern USB.SUB.REQ.GET_MS_DESCRIPTOR.setup
.extern USB.SUB.REQ.GET_MS_DESCRIPTOR.data
.extern USB.SUB.REQ.GET_MS_DESCRIPTOR.status

.extern USB.SUB.REQ.GET_MS_20_DESCRIPTOR.setup
.extern USB.SUB.REQ.GET_MS_20_DESCRIPTOR.data
.extern USB.SUB.REQ.GET_MS_20_DESCRIPTOR.status

.extern USB.SUB.REQ.TOGGLE_LED.setup
.extern USB.SUB.REQ.TOGGLE_LED.status
    
.extern USB.SUB.REQ.READ_BUTTONS.setup
.extern USB.SUB.REQ.READ_BUTTONS.data
.extern USB.SUB.REQ.READ_BUTTONS.status

.extern USB.SUB.REQ.WINDOWS_COMMAND.setup
.extern USB.SUB.REQ.WINDOWS_COMMAND.status

.extern USB.SUB.DEBUG.LogEvent
    
.extern AppError1
.extern AppError2
.extern AppError3
.extern AppError4
.extern AppError5
.extern AppError6
.extern AppError7
.extern AppError8
.extern AppError9
.extern AppError10
.extern AppError11
.extern AppError12
.extern AppError13
.extern AppError14
.extern AppError15
.extern AppError16
.extern AppError17
.extern AppError18
.extern AppError19
.extern AppError20
.extern AppError21
.extern AppError22
.extern AppError23
.extern AppError24
.extern AppError25
.extern AppError26
.extern AppError27
.extern AppError28
.extern AppError29
.extern AppError30
.extern AppError31
.extern AppError32
.extern AppError33
.extern AppError34
.extern AppError35
.extern AppError36
.extern AppError37
.extern AppError38
.extern AppError39
.extern AppError40
.extern AppError41
.extern AppError42
.extern AppError43
.extern AppError44
    
    
; ===================== REGISTER DECLARATIONS ========================

.extern USB.SUB.CONFIG
.extern USB.SUB.ENABLE
    
.extern USB.REG.TRN  
    
.extern USB.REG.CurrentBD
    
.extern USB.REG.CT.CurrentRegBlockAddress
.extern USB.REG.CT.PendingAddress
.extern USB.REG.CT.NextBufferAddress
.extern USB.REG.CT.NextTransferLength
    
.extern USB.REG.DEBUG.NextEventAddress
    
.extern USB.REG.STAT.General
    
.extern USB.w0
.extern USB.w1
.extern USB.w2
.extern USB.w3
.extern USB.w4
.extern USB.w5
.extern USB.w6
.extern USB.w7
.extern USB.w8
.extern USB.w9
.extern USB.w10
.extern USB.w11
.extern USB.w12
.extern USB.w13
.extern USB.w14
.extern USB.w15
    
.extern USB.REG.IT.DATA
.extern USB.REG.IT.CurrentRegBlockAddress
.extern USB.REG.IT.TX.status
.extern USB.REG.IT.TX.BUFFER.pointer_gap
.extern USB.REG.IT.TX.BUFFER.pointer.send
.extern USB.REG.IT.TX.BUFFER.pointer.fill
.extern USB.REG.IT.RX.status
.extern USB.REG.IT.RX.BUFFER.pointer_gap
.extern USB.REG.IT.RX.BUFFER.pointer.receive
.extern USB.REG.IT.RX.BUFFER.pointer.read
    
.extern USB.REG.BT.DATA
.extern USB.REG.BT.CurrentRegBlockAddress
.extern USB.REG.BT.TX.status
.extern USB.REG.BT.TX.BUFFER.pointer_gap
.extern USB.REG.BT.TX.BUFFER.pointer.send
.extern USB.REG.BT.TX.BUFFER.pointer.fill
.extern USB.REG.BT.RX.status
.extern USB.REG.BT.RX.BUFFER.pointer_gap
.extern USB.REG.BT.RX.BUFFER.pointer.receive
.extern USB.REG.BT.RX.BUFFER.pointer.read
    
; Buffer Descriptor Table
.extern USB.BDT.EP1
.extern USB.BDT.EP2
.extern EP2.WORD0
    
; Debug records 
.extern USB.DEBUG.ResetEvent
.extern USB.DEBUG.IdleEvent
.extern USB.DEBUG.GetDescriptorSetup
.extern USB.DEBUG.SetAddressSetup
.extern USB.DEBUG.RequestError
.extern USB.DEBUG.StallEvent
.extern USB.DEBUG.GetMSDescriptorSetup
.extern USB.DEBUG.GetStatusSetup
.extern USB.DEBUG.SetConfigurationSetup
.extern USB.DEBUG.ToggleLEDSetup
.extern USB.DEBUG.ReadButtonsSetup
.extern USB.DEBUG.WindowsCommandSetup
.extern USB.DEBUG.TXInterrupt
.extern USB.DEBUG.RXInterrupt
.extern USB.DEBUG.TXBulk
.extern USB.DEBUG.RXBulk
    
; Windows functions    
.extern USB.SUB.WIN.WF1
    
    