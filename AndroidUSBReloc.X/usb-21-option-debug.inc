/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* File Name: usb-21-option-debug.inc
*
* Type: OPTION
*
* Title: USB Firmware Debug Options
*
* Version: 2.1
*
* Purpose: Allows the user to switch on various debugging features
*          written into the firmware of the device. Debugging options
*          are set by declaring symbols in this file. These symbols
*          then control conditional compilation of some blocks of
*          assembly code in other source files. Further details on
*          each option are described below.
*
* Date first created: 11th October 2015
* Date last modified: 26th January 2017
*
* Author: John Scott
*
* Used by: usb-21.s
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    
; --------------------------------------------------------------------
; Event Log
; --------------------------------------------------------------------
; The code has a built in system to log USB events. This can be
; switched on by uncommenting the first statement below. The program
; can be forced to break after a certain number of events have
; occured. The number of events is defined in the second statement.
; --------------------------- STATEMENT ------------------------------
.global USB.OPTION.DEBUG.SwitchOnEventLog
.equiv  USB.OPTION.DEBUG.EventCounterLimit, 2000
; --------------------------------------------------------------------
; Choose the level of event logging detail below. Choosing a greater 
; level of detail logs more events but uses more memory.
; --------------------------- STATEMENT ------------------------------
.global USB.OPTION.DEBUG.EventLog.DetailLevel1
;.global USB.OPTION.DEBUG.EventLog.DetailLevel2
;.global USB.OPTION.DEBUG.EventLog.DetailLevel3
; --------------------------------------------------------------------










