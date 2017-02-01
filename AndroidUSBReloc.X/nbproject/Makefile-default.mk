#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/AndroidUSBReloc.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/AndroidUSBReloc.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=/root/MPLABXProjects/AndroidUSBReloc.X/io-11-definitions.s /root/MPLABXProjects/AndroidUSBReloc.X/io-11.s /root/MPLABXProjects/AndroidUSBReloc.X/main-11.s /root/MPLABXProjects/AndroidUSBReloc.X/sys-11-debug.s /root/MPLABXProjects/AndroidUSBReloc.X/sys-11-definitions.s /root/MPLABXProjects/AndroidUSBReloc.X/sys-11-interrupt.s /root/MPLABXProjects/AndroidUSBReloc.X/sys-11-reg.s /root/MPLABXProjects/AndroidUSBReloc.X/sys-11.s /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-bdt.s /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-bulk-transfer.s /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-control-transfer.s /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-debug.s /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-definitions.s /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-descriptors.s /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-info.s /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-interrupt-transfer.s /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-interrupt.s /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-reg.s /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-requests.s /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-transaction.s /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-windows.s /root/MPLABXProjects/AndroidUSBReloc.X/usb-21.s /root/MPLABXProjects/AndroidUSBReloc.X/io-11-reg.s

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1573387751/io-11-definitions.o ${OBJECTDIR}/_ext/1573387751/io-11.o ${OBJECTDIR}/_ext/1573387751/main-11.o ${OBJECTDIR}/_ext/1573387751/sys-11-debug.o ${OBJECTDIR}/_ext/1573387751/sys-11-definitions.o ${OBJECTDIR}/_ext/1573387751/sys-11-interrupt.o ${OBJECTDIR}/_ext/1573387751/sys-11-reg.o ${OBJECTDIR}/_ext/1573387751/sys-11.o ${OBJECTDIR}/_ext/1573387751/usb-21-bdt.o ${OBJECTDIR}/_ext/1573387751/usb-21-bulk-transfer.o ${OBJECTDIR}/_ext/1573387751/usb-21-control-transfer.o ${OBJECTDIR}/_ext/1573387751/usb-21-debug.o ${OBJECTDIR}/_ext/1573387751/usb-21-definitions.o ${OBJECTDIR}/_ext/1573387751/usb-21-descriptors.o ${OBJECTDIR}/_ext/1573387751/usb-21-info.o ${OBJECTDIR}/_ext/1573387751/usb-21-interrupt-transfer.o ${OBJECTDIR}/_ext/1573387751/usb-21-interrupt.o ${OBJECTDIR}/_ext/1573387751/usb-21-reg.o ${OBJECTDIR}/_ext/1573387751/usb-21-requests.o ${OBJECTDIR}/_ext/1573387751/usb-21-transaction.o ${OBJECTDIR}/_ext/1573387751/usb-21-windows.o ${OBJECTDIR}/_ext/1573387751/usb-21.o ${OBJECTDIR}/_ext/1573387751/io-11-reg.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1573387751/io-11-definitions.o.d ${OBJECTDIR}/_ext/1573387751/io-11.o.d ${OBJECTDIR}/_ext/1573387751/main-11.o.d ${OBJECTDIR}/_ext/1573387751/sys-11-debug.o.d ${OBJECTDIR}/_ext/1573387751/sys-11-definitions.o.d ${OBJECTDIR}/_ext/1573387751/sys-11-interrupt.o.d ${OBJECTDIR}/_ext/1573387751/sys-11-reg.o.d ${OBJECTDIR}/_ext/1573387751/sys-11.o.d ${OBJECTDIR}/_ext/1573387751/usb-21-bdt.o.d ${OBJECTDIR}/_ext/1573387751/usb-21-bulk-transfer.o.d ${OBJECTDIR}/_ext/1573387751/usb-21-control-transfer.o.d ${OBJECTDIR}/_ext/1573387751/usb-21-debug.o.d ${OBJECTDIR}/_ext/1573387751/usb-21-definitions.o.d ${OBJECTDIR}/_ext/1573387751/usb-21-descriptors.o.d ${OBJECTDIR}/_ext/1573387751/usb-21-info.o.d ${OBJECTDIR}/_ext/1573387751/usb-21-interrupt-transfer.o.d ${OBJECTDIR}/_ext/1573387751/usb-21-interrupt.o.d ${OBJECTDIR}/_ext/1573387751/usb-21-reg.o.d ${OBJECTDIR}/_ext/1573387751/usb-21-requests.o.d ${OBJECTDIR}/_ext/1573387751/usb-21-transaction.o.d ${OBJECTDIR}/_ext/1573387751/usb-21-windows.o.d ${OBJECTDIR}/_ext/1573387751/usb-21.o.d ${OBJECTDIR}/_ext/1573387751/io-11-reg.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1573387751/io-11-definitions.o ${OBJECTDIR}/_ext/1573387751/io-11.o ${OBJECTDIR}/_ext/1573387751/main-11.o ${OBJECTDIR}/_ext/1573387751/sys-11-debug.o ${OBJECTDIR}/_ext/1573387751/sys-11-definitions.o ${OBJECTDIR}/_ext/1573387751/sys-11-interrupt.o ${OBJECTDIR}/_ext/1573387751/sys-11-reg.o ${OBJECTDIR}/_ext/1573387751/sys-11.o ${OBJECTDIR}/_ext/1573387751/usb-21-bdt.o ${OBJECTDIR}/_ext/1573387751/usb-21-bulk-transfer.o ${OBJECTDIR}/_ext/1573387751/usb-21-control-transfer.o ${OBJECTDIR}/_ext/1573387751/usb-21-debug.o ${OBJECTDIR}/_ext/1573387751/usb-21-definitions.o ${OBJECTDIR}/_ext/1573387751/usb-21-descriptors.o ${OBJECTDIR}/_ext/1573387751/usb-21-info.o ${OBJECTDIR}/_ext/1573387751/usb-21-interrupt-transfer.o ${OBJECTDIR}/_ext/1573387751/usb-21-interrupt.o ${OBJECTDIR}/_ext/1573387751/usb-21-reg.o ${OBJECTDIR}/_ext/1573387751/usb-21-requests.o ${OBJECTDIR}/_ext/1573387751/usb-21-transaction.o ${OBJECTDIR}/_ext/1573387751/usb-21-windows.o ${OBJECTDIR}/_ext/1573387751/usb-21.o ${OBJECTDIR}/_ext/1573387751/io-11-reg.o

