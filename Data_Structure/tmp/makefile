TARGET = Polynomial
OBJ = main.o set.o Node_function.o postfix.o cal.o sub.o exception.o

$(TARGET) : $(OBJ)
	gcc -o $(TARGET) $(OBJ)
.c.o :
	gcc -c -g $<

clean :
	rm -f *.o
	clear
