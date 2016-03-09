#include<stdio.h>
#include<stdlib.h>
int leftsum=0;
struct tree
{
    int data;
    struct tree* left;
    struct tree* right;
}*root=NULL,*current=NULL;

struct tree* create()
{
    struct tree* temp;
    temp = (struct tree*)malloc(sizeof(struct tree));
    temp->left = temp-> right = NULL;
    if(root == NULL)
    {
        root = (struct tree*)malloc(sizeof(struct tree));
        root->left = root->right = NULL;
        current = root;
        return root;

    }
    else
    {
        return temp;
    }
}

void construct(int lvalue,int rvalue)
{
    struct tree *temp1,*temp2;
    temp1 = create();
    temp2 = create();
    temp1->data = lvalue;
    temp2->data = rvalue;
    current->left = temp1;
    current->right = temp2;

}

int isleaf(struct tree* node)
{
    if((node->left == NULL) && (node->right == NULL))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void calculate(struct tree* node)
{
    if(isleaf(node->left))
    {
        leftsum = leftsum + node->left->data;
    }
    else
    {
        calculate(node->left);
        calculate(node->right);
    }

}

int main()
{
    struct tree* root;
    current = (struct tree*)malloc(sizeof(struct tree));
    root = create();
    root->data = 10;
    construct(20,30);
    current = root->left;
    construct(40,50);
    current = root->right;
    construct(60,70);
    calculate(root);
    printf("\n Sum of left leaves : %d",leftsum);
    return 0;
}
