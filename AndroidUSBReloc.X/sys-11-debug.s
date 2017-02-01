/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* File Name: sys-11-debug.s
*
* Type: SOURCE
*
* Title: System debugging
*
* Version: 1.1
*
* Purpose: Contains debugging routines for use by the system
*
* Date first created: 11th October 2015
* Date last modified: 26th January 2017
*
* Author: John Scott
*
* Used by: sys-11.s
*
*
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

.include "p33EP512MU810.inc"
    
.text
; --------------------------------------------------------------------
; Application Errors
; --------------------------------------------------------------------

SysAppError1:  BRA     SysAppError1
; This error occurs if the system routine attempts to access an
; unimplemeted entry in the execution jump table
