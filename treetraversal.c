#include <stdio.h>
#include <stdlib.h>
struct tree
{
    int data;
    struct tree* left;
    struct tree* right;
};

struct tree* create()
{
    struct tree* temp;
    temp = (struct tree*)malloc(sizeof(struct tree));
    temp->left=temp->right=NULL;
    return temp;
}

void prorder(struct tree* temp)
{
    printf("%d ",temp->data);
    if(temp->left!=NULL)
    {
        prorder(temp->left);
    }
    if(temp->right!=NULL)
    {
        prorder(temp->right);
    }
}

void inorder(struct tree* temp)
{
    if(temp->left!=NULL)
    {
        inorder(temp->left);
    }
    printf("%d ",temp->data);
    if(temp->right!=NULL)
    {
        inorder(temp->right);
    }
    
}

void posorder(struct tree* temp)
{
    if(temp->left!=NULL)
    {
        posorder(temp->left);
        posorder(temp->right);
    }
    printf("%d ",temp->data);
}

int isleaf(struct tree* node)
{
    
    
}





int main(int argc, const char * argv[]) {
    // insert code here...
    struct tree* current;
    struct tree* root;
    root=create();
    current = create();
    root=current;
    current->data=5;
    
    current = create();
    current->data=2;
    root->left = current;
    
    current=create();
    current->data=12;
    root->right=current;
    
    current=create();
    current->data = -4;
    root->left->left=current;
    
    current=create();
    current->data= 3;
    root->left->right=current;
    
    current=create();
    current->data=9;
    root->right->left=current;
    
    current=create();
    current->data=21;
    root->right->right=current;
    
    current=create();
    current->data=19;
    root->right->right->left=current;
    
    current=create();
    current->data=25;
    root->right->right->right=current;
    
    prorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    posorder(root);
    return 0;
}
