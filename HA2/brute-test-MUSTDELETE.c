#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
    char filename[] = "";
    scanf("%s",filename);
    FILE *fp = fopen(filename,"r");
    int i = 0;
    char HASH[256];
    char strs[100][256];
    while(fgets(HASH, sizeof(HASH),fp)!= NULL){
        strcpy(strs[i],HASH);
        //printf("%s\n",strs[i]);
        i++;
        
    }
    printf("%s",strs[6]);
    
    fclose(fp);
    return 0;
}