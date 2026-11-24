// LAB 9: PRIORITY QUEUE USING HEAP
#include <stdio.h>
#include <stdlib.h>

void heapify(int a[10], int n) // heap function definition
{
    int i, k, v, j, flag;
    for (i = n / 2; i >= 1; i--)
    {
        k = i;
        v = a[k];
        flag = 0;
        while (!flag && 2 * k <= n)
        {
            j = 2 * k;
            if (j < n)
            {
                if (a[j] < a[j + 1])
                    j = j + 1;
            }
            if (v >= a[j])
                flag = 1;
            else
            {
                a[k] = a[j];
                k = j;
            }
        }
        a[k] = v;
    }
}

int main() // main function
{
    int n = 0, a[10], i, ch;
    for (;;)
    {
        printf("\n 1.CREATE HEAP \n 2.EXTRACT MAX \n 3.EXIT \n");
        printf("\n READ CHOICE: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n READ NUMBER OF ELEMENTS: ");
            scanf("%d", &n);
            if (n < 1 || n > 9)
            {
                printf("\n INVALID SIZE");
                n = 0;
                break;
            }
            printf("\n READ ELEMENTS: ");
            for (i = 1; i <= n; i++)
                scanf("%d", &a[i]);
            heapify(a, n);
            printf("\n ELEMENTS AFTER CONSTRUCTING HEAP: ");
            for (i = 1; i <= n; i++)
                printf("%d\t", a[i]);
            break;
        case 2:
            if (n >= 1)
            {
                printf("\n ELEMENT DELETED IS %d ", a[1]);
                a[1] = a[n];
                n = n - 1;
                heapify(a, n);
                printf("\n HEAP AFTER DELETION: ");
                for (i = 1; i <= n; i++)
                    printf("%d\t", a[i]);
            }
            else
                printf("\n NO ELEMENTS TO DELETE");
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("INVALID CHOICE");
        }
    }
    return 0;
}
