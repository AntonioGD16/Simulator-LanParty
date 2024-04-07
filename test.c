#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main(int argc, char* argv[]){
    FILE* fin, *fout;
    fin = fopen(argv[2], "rb");
    if(fin == NULL){
        exit(1);
    }
    fout = fopen(argv[3], "wb");
    if(fout == NULL){
        exit(1);
    }    





    return 0;
}