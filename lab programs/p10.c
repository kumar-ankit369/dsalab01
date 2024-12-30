#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
};
struct node *createnode(int data){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
struct node *insertnode(struct node *root,int data){
    struct node *newnode;
    if(root==NULL){
        newnode=createnode(data);
        root=newnode;
        return root;
    }
    if(root->data>data){
        root->left=insertnode(root->left,data);
    }
    if(root->data<data){
        root->right=insertnode(root->right,data);
    }
    return root;
}
int inorder(struct node *root){
    if(root==NULL){
        return 0;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
int preorder(struct node *root){
    if(root==NULL){
        return 0;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
int postorder(struct node*root){
    if(root==NULL){
        return 0;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
int searchnode(struct node *root,int key){
    if(root==NULL){
        return 0;
    }
    if(root->data==key){
        return 1;
    }
    if(root->data>key){
        return searchnode(root->left,key);
    }
    if(root->data<key){
        return searchnode(root->right,key);
    }
}
int main(){
    printf("Atul Raj\nUSN-1AY23CS045");
    int choice,n,i,val,key,result;
    char ch;
    struct node *root=NULL;
    while(1){
        printf("\n1.Create BST\n2.Traverse  BST(Inorder/preorder/postorder\n3.Search KEY\n4.Exit)");
        printf("enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("enter number of elements : ");
                    scanf("%d",&n);
                    for(i=1;i<=n;i++){
                        printf("\nenter element %d: ",i);
                        scanf("%d",&val);
                        root=insertnode(root,val);
                    }
                    break;
            case 2: printf("\ninorder: ");
                    inorder(root);
                    printf("\npreorder: ");
                    preorder(root);
                    printf("\npostorder: ");
                    postorder(root);
                    break;
            case 3: printf("\nenter key to search : ");
                    scanf("%d",&key);
                    result=searchnode(root,key);
                    if(result==0){
                        printf("\nkey not found");
                    }
                    else{
                        printf("\nkey found");
                    }
                    break;
            case 4: exit(0);
            default: printf("\nInvalid choice");
        }
    }
}