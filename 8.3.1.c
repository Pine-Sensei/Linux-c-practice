#include <stdio.h>
#include <stdlib.h>
#define COUNT 100
#define NBR 5

int a[COUNT], histogram[NBR+1] = {0};

void gen_random(int count, int upper_bound)
{
	int i;
	for (i = 0; i < count; i++)
		a[i] = rand() % upper_bound;
}

void print(int n)
{
    for (int j = 0; j < n+1; j++)
    {
        printf("%d\t",j);
    }
    printf("\n\n");
    for (int i = 0, x = 1; x != 0; i++)
    {
        x = 0;
        for (int j = 0; j < n+1; j++)
        {
            if(histogram[j] >= i+1)
            {
                printf("*\t");
                x = 1;
            }
            else
            {
                printf("\t");
            }
            if(j == n)
            {
                printf("\n");
            }
        }
    }
}

int main(void)
{
	gen_random(COUNT,NBR+1);
	for (int i = 0; i < COUNT; i++)
		histogram[a[i]]++;
    //for (int i = 0; i < 10; i++)
	//	printf("%d\t%d\n", i, histogram[i]);
    print(NBR);
}









































/*
int n=9999,a[9999];

int main() 
{
    int print(int n);
    print(n);
}
int print(int n)
{
    for (int i=0 , x=1 ; x!=0 ; i++) {
        for (int j=0 ; j<=n ; j++) {
            x=0;
            if (i=0) {
                printf("%d\t", j);
                if (j=n)
                    printf("\n\n");
                x = 1;
            }
            if (i > 0) {
                if(i<=){

                }
            }
        }
    }
}*/