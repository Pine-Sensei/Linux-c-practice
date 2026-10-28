#include <stdio.h>
#define LEN 16
int a[LEN] = { 12, 5, 8, 3, 15, 1, 9, -6, 14, 2, 11, 7, 4, 16, 10, 13 };

int main()
{
    int min = a[0];
    for (int i = 0; i < LEN; i++)
    {
        if (a[i] <= min)
            min = a[i];
    }
    printf("%d", min);
}