/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* File Name: usb-21-descriptors.inc
*
* Type: DATA
*
* Title: USB Descriptor Initialisation
*
* Version: 2.1
*
* Purpose: A large amount of information must be stored by a USB
*          device in order for it to successfully enumerate on a
*          computer. Some of this information is defined by the
*          USB 2.0 specification and the rest is defined by
*          Microsoft and is specific to Windows operating systems.
*          This information is stored on a USB device in a data
*          structure called a USB descriptor (which is distinct from
*          the buffer descriptor used by the USB Module). The
*          descriptors are initialised in this file.
*
* Date first created: 11th October 2015
* Date last modified: 11th October 2015
*
* Author: John Scott
*
* Used by: usb-21.inc
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */



; ============================= DATA =================================

; DEVICE DESCRIPTOR --------------------------------------------------

.section USB.DESC.ST.DEVICE, data
/* LENGTH_FIELD       */ .byte 18
/* bLength            */ .byte 18
/* bDescriptorType    */ .byte DEVICE
/* bcdUSB             */ .word 0x0200  ; Specification type
/* bDeviceClass       */ .byte 0x00    ; Has no defined class
/* bDeviceSubClass    */ .byte 0x00    ; Has no defined subclass
/* bDeviceProtocol    */ .byte 0x00    ; No class protocol
/* bMaxPacketSize     */ .byte USB.OPTION.CONFIG.EPBufferSize
/* idVendor           */ .word VendorID
/* idProduct          */ .word ProductID
/* bcdDevice          */ .word ReleaseNo
.ifdef  USB.OPTION.INFO.ManufacturerName
/* iManufacturer      */ .byte MANUFACTURER
.else
/* iManufacturer      */ .byte 0x00
.endif
.ifdef  USB.OPTION.INFO.ProductName
/* iProduct           */ .byte PRODUCT
.else
/* iProduct           */ .byte 0x00    ; String descriptor index
.endif
.ifdef  USB.OPTION.INFO.SerialNum
/* iSerialNumber      */ .byte SERIAL
.else
/* iSerialNumber      */ .byte 0x00
.endif
/* bNumConfigurations */ .byte 0x01    ; Possible configurations

; CONFIGURATION DESCRIPTOR 1 -----------------------------------------

.section USB.DESC.ST.CONFIG.1, data
/* LENGTH_FIELD        */ .byte 9+9+28
/* bLength             */ .byte 9
/* bDescriptorType     */ .byte CONFIGURATION
/* wTotalLength        */ .word 9+9+28  ; Length of returned data
/* bNumInterface       */ .byte 0x01    ; Supports 1 interface
/* bConfigurationValue */ .byte 0x01    ; Config descriptor index
/* iConfiguration      */ .byte 0x00    ; String descriptor index
/* bmAttributes        */ .byte 0x80    ; Bus-power; No remote wake-up
/* bMaxPower           */ .byte 0xFA    ; Device may draw 500mA

 /*** INTERFACE DESCRIPTOR 0 ***/

/* bLength            */  .byte 9
/* bDescriptorType    */  .byte INTERFACE
/* bInterfaceNumber   */  .byte 0x00
/* bAlternateSettings */  .byte 0x00   ; No alternate settings
/* bNumEndpoints      */  .byte 0x04   ; Count IN and OUT seperately!
/* bInterfaceClass    */  .byte 0xFF   ; Class is vendor specific
/* bInterfaceSubClass */  .byte 0x00   ; No sub class implemented
/* bInterfaceProtocol */  .byte 0x00   ; No class protocol
/* iInterface         */  .byte 0x00   ; String descriptor index

/*** ENDPOINT DESCRIPTOR 1, IN ***/

/* bLength          */ .byte 7
/* bDescriptorType  */ .byte ENDPOINT
/* bEndpointAddress */ .byte 0x81    ; EP1; IN
/* bmAttributes     */ .byte 0x03    ; Interrupt 
/* wMaxPacketSize   */ .word 0x0040  ; 64 bytes
/* bInterval        */ .byte 0x05    ; Poll: Every 5 frames

/*** ENDPOINT DESCRIPTOR 1, OUT ***/

/* bLength          */ .byte 7
/* bDescriptorType  */ .byte ENDPOINT
/* bEndpointAddress */ .byte 0x01    ; EP1; OUT
/* bmAttributes     */ .byte 0x03    ; Interrupt 
/* wMaxPacketSize   */ .word 0x0040  ; 64 bytes
/* bInterval        */ .byte 0x05    ; Poll: Every 5 frames

/*** ENDPOINT DESCRIPTOR 2, IN ***/

/* bLength          */ .byte 7
/* bDescriptorType  */ .byte ENDPOINT
/* bEndpointAddress */ .byte 0x82    ; EP2; IN
/* bmAttributes     */ .byte 0x02    ; Bulk
/* wMaxPacketSize   */ .word 0x0040  ; 64 bytes
/* bInterval        */ .byte 0x00    ; Unused field

/*** ENDPOINT DESCRIPTOR 2, OUT ***/

/* bLength          */ .byte 7
/* bDescriptorType  */ .byte ENDPOINT
/* bEndpointAddress */ .byte 0x02    ; EP2; OUT
/* bmAttributes     */ .byte 0x02    ; Bulk
/* wMaxPacketSize   */ .word 0x0040  ; 64 bytes
/* bInterval        */ .byte 0x00    ; Unused field

; STRING DESCRIPTORS -------------------------------------------------
; NOTE: It is important that all string descriptor indices are EVEN
;       numbers. This is not a USB requirement but is necessary
;       in order that the indices can be used directly as offsets to
;       string descriptor addresses (which occupy word aligned
;       locations in device memory).

