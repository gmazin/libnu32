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
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/libnu32.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/libnu32.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=NU32.c ../../Downloads/Ultrasonic.c Workshop1_main.c Servo.c PWM.c Workshop2_main.c Workshop3_main.c Workshop4_main.c Workshop5_main.c Workshop6_main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/NU32.o ${OBJECTDIR}/_ext/1199933227/Ultrasonic.o ${OBJECTDIR}/Workshop1_main.o ${OBJECTDIR}/Servo.o ${OBJECTDIR}/PWM.o ${OBJECTDIR}/Workshop2_main.o ${OBJECTDIR}/Workshop3_main.o ${OBJECTDIR}/Workshop4_main.o ${OBJECTDIR}/Workshop5_main.o ${OBJECTDIR}/Workshop6_main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/NU32.o.d ${OBJECTDIR}/_ext/1199933227/Ultrasonic.o.d ${OBJECTDIR}/Workshop1_main.o.d ${OBJECTDIR}/Servo.o.d ${OBJECTDIR}/PWM.o.d ${OBJECTDIR}/Workshop2_main.o.d ${OBJECTDIR}/Workshop3_main.o.d ${OBJECTDIR}/Workshop4_main.o.d ${OBJECTDIR}/Workshop5_main.o.d ${OBJECTDIR}/Workshop6_main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/NU32.o ${OBJECTDIR}/_ext/1199933227/Ultrasonic.o ${OBJECTDIR}/Workshop1_main.o ${OBJECTDIR}/Servo.o ${OBJECTDIR}/PWM.o ${OBJECTDIR}/Workshop2_main.o ${OBJECTDIR}/Workshop3_main.o ${OBJECTDIR}/Workshop4_main.o ${OBJECTDIR}/Workshop5_main.o ${OBJECTDIR}/Workshop6_main.o

# Source Files
SOURCEFILES=NU32.c ../../Downloads/Ultrasonic.c Workshop1_main.c Servo.c PWM.c Workshop2_main.c Workshop3_main.c Workshop4_main.c Workshop5_main.c Workshop6_main.c


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
	${MAKE} ${MAKE_OPTIONS} -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/libnu32.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX795F512L
MP_LINKER_FILE_OPTION=,--script="NU32bootloaded.ld"
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/NU32.o: NU32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/NU32.o.d 
	@${FIXDEPS} "${OBJECTDIR}/NU32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/NU32.o.d" -o ${OBJECTDIR}/NU32.o NU32.c   
	
${OBJECTDIR}/_ext/1199933227/Ultrasonic.o: ../../Downloads/Ultrasonic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1199933227 
	@${RM} ${OBJECTDIR}/_ext/1199933227/Ultrasonic.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1199933227/Ultrasonic.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1199933227/Ultrasonic.o.d" -o ${OBJECTDIR}/_ext/1199933227/Ultrasonic.o ../../Downloads/Ultrasonic.c   
	
${OBJECTDIR}/Workshop1_main.o: Workshop1_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Workshop1_main.o.d 
	@${FIXDEPS} "${OBJECTDIR}/Workshop1_main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Workshop1_main.o.d" -o ${OBJECTDIR}/Workshop1_main.o Workshop1_main.c   
	
${OBJECTDIR}/Servo.o: Servo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Servo.o.d 
	@${FIXDEPS} "${OBJECTDIR}/Servo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Servo.o.d" -o ${OBJECTDIR}/Servo.o Servo.c   
	
${OBJECTDIR}/PWM.o: PWM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/PWM.o.d 
	@${FIXDEPS} "${OBJECTDIR}/PWM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/PWM.o.d" -o ${OBJECTDIR}/PWM.o PWM.c   
	
${OBJECTDIR}/Workshop2_main.o: Workshop2_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Workshop2_main.o.d 
	@${FIXDEPS} "${OBJECTDIR}/Workshop2_main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Workshop2_main.o.d" -o ${OBJECTDIR}/Workshop2_main.o Workshop2_main.c   
	
${OBJECTDIR}/Workshop3_main.o: Workshop3_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Workshop3_main.o.d 
	@${FIXDEPS} "${OBJECTDIR}/Workshop3_main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Workshop3_main.o.d" -o ${OBJECTDIR}/Workshop3_main.o Workshop3_main.c   
	
