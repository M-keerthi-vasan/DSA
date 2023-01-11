#include "stdio.h"
#include "stdlib.h"
typedef struct node{
    int data;
    struct node *next,*prev;
}node;
node *head = NULL;
node *temp1,*temp2;
void insert(){
    temp1 = head;
    int data,choice,position;
    printf("enter the data : ");
    scanf("%d",&data);
    node *newnode = (node *)malloc(sizeof(node *));
    newnode -> data = data;
    if(head == NULL){
        head = newnode;
        newnode -> next = head;
        newnode -> prev = head;
    }else{
        printf("\n1.insertbegin\n2.insertend\nenter the choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            while(temp1 -> next != head){
                temp1 = temp1 -> next;
            }
            newnode -> next = head;
            temp1 -> next = newnode;
            newnode -> prev = temp1;
            head -> prev = newnode;
            head = newnode;
            break;
            case 2:
            while(temp1 -> next != head){
                temp1 = temp1 -> next;
            }
            temp1 -> next = newnode;
            head -> prev = newnode;
            newnode -> prev = temp1;
            newnode -> next = head;
            break;
        }
    }
}
void del(){
    int position,choice;
    temp1 = head;
    if(head -> next == NULL){
        head = NULL;
        free(head);
    }else{
        printf("\n1.deletebegin\n2.deleteend\nenter the choice : ");
        scanf("%d",&choice);
        switch(choice){
                case 1:
                while(temp1 -> next != head){
                    temp1 = temp1 -> next;
                }
                temp1 -> next = head -> next;
                head -> next -> prev = temp1;
                free(head);
                head = temp1 -> next;
                break;
                case 2:
                while(temp1 -> next -> next != head){
                    temp1 = temp1 -> next;
                }
                temp1 -> next = head;
                head -> prev = temp1;
                break;
        }
    }
}
void display(){
    temp1 = head;
    while(temp1 -> next != head){
        printf("%d--->",temp1 -> data);
        temp1 = temp1 -> next;
    }
    printf("%d",temp1 -> data);
}
void main(){
    int choice;
    while(1){
        printf("\n1.insert\n");
        printf("2.delete\n");
        printf("enter the choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            insert();
            display();
            break;
            case 2:
            del();
            display();
            break;
            case 3:
            exit(0);
        }
    }
}