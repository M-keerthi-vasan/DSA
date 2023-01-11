#include "stdio.h"
void main(){
    int size,arr[100],ele,pos,i;
    printf("enter the array size : ");
    scanf("%d",&size);
    for(i = 0;i < size;i++){
        printf("arr[%d] : ",i);
        scanf("%d",&arr[i]);
    }
    printf("enter the element to insert : ");
    scanf("%d",&ele);
    printf("enter the position : ");
    scanf("%d",&pos);
    for(i = size-1;i>=pos-1;i--){
        arr[i+1] = arr[i];
    }
    arr[pos-1] = ele;
    for(i = 0;i<=size;i++){
        printf("%d\t",arr[i]);
    }
}