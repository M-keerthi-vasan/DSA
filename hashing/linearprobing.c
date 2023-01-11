#include "stdio.h"
#include "stdlib.h"
#define n 10
int hash[n] = {0};
int data,i,hashkey;
void check(){
    printf("enter the data : ");
    scanf("%d",&data);
    hashkey = data % n;
}
void insert(){
    int index;
    check();
    for(i = 0;i < n;i++){
        index = (hashkey+i)%n;
        if(hash[index] == 0){
            hash[index] = data;
            break;
        }
    }
    if(i == n){
        printf("Table is full\n");
    }   
}
void delete(){
    int index;
    check();
    for(i = 0;i < n;i++){
        index = (hashkey+i)%n;
        if(hash[index] == data){
            hash[index] = 0;
            break;
        }
    }
}
void search(){
    int index,flag = 0;
    check();
    for(i = 0;i < n;i++){
        index = (hashkey+i)%n;
        if(hash[index] == data){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        printf("Element found\n");
    }else{
        printf("Element not found\n");
    }
}
void display(){
    for(i = 0;i < n;i++){
        printf("key(%d) value==>%d\n",i,hash[i]);
    }
}
void main(){
    int choice;
    while(1){
        printf("\n1.insert\n");
        printf("2.delete\n");
        printf("3.search\n");
        printf("enter the choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            insert();
            display();
            break;
            case 2:
            delete();
            display();
            break;
            case 3:
            search();
            break;
        }
    }
}