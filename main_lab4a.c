// LAB 4A: EVALUATING A GIVEN EXPRESSION USING EUCLID'S ALGORITHM AKA GCD
#include<stdio.h>
#include<stdlib.h>
int gcd(int a,int b) // recusive gcd function
{
    if(b==0)
        return a;
    return gcd(b,a%b); // applying recursion and calling the function for evaluation
}
int main() // main function
{
    int a,b,res;
    printf("\n READ THE 2 NUMBERS \n ");
    scanf("%d%d",&a,&b);
    res=gcd(a,b);
    printf("\n GCD OF %d & %d IS %d ",a,b,res);
    return 0;
}
