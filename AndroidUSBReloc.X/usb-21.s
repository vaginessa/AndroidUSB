/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* File Name: usb-21.s
*
* Type: SOURCE
*
* Title: USB Transfer Handling Framework
*
* Version: 2.1
*
* Purpose: Contains a structure of source files which implement the
*          USB 2.0 protocol on a dsPIC33E series device. The framework
*          uses conditional compilation to allow flexibility in the
*          behaviour of the device firmware. Options are chosen
*          by decalaring symbols in the OPTION files. Files containing
*          assembly source code are labelled SOURCE. The meaning of
*          each option is described in the relevant OPTION file.
*
*          To use the USB Transfer Handling Framework in another
*          project, include the file usb-21.inc using the .include
*          directive. This file will include all others as required.
*
* Date first created: 11th October 2015
* Date last modified: 26th January 2017
*
* Author: John Scott
*
* Used by: <main application file>.s
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

.include "p33EP512MU810.inc"
.include "usb-21-const.inc"
    
; ========================= INCLUDE FILES ============================

;.include "usb-21-definitions.inc"
;.include "usb-21-option-config.inc"
;.include "usb-21-option-debug.inc"
;.include "usb-21-option-info.inc"
;.include "usb-21-debug.inc"
;.include "usb-21-interrupt.inc"
;.include "usb-21-reg.inc"
;.include "usb-21-bdt.inc"
;.include "usb-21-transaction.inc"
;.include "usb-21-control-transfer.inc"
;.include "usb-21-interrupt-transfer.inc"
;.include "usb-21-bulk-transfer.inc"
;.include "usb-21-requests.inc"
;.include "usb-21-descriptors.inc"
;.include "usb-21-windows.inc"

; =================== SUBROUTINE DECLARATIONS ==========================

.global USB.SUB.CONFIG
.global USB.SUB.ENABLE
    
.text
; ============================== CODE ================================

; --------------------------------------------------------------------
; USB module configuration routine
; --------------------------------------------------------------------
; This routine must be called by the main application to set up the
; USB Module ready to be enabled by the application

USB.SUB.CONFIG:

    ; Set up USB 48MHz clock source
    MOV     #0x24C1, w0
    MOV     w0, ACLKCON3
    MOV     #0x0007, w0
    MOV     w0, ACLKDIV3
    BSET    ACLKCON3, #ENAPLL   ; Enable the Auxiliary PLL
0:  BTSS    ACLKCON3, #APLLCK   ; Wait of APLL lock
    BRA     0b

    ; Provide power to the USB Module
    BSET    U1PWRC, #USBPWR

    ; Configure USB specific interrupts
    MOV     #0x00BB, w0
    MOV     w0, U1IE
    MOV     #0x00FF, w0
    MOV     w0, 0x04C6; U1EIE

    ; Perform general USB Module
    MOV     #0x0000, w0
    MOV     w0, U1CNFG1     ; Various configuration options
    MOV     w0, U1CNFG2

    MOV     #.startof.(USB.BDT), w0
    AND     #0x01FF, w0
    MOV     #0x0000, w1
    CPSEQ   w0, w1
    BRA     AppError4
    MOV     #.startof.(USB.BDT), w0
    LSR     w0, #8, w0      ; Condition the address for storage
    MOV     w0, U1BDTP1
    MOV     #0x0000, w0
    MOV     w0, U1BDTP2
    MOV     #0x0000, w0
    MOV     w0, U1BDTP3

    MOV     #0x0002, w0
    MOV     w0, U1CON

    MOV     #0x000D, w0
    MOV     w0, U1EP0       ; Enable EP0 for RX/TX control transfers

    ; Setup USB registers
    MOV     #0x0000, w0         ; Bus powered, no remote wakeup
    MOV     w0, USB.REG.STAT.General

    ; USB Module setup complete. Return to main application
    RETURN
                                                      ; End of routine
; --------------------------------------------------------------------


; --------------------------------------------------------------------
; Enable USB Module
; --------------------------------------------------------------------
; This routine must be called by the main application to enable the
; USB Module for communication

USB.SUB.ENABLE:
    ; Set USB interrupt priority level
    MOV     #0x4500, w0
    MOV     w0, IPC21

    ; Turn on USB interrupts
    BSET    IEC5, #USB1IE

    ; Enable the USB Module in Device mode
    BSET    U1CON, #USBEN

    ; USB Module switched on. Return to main application
    RETURN
                                                      ; End of routine
; --------------------------------------------------------------------




