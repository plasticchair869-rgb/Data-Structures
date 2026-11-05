// LAB 7: SPARSE MATRIX USING DOUBLE LINKED LIST
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int row,col,data;
    struct node *next;
    struct node *prev;
};
typedef struct node *NODE;
NODE insertEnd(NODE start,int row, int col,int item)
{
    NODE temp,curr;
    temp=(NODE)malloc(sizeof(struct node));
    temp->row=row;
    temp->col=col;
    temp->data=item;
    temp->prev=NULL;
    temp->next=NULL;
    if(start==NULL)
        return temp;
    curr=start;
    while(curr->next!=NULL)
        curr=curr->next;
    curr->next=temp;
    temp->prev=curr;
    return start;
}
void display(NODE start)
{
    NODE temp;
    if(start==NULL)
        printf("\n LIST IS EMPTY ");
    else
    {
        printf("\nROW\tCOLUMN\tDATA\n");
        temp=start;
        while(temp!=NULL)
        {
            printf("%d\t%d\t%d\n",temp->row,temp->col,temp->data);
            temp=temp->next;
        }
    }
}
void displayMatrix(NODE start,int m,int n)
{
    NODE temp=start;
    int i,j;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(temp!=NULL && temp->row==i && temp->col==j)
            {
                printf("%d\t",temp->data);
                temp=temp->next;
            }

            else
                printf("0\t");
        }
        printf("\n");
    }
}
int main()
{
    NODE start=NULL;
    int m,n,i,j,item;
    printf("\n READ ORDER OF MATRIX: ");
    scanf("%d%d",&m,&n);
    printf("\n READ ELEMENTS: ");
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&item);
            if(item!=0)
                start=insertEnd(start,i,j,item);

        }
    }
    display(start);
    printf("\n SPARSE MATRIX IS \n");
    displayMatrix(start,m,n);
    return 0;
}
