#include "stdio.h"
#define max 10
int queue[max],front = -1,rear = -1,data,item;
void enqueue(){
    printf("enter the data : ");
    scanf("%d",&data);
    if(rear == max-1){
        printf("queue is full\n");
    }else{
        if(front == -1){
            front = 0;
        }
        rear = rear + 1;
        queue[rear] = data;
    }
}
void dequeue(){
    if(front == -1 || front>rear){
        printf("queue is empty\n");
    }else{
        item = queue[front];
        front = front + 1;
        printf("The removed element is %d\n",item);
    }
}
void display(){
    if(front == -1){
        printf("queue is empty\n");
    }else{
        for(int i = front;i <= rear;i++){
            printf("%d\t",queue[i]);
        }
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