#include <stdio.h>
#define LEN 4

int a[LEN] = {1, 2, 3, 4};

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

int order_statistic(int start, int end, int k)
{
	int i = partition(start, end);
	if (k == i)
		return a[i];
	else if (k > i)
		return order_statistic(i + 1, end, k);
	else
		return order_statistic(start, i - 1, k);
}

int main()
{
    printf("%d\n", order_statistic(0, LEN - 1, 0));
}