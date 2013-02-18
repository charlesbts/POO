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
CC=gcc.exe
CCC=g++.exe
CXX=g++.exe
FC=gfortran
AS=as.exe

# Macros
CND_PLATFORM=Cygwin_4.x-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include MakePOO

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/BancoDados/Sources/RotinasBD.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/LogicaNegocio/Sources/MetodosClassePaciente.o \
	${OBJECTDIR}/BancoDados/Sources/BancoDados.o \
	${OBJECTDIR}/BancoDados/Sources/ExcecoesBancoDados.o \
	${OBJECTDIR}/LogicaNegocio/Sources/MetodosClasseMedico.o \
	${OBJECTDIR}/LogicaNegocio/Sources/MetodosClasseConsulta.o \
	${OBJECTDIR}/InterfaceUsuario/Sources/MetodosIntefaceUsuario.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1 \
	${TESTDIR}/TestFiles/f4 \
	${TESTDIR}/TestFiles/f3 \
	${TESTDIR}/TestFiles/f2

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-lsqlite3 -lsqlite3.dll

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/consultorionetbeans.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/consultorionetbeans.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/consultorionetbeans ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/BancoDados/Sources/RotinasBD.o: BancoDados/Sources/RotinasBD.cpp 
	${MKDIR} -p ${OBJECTDIR}/BancoDados/Sources
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/BancoDados/Sources/RotinasBD.o BancoDados/Sources/RotinasBD.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/LogicaNegocio/Sources/MetodosClassePaciente.o: LogicaNegocio/Sources/MetodosClassePaciente.cpp 
	${MKDIR} -p ${OBJECTDIR}/LogicaNegocio/Sources
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/LogicaNegocio/Sources/MetodosClassePaciente.o LogicaNegocio/Sources/MetodosClassePaciente.cpp

${OBJECTDIR}/BancoDados/Sources/BancoDados.o: BancoDados/Sources/BancoDados.cpp 
	${MKDIR} -p ${OBJECTDIR}/BancoDados/Sources
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/BancoDados/Sources/BancoDados.o BancoDados/Sources/BancoDados.cpp

${OBJECTDIR}/BancoDados/Sources/ExcecoesBancoDados.o: BancoDados/Sources/ExcecoesBancoDados.cpp 
	${MKDIR} -p ${OBJECTDIR}/BancoDados/Sources
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/BancoDados/Sources/ExcecoesBancoDados.o BancoDados/Sources/ExcecoesBancoDados.cpp

${OBJECTDIR}/LogicaNegocio/Sources/MetodosClasseMedico.o: LogicaNegocio/Sources/MetodosClasseMedico.cpp 
	${MKDIR} -p ${OBJECTDIR}/LogicaNegocio/Sources
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/LogicaNegocio/Sources/MetodosClasseMedico.o LogicaNegocio/Sources/MetodosClasseMedico.cpp

${OBJECTDIR}/LogicaNegocio/Sources/MetodosClasseConsulta.o: LogicaNegocio/Sources/MetodosClasseConsulta.cpp 
	${MKDIR} -p ${OBJECTDIR}/LogicaNegocio/Sources
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/LogicaNegocio/Sources/MetodosClasseConsulta.o LogicaNegocio/Sources/MetodosClasseConsulta.cpp

${OBJECTDIR}/InterfaceUsuario/Sources/MetodosIntefaceUsuario.o: InterfaceUsuario/Sources/MetodosIntefaceUsuario.cpp 
	${MKDIR} -p ${OBJECTDIR}/InterfaceUsuario/Sources
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/InterfaceUsuario/Sources/MetodosIntefaceUsuario.o InterfaceUsuario/Sources/MetodosIntefaceUsuario.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f1: ${TESTDIR}/TESTES/RunnerBD.o ${TESTDIR}/TESTES/newtestclass.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} -lcppunit 

${TESTDIR}/TestFiles/f4: ${TESTDIR}/TESTES/LogicaNegocio/TesteClasseConsulta/RunnerClasseConsulta.o ${TESTDIR}/TESTES/LogicaNegocio/TesteClasseConsulta/TesteClasseConsulta.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS} -lcppunit 

${TESTDIR}/TestFiles/f3: ${TESTDIR}/TESTES/LogicaNegocio/RunnerMedico.o ${TESTDIR}/TESTES/LogicaNegocio/TesteClasseMedico.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS} -lcppunit 

