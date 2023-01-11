#include "stdio.h"
#include "stdlib.h"
typedef struct node{
    int data;
    struct node *next;
}node;
node *front = NULL,*rear = NULL;
void enqueue(){
    int data;
    printf("enter the data : ");
    scanf("%d",&data);
    node *newnode = (node *)malloc(sizeof(node *));
    newnode -> data = data;
    if(front == NULL){
        front = rear = newnode;
        front -> next = rear -> next = NULL;
    }else{
        rear -> next = newnode;
        rear = newnode;
        rear -> next = NULL;
    }
}
void dequeue(){
    node *temp = front;
    if(front == NULL){
        printf("Stack is empty\n");
    }else{
        front = temp -> next;
        free(temp);
    }
}
void peek(){
    if(front == NULL){
        printf("Stack is empty\n");
    }else{
        printf("The top element present in the queue is %d\n",front -> data);
    }
}
void display(){
    if(front == NULL){
        printf("Stack is empty\n");
    }else{
        node *temp = front;
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
            enqueue();
            display();
            break;
            case 2:
            dequeue();
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