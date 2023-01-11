#include "stdio.h"
void main(){
    int size,arr[100],i,max;
    printf("enter the array size : ");
    scanf("%d",&size);
    for(i = 0;i < size;i++){
        printf("arr[%d] : ",i);
        scanf("%d",&arr[i]);
    }
    max = arr[0];
    for(i = 0;i<size;i++){
        if(max<arr[i]){
            max = arr[i];
        }
    }
    printf("The maximum element present in the array is %d\n",max);
}