# Source Files
SOURCEFILES=/root/MPLABXProjects/AndroidUSBReloc.X/io-11-definitions.s /root/MPLABXProjects/AndroidUSBReloc.X/io-11.s /root/MPLABXProjects/AndroidUSBReloc.X/main-11.s /root/MPLABXProjects/AndroidUSBReloc.X/sys-11-debug.s /root/MPLABXProjects/AndroidUSBReloc.X/sys-11-definitions.s /root/MPLABXProjects/AndroidUSBReloc.X/sys-11-interrupt.s /root/MPLABXProjects/AndroidUSBReloc.X/sys-11-reg.s /root/MPLABXProjects/AndroidUSBReloc.X/sys-11.s /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-bdt.s /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-bulk-transfer.s /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-control-transfer.s /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-debug.s /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-definitions.s /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-descriptors.s /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-info.s /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-interrupt-transfer.s /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-interrupt.s /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-reg.s /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-requests.s /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-transaction.s /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-windows.s /root/MPLABXProjects/AndroidUSBReloc.X/usb-21.s /root/MPLABXProjects/AndroidUSBReloc.X/io-11-reg.s


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/AndroidUSBReloc.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33EP512MU810
MP_LINKER_FILE_OPTION=,--script=p33EP512MU810.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1573387751/io-11-definitions.o: /root/MPLABXProjects/AndroidUSBReloc.X/io-11-definitions.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/io-11-definitions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/io-11-definitions.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/io-11-definitions.s  -o ${OBJECTDIR}/_ext/1573387751/io-11-definitions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/io-11-definitions.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/io-11-definitions.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/io-11.o: /root/MPLABXProjects/AndroidUSBReloc.X/io-11.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/io-11.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/io-11.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/io-11.s  -o ${OBJECTDIR}/_ext/1573387751/io-11.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/io-11.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/io-11.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/main-11.o: /root/MPLABXProjects/AndroidUSBReloc.X/main-11.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/main-11.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/main-11.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/main-11.s  -o ${OBJECTDIR}/_ext/1573387751/main-11.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/main-11.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/main-11.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/sys-11-debug.o: /root/MPLABXProjects/AndroidUSBReloc.X/sys-11-debug.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/sys-11-debug.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/sys-11-debug.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/sys-11-debug.s  -o ${OBJECTDIR}/_ext/1573387751/sys-11-debug.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/sys-11-debug.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/sys-11-debug.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/sys-11-definitions.o: /root/MPLABXProjects/AndroidUSBReloc.X/sys-11-definitions.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/sys-11-definitions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/sys-11-definitions.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/sys-11-definitions.s  -o ${OBJECTDIR}/_ext/1573387751/sys-11-definitions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/sys-11-definitions.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/sys-11-definitions.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/sys-11-interrupt.o: /root/MPLABXProjects/AndroidUSBReloc.X/sys-11-interrupt.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/sys-11-interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/sys-11-interrupt.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/sys-11-interrupt.s  -o ${OBJECTDIR}/_ext/1573387751/sys-11-interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/sys-11-interrupt.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/sys-11-interrupt.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/sys-11-reg.o: /root/MPLABXProjects/AndroidUSBReloc.X/sys-11-reg.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/sys-11-reg.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/sys-11-reg.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/sys-11-reg.s  -o ${OBJECTDIR}/_ext/1573387751/sys-11-reg.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/sys-11-reg.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/sys-11-reg.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/sys-11.o: /root/MPLABXProjects/AndroidUSBReloc.X/sys-11.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/sys-11.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/sys-11.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/sys-11.s  -o ${OBJECTDIR}/_ext/1573387751/sys-11.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/sys-11.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/sys-11.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/usb-21-bdt.o: /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-bdt.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-bdt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-bdt.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-bdt.s  -o ${OBJECTDIR}/_ext/1573387751/usb-21-bdt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/usb-21-bdt.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/usb-21-bdt.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/usb-21-bulk-transfer.o: /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-bulk-transfer.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-bulk-transfer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-bulk-transfer.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-bulk-transfer.s  -o ${OBJECTDIR}/_ext/1573387751/usb-21-bulk-transfer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/usb-21-bulk-transfer.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/usb-21-bulk-transfer.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/usb-21-control-transfer.o: /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-control-transfer.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-control-transfer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-control-transfer.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-control-transfer.s  -o ${OBJECTDIR}/_ext/1573387751/usb-21-control-transfer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/usb-21-control-transfer.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/usb-21-control-transfer.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/usb-21-debug.o: /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-debug.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-debug.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-debug.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-debug.s  -o ${OBJECTDIR}/_ext/1573387751/usb-21-debug.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/usb-21-debug.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/usb-21-debug.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/usb-21-definitions.o: /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-definitions.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-definitions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-definitions.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-definitions.s  -o ${OBJECTDIR}/_ext/1573387751/usb-21-definitions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/usb-21-definitions.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/usb-21-definitions.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/usb-21-descriptors.o: /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-descriptors.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-descriptors.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-descriptors.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-descriptors.s  -o ${OBJECTDIR}/_ext/1573387751/usb-21-descriptors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/usb-21-descriptors.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/usb-21-descriptors.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/usb-21-info.o: /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-info.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-info.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-info.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-info.s  -o ${OBJECTDIR}/_ext/1573387751/usb-21-info.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/usb-21-info.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/usb-21-info.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/usb-21-interrupt-transfer.o: /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-interrupt-transfer.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-interrupt-transfer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-interrupt-transfer.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-interrupt-transfer.s  -o ${OBJECTDIR}/_ext/1573387751/usb-21-interrupt-transfer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/usb-21-interrupt-transfer.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/usb-21-interrupt-transfer.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/usb-21-interrupt.o: /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-interrupt.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-interrupt.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-interrupt.s  -o ${OBJECTDIR}/_ext/1573387751/usb-21-interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/usb-21-interrupt.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/usb-21-interrupt.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/usb-21-reg.o: /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-reg.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-reg.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-reg.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-reg.s  -o ${OBJECTDIR}/_ext/1573387751/usb-21-reg.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/usb-21-reg.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/usb-21-reg.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/usb-21-requests.o: /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-requests.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-requests.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-requests.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-requests.s  -o ${OBJECTDIR}/_ext/1573387751/usb-21-requests.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/usb-21-requests.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/usb-21-requests.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/usb-21-transaction.o: /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-transaction.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-transaction.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-transaction.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-transaction.s  -o ${OBJECTDIR}/_ext/1573387751/usb-21-transaction.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/usb-21-transaction.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/usb-21-transaction.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/usb-21-windows.o: /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-windows.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-windows.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-windows.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-windows.s  -o ${OBJECTDIR}/_ext/1573387751/usb-21-windows.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/usb-21-windows.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/usb-21-windows.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/usb-21.o: /root/MPLABXProjects/AndroidUSBReloc.X/usb-21.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/usb-21.s  -o ${OBJECTDIR}/_ext/1573387751/usb-21.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/usb-21.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/usb-21.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/io-11-reg.o: /root/MPLABXProjects/AndroidUSBReloc.X/io-11-reg.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/io-11-reg.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/io-11-reg.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/io-11-reg.s  -o ${OBJECTDIR}/_ext/1573387751/io-11-reg.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/io-11-reg.o.d",--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/io-11-reg.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/_ext/1573387751/io-11-definitions.o: /root/MPLABXProjects/AndroidUSBReloc.X/io-11-definitions.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/io-11-definitions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/io-11-definitions.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/io-11-definitions.s  -o ${OBJECTDIR}/_ext/1573387751/io-11-definitions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/io-11-definitions.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/io-11-definitions.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/io-11.o: /root/MPLABXProjects/AndroidUSBReloc.X/io-11.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/io-11.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/io-11.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/io-11.s  -o ${OBJECTDIR}/_ext/1573387751/io-11.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/io-11.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/io-11.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/main-11.o: /root/MPLABXProjects/AndroidUSBReloc.X/main-11.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/main-11.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/main-11.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/main-11.s  -o ${OBJECTDIR}/_ext/1573387751/main-11.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/main-11.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/main-11.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/sys-11-debug.o: /root/MPLABXProjects/AndroidUSBReloc.X/sys-11-debug.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/sys-11-debug.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/sys-11-debug.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/sys-11-debug.s  -o ${OBJECTDIR}/_ext/1573387751/sys-11-debug.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/sys-11-debug.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/sys-11-debug.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/sys-11-definitions.o: /root/MPLABXProjects/AndroidUSBReloc.X/sys-11-definitions.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/sys-11-definitions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/sys-11-definitions.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/sys-11-definitions.s  -o ${OBJECTDIR}/_ext/1573387751/sys-11-definitions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/sys-11-definitions.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/sys-11-definitions.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/sys-11-interrupt.o: /root/MPLABXProjects/AndroidUSBReloc.X/sys-11-interrupt.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/sys-11-interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/sys-11-interrupt.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/sys-11-interrupt.s  -o ${OBJECTDIR}/_ext/1573387751/sys-11-interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/sys-11-interrupt.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/sys-11-interrupt.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/sys-11-reg.o: /root/MPLABXProjects/AndroidUSBReloc.X/sys-11-reg.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/sys-11-reg.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/sys-11-reg.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/sys-11-reg.s  -o ${OBJECTDIR}/_ext/1573387751/sys-11-reg.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/sys-11-reg.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/sys-11-reg.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/sys-11.o: /root/MPLABXProjects/AndroidUSBReloc.X/sys-11.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/sys-11.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/sys-11.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/sys-11.s  -o ${OBJECTDIR}/_ext/1573387751/sys-11.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/sys-11.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/sys-11.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/usb-21-bdt.o: /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-bdt.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-bdt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-bdt.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-bdt.s  -o ${OBJECTDIR}/_ext/1573387751/usb-21-bdt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/usb-21-bdt.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/usb-21-bdt.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/usb-21-bulk-transfer.o: /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-bulk-transfer.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-bulk-transfer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-bulk-transfer.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-bulk-transfer.s  -o ${OBJECTDIR}/_ext/1573387751/usb-21-bulk-transfer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/usb-21-bulk-transfer.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/usb-21-bulk-transfer.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/usb-21-control-transfer.o: /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-control-transfer.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-control-transfer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-control-transfer.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-control-transfer.s  -o ${OBJECTDIR}/_ext/1573387751/usb-21-control-transfer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/usb-21-control-transfer.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/usb-21-control-transfer.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/usb-21-debug.o: /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-debug.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-debug.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-debug.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-debug.s  -o ${OBJECTDIR}/_ext/1573387751/usb-21-debug.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/usb-21-debug.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/usb-21-debug.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/usb-21-definitions.o: /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-definitions.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-definitions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-definitions.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-definitions.s  -o ${OBJECTDIR}/_ext/1573387751/usb-21-definitions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/usb-21-definitions.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/usb-21-definitions.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/usb-21-descriptors.o: /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-descriptors.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-descriptors.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-descriptors.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-descriptors.s  -o ${OBJECTDIR}/_ext/1573387751/usb-21-descriptors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/usb-21-descriptors.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/usb-21-descriptors.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/usb-21-info.o: /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-info.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-info.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-info.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-info.s  -o ${OBJECTDIR}/_ext/1573387751/usb-21-info.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/usb-21-info.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/usb-21-info.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/usb-21-interrupt-transfer.o: /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-interrupt-transfer.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-interrupt-transfer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-interrupt-transfer.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-interrupt-transfer.s  -o ${OBJECTDIR}/_ext/1573387751/usb-21-interrupt-transfer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/usb-21-interrupt-transfer.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/usb-21-interrupt-transfer.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/usb-21-interrupt.o: /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-interrupt.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-interrupt.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-interrupt.s  -o ${OBJECTDIR}/_ext/1573387751/usb-21-interrupt.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/usb-21-interrupt.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/usb-21-interrupt.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/usb-21-reg.o: /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-reg.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-reg.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-reg.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-reg.s  -o ${OBJECTDIR}/_ext/1573387751/usb-21-reg.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/usb-21-reg.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/usb-21-reg.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/usb-21-requests.o: /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-requests.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-requests.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-requests.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-requests.s  -o ${OBJECTDIR}/_ext/1573387751/usb-21-requests.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/usb-21-requests.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/usb-21-requests.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/usb-21-transaction.o: /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-transaction.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-transaction.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-transaction.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-transaction.s  -o ${OBJECTDIR}/_ext/1573387751/usb-21-transaction.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/usb-21-transaction.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/usb-21-transaction.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/usb-21-windows.o: /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-windows.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-windows.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21-windows.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/usb-21-windows.s  -o ${OBJECTDIR}/_ext/1573387751/usb-21-windows.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/usb-21-windows.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/usb-21-windows.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/usb-21.o: /root/MPLABXProjects/AndroidUSBReloc.X/usb-21.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/usb-21.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/usb-21.s  -o ${OBJECTDIR}/_ext/1573387751/usb-21.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/usb-21.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/usb-21.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1573387751/io-11-reg.o: /root/MPLABXProjects/AndroidUSBReloc.X/io-11-reg.s  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1573387751" 
	@${RM} ${OBJECTDIR}/_ext/1573387751/io-11-reg.o.d 
	@${RM} ${OBJECTDIR}/_ext/1573387751/io-11-reg.o 
	${MP_CC} $(MP_EXTRA_AS_PRE)  /root/MPLABXProjects/AndroidUSBReloc.X/io-11-reg.s  -o ${OBJECTDIR}/_ext/1573387751/io-11-reg.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,-MD,"${OBJECTDIR}/_ext/1573387751/io-11-reg.o.d",--defsym=__MPLAB_BUILD=1,-g,--no-relax$(MP_EXTRA_AS_POST)
	@${FIXDEPS} "${OBJECTDIR}/_ext/1573387751/io-11-reg.o.d"  $(SILENT)  -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/AndroidUSBReloc.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/AndroidUSBReloc.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x1000:0x101B -mreserve=data@0x101C:0x101D -mreserve=data@0x101E:0x101F -mreserve=data@0x1020:0x1021 -mreserve=data@0x1022:0x1023 -mreserve=data@0x1024:0x1027 -mreserve=data@0x1028:0x104F   -Wl,--local-stack,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/AndroidUSBReloc.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/AndroidUSBReloc.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--local-stack,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}/xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/AndroidUSBReloc.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
