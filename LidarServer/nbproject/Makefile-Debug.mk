#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/Client.o \
	${OBJECTDIR}/src/Connection.o \
	${OBJECTDIR}/src/ConnectionManager.o \
	${OBJECTDIR}/src/LidarConnection.o \
	${OBJECTDIR}/src/LidarMessage.o \
	${OBJECTDIR}/src/Logger.o \
	${OBJECTDIR}/src/Message.o \
	${OBJECTDIR}/src/ServerSocket.o \
	${OBJECTDIR}/src/SimpleMessage.o \
	${OBJECTDIR}/src/Socket.o \
	${OBJECTDIR}/src/UIConnection.o \
	${OBJECTDIR}/src/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-std=c++14 -pthread
CXXFLAGS=-std=c++14 -pthread

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lidarserver

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lidarserver: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lidarserver ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/Client.o: src/Client.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iincl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Client.o src/Client.cpp

${OBJECTDIR}/src/Connection.o: src/Connection.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iincl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Connection.o src/Connection.cpp

${OBJECTDIR}/src/ConnectionManager.o: src/ConnectionManager.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iincl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ConnectionManager.o src/ConnectionManager.cpp

${OBJECTDIR}/src/LidarConnection.o: src/LidarConnection.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iincl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/LidarConnection.o src/LidarConnection.cpp

${OBJECTDIR}/src/LidarMessage.o: src/LidarMessage.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iincl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/LidarMessage.o src/LidarMessage.cpp

${OBJECTDIR}/src/Logger.o: src/Logger.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iincl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Logger.o src/Logger.cpp

${OBJECTDIR}/src/Message.o: src/Message.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iincl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Message.o src/Message.cpp

${OBJECTDIR}/src/ServerSocket.o: src/ServerSocket.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iincl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ServerSocket.o src/ServerSocket.cpp

${OBJECTDIR}/src/SimpleMessage.o: src/SimpleMessage.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iincl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/SimpleMessage.o src/SimpleMessage.cpp

${OBJECTDIR}/src/Socket.o: src/Socket.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iincl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Socket.o src/Socket.cpp

${OBJECTDIR}/src/UIConnection.o: src/UIConnection.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iincl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/UIConnection.o src/UIConnection.cpp

${OBJECTDIR}/src/main.o: src/main.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Iincl -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
