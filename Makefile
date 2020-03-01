# template Makefile

# Setting the compiler and the default lonker program
CC =  gcc
# options for pre-processor (-I, -include, -D, ...)
CPPFLAGS = -MMD
# main compilation options
CFLAGS = -g -Wall -Wextra -std=c99 -O0
# Linker options (probably always empty)
LDFLAGS = -lSDL -lSDL_mixer
# libs and path for linker
LDLIBS =

SRC = main.c graphics.c sorts.c

OBJ = ${SRC:.c=.o}
# add list of dependency files
DEP = ${SRC:.c=.d}

all: main

main: CFLAGS += -O2
main: ${OBJ}

debug: CFLAGS += -g
debug: ${OBJ}

.PHONY: clean

clean:
	${RM} *.o	# remove object files
	${RM} main	# remove main program
	${RM} *.d	# remove depedency files

# include dependency files
-include ${DEP}

#END
