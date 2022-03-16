CC=clang
CFLAGS=-std=c11 -Wall -Wextra -Wpedantic -DGPU -g
OBJ=src/main.o src/gpu.o src/cpu.o src/timing.o src/args.o
OUT=app
FRAMEWORK=-framework OpenCL
LIBS=-L./lib -llog
INCLUDE=-I./include

all: primes clean

primes: $(OBJ)
	$(CC) $(CFLAGS) -o $(OUT) $(OBJ) $(FRAMEWORK) $(LIBS)

clean: $(OBJ)
	rm -rf $(OBJ)

run:
	./$(OUT)

test: primes run clean

.c.o:
	$(CC) $(INCLUDE) -c -o $@ $<
