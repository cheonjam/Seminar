#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h> 
#include <dirent.h>
 
static int  indent = 0; 
static int fileCount;
static int dirCount;
char cdir[256];

void myfunc(char *file) 
{ 
//    printf("%s\n",file);
    printf("%s/%s\n", getcwd(cdir, 256),file);
} 
 
void Scandir(char *wd, int depth) 
{ 
    struct dirent **items; 
    int nitems, i; 

    if (chdir(wd) < 0) 
	{ 
		printf("DIR : %s\n", wd); 
		perror("chdir "); 
		exit(1); 
    } 
	
	 nitems = scandir(".", &items, NULL, alphasort); 
					 
	for (i = 0; i < nitems; i++) 
	{ 
		struct stat fstat; 
					 
		if ( (!strcmp(items[i]->d_name, ".")) || (!strcmp(items[i]->d_name, "..")) ) 
			continue; 
	
		myfunc(items[i]->d_name); 
																	 
		lstat(items[i]->d_name, &fstat); 
		if ((fstat.st_mode & S_IFDIR) == S_IFDIR) 
	    { 
			dirCount++;
			if (indent < (depth-1) || (depth == 0)) 
			{ 
				indent ++; 
				Scandir(items[i]->d_name, depth); 
			} 
		} 
	    else
			fileCount++;
	} 
	
	indent --; 
	chdir(".."); 
}

int main (int argc, char *argv[])
{
	Scandir(argv[1], 0);
	printf("fileCount=%d\n", fileCount);
	printf("dirCount=%d\n", dirCount);

	return 0;
}
