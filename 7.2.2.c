#include <stdio.h>
#include <stdlib.h>
struct rational
{
    int x,y;
};

struct rational_result
{
    int ok;
    struct rational g;
};

struct rational_result make_rational(int a,int b)
{
    int i=0;
    if(b==0)
        i=1;
    struct rational_result x={i,{a,b}};
    return x;
}

/*int numerator(struct rational a)
{
    return a.x;
}

int denominator(struct rational a)
{
    return a.y;
}*/

int gcd(int a,int b);

struct rational simplify(struct rational a)
{
    struct rational x;
    int gcdn;
    gcdn=gcd(a.x,a.y);
    x.x=a.x/gcdn;
    x.y=a.y/gcdn;
    return x;
}

double decimal(struct rational a)
{
    return (double)a.x/a.y;
}

//struct rational fraction(double a){}
//因为有损储存小数，无法实现

void print_rational(struct rational a)
{
    if(a.x==0)
        printf("0\n");
    else
    {
        if((a.x<0||a.y<0)&&!(a.x<0&&a.y<0))
            printf("-");
        printf("%d/%d\n",abs(a.x),abs(a.y));
        printf("%f\n",decimal(a));    
    }
}

struct rational add_rational(struct rational a,struct rational b)
{
    struct rational x={a.x*b.y+b.x*a.y,a.y*b.y};
    return simplify(x);
}

struct rational sub_rational(struct rational a,struct rational b)
{
    struct rational x={a.x*b.y-b.x*a.y,a.y*b.y};
    return simplify(x);
}

struct rational mul_rational(struct rational a,struct rational b)
{
    struct rational x={a.x*b.x,a.y*b.y};
    return simplify(x);
}

struct rational div_rational(struct rational a,struct rational b)
{
    struct rational x={a.x*b.y,a.y*b.x};
    return simplify(x);
}

int main()
{
	struct rational a,b;
    struct rational_result z1 = make_rational(1, 8),z2 = make_rational(-1, 8);
    if(z1.ok==1||z2.ok==1)
    {
        printf("wrong");
        return 1;
    }
    else
    {
        a=z1.g;
        b=z2.g;    
    }
	print_rational(add_rational(a, b));
	print_rational(sub_rational(a, b));
	print_rational(mul_rational(a, b));
	print_rational(div_rational(a, b));
	return 0;
}

int gcd(int x,int y)
{
    int a=abs(x),b=abs(y);
    while(1)
    {
        if(a%b==0)
        {
            return b;
        }
        else
        {
            int x=a,y=b;
            a=y;
            b=x%y;
        }
    }
}