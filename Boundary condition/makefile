CC = gcc
DEBUG = -g
SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)
LIBS = $(wildcard *.h)
EXE = program
DEPS := $(OBJS:.o=.d)

all: $(SRC) $(EXE)

-include $(DEPS)

$(EXE): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o mc_brzeg -lm -O3
.cpp.o:
	$(CC) $(CPPFLAGSC) $< -o $@

.PHONY: clean

clean:
	rm *.o
