// LAB 2: CONVERTING A GIVEN INFIX EXPRESSION TO POSTFIX USING STACK
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 20
struct stack
{
    int top;
    char data[SIZE];
};
typedef struct stack STACK;
void push(STACK *s, char item)
{
    s->data[++(s->top)]=item;
}
char pop(STACK *s)
{
    return s->data[(s->top)--];

}
int preced(char symbol)
{
    switch(symbol)
    {
        case '^': return 5;
        case '*':
        case '/': return 3;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}
void infixtopostfix(STACK *s, char infix[20])
{
    char postfix[30],symbol,temp;
    int i,j=0;
    for(i=0;infix[i]!='\0';i++)
    {
        symbol=infix[i];
        if(isalnum(symbol))
        {
            postfix[j++]=symbol;
        }
        else
        {
            switch(symbol)
            {
            case '(':
                push(s,symbol);
                break;
            case ')':
                temp=pop(s);
                while(temp!='(')
                {
                    postfix[j++]=temp;
                    temp=pop(s);
                }
                break;
            case'+':
            case'-':
            case'*':
            case'/':
            case'^':
                if(s->top==-1||s->data[s->top]=='(')
                {
                    push(s,symbol);

                }
                else
                {
                    while(s->top!=-1 && s->data[s->top]!='('&&preced(s->data[s->top]>=preced(symbol)))
                                                           {
                                                               postfix[j++]=pop(s);
                                                           }
                         push(s,symbol);
                }
                break;
            }
        }
    }
    while(s->top!=-1)
    {
        postfix[j++]=pop(s);
    }
    postfix[j]='\0';
    printf("\n POSTFIX EXPRESSION IS: %s\n",postfix);
}
int main()
{
    char infix[20];
    STACK s;
    s.top=-1;
    printf("\n READ INFIX: \n");
    scanf("%s",infix);
    infixtopostfix(&s,infix);
    return 0;
}
