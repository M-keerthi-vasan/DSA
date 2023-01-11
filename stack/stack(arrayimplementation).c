#include "stdio.h"
#include "stdbool.h"
#define n 5
int stack[n],top = -1;
bool isfull(){
    return top == n;
}
bool isempty(){
    return top == -1;
}
void push(){
    int data;
    printf("enter the data : ");
    scanf("%d",&data);
    if(isfull()){
        return 0;
    }else{
        stack[++top] = data;
    }
}
void pop(){
    if(isempty()){
        return 0;
    }else{
        printf("The poped element is %d\n",stack[top]);
        top--;
    }
}
void peek(){
    if(isempty()){
        return 0;
    }else{
        printf("The top most element in the stack is %d\n",stack[top]);
    }
}
void display(){
    if(isempty()){
        return 0;
    }else{
        for(int i = top;i >= 0;i--){
            printf("%d\t",stack[i]);
        }
    }
}
void main(){
    int choice;
    while(1){
        printf("\n1.push\n");
        printf("2.pop\n");
        printf("3.peek\n");
        printf("4.display\n");
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