/*** LANGUAGE ID STRING DESCRIPTOR ***/

.section USB.DESC.ST.STRING.LANGID, data
/* LENGTH_FIELD     */ .byte 4
/* bLength          */ .byte 4
/* bDescriptorType  */ .byte STRING
/* LANGID0          */ .word 0x0809   ; 'English (United Kingdom)'

; *** MANUFACTURER STRING DESCRIPTOR ***

.section USB.DESC.ST.STRING.MANUFACTURER, data
/* LENGTH_FIELD     */ .byte 22
/* bLength          */ .byte 22
/* bDescriptorType  */ .byte STRING
/* bString          */ .ascii "J\0o\0h\0n\0 \0S\0c\0o\0t\0t\0"

; *** PRODUCT STRING DESCRIPTOR ***

.section USB.DESC.ST.STRING.PRODUCT, data
/* LENGTH_FIELD     */ .byte 54
/* bLength          */ .byte 54
/* bDescriptorType  */ .byte STRING
/* bString          */ .ascii "R\0e\0s\0p\0i\0r\0a\0t\0o\0r\0y\0 \0D\0a\0t\0a\0 \0C\0o\0l\0l\0e\0c\0t\0o\0r\0"

; *** SERIAL NUMBER STRING DESCRIPTOR ***

.section USB.DESC.ST.STRING.SERIAL, data
/* LENGTH_FIELD     */ .byte 10
/* bLength          */ .byte 10
/* bDescriptorType  */ .byte STRING
/* bString          */ .ascii "R\0E\0S\0P\0"


/*** BINARY DEVICE OBJECT STORE DESCRIPTOR ***/

.section USB.DESC.MS.BOS, data
/* LENGTH_FIELD            */ .byte 5+28
/* bLength                 */ .byte 5
/* bDescriptorType         */ .byte BOS
/* wTotalLength            */ .word 5+28 ; Length of returned data
/* bNumDeviceCaps          */ .byte 0x01

/*** CAPABILITY DESCRIPTOR 1 ***/

/* bLength                 */ .byte 28
/* bDescriptorType         */ .byte DEVICE_CAPABILITY
/* bDevCapabilityType      */ .byte PLATFORM
/* breserved1              */ .byte 0x00
/* PlatformCapabilityUUID  */ .long 0x9E648A9F
                              .long 0x9CD2659D
                              .long 0x45894CC7
                              .long 0xD8DD60DF
/* dwWindowsVersion        */ .long 0x06030000 ; Windows 8.1 UUID
/* wMSOSDescriptorLength   */ .word 0x0000 ; Length of 2.0 descriptor
/* bMS_VendorCode          */ .byte 14
/* bAltEnumCode            */ .byte 0x00 ; No alternative enumeration

/*** MS OS 2.0 DESCRIPTOR ***/
; Not currently implemented


/*** MS OS STRING DESCRIPTOR ***/

.section USB.DESC.MS.OSSTRING, data
/* LENGTH_FIELD    */ .byte 18
/* bLength         */ .byte 18 ; 18 bytes long
/* bDescriptorType */ .byte STRING
/* qwSignature     */ .word 0x4D  ; 'M' (UNICODE)
                      .word 0x53  ; 'S'
                      .word 0x46  ; 'F'
                      .word 0x54  ; 'T'
                      .word 0x31  ; '1'
                      .word 0x30  ; '0'
                      .word 0x30  ; '0'
/* bMS_VendorCode  */ .byte 13    ; bRequest for GET_MS_DESCRIPTOR
/* bPad            */ .byte 0x00  ; 0 padding

/*** MS OS EXTENDED COMPAT ID DESCRIPTOR ***/

.section USB.DESC.MS.ECID, data

/* LENGTH_FIELD    */ .byte 16+24

    /*** HEADER SECTION***/

/* dwLength        */ .long 16+24     ; Length of returned data
/* bcdVersion      */ .word 0x0100    ; Version 1.00
/* wIndex          */ .word EXTENDED_COMPAT_ID
/* bCount          */ .byte 0x01      ; There is one function section
/* reserved        */ .space 7, 0     ; 7 bytes of 0x0000

    /*** FUNCTION SECTION 1 ***/

/* bFirstInterfaceNumber  */ .byte  0x00
/* reserved               */ .byte  0x01
/* compatibleID:          */ .ascii "WINUSB\0\0"
/* subCompatibleID:       */ .space 8, 0
/* reserved               */ .space 6, 0  ; 6 bytes of 0x0000

/*** MS OS EXTENDED PROPERTIES DESCRIPTOR ***/

.section USB.DESC.MS.EP, data

/* LENGTH_FIELD           */ .byte 132+10

    /*** HEADER SECTION***/

/* dwLength               */ .long 132+10  ; Length of returned data
/* bcdVersion             */ .word 0x0100    ; Version 1.00
/* wIndex                 */ .word EXTENDED_PROPERTIES
/* wCount                 */ .word 0x0001

    /*** FUNCTION SECTION 1 ***/

/* dwSize                 */ .long 132  ; Length of returned data
/* dwPropertyDataType     */ .long 0x00000001   ; Unicode string
/* wPropertyNameLength    */ .word 40
/* wPropertyName          */ .ascii "D\0e\0v\0i\0c\0e\0I\0n\0t\0e\0r\0f\0a\0c\0e\0G\0U\0I\0D\0\0\0"
/* dwPropertyDataLength   */ .long 78
/* wPropertyData          */ .ascii "{\0A\0B\0C\0D\0E\0F\0E\0D\0-\0A\0B\0C\0D\0-\0D\0C\0B\0A\0-\0D\0C\0B\0A\0-\0A\0B\0C\0D\0E\0F\0E\0D\0C\0B\0A\0B\0}\0\0\0"


