#include <stdio.h>
#include <stdlib>
#include <string.h>

int main(int argc, char* argv[]){

    //if strcmp(argv[1], "--help") == 0 
    FILE *fp;

    if strcmp(argv[argc-1], "/h") == 0 {

        if strcmp(argv[1], "create") == 0 
        printf("To create a file do \"main display filename.txt\"\n");

        else if strcmp(argv[1], "remove") == 0 
        printf("To remove a file do \"main remove filenmae.txt\"\n");

        else if strcmp(argv[1], "rename") == 0 
        printf("To rename a file do \"main rename oldname.txt newname.txt\"\n");

        else if strcmp(argv[1], "copy") == 0 
        printf("To copy a file do \"main copy source.txt destination.txt\"\n");

        else if strcmp(argv[1], "move") == 0 
        printf("To move a file do \"main move filename.txt ../files/filename.txt\"\n");

        else if strcmp(argv[1], "append") == 0 
        printf("To append a file do \"main append filename.txt helloworld\"\n");

        else if strcmp(argv[1], "writeat") == 0 
        printf("To write at a specific locatipn to file do \"main writeat location filename.txt\"\n");

        else if strcmp(argv[1], "clear") == 0 
        printf("To clear a file do \"main clear filename.txt\"\n");

        else if strcmp(argv[1], "display") == 0 
        printf("To display a file do \"main display filename.txt\"\n");

        return 0;
    }

    if strcmp(argv[1], "create") == 0 {
        fp = fopen(argv[2], "w");
    }

    else if strcmp(argv[1], "remove") == 0 {
        remove(argv[2]);
    }
}