${OBJECTDIR}/Workshop4_main.o: Workshop4_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Workshop4_main.o.d 
	@${FIXDEPS} "${OBJECTDIR}/Workshop4_main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Workshop4_main.o.d" -o ${OBJECTDIR}/Workshop4_main.o Workshop4_main.c   
	
${OBJECTDIR}/Workshop5_main.o: Workshop5_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Workshop5_main.o.d 
	@${FIXDEPS} "${OBJECTDIR}/Workshop5_main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Workshop5_main.o.d" -o ${OBJECTDIR}/Workshop5_main.o Workshop5_main.c   
	
${OBJECTDIR}/Workshop6_main.o: Workshop6_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Workshop6_main.o.d 
	@${FIXDEPS} "${OBJECTDIR}/Workshop6_main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Workshop6_main.o.d" -o ${OBJECTDIR}/Workshop6_main.o Workshop6_main.c   
	
else
${OBJECTDIR}/NU32.o: NU32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/NU32.o.d 
	@${FIXDEPS} "${OBJECTDIR}/NU32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/NU32.o.d" -o ${OBJECTDIR}/NU32.o NU32.c   
	
${OBJECTDIR}/_ext/1199933227/Ultrasonic.o: ../../Downloads/Ultrasonic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1199933227 
	@${RM} ${OBJECTDIR}/_ext/1199933227/Ultrasonic.o.d 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1199933227/Ultrasonic.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1199933227/Ultrasonic.o.d" -o ${OBJECTDIR}/_ext/1199933227/Ultrasonic.o ../../Downloads/Ultrasonic.c   
	
${OBJECTDIR}/Workshop1_main.o: Workshop1_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Workshop1_main.o.d 
	@${FIXDEPS} "${OBJECTDIR}/Workshop1_main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Workshop1_main.o.d" -o ${OBJECTDIR}/Workshop1_main.o Workshop1_main.c   
	
${OBJECTDIR}/Servo.o: Servo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Servo.o.d 
	@${FIXDEPS} "${OBJECTDIR}/Servo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Servo.o.d" -o ${OBJECTDIR}/Servo.o Servo.c   
	
${OBJECTDIR}/PWM.o: PWM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/PWM.o.d 
	@${FIXDEPS} "${OBJECTDIR}/PWM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/PWM.o.d" -o ${OBJECTDIR}/PWM.o PWM.c   
	
${OBJECTDIR}/Workshop2_main.o: Workshop2_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Workshop2_main.o.d 
	@${FIXDEPS} "${OBJECTDIR}/Workshop2_main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Workshop2_main.o.d" -o ${OBJECTDIR}/Workshop2_main.o Workshop2_main.c   
	
${OBJECTDIR}/Workshop3_main.o: Workshop3_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Workshop3_main.o.d 
	@${FIXDEPS} "${OBJECTDIR}/Workshop3_main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Workshop3_main.o.d" -o ${OBJECTDIR}/Workshop3_main.o Workshop3_main.c   
	
${OBJECTDIR}/Workshop4_main.o: Workshop4_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Workshop4_main.o.d 
	@${FIXDEPS} "${OBJECTDIR}/Workshop4_main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Workshop4_main.o.d" -o ${OBJECTDIR}/Workshop4_main.o Workshop4_main.c   
	
${OBJECTDIR}/Workshop5_main.o: Workshop5_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Workshop5_main.o.d 
	@${FIXDEPS} "${OBJECTDIR}/Workshop5_main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Workshop5_main.o.d" -o ${OBJECTDIR}/Workshop5_main.o Workshop5_main.c   
	
${OBJECTDIR}/Workshop6_main.o: Workshop6_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Workshop6_main.o.d 
	@${FIXDEPS} "${OBJECTDIR}/Workshop6_main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/Workshop6_main.o.d" -o ${OBJECTDIR}/Workshop6_main.o Workshop6_main.c   
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/libnu32.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    NU32bootloaded.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_ICD3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/libnu32.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_ICD3=1,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/libnu32.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   NU32bootloaded.ld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/libnu32.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/libnu32.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
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

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
