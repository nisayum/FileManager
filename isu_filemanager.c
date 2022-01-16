#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    //if(strcmp(argv[1],"--help") == 0)
    FILE *fp;
    if(strcmp(argv[argc-1], "/h") == 0)
    {
    	if(strcmp(argv[1], "create") == 0)
    	printf("To create a file do \"main create filename.txt\"\n");
    	
    	else if(strcmp(argv[1], "remove") == 0)
    	printf("To remove a file do \"main remove filename.txt\"\n");
    	
    	else if(strcmp(argv[1], "rename") == 0)
    	printf("To rename a file do \"main rename oldname.txt newname.txt\"\n");
    	
    	else if(strcmp(argv[1], "copy") == 0)
    	printf("To copy a file do \"main copy source.txt destination.txt\"\n");
    	
    	else if(strcmp(argv[1], "move") == 0)
    	printf("To move a file do \"main move filename.txt ../files/filename.txt\"\n");
    	
    	else if(strcmp(argv[1], "append") == 0)
    	printf("To append a file do \"main append filename.txt helloworld!\"\n");
    	
    	else if(strcmp(argv[1], "writeat") == 0)
    	printf("To write at a specific location to file do \"main writeat location filename.txt\"\n");
    	
    	else if(strcmp(argv[1], "clear") == 0)
    	printf("To clear a file do \"main clear filename.txt\"\n");
    	
    	else if(strcmp(argv[1], "display") == 0)
    	printf("To display a file do \"main display filename.txt\"\n");
    	
    	return 0;
    }
    if(strcmp(argv[1], "create") == 0) {
        fp = fopen(argv[2], "w");
    }

    else if(strcmp(argv[1], "remove") == 0) {
        remove(argv[2]);
    }

    else if(strcmp(argv[1], "rename") == 0) {
        rename(argv[2], argv[3]);
    }

    else if(strcmp(argv[1], "copy") == 0) {
        char ch;
        FILE *dest;
        fp = fopen(argv[2], "r");

        dest = fopen(argv[3], "w");

        while ((ch = fgetc(fp)) != EOF)
            fputc(ch, dest);
    }

    else if(strcmp(argv[1], "move") == 0) {
        char ch;
        FILE *dest;
        fp = fopen(argv[2], "r");

        dest = fopen(argv[3], "w");

        while ((ch = fgetc(fp)) != EOF)
            fputc(ch, dest);
        fclose(fp);
        fp = fopen(argv[2], "w");
        remove(argv[2]);
    }

    else if(strcmp(argv[1], "append") == 0) {
        char *ap;
        ap = argv[3];
        FILE *dest;
        dest = fopen(argv[2], "a");
        for(int i = 0; i < strlen(ap); i++)
        {
            
        }
        
        fclose(fp);
    }

   }

/* 
#include <stdio.h>

void main()
{
	int status;
	char fname[20];
	printf("\n\n Remove a file from the disk :\n");
	printf("----------------------------------\n"); 	
	printf(" Input the name of file to delete : ");
	scanf("%s",fname);
	status=remove(fname);
	if(status==0)
	{
		printf(" The file %s is deleted successfully!!\n\n",fname);
	}
	else
	{
		printf(" This file is can not be deleted %s\n\n",fname);
	}
}*/


/// COPING A TEXT FILE TO ANOTHER TEXT FILE
/*
#include <stdio.h>
#include <stdlib.h>

void main(){
	FILE *fptr1, *fptr2;
	char ch, fname1[1000], fname2[1000];
	
	printf("\n Program to copy a file in another name: \n");
	printf("Enter the source file name: ");
	scanf("%s", fname1);
	
	fptr1 = fopen(fname1, "rb");
	if (fptr1 == NULL){
		printf("File does not found or an error occured when opening!!");
		exit(1);
	}
	printf("\n Enter the new file name: ");
	scanf("%s", fname2);
	fptr2 = fopen(fname2, "wb");
	if( fptr2 == NULL){
		printf("File does not found or an error occured when opening!!");
		fclose(fptr1);
		exit(2);
		
	}
	while(1){
		ch = fgetc(fptr1);
		
		if(ch == EOF){
			break;
		}
		else{
			fputc(ch, fptr2);
		}
	}
	printf("The file %s copied to file %s succesfully.\n", fname1, fname2);
	fclose(fptr1);
	fclose(fptr2);
	
}*/

