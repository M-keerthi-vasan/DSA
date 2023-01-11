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
        newnode -> next = NULL;
        head = newnode;
    }else{
        printf("\n1.insertbegin\n2.insertend\n3.insertposition\nenter the choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            newnode -> next = head;
            head = newnode;
            break;
            case 2:
            while(temp -> next != NULL)
                temp = temp -> next;
            newnode -> next = NULL;
            temp -> next = newnode;
            break;
            case 3:
            printf("enter the position : ");
            scanf("%d",&position);
            for(int i = 1;i < position-1;i++){
                temp = temp -> next;
            }
            newnode -> next = temp -> next;
            temp -> next = newnode;
            break;  
        }
    }
}
void del(){
    temp = head;
    int position,choice;
    printf("\n1.deletebegin\n2.deleteend\n3.deleteposition\nenter the choice : ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        head = temp -> next;
        free(temp);
        break;
        case 2:
        while(temp->next->next != NULL){
            temp = temp -> next;
        }
        temp -> next = NULL;
        break;
        case 3:
        printf("enter position to delete : ");
        scanf("%d",&position);
        for(int i=1;i<position;i++)
            temp2 = temp;
            temp = temp -> next;
        temp2 -> next = temp -> next;
        free(temp);
        break;
    }
}
void display(){
    temp = head;
    while(temp != NULL){
        printf("%d---->",temp -> data);
        temp = temp -> next;
    }
    printf("NULL");
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