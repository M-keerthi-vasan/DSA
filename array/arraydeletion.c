#include "stdio.h"
void main(){
    int size,arr[100],pos,i;
    printf("enter the array size : ");
    scanf("%d",&size);
    for(i = 0;i < size;i++){
        printf("arr[%d] : ",i);
        scanf("%d",&arr[i]);
    }
    printf("enter the position to delete : ");
    scanf("%d",&pos);
    for(i = pos-1;i<size-1;i++){
        arr[i] = arr[i+1];
    }
    size--;
    for(i = 0;i<size;i++){
        printf("%d\t",arr[i]);
    }
}