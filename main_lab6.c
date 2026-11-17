// LAB 6: MULTIPLY 2 POLYNOMIALS USING SINGLE LINKED LIST
#include <stdio.h>
#include <stdlib.h>
struct node // structure definition
{
    int co,po;
    struct node *addr;
};
typedef struct node *NODE; // macro
NODE insertEnd(NODE start, int co, int po) // insert function at the end of the list
{
    NODE temp,curr;
    temp=(NODE)malloc(sizeof(struct node));
    temp->co=co;
    temp->po=po;
    temp->addr=NULL;
    if(start==NULL)
        return temp;
    curr=start;
    while(curr->addr!=NULL)
        curr=curr->addr;
    curr->addr=temp;
    return start;
}
void display(NODE start) // function to display the polynomial
{
    NODE temp;
    if(start==NULL)
        printf("\n POLYNOMIAL IS EMPTY");
    else
    {
        temp=start;
        while(temp->addr!=NULL)
        {
            printf("%d*x^%d+",temp->co,temp->po);
            temp=temp->addr;
        }
    printf("%d*x^%d\n",temp->co,temp->po);
    }
}
NODE addTerm(NODE res,int co,int po) // function to add the polynomials together
{
    NODE curr=res;
    while(curr!=NULL)
    {
        if(curr->po==po)
        {
            curr->co+=co;
            return res;
        }
        curr=curr->addr;
    }
    return insertEnd(res,co,po);
}
NODE multiply(NODE poly1,NODE poly2) // function to multiply the 2 polynomials
{
    NODE p1,p2,res=NULL;
    for(p1=poly1 ; p1!=NULL ; p1=p1->addr)
    {
        for(p2=poly2 ; p2!=NULL ; p2=p2->addr)
        {
            res=addTerm(res,p1->co*p2->co,p1->po+p2->po);
        }
    }
    return res;
}
int main() // main function
{
    NODE poly1=NULL,poly2=NULL,poly;
    int m,i,co,po;
    printf("\n READ NUMBER OF TERMS OF FIRST POLYNOMIAL: ");
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        printf("\n READ COEFFICENT & POWER FOR %d TERM: ",i);
        scanf("%d%d",&co,&po);
        poly1=insertEnd(poly1,co,po);
    }
     printf("\n 1ST POLYNOMIAL: \n");
     display(poly1);

    printf("\n READ NUMBER OF TERMS OF SECOND POLYNOMIAL: ");
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        printf("\n READ COEFFICENT & POWER FOR %d TERM: ",i);
        scanf("%d%d",&co,&po);
        poly2=insertEnd(poly2,co,po);
    }
     printf("\n 2ND POLYNOMIAL: \n");
     display(poly2);
     poly=multiply(poly1,poly2);
     printf("\n RESULTANT POLYNOMIAL IS: ");
     display(poly);
    return 0;
}
