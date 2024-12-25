OBJ=main
FILE=main.c adc.c
OPT=-lpthread
all:
	$(CC) -o $(OBJ) $(FILE) $(OPT)