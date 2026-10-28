#include <stdio.h>

/*3、编写一个函数double mypow(double x, int n);
求x的n次方，参数n是正整数。最简单的算法是：
double product = 1;
for (i = 0; i < n; i++)
	product *= x;
这个算法的时间复杂度是Θ(n)。
其实有更好的办法，比如mypow(x, 8)，
第一次循环算出x·x=x2，第二次循环算出x2·x2=x4，
第三次循环算出4·x4=x8。这样只需要三次循环，
时间复杂度是Θ(lgn)。思考一下如果n不是2的整数次幂应该怎么处理。
请分别用递归和循环实现这个算法。*/

double mypow(double x, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
}


int main()
{
    printf("%f", mypow(3.1415, 7, 1, 3.1415));
}
