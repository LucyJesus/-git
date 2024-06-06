#include <stdio.h>
#include <math.h>
float f(float x)
{
    return x*x+2*x+1;
}


float Integrate_1(float (*f)(float), float a, float b, int D)//復化矩形
{
    float I_1 = 0, p = a+(a+b)/(2*D);//取中点
    int i;
    for(i=1;i<D;i++)
        I_1 += f((p));
        p += (a+b)/D;
    I_1 *= (a+b)/D;
    return I_1;
}

float Integrate_2(float (*f)(float), float a, float b, int D)//復化simpson
{
    float I_2 = 0, p = a+(a+b)/D,q = a;
    int i;
    for(i=1;i<D;i++)
        I_2 += (f(q)+4*f((q+p)/2)+f(p))/6;
        q += (a+b)/D;
        p += (a+b)/D;
    I_2 *= (a+b)/D;
    return I_2;
}
int main()
{
    float a,b;
    int D;
    printf("积分上下限,划分:");
    scanf("%f/%f/%d",&b,&a,&D);
    float a_1 = Integrate_1(f,a,b,D),a_2 = Integrate_2(f,a,b,D);
    printf("积分1为%f/n积分2为%f",a_1,a_2);
    return 0;
}