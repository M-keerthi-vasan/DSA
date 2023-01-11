#include "stdio.h"
#include "stdlib.h"
#define COUNT 10
struct tree{
    int data;
    struct tree *lchild,*rchild;
};
struct tree *create(int data){
    struct tree *newnode = (struct tree *)malloc(sizeof(struct tree));
    newnode -> data = data;
    newnode -> lchild = newnode -> rchild = NULL;
    return newnode;
}
struct tree *insert(struct tree *root,int data){
    if(root == NULL){
        return create(data);
    }else if(data > root -> data){
        root -> rchild = insert(root -> rchild,data);
    }else{
        root -> lchild = insert(root -> lchild,data);
    }
    return root;
}
struct tree *findmin(struct tree *root){
    if(root -> lchild != NULL){
        return findmin(root -> lchild);
    }else{
        return root;
    }
}
struct tree *findmax(struct tree *root){
    if(root -> rchild != NULL){
        return findmax(root -> rchild);
    }else{
        return root;
    }
}
struct tree *delete(struct tree *root,int data){
    if(data > root -> data){
        root -> rchild = delete(root -> rchild,data);
    }else if(data < root -> data){
        root -> lchild = delete(root -> lchild,data);
    }else{
        if(root -> lchild == NULL && root -> rchild == NULL){
            free(root);
            root = NULL;
        }else if(root -> lchild == NULL || root -> rchild == NULL){
            struct tree *temp;
            if(root -> rchild == NULL){
                temp = root -> lchild;
            }else if(root -> lchild == NULL){
                temp = root -> rchild;
            }
            free(root);
            return temp;
        }else{
            struct tree *temp = findmin(root -> rchild);
            root -> data = temp -> data;
            root -> rchild = delete(root -> rchild,temp -> data);
        }
    }
    return root;
}
void printtree(struct tree *root,int space){
    if(root == NULL){
        return;
    }
    space = space + COUNT;
    printtree(root -> rchild,space);
    for(int i = COUNT;i < space;i++){
        printf(" ");
    }
    printf("%d\n",root->data);
    printtree(root -> lchild,space);
}
void main(){
    int data,choice;
    struct tree *root = NULL;
    struct tree *temp;
    while(1){
        printf("\n1.insert\n");
        printf("\n2.delete\n");
        printf("\n3.find minimum\n");
        printf("4.find maximum\n");
        printf("enter the choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("enter the data : ");
            scanf("%d",&data);
            root = insert(root,data);
            break;
            case 2:
            if(root == NULL){
                printf("Tree is empty\n");
            }else{
                printf("enter the data : ");
                scanf("%d",&data);
                root = delete(root,data);
            }
            break;
            case 3:
            if(root == NULL){
                printf("Tree is empty\n");
            }else{
                temp = findmin(root);
                printf("The minimum element present in the tree is %d\n",temp -> data);
            }
            break;
            case 4:
            if(root == NULL){
                printf("Tree is empty\n");
            }else{
                temp = findmax(root);
                printf("The maximum element present in the root is %d\n",temp -> data);
            }
            break;
            case 5:
            printtree(root,0);
            break;
            case 6:
            exit(0);
        }
    }
}