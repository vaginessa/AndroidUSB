/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* File Name: usb-21-definitions.inc
*
* Type: DEFINITIONS
*
* Title: USB Related Constant Definitions
*
* Version: 2.1
*
* Purpose: The USB 2.0 and related specifications contains a large
*          number of (usually) byte-long or work-long codes that have
*          different meanings. Instead of copying these numerical c
*          codes into the assembly code as they are required,
*          readability and code reliability are both improved by
*          defining symbols with recognisable names to have the
*          required values. There is the additional advantage that
*          if a mistake is discovered the value of the symbol can be
*          altered instead of changing every instance of the symbol
*          throughout the source file structure.
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

.section USB.DEBUG.definitions, data
; ============================== DEBUG ===============================

USB.DEBUG.ResetEvent:               .ascii "RS"
USB.DEBUG.IdleEvent:                .ascii "ID"
USB.DEBUG.GetDescriptorSetup:       .ascii "D."
.equiv USB.DEBUG.GetDescriptorData,         5
.equiv USB.DEBUG.GetDescriptorStatus,       6
USB.DEBUG.SetAddressSetup:          .ascii "SA"
.equiv USB.DEBUG.SetAddressStatus,          8
USB.DEBUG.RequestError:             .ascii "RE"
USB.DEBUG.StallEvent:               .ascii "ST"
.equiv USB.DEBUG.CTCall,                    11
USB.DEBUG.GetMSDescriptorSetup:     .ascii "M."
.equiv USB.DEBUG.GetMSDescriptorData,       13
.equiv USB.DEBUG.GetMSDescriptorStatus,     14
USB.DEBUG.GetStatusSetup:           .ascii "GS"
.equiv USB.DEBUG.GetStatusData,             16
.equiv USB.DEBUG.GetStatusStatus,           17
USB.DEBUG.SetConfigurationSetup:    .ascii "SC"
.equiv USB.DEBUG.SetConfigurationStatus,    19
USB.DEBUG.ToggleLEDSetup:           .ascii "TL"
.equiv USB.DEBUG.ToggleLEDStatus,           21
USB.DEBUG.WindowsCommandSetup:      .ascii "WC"
.equiv USB.DEBUG.WindowsCommandStatus,      24
USB.DEBUG.TXInterrupt:              .ascii "TI"
USB.DEBUG.RXInterrupt:              .ascii "RI"
USB.DEBUG.TXBulk:                   .ascii "TB"
USB.DEBUG.RXBulk:                   .ascii "RB"



; ========================= WINDOWS COMMANDS =========================
; These are commands sent by a Windows application to the default
; control pipe which allow the application to control the
; device. The command is contained in the wValue field. These should
; be used in a windows application for calling the required
; function. The wValue is used as a program memory offset so it must
; be an even number.

.equiv USB.WINDOWS_COMMAND.wValue.PF1,   0
.equiv USB.WINDOWS_COMMAND.wValue.WF1,   2



; ======================== LED TOGGLE COMMANDS =======================
; The following are LED toggle commands. The code is written into 
; the wValue of a control transfer request.
.equiv red_on,      1
.equiv amber_on,    2
.equiv green_on,    3
.equiv red_off,     4
.equiv amber_off,   5
.equiv green_off,   6







