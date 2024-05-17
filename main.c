#include "struct.h"



int main(int argc, char* argv[]){
    FILE* fin, *fout, *fcer;
    fin = fopen(argv[2], "rb");
    if(fin == NULL){
        exit(1);
    }
    fout = fopen(argv[3], "wb");
    if(fout == NULL){
        exit(1);
    }
    fcer = fopen(argv[1], "rb");
    if(fcer == NULL){
        exit(1);
    }

    int cerinta[5];
    for (int k = 0; k < 5; k++) {
        fscanf(fcer, "%d", &cerinta[k]);
        getc(fcer); // pentru a lua spatiul dintre cifre
    }

    if(cerinta[0] == 1 && cerinta[1] == 0 && cerinta[2] == 0 && cerinta[3] == 0 && cerinta[4] == 0){ 
        task1(fin, fout);
    }

    if(cerinta[0] == 1 && cerinta[1] == 1 && cerinta[2] == 0 && cerinta[3] == 0 && cerinta[4] == 0){
        task2(fin, fout);
    }

    if(cerinta[0] == 1 && cerinta[1] == 1 && cerinta[2] == 1 && cerinta[3] == 0 && cerinta[4] == 0){
        task3(fin, fout);
    }

    if(cerinta[0] == 1 && cerinta[1] == 1 && cerinta[2] == 1 && cerinta[3] == 1 && cerinta[4] == 0){
        task4(fin, fout);
    }

    return 0;
}