// LAB 3: EVALUATING A GIVEN POSTFIX EXPRESSION
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 20 //macro
struct stack // structure definition
{
    int top;
    float data[SIZE];
};
typedef struct stack STACK;
void push(STACK *s,float item)// push function
{
    s->data[++(s->top)]=item;
}
float pop(STACK *s)//pop function
{
    return s->data[(s->top)--];
}
float compute(float op1,char symbol,float op2)// computational part
{
    switch(symbol)
    {
    case'+':
        return op1+op2;
    case '-':
        return op1-op2;
    case '*':
        return op1*op2;
    case '/':
        return op1/op2;
    case '^':
        return pow(op1,op2);
    }
}
float evalPostfix(STACK *s,char postfix[15]) // main c function for the program
{
    char symbol;
    int i;
    float op1,op2,res;
    for(i=0;postfix[i]!='\0';i++)
    {
        symbol=postfix[i];
        if(isdigit(symbol))
            push(s,symbol-'0');
        else
        {
            op2=pop(s);
            op1=pop(s);
            res=compute(op1,symbol,op2);
            push(s,res);
        }
    }
    return pop(s);
}
int main()
{
    char postfix[15];
    float res;
    STACK s;
    s.top=-1;
    printf("\n READ POSTFIX: \n");
    scanf("%s",postfix);
    res=evalPostfix(&s,postfix);
    printf("\n FINAL ANSWER IS: %f",res);
    return 0;
}
