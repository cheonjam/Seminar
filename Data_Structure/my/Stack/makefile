TARGET = stack
OBJ = main.o push.o pop.o print.o

$(TARGET) : $(OBJ)
	gcc -o $(TARGET) $(OBJ)
.c.o : 
	gcc -c -g $<

clean : 
	rm -f $(OBJ)
	clear
	ls
