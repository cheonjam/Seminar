TARGET = TreeCalculator
OBJ = main.o stack.o set.o change.o exception.o exception_func.o etc.o MakeTree.o BinaryTree.o Calculate.o

$(TARGET) : $(OBJ)
	gcc -o $(TARGET) $(OBJ)
.c.o : 
	gcc -c -g $<

clean : 
	rm -f *.o 
	clear

