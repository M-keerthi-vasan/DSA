#include "stdio.h"
void main(){
    int size,arr[100],i,flag = 0,ele;
    printf("enter the array size : ");
    scanf("%d",&size);
    for(i = 0;i < size;i++){
        printf("arr[%d] : ",i);
        scanf("%d",&arr[i]);
    }
    printf("enter the element : ");
    scanf("%d",&ele);
    for(i = 0;i < size;i++){
        if(arr[i] == ele){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        printf("element found\n");
    }else{
        printf("element not found\n");
    }
}