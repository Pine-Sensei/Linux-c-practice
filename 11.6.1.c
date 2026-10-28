#include <stdio.h>
#define LEN 4

int a[LEN] = {1, 2, 3, 4};

int binarysearch(int number)
{
    int start = 0, end = LEN - 1, mid, temp = -1;
    while (start <= end)
    {
        mid = (end + start)/2;
        if (a[mid] == number)
        {
            temp = mid;
            end = mid - 1;
        }
        if (a[mid] > number)
            start = mid + 1;
	    else
            end = mid - 1; 
    }
    return temp;
}

int main()
{
    printf("%d\n", binarysearch(2));
}