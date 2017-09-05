TARGET = Calculator
OBJ = main.o stack.o Calculate.o set.o change.o operate.o exception.o new_exception.o etc.o

$(TARGET) : $(OBJ)
	gcc -o $(TARGET) $(OBJ)
.c.o : 
	gcc -c -g $<

clean : 
	rm -f *.o 
	clear

