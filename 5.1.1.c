#include <stdio.h>
/*1、编写一个布尔函数int is_leap_year(int year)，
判断参数year是不是闰年。如果某年份能被4整除，
但不能被100整除，那么这一年就是闰年，
此外，能被400整除的年份也是闰年。*/
int main()
{
    int is_leap_year(int year);
    int x=is_leap_year(2342);
    if(x==1)
    {
        printf("leap year");
    }
    else
    {
        printf("not leap year");
    }
    return 0;
}
int is_leap_year(int year)
{
    return ((year%4==0&&year%100!=0)||year%400==0);
}