#include "stdio.h"
#include "stdlib.h"
typedef struct node{
    int data;
    struct node *next;
}node;
node *top = NULL;
void push(){
    int data;
    printf("enter the data : ");
    scanf("%d",&data);
    node *newnode = (node *)malloc(sizeof(node *));
    newnode -> data = data;
    if(top == NULL){
        newnode -> next = NULL;
        top = newnode;
    }else{
        newnode -> next = top;
        top = newnode;
    }
}
void pop(){
    node *temp = top;
    if(top == NULL){
        printf("Stack is empty\n");
    }else{
        top = temp -> next;
        free(temp);
    }
}
void peek(){
    if(top == NULL){
        printf("Stack is empty\n");
    }else{
        printf("The top element present in the stack is %d\n",top -> data);
    }
}
void display(){
    if(top == NULL){
        printf("Stack is empty\n");
    }else{
        node *temp = top;
        while(temp != NULL){
            printf("%d---->",temp -> data);
            temp = temp -> next;
        }
    }
}
void main(){
    int choice;
    while(1){
        printf("\n1.insert\n");
        printf("2.delete\n");
        printf("3.peek\n");
        printf("enter the choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            push();
            display();
            break;
            case 2:
            pop();
            display();
            break;
            case 3:
            peek();
            break;
            case 4:
            exit(0);
        }
    }
}