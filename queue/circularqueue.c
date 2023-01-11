#include "stdio.h"
#define max 3
int queue[max],front = -1,rear = -1,data,item;
void enqueue(){
    printf("enter the data : ");
    scanf("%d",&data);
    if((rear == max-1 && front == 0)||(front == rear+1)){
        printf("queue is full\n");
    }else{
        if(front == -1){
            front = 0;
        }
        rear = (rear + 1)%max;
        queue[rear] = data;
    }
}
void dequeue(){
    if(front == -1){
        printf("queue is empty\n");
    }
    if(front == rear){
        printf("The removed element is %d\n",queue[front]);
        front = rear = -1;
        
    }
    else{
        printf("The removed element is %d\n",queue[front]);
        front = (front + 1)%max;
    }
}
void display(){
    int i;
    if(front == -1){
        printf("queue is empty\n");
    }else{
        for(i = front;i != rear;i=(i+1)%max){
            printf("%d\t",queue[i]);
        }
        printf("%d",queue[i]);
    }
}
void main(){
    int choice;
    while(1){
        printf("\nenter 1 to enqueue\n");
        printf("enter 2 to dequeue\n");
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
            exit(0);
        }
    }
}