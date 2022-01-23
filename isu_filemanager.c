	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <math.h>
        #include <errno.h>
	
	int main(int argc, char* argv[]) {
	    //if(strcmp(argv[1],"--help") == 0)
	    FILE *fp;
	    int errnum;
	    if (fp == NULL) {
	        printf("fopen failed!");
	        exit(-1);
		}
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
	        if (fp == NULL) {
	        	printf("fopen failed!");
	        	exit(-1);
			}
	
	        dest = fopen(argv[3], "w");
	        if (fp == NULL) {
	        	printf("fopen failed!");
	        	exit(-1);
			}
	
	        while ((ch = fgetc(fp)) != EOF)
	            fputc(ch, dest);
	        fclose(fp);
	        fp = fopen(argv[2], "w");
	        if (fp == NULL) {
	        	printf("fopen failed!");
	        	exit(-1);
			}
	        remove(argv[2]);
	    }
	
	    else if(strcmp(argv[1], "append") == 0) {
	        char *ap;
	        ap = argv[3];
	        FILE *dest;
	        dest = fopen(argv[2], "a");
	        if (dest == NULL) {
	        	printf("fopen failed!");
	        	exit(-1);
			}	        
	        int i;
	        for( i = 0; i < strlen(ap); i++)
	        {
	            fputc(argv[3][i], dest);
	        }
	        
	    }
	    
	    else if(strcmp(argv[1], "writeat") == 0) {
	        char *ap; 
	        ap = argv[4];
	        FILE *dest;
	    
	        dest = fopen(argv[2], "r+b");
	        if (dest == NULL) {
	        	printf("fopen failed!");
	        	exit(-1);
			}
	        fseek(dest, strtol(argv[3], NULL, 10), SEEK_SET);
	        int i;
	        for( i = 0; i < strlen(ap); i++) 
	        {
	            fputc(argv[4][i], dest);
	        }    
	   }
	
	   else if(strcmp(argv[1], "clear") == 0) {
	       fp = fopen(argv[2], "w");
	   }
	
	   else if(strcmp(argv[1], "display") == 0) {
	       char ch;
	       fp = fopen(argv[2], "r");
	       	if (fp == NULL) {
	        	printf("fopen failed!");
	        	exit(-1);
			}
	       do {
	           /* Read single character from file */
	           ch = fgetc(fp);
	
	           /* Print character read on console */
	           putchar(ch);
	       } while(ch != EOF); /* Repeat this if last read character is not EOF */
	
	       /* Done with this file, close file to release resource */
	       fclose(fp);
	   }   
	}
