#include <stdio.h>
#define N 5

int a[N] = { 5, 2, 3, 4, 1};

void insertion_sort(int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (a[j] > a[i])
            {
                int temp = a[j];
                a[j] = a[i];
                for (int k = j+1, temp1; k <= i; k++)
                {
                    temp1 = a[k];
                    a[k] = temp;
                    temp = temp1;
                }
                break;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    return;
}

int main()
{
    insertion_sort(N);
}

