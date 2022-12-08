#include "file/file_worker_c.h"
#include <stdio.h>
#include <stdlib.h>

int FileWorkerC::copy_file(const std::string &src, const std::string &dest)
{
    printf("c file worker~\n");

    //define file ptr
    FILE *fptr_src, *fptr_dest;

    //open src file
    fptr_src = fopen(src.c_str(), "r");
    if (fptr_src == NULL){
        printf("can not open file:  %s\n",  src.c_str());
        return -1;
    }

    //open dest file
    fptr_dest = fopen(dest.c_str(), "w");
    if (fptr_dest == NULL){
        printf("can not open file:  %s\n",  dest.c_str());
        return -1;
    }

    //copy content from src to content
    char c = fgetc(fptr_src);
    while (c != EOF){
        fputc(c, fptr_dest);
        c = fgetc(fptr_src);
    }

    //close file ptr
    fclose(fptr_src);
    fclose(fptr_dest);

    return 0;
}
