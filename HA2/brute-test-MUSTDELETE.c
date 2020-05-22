#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "bruteforcer.h"

int main(){

    hashes *loaded_hashes = NULL;
    char filename[] = "";
    //loaded_hashes->array = NULL;
    scanf("%s",filename);
    ////loaded_hashes = fopen(filename, "r");
    //FILE *frt = fopen(filename, 'r');
    //int i = 0;

    loaded_hashes = load_hashes(filename);
    //FILE *fp = fopen(filename,"r");
    //int i = 0;
    //char HASH[256];
    //char strs[100][256];
    //while(fgets(HASH, sizeof(load_hashes),fp)!= NULL){
    //    strcpy(strs[i],HASH);
    //    //loaded_hashes->array[i] -> strs[i];
    //    
    //    
    //    //printf("%s\n",strs[i]);
    //    i++;
    //    
    //}
    //loaded_hashes->array = strs;
    for (int i = 0; i < sizeof(loaded_hashes); i++){
        printf("%s\n",loaded_hashes->array[i]);
    }
    
    
    //fclose(fp);
    return 0;
}