${TESTDIR}/TestFiles/f2: ${TESTDIR}/TESTES/LogicaNegocio/RunnerClassePaciente.o ${TESTDIR}/TESTES/LogicaNegocio/TesteClassePaciente.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} -lcppunit -lcppunit -lcppunit 


${TESTDIR}/TESTES/RunnerBD.o: TESTES/RunnerBD.cpp 
	${MKDIR} -p ${TESTDIR}/TESTES
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${TESTDIR}/TESTES/RunnerBD.o TESTES/RunnerBD.cpp


${TESTDIR}/TESTES/newtestclass.o: TESTES/newtestclass.cpp 
	${MKDIR} -p ${TESTDIR}/TESTES
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${TESTDIR}/TESTES/newtestclass.o TESTES/newtestclass.cpp


${TESTDIR}/TESTES/LogicaNegocio/TesteClasseConsulta/RunnerClasseConsulta.o: TESTES/LogicaNegocio/TesteClasseConsulta/RunnerClasseConsulta.cpp 
	${MKDIR} -p ${TESTDIR}/TESTES/LogicaNegocio/TesteClasseConsulta
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${TESTDIR}/TESTES/LogicaNegocio/TesteClasseConsulta/RunnerClasseConsulta.o TESTES/LogicaNegocio/TesteClasseConsulta/RunnerClasseConsulta.cpp


${TESTDIR}/TESTES/LogicaNegocio/TesteClasseConsulta/TesteClasseConsulta.o: TESTES/LogicaNegocio/TesteClasseConsulta/TesteClasseConsulta.cpp 
	${MKDIR} -p ${TESTDIR}/TESTES/LogicaNegocio/TesteClasseConsulta
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${TESTDIR}/TESTES/LogicaNegocio/TesteClasseConsulta/TesteClasseConsulta.o TESTES/LogicaNegocio/TesteClasseConsulta/TesteClasseConsulta.cpp


${TESTDIR}/TESTES/LogicaNegocio/RunnerMedico.o: TESTES/LogicaNegocio/RunnerMedico.cpp 
	${MKDIR} -p ${TESTDIR}/TESTES/LogicaNegocio
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${TESTDIR}/TESTES/LogicaNegocio/RunnerMedico.o TESTES/LogicaNegocio/RunnerMedico.cpp


${TESTDIR}/TESTES/LogicaNegocio/TesteClasseMedico.o: TESTES/LogicaNegocio/TesteClasseMedico.cpp 
	${MKDIR} -p ${TESTDIR}/TESTES/LogicaNegocio
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${TESTDIR}/TESTES/LogicaNegocio/TesteClasseMedico.o TESTES/LogicaNegocio/TesteClasseMedico.cpp


${TESTDIR}/TESTES/LogicaNegocio/RunnerClassePaciente.o: TESTES/LogicaNegocio/RunnerClassePaciente.cpp 
	${MKDIR} -p ${TESTDIR}/TESTES/LogicaNegocio
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/TESTES/LogicaNegocio/RunnerClassePaciente.o TESTES/LogicaNegocio/RunnerClassePaciente.cpp


${TESTDIR}/TESTES/LogicaNegocio/TesteClassePaciente.o: TESTES/LogicaNegocio/TesteClassePaciente.cpp 
	${MKDIR} -p ${TESTDIR}/TESTES/LogicaNegocio
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/TESTES/LogicaNegocio/TesteClassePaciente.o TESTES/LogicaNegocio/TesteClassePaciente.cpp


${OBJECTDIR}/BancoDados/Sources/RotinasBD_nomain.o: ${OBJECTDIR}/BancoDados/Sources/RotinasBD.o BancoDados/Sources/RotinasBD.cpp 
	${MKDIR} -p ${OBJECTDIR}/BancoDados/Sources
	@NMOUTPUT=`${NM} ${OBJECTDIR}/BancoDados/Sources/RotinasBD.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/BancoDados/Sources/RotinasBD_nomain.o BancoDados/Sources/RotinasBD.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/BancoDados/Sources/RotinasBD.o ${OBJECTDIR}/BancoDados/Sources/RotinasBD_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/LogicaNegocio/Sources/MetodosClassePaciente_nomain.o: ${OBJECTDIR}/LogicaNegocio/Sources/MetodosClassePaciente.o LogicaNegocio/Sources/MetodosClassePaciente.cpp 
	${MKDIR} -p ${OBJECTDIR}/LogicaNegocio/Sources
	@NMOUTPUT=`${NM} ${OBJECTDIR}/LogicaNegocio/Sources/MetodosClassePaciente.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/LogicaNegocio/Sources/MetodosClassePaciente_nomain.o LogicaNegocio/Sources/MetodosClassePaciente.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/LogicaNegocio/Sources/MetodosClassePaciente.o ${OBJECTDIR}/LogicaNegocio/Sources/MetodosClassePaciente_nomain.o;\
	fi

