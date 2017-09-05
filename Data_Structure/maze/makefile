TARGET = maze
OBJ = main.o set.o stack.o print.o save.o

$(TARGET) : $(OBJ)
	gcc -o $(TARGET) $(OBJ)
.c.o : 
	gcc -c -g $<

clean : 
	rm -f $(OBJ)
	clear
	ls
