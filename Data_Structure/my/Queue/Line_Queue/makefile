TARGET = queue
OBJ = main.o add.o delete.o print.o etc.o

$(TARGET) : $(OBJ)
	gcc -o $(TARGET) $(OBJ)
.c.o : 
	gcc -c -g $<

clean : 
	rm -f $(OBJ)
	clear
	ls
