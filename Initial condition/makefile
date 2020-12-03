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
	$(CC) $(CPPFLAGS) $(OBJS) -o mc_pocz -lm
.cpp.o:
	$(CC) $(CPPFLAGSC) $< -o $@

.PHONY: clean

clean:
	rm *.o

alg12:
	./mc_pocz alg12
	
alg3:
	./mc_pocz alg3
	
rk4:
	./mc_pocz rk4
	
zad4:
	./mc_pocz zad4
	
compare:
	./mc_pocz compare
	
draw:
	gnuplot *.p