#include <stdio.h>
#include <math.h>
/*2、编写一个函数double myround(double x)，
输入一个小数，将它四舍五入。
例如myround(-3.51)的值是-4.0，myround(4.49)的值是4.0。
可以调用math.h中的库函数ceil和floor实现这个函数。*/
int main()
{
    int myround(double x);
    int fn=myround(3.1415926);
    printf("%d",fn);
    return 0;
}
int myround(double x)
{
    if(x-floor(x)>=0.5)
        return ceil(x);
    else
        return floor(x);
}