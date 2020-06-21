APP			:= rtw
CC 			:= clang++
OBJDIR 		:= .obj
SRCDIR 		:= src
OBJFILES 	:= ${OBJDIR}/main.o \
			   ${OBJDIR}/vec3.o \
			   ${OBJDIR}/ray.o  \
			   ${OBJDIR}/hitablelist.o \
			   ${OBJDIR}/sphere.o \
			   ${OBJDIR}/camera.o
INCDIRS		:= ${SRCDIR}
CFLAGS 		:= -Wall -pedantic -I${INCDIRS} -std=c++17
LDFLAGS		:=

${APP} : ${OBJFILES}
	${CC} ${LDFLAGS} ${OBJFILES} -o $@

${OBJDIR}/%o : ${SRCDIR}/%cpp
	${CC} -c ${CFLAGS} $< -o $@	

.PHONY: clean cleanall

clean:
	rm -f ${OBJFILES}

cleanall:
	rm -f ${OBJFILES} ${APP}