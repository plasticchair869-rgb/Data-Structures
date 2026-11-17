// LAB 8: DEMONSTRATING BINARY SEARCH TREE
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node *NODE;

NODE createBST(NODE root, int item)
{
    NODE temp, cur, prev;
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;

    if(root == NULL)
        return temp;

    prev = NULL;
    cur = root;

    while(cur != NULL)
    {
        prev = cur;
        if(item < cur->data)
            cur = cur->left;
        else
            cur = cur->right;
    }

    if(item < prev->data)
        prev->left = temp;
    else
        prev->right = temp;

    return root;
}

void preOrder(NODE root)
{
    if(root != NULL)
    {
        printf("%d\t", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(NODE root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("%d\t", root->data);
        inOrder(root->right);
    }
}

void postOrder(NODE root)
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d\t", root->data);
    }
}

int main()
{
    NODE root = NULL;
    int ch, item;

    for(;;)
    {
        printf("\n 1. INSERT \n 2. PREORDER \n 3. INORDER \n 4. POSTORDER \n 5. EXIT");
        printf("\n READ CHOICE: ");
        scanf("%d", &ch);

        switch(ch)
        {
        case 1:
            printf("\n READ ELEMENT TO BE INSERTED: ");
            scanf("%d", &item);
            root = createBST(root, item);
            break;
        case 2:
            printf("\n PREORDER: \n");
            preOrder(root);
            printf("\n");
            break;
        case 3:
            printf("\n INORDER: \n");
            inOrder(root);
            printf("\n");
            break;
        case 4:
            printf("\n POSTORDER: \n");
            postOrder(root);
            printf("\n");
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("INVALID CHOICE\n");
        }
    }
    return 0;
}
