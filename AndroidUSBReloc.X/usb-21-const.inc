/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* File Name: usb-21-const.inc
*
* Type: Definition
*
* Title: Constant symbol definitions
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

; Include configuration files
.include "usb-21-option-info.inc"
.include "usb-21-option-config.inc"
.include "usb-21-option-debug.inc"
		  
; Include this to reference the system control bits
.include "sys-11-const.inc"
		  
; --------------------------------------------------------------------
; Endpoint Transaction Processing
; --------------------------------------------------------------------
; Each USB endpoint has a 16 byte block of memory associated with it
; (USB.REG.EP) which is laid out as follows

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
		  
; ========================= DEFINITIONS ==============================

; Descriptor types as defined in Chapter 9 USB 2.0 Specification
.equiv DEVICE,                      1
.equiv CONFIGURATION,               2
.equiv STRING,                      3
.equiv INTERFACE,                   4
.equiv ENDPOINT,                    5
.equiv DEVICE_QUALIFIER,            6
.equiv OTHER_SPEED_CONFIGURATION,   7
.equiv INTERFACE_POWER,             8

; Extension descriptor types are defined in Chapter 7 Wireless USB 1.1
.equiv SECURITY,                    12
.equiv KEY,                         13
.equiv ENCRYPTION_TYPE,             14
.equiv BOS,                         15
.equiv DEVICE_CAPABILITY,           16
.equiv WIRELESS_ENDPOINT_COMPANION, 17

; Microsoft specific descriptor types
.equiv GENRE,               1
.equiv EXTENDED_COMPAT_ID,  4
.equiv EXTENDED_PROPERTIES, 5

; Device capability types (Windows 8)
.equiv PLATFORM,    5

; Request types as defined in Chapter 9 USB 2.0 Specification
.equiv GET_STATUS,              0
.equiv CLEAR_FEATURE,           1
.equiv SET_FEATURE,             3
.equiv SET_ADDRESS,             5
.equiv GET_DESCRIPTOR,          6
.equiv SET_DESCRIPTOR,          7
.equiv GET_CONFIGURATION,       8
.equiv SET_CONFIGURATION,       9
.equiv GET_INTERFACE,           10
.equiv SET_INTERFACE,           11
.equiv SYNCH_FRAME,             12

; Microsoft specific request codes
.equiv GET_MS_DESCRIPTOR,       13 ; OSString/bMS_VendorCode
.equiv GET_MS_20_DESCRIPTOR,    14 ; Cap Desc./bMS_VendorCode

; Custom requests
.equiv TOGGLE_LED,              15
.equiv WINDOWS_COMMAND,         16

; Packet identifier (PID) codes for token packets
.equiv OUT,     1
.equiv IN,      9
.equiv SETUP,   13

; BD offsets
.equiv RX.EVEN.WORD0,       0
.equiv RX.EVEN.BYTECOUNT,   2
.equiv RX.EVEN.ADDRESS,     4
.equiv RX.ODD.WORD0,        8
.equiv RX.ODD.BYTECOUNT,    10
.equiv RX.ODD.ADDRESS,      12
.equiv TX.EVEN.WORD0,       16
.equiv TX.EVEN.BYTECOUNT,   18
.equiv TX.EVEN.ADDRESS,     20
.equiv TX.ODD.WORD0,        24
.equiv TX.ODD.BYTECOUNT,    26
.equiv TX.ODD.ADDRESS,      28

; WORD0 bits
.equiv BSTALL,  2
.equiv DTSEN,   3
.equiv NINC,    4
.equiv KEEP,    5
.equiv DATA01,  6
.equiv UOWN,    7

; CT Setup data ffsets
.equiv CT.SETUP.bmRequestType,  0
.equiv CT.SETUP.bRequest,       1
.equiv CT.SETUP.wValue,         2
.equiv CT.SETUP.wIndex,         4
.equiv CT.SETUP.wLength,        6

; String descriptor indices
.equiv MANUFACTURER,   2
.equiv PRODUCT,        4
.equiv SERIAL,         6
.equiv LANGID,         0
.equiv OSSTRING,       0xEE

; ======================== LED TOGGLE COMMANDS =======================
; The following are LED toggle commands. The code is written into 
; the wValue of a control transfer request.
.equiv red_on,      1
.equiv amber_on,    2
.equiv green_on,    3
.equiv red_off,     4
.equiv amber_off,   5
.equiv green_off,   6
	

; ======================== FOR DEBUG LOGS =======================
		  
.equiv USB.DEBUG.GetDescriptorData,         5
.equiv USB.DEBUG.GetDescriptorStatus,       6
.equiv USB.DEBUG.SetAddressStatus,          8
.equiv USB.DEBUG.CTCall,                    11
.equiv USB.DEBUG.GetMSDescriptorData,       13
.equiv USB.DEBUG.GetMSDescriptorStatus,     14
.equiv USB.DEBUG.GetStatusData,             16
.equiv USB.DEBUG.GetStatusStatus,           17
.equiv USB.DEBUG.SetConfigurationStatus,    19
.equiv USB.DEBUG.ToggleLEDStatus,           21
.equiv USB.DEBUG.ReadButtonsData,           23
.equiv USB.DEBUG.ReadButtonsStatus,         24
.equiv USB.DEBUG.WindowsCommandStatus,      26
		  