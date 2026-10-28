#include <stdio.h>

#define LEN 16
int a[LEN] = { 12, 5, 8, 3, 15, 1, 9, 6, 14, 2, 11, 7, 4, 16, 10, 13 };

void swap(int x, int y)
{
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}

int partition(int start, int end)
{
    int pivot = a[start], x = start, y = end; 
    while (y > x)
    {  
        while (y > x && a[y] >= pivot)
            y--;        
        while (y > x && a[x] <= pivot)
            x++;        

        if (y > x)
            swap(x, y);     
    }
    swap(start, x);     
    return x;
}

void quicksort(int start, int end)
{
    if (start < end)
    {
        int mid = partition(start, end);
        quicksort(start, mid - 1);
        quicksort(mid + 1, end);
    }
}

int main(void)
{
    quicksort(0, LEN - 1);
    for (int i = 0; i < LEN; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}