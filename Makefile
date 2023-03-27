CC=gcc
CFLAGS=-Wall
RFLAGS=
OL=2
OUT=stack

all: compile clean

%.o: %.c
	$(CC) $(CFLAGS) -c $^

compile: main.c stacklib.o
	$(CC) -O$(OL) -o $(OUT) $^ $(CFLAGS)
	$(CC) -g -o $(OUT)-debug $^ $(CFLAGS)

clean:
	rm *.o

run:
	./$(OUT) $(RFLAGS)

debug:
	gdb --args $(OUT) $(RFLAGS)
