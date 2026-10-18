#include <stdio.h>
#include <math.h>
enum coordinate_type { RECTANGULAR, POLAR };
struct complex_struct {
	enum coordinate_type t;
	double a, b;
};

struct complex_struct make_from_real_img(double x, double y)
{
	struct complex_struct z;
	z.t = RECTANGULAR;
	z.a = x;
	z.b = y;
	return z;
}

struct complex_struct make_from_mag_ang(double r, double A)
{
	struct complex_struct z;
	z.t = POLAR;
	z.a = r;
	z.b = A;
	return z;
}

struct complex_struct transform(struct complex_struct z)
{
    if(z.t==0)
    {
        return make_from_mag_ang(sqrt(z.a * z.a + z.b * z.b),atan2(z.b, z.a));
    }
    else
    {
        return make_from_real_img(z.a*cos(z.b),z.a*sin(z.b));
    }
}

double real_part(struct complex_struct z)
{
    if(z.t==0)
	    return z.a;
    else
    {
        return transform(z).a;
    }
}

double img_part(struct complex_struct z)
{
    if(z.t==0)
	    return z.b;
    else
    {
        return transform(z).b;
    }
}

double magnitude(struct complex_struct z)
{
    if(z.t==1)
	    return z.a;
    else
        return magnitude(transform(z));
}

double angle(struct complex_struct z)
{
    if(z.t==1)
	    return z.b;
    else
        return angle(transform(z));
}

struct complex_struct output(enum coordinate_type method,struct complex_struct z)
{
    if(method==z.t)
        return z;
    else
        return transform(z);
}

struct complex_struct add_complex(enum coordinate_type method,struct complex_struct z1, struct complex_struct z2)
{
	return output(method,make_from_real_img(real_part(z1) + real_part(z2),
				  img_part(z1) + img_part(z2)));
}

struct complex_struct sub_complex(enum coordinate_type method,struct complex_struct z1, struct complex_struct z2)
{
	return output(method,make_from_real_img(real_part(z1) - real_part(z2),
				  img_part(z1) - img_part(z2)));
}

struct complex_struct mul_complex(enum coordinate_type method,struct complex_struct z1, struct complex_struct z2)
{
	return output(method,make_from_mag_ang(magnitude(z1) * magnitude(z2),
				 angle(z1) + angle(z2)));
}

struct complex_struct div_complex(enum coordinate_type method,struct complex_struct z1, struct complex_struct z2)
{
	return output(method,make_from_mag_ang(magnitude(z1) / magnitude(z2),
				 angle(z1) - angle(z2)));
}

struct complex_struct test(struct complex_struct z1, struct complex_struct z2)
{
    printf("%f\n",real_part(z1));
    printf("%f\n",img_part(z1));
    printf("%f\n",magnitude(z1));
    printf("%f\n",angle(z1));
    printf("RECTANGULAR：\n");
    printf("%f,%f\n",add_complex(0,z1,z2).a,add_complex(0,z1,z2).b);
    printf("%f,%f\n",sub_complex(0,z1,z2).a,sub_complex(0,z1,z2).b);
    printf("%f,%f\n",mul_complex(0,z1,z2).a,mul_complex(0,z1,z2).b);
    printf("%f,%f\n",div_complex(0,z1,z2).a,div_complex(0,z1,z2).b);
    printf("POLAR：\n");
    printf("%f,%f\n",add_complex(1,z1,z2).a,add_complex(1,z1,z2).b);
    printf("%f,%f\n",sub_complex(1,z1,z2).a,sub_complex(1,z1,z2).b);
    printf("%f,%f\n",mul_complex(1,z1,z2).a,mul_complex(1,z1,z2).b);
    printf("%f,%f\n",div_complex(1,z1,z2).a,div_complex(1,z1,z2).b);
    return z1;
}

int print(enum coordinate_type method,struct complex_struct z)
{
    struct complex_struct x;
    x=output(method,z);
    if(method==0)
    {
    if(real_part(x)==0&&img_part(x)==0)
    {
        printf("0");
        return 0;
    }
    if(real_part(x)==0)
    {
        printf("%fi\n",img_part(x));
        return 0;
    }
    if(img_part(x)==0)
    {
        printf("%f\n",real_part(x));
        return 0;
    }
    printf("%f%+fi\n",real_part(x),img_part(x));

    return 0;
    }

    else
    {
        printf("(%f, %f)",x.a,x.b);
        return 0;
    }
}

int main()
{
    double x=-123.0,y=-321.0,a=1,b=1;
    struct complex_struct z1=make_from_real_img(x,b),z2=make_from_real_img(a,y);
    print(0,z1);
    print(1,z2);
    printf("（%f，%f）",test(z1,z2).a,test(z1,z2).b);
    return 0;
}
