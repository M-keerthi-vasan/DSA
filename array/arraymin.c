#include "stdio.h"
void main(){
    int size,arr[100],i,min;
    printf("enter the array size : ");
    scanf("%d",&size);
    for(i = 0;i < size;i++){
        printf("arr[%d] : ",i);
        scanf("%d",&arr[i]);
    }
    min = arr[0];
    for(i = 0;i<size;i++){
        if(min>arr[i]){
            min = arr[i];
        }
    }
    printf("The minimum element present in the array is %d\n",min);
}