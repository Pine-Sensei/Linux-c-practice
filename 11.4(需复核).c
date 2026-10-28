#include <stdio.h>

#define LEN 4
int a[LEN] = {1, 3, 2, 6 };

int partition(int start, int end)
{
    int pivot = a[start], j = 0;
    for (int i = start + 1, temp; i != end - j; i++)
    {
        if (a[i] < pivot)
        {
            a[i-1] = a[i];
            continue;
        }
        int k = 1;
        while (k == 1)
        {
            temp = a[end-j];
            a[end-j] = a[i];
            a[i] = temp;
            j++;
            if (a[i] < pivot)
                k = 0;
        }
    }
    a[end-j-1] = pivot;
	return end-j-1;
}

void quicksort(int start, int end)
{
	int mid;
	if (end > start) {
		mid = partition(start, end);
		quicksort(start, mid-1);
		quicksort(mid+1, end);
	}
} 

int main(void)
{
	quicksort(0, LEN-1);
    for(int i = 0; i < LEN; i++)
    {
        printf("%d\t", a[i]);
    }
	return 0;
}