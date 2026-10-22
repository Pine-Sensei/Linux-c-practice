#include <stdio.h>
#define N 5
#define M 3

int a[N] = { 1, 2, 3, 4, 5}, temp[M];

void swap(int x, int y)
{
    int tmp = a[x];
    a[x] = a[y];
    a[y] = tmp;
}

void permutation(int n, int now, int how)
{
    if (now == how)
    {
        for(int i = 0; i < how; i++)
        {
            printf("%d\t", a[i]);
        }
        printf("\n");
        return;
    }
    for(int i = now; i < n; i++)
    {
        swap(now, i);
        permutation(n, now+1, how);
        swap(now, i);
    }
}

void combination(int n, int where, int now, int how)
{
    if (now == how)
    {
        for (int i = 0; i < how; i++)
        {
            printf("%d\t", temp[i]);
        }
        printf("\n");
        return;
    }
    for (int i = where, j = 0; i < n; i++, j++)
    {
        temp[now] = a[i];
        combination(n, i + 1,now + 1,how);
    }
}

int main()
{
    permutation(N, 0, M);
    printf("*********************\n");
    combination(N, 0, 0, M);
}
