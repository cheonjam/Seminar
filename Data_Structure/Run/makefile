TARGET = run 
OBJ = main.o bit.o file.o type.o enc.o neg.o pattern.o dec.o file2.o ctoi.o

$(TARGET) : $(OBJ)
	gcc -o $(TARGET) $(OBJ)
.c.o : 
	gcc -c -g $<

clean : 
	rm -f $(OBJ)
	clear
	ls
