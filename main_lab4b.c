// LAB 4B: SOLVING TOWER OF HANOI USING RECURSION
#include <stdio.h>
#include <stdlib.h>
void toh(int n,char source,char dest,char temp)
{
    if(n>1)
    {
        toh(n-1,source,temp,dest);
        printf("\n MOVE DISC %d FROM %c to %c ",n,source,dest);
        toh(n-1,temp,dest,source);
    }
    else
        printf("\n MOVE DISC %d FROM %c to %c ",n,source,dest);

}
int main()
{
    int n;
    printf("\n READ NUMBER OF DISC: ");
    scanf("%d",&n);
    toh(n,'S','D','T');
    return 0;
}
