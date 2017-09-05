TARGET = Vocabularay
OBJ = main.o Insert.o Find.o Delete.o Print.o Save.o Initialize.o

$(TARGET) : $(OBJ)
	gcc -o $(TARGET) $(OBJ) -g
.c.o : 
	gcc -c -g $<

clean : 
	rm -f *.o 
	clear

