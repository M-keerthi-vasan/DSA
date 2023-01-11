#include "stdio.h"
void main(){
    int size,arr[100],i,j,temp;
    printf("enter the array size : ");
    scanf("%d",&size);
    for(i = 0;i < size;i++){
        printf("arr[%d] : ",i);
        scanf("%d",&arr[i]);
    }
    for(i = 0;i<size;i++){
        for(j=i+1;j<size;j++){
            if(arr[i]>arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(i = 0;i<size;i++){
        printf("%d\t",arr[i]);
    }
}