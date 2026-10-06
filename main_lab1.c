// LAB 1: IMPLEMENT A STACK USING STRUCTURES AND POINTERS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
struct stack
   {
       int top;
       int data[SIZE];
   };
typedef struct stack STACK;
void push(STACK *s,int item)
   {
       if(s->top==SIZE-1)
            printf("\nOVERFLOW \n");
       else
        {
            s->top=s->top+1;
            s->data[s->top]=item;
       }
   }
void pop(STACK *s)
   {
       if(s->top==-1)
        printf("\nUNDERFLOW\n");
       else
       {
           printf("POPPED ELEMENT IS %d",s->data[s->top]);
           s->top=s->top-1;
       }
   }
   void display(STACK s)
   {
       int i;
       if(s.top==-1)
        printf("\nEMPTY STACK");
       else{
        printf("\nCONTENT OF STACK: \n");
        for(i=s.top;i>=0;i--)
            printf("%d\n", s.data[i]);
       }
   }
   int main()
   {
       int item,ch;
       STACK s;
       s.top=-1;
       for(;;)
       {
           printf("\n1. PUSH");
           printf("\n2. POP");
           printf("\n3. DISPLAY");
           printf("\n4. EXIT");
           printf("\n Read Choice:");
           scanf("%d",&ch);
           switch(ch)
           {
           case 1: printf("\nREAD ELEMENT TO BE PUSHED:");
            scanf("%d",&item);
            push(&s,item);
            break;
           case 2: pop(&s);
           break;
           case 3: display(s);
           break;
           default: exit(0);
           }
       }
   return 0;
  }
