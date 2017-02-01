/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* File Name: usb-21-windows.s
*
* Type: SOURCE
*
* Title: Windows Callable Functions
*
* Version: 2.1
*
* Purpose: These routines may be called by sending a control
*          windows_command request to the device.
*
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
    
    
; ==================== SUBROUTINE DECLARATIONS =======================
.global USB.SUB.WIN.WF1
    
.text
; ============================== CODE ================================


; --------------------------------------------------------------------
; Windows Function 1
; --------------------------------------------------------------------
USB.SUB.WIN.WF1:
; Function used to test the real time interrupt transfer processing
; for passing data from the device to the computer.
;
    
    
    