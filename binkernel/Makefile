CC=clang
CFLAGS=-std=c11 -Wall -Wextra -Wpedantic
OBJ=binkernel.o
EXE=binkernel
FRAMEWORK=-framework OpenCL

all: binkernel clean

binkernel: $(OBJ)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ) $(FRAMEWORK) 

clean:
	rm -rf $(OBJ)

.c.o:
	$(CC) -c -o $@ $<