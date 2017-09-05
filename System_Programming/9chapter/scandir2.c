#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

const char *path = ".";

int backup_file_only(const struct dirent *info)
{
	char *ext;

	ext=strchr(info->d_name, '.');

	if(ext == NULL)
		return 0;

	if(!strcmp(ext,".bak"))
		return 1;
	else
		return 0;
}

int main(void)
{
	struct dirent **namelist;
	int count,i;
	char file_path[1024];

	if( (count = scandir(path,&namelist,NULL,alphasort)) == -1 )
	{
		perror("scandir");
		return -1;
	}

	for(i=0 ; i < count ; i++)
	{
		snprintf(file_path,1024, "%s%s",path,namelist[i]->dname);
		if(unlink(file_path)==0)
			printf("%s file delete\n",namelist[i]->d_name);
		else
			fprintf(stderr,"%s file error : %s\n",namelist[i]->d_name, strerror(error));
	}

	for(i=0; i<count ; i++)
		free(namelist[i]);

	free(namelist);

	return 0;
}
