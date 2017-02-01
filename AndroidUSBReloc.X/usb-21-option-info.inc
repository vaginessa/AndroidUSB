/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* File Name: usb-21-option-info.inc
*
* Type: OPTION
*
* Title: USB Firmware Information
*
* Version: 2.1
*
* Purpose: The USB 2.0 specification requires a large amount of
*          information to be stored on a USB device in the form of
*          descriptors, which are returned to the host computer on
*          request. There is flexibility in some of the information
*          that is returned. For example, the USB device can return
*          strings containing a description of device functionality
*          to make it easier for the end user to recognise the device
*          on the computer system. Additionally, other information is
*          required by Windows (defined by Microsoft and not USB 2.0)
*          that makes it easier for a desktop application to interact
*          with a USB device.
*
*          This file can be used to set all configurable information
*          contained in the device firmware. For explanations of how
*          to set the configurable information, see below.
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
; Set Vendor ID, Hardware ID and Device Release Number
; --------------------------------------------------------------------
; USB devices contain information about themself which is sent to the
; computer during the enumeration sequence. The Vendor ID is assigned
; by the USB Implementors Forum (USB-IF) and can be left as 0x0000.
; The Product ID is arbitarily defined by a device manufacturer. The
; Device Release Number is similarly arbitrary. The only function of
; the three codes is to allow the computer to recognise hardware that
; has previously been connected to the computer. Changing the numbers
; will force the computer to behave as if it is seeing the device for
; the first time. On Windows, the computer writes the codes into a
; registry entry. An alternative way to make the device appear
; unknown to the computer is to delete the registry entry. All three
; codes are at most one word long.
; --------------------------- STATEMENT ------------------------------
.equiv VendorID,  /* Put Vendor ID here -----> */ 0x0000 /* <------ */
.equiv ProductID, /* Put Product ID here ----> */ 0x0001 /* <------ */
.equiv ReleaseNo, /* Put Release No. here ---> */ 0x0001 /* <------ */
; --------------------------------------------------------------------

; --------------------------------------------------------------------
; Set Manufacturer, Product and Serial Number Strings
; --------------------------------------------------------------------
; The USB device can contain information about itself that is
; displayed to the user of the device on the computer after
; enumeration has successfully finished. These are defined here
; CURENTLY UNCOMPLETED.
; --------------------------- STATEMENT ------------------------------
.equiv USB.OPTION.INFO.ManufacturerName, 0
.equiv USB.OPTION.INFO.ProductName, 0
.equiv USB.OPTION.INFO.SerialNum, 0
; --------------------------------------------------------------------