${OBJECTDIR}/BancoDados/Sources/BancoDados_nomain.o: ${OBJECTDIR}/BancoDados/Sources/BancoDados.o BancoDados/Sources/BancoDados.cpp 
	${MKDIR} -p ${OBJECTDIR}/BancoDados/Sources
	@NMOUTPUT=`${NM} ${OBJECTDIR}/BancoDados/Sources/BancoDados.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/BancoDados/Sources/BancoDados_nomain.o BancoDados/Sources/BancoDados.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/BancoDados/Sources/BancoDados.o ${OBJECTDIR}/BancoDados/Sources/BancoDados_nomain.o;\
	fi

${OBJECTDIR}/BancoDados/Sources/ExcecoesBancoDados_nomain.o: ${OBJECTDIR}/BancoDados/Sources/ExcecoesBancoDados.o BancoDados/Sources/ExcecoesBancoDados.cpp 
	${MKDIR} -p ${OBJECTDIR}/BancoDados/Sources
	@NMOUTPUT=`${NM} ${OBJECTDIR}/BancoDados/Sources/ExcecoesBancoDados.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/BancoDados/Sources/ExcecoesBancoDados_nomain.o BancoDados/Sources/ExcecoesBancoDados.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/BancoDados/Sources/ExcecoesBancoDados.o ${OBJECTDIR}/BancoDados/Sources/ExcecoesBancoDados_nomain.o;\
	fi

${OBJECTDIR}/LogicaNegocio/Sources/MetodosClasseMedico_nomain.o: ${OBJECTDIR}/LogicaNegocio/Sources/MetodosClasseMedico.o LogicaNegocio/Sources/MetodosClasseMedico.cpp 
	${MKDIR} -p ${OBJECTDIR}/LogicaNegocio/Sources
	@NMOUTPUT=`${NM} ${OBJECTDIR}/LogicaNegocio/Sources/MetodosClasseMedico.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/LogicaNegocio/Sources/MetodosClasseMedico_nomain.o LogicaNegocio/Sources/MetodosClasseMedico.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/LogicaNegocio/Sources/MetodosClasseMedico.o ${OBJECTDIR}/LogicaNegocio/Sources/MetodosClasseMedico_nomain.o;\
	fi

${OBJECTDIR}/LogicaNegocio/Sources/MetodosClasseConsulta_nomain.o: ${OBJECTDIR}/LogicaNegocio/Sources/MetodosClasseConsulta.o LogicaNegocio/Sources/MetodosClasseConsulta.cpp 
	${MKDIR} -p ${OBJECTDIR}/LogicaNegocio/Sources
	@NMOUTPUT=`${NM} ${OBJECTDIR}/LogicaNegocio/Sources/MetodosClasseConsulta.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/LogicaNegocio/Sources/MetodosClasseConsulta_nomain.o LogicaNegocio/Sources/MetodosClasseConsulta.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/LogicaNegocio/Sources/MetodosClasseConsulta.o ${OBJECTDIR}/LogicaNegocio/Sources/MetodosClasseConsulta_nomain.o;\
	fi

${OBJECTDIR}/InterfaceUsuario/Sources/MetodosIntefaceUsuario_nomain.o: ${OBJECTDIR}/InterfaceUsuario/Sources/MetodosIntefaceUsuario.o InterfaceUsuario/Sources/MetodosIntefaceUsuario.cpp 
	${MKDIR} -p ${OBJECTDIR}/InterfaceUsuario/Sources
	@NMOUTPUT=`${NM} ${OBJECTDIR}/InterfaceUsuario/Sources/MetodosIntefaceUsuario.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/InterfaceUsuario/Sources/MetodosIntefaceUsuario_nomain.o InterfaceUsuario/Sources/MetodosIntefaceUsuario.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/InterfaceUsuario/Sources/MetodosIntefaceUsuario.o ${OBJECTDIR}/InterfaceUsuario/Sources/MetodosIntefaceUsuario_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	    ${TESTDIR}/TestFiles/f4 || true; \
	    ${TESTDIR}/TestFiles/f3 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/consultorionetbeans.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
