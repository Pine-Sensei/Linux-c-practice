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
    return;
}

int main()
{
    insertion_sort(N);
    for(int i = 0; i < N; i++)
    {
        printf("%d\t", a[i]);
    }
}

/*
void insertion_sort(void)
{
	int i, j, key;
	for (j = 1; j < LEN; j++) {
		key = a[j];
		i = j - 1;
		while (i >= 0 && a[i] > key) {
			a[i+1] = a[i];
			i--;
		}
		a[i+1] = key;
	}
}


void insertion_sort(int a[], int n)
{
    if (n <= 1)
    {
        return;
    }
    insertion_sort(a, n - 1);
    int key = a[n - 1];
    int j = n - 2;

    while (j >= 0 && a[j] > key)
    {
        a[j + 1] = a[j];
        j--;
    }

    a[j + 1] = key;
}
*/