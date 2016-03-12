#include <stdio.h>
#include <stdlib.h>
int flag = 1;
struct tree
{
    int data;
    struct tree* left;
    struct tree* right;
}*root=NULL;

struct tree* create()
{
    struct tree* temp;
    temp = (struct tree*)malloc(sizeof(struct tree));
    temp->right = NULL;
    temp->left = NULL;
    if(root == NULL)
    {
        root = (struct tree*)malloc(sizeof(struct tree));
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else
    {
        return temp;
    }
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


int calculate(struct tree* node)
{
    
    int sum = 0;
    if(isleaf(node)==0)
    {
        if(node->right==NULL)
        {
            sum = node->left->data;
            sum = sum + calculate(node->left);
        }
        else if(node->left==NULL)
        {
            sum = node->right->data;
            sum = sum + calculate(node->right);
        }
        else
        {
            sum = sum + node->right->data + node->left->data;
            sum = sum + calculate(node->left);
            sum = sum + calculate(node->right);
        }
    }
    return sum;

}

void check(struct tree* node)
{
    if(isleaf(node)==0)
    {
        if(node->data == calculate(node))
        {
            if(node->left != NULL)
            {
                check(node->left);
            }
            if(node->right != NULL)
            {
                check(node->right);
            }
        }
        else
        {
            flag = 0;
        }
    }
}

void print(struct tree* node)
{
    printf("Printing %d ",node->data);
    if(isleaf(node)==0)
    {
        print(node->left);
        print(node->right);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    struct tree *current,*temp1,*temp2;
    current = create();
    current->data = 26;
    temp1 = create();
    temp2 = create();
    temp1->data = 10;
    temp2->data = 3;
    current->left = temp1;
    current->right = temp2;
    temp1 = create();
    temp2 = create();
    temp1->data = 4;
    temp2->data = 6;
    current->left->left = temp1;
    current->left->right = temp2;
    temp2=create();
    temp2->data = 3;
    current->right->right=temp2;
    check(current);
    printf("%d",flag);
    //print(current);
    return 0;
}
