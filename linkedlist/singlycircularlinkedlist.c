#include "stdio.h"
#include "stdlib.h"
typedef struct node{
    int data;
    struct node *next;
}node;
node *head = NULL,*temp,*temp2;
void insert(){
    temp = head;
    int data,choice,position;
    printf("enter the data : ");
    scanf("%d",&data);
    node *newnode = (node *)malloc(sizeof(node *));
    newnode -> data = data;
    if(head == NULL){
        head = newnode;
        newnode -> next = head;
    }else{
        printf("\n1.insertbegin\n2.insertend\nenter the choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            while(temp->next!=head){
                temp =temp -> next;
            }
            newnode -> next = head;
            temp -> next = newnode;
            head = newnode;
            break;
            case 2:
            while(temp -> next != head)
                temp = temp -> next;
            newnode -> next = head;
            temp -> next = newnode;
            break;  
        }
    }
}
void del(){
    temp = head;
    int position,choice;
    if(head->next == head){
        head = NULL;
        free(head);
    }else{
        printf("\n1.deletebegin\n2.deleteend\nenter the choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            while(temp -> next != head){
                temp = temp -> next;
            }
            temp -> next = head -> next;
            free(head);
            head = temp-> next;
            break;
            case 2:
            while(temp->next->next != head){
                temp = temp -> next;
            }
            temp -> next = head;
            break;
        }
    }
}
void display(){
    temp = head;
    while(temp->next!=head){
        printf("%d---->",temp -> data);
        temp = temp -> next;
    }
    printf("%d",temp -> data);
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