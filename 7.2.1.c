#include <stdio.h>
#include <math.h>
struct complex_struct {
	double x, y;
};

double real_part(struct complex_struct z)
{
	return z.x;
}

double img_part(struct complex_struct z)
{
	return z.y;
}

double magnitude(struct complex_struct z)
{
	return sqrt(z.x * z.x + z.y * z.y);
}

double angle(struct complex_struct z)
{
	return atan2(z.y, z.x);
}

struct complex_struct make_from_real_img(double x, double y)
{
	struct complex_struct z;
	z.x = x;
	z.y = y;
	return z;
}

struct complex_struct make_from_mag_ang(double r, double A)
{
	struct complex_struct z;
	z.x = r * cos(A);
	z.y = r * sin(A);
	return z;
}

struct complex_struct add_complex(struct complex_struct z1, struct complex_struct z2)
{
	return make_from_real_img(real_part(z1) + real_part(z2),
				  img_part(z1) + img_part(z2));
}

struct complex_struct sub_complex(struct complex_struct z1, struct complex_struct z2)
{
	return make_from_real_img(real_part(z1) - real_part(z2),
				  img_part(z1) - img_part(z2));
}

struct complex_struct mul_complex(struct complex_struct z1, struct complex_struct z2)
{
	return make_from_mag_ang(magnitude(z1) * magnitude(z2),
				 angle(z1) + angle(z2));
}

struct complex_struct div_complex(struct complex_struct z1, struct complex_struct z2)
{
	return make_from_mag_ang(magnitude(z1) / magnitude(z2),
				 angle(z1) - angle(z2));
}

struct complex_struct test(struct complex_struct z1, struct complex_struct z2)
{
    printf("%f\n",real_part(z1));
    printf("%f\n",img_part(z1));
    printf("%f\n",magnitude(z1));
    printf("%f\n",angle(z1));
    printf("%f\n%f\n",add_complex(z1,z2).x,add_complex(z1,z2).y);
    printf("%f\n%f\n",sub_complex(z1,z2).x,sub_complex(z1,z2).y);
    printf("%f\n%f\n",mul_complex(z1,z2).x,mul_complex(z1,z2).y);
    printf("%f\n%f\n",div_complex(z1,z2).x,div_complex(z1,z2).y);
    return z1;
}

int print(struct complex_struct z)
{
    if(real_part(z)==0&&img_part(z)==0)
    {
        printf("0");
        return 0;
    }
    if(real_part(z)==0)
    {
        printf("%f\n",img_part(z));
        return 0;
    }
    if(img_part(z)==0)
    {
        printf("%fi\n",real_part(z));
        return 0;
    }
    char c=0;
    if(img_part(z)>0)
    {
        c='+';
    }
    printf("%f%c%fi\n",real_part(z),c,img_part(z));
    return 0;
}

int main()
{
    double x=-123.0,y=-321.0,a=1,b=1;
    struct complex_struct z1=make_from_real_img(x,b),z2=make_from_real_img(a,y);
    print(z1);
    print(z2);
    test(z1,z2);
    printf("（%f，%f）",test(z1,z2).x,test(z1,z2).y);
    return 0;
}
