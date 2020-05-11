#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    int data = 1;
    int *front = data;
    int frunt = &data;
    int neu = front;

    printf("%d \n" , neu);
    printf("%d \n" , frunt);
    printf("%d \n" , front);

    return 0;
}
