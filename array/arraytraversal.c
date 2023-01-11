#include "stdio.h"
void main(){
    int size,arr[100],i;
    printf("enter the array size : ");
    scanf("%d",&size);
    for(i = 0;i < size;i++){
        printf("arr[%d] : ",i);
        scanf("%d",&arr[i]);
    }
    for(i = 0;i<size;i++){
        printf("%d\t",arr[i]);
    }
}