#include <stdio.h>
#include <math.h>

float f(float x)
{
    return sin(x);
}

float Integrate_1(float a, float b, int D)//復化矩形
{
    float I_1 = 0, p = a+(b-a)/(2*D);//取中点
    int i;
    for(i=1;i<=D;i++){
        I_1 += f(p);
        p += (b-a)/D;
    }
    I_1 *= (b-a)/D;
    return I_1;
}

float Integrate_2(float a, float b, int D) //simpson
{
    float I_2 = 0,p = a,q = a + (b-a)/D; 
    int i;
    for(i=1;i<=D;i++){
        I_2 += (f(p)+f(q)+4*(f((p+q)/2)));
        p += (b-a)/D;
        q += (b-a)/D;
    }
    I_2 *= (b-a)/(6*D);
    return I_2;
}

int main()
{
    float a,b,f;
    int D[7] = {16,32,64,128,256,512,1024},j;
    printf("积分上下限:");
    scanf("%f %f",&b,&a);
    if(a>b){
        printf("上下限错误,可能是写反了");
    }
    else{
        for(j = 0;j < 7; j++){
            float a_1 = Integrate_1(a,b,D[j]),a_2 = Integrate_2(a,b,D[j]);
            printf("%d划分下积分1为%.9f\t积分2为%.9f\n",D[j],a_1,a_2);
        }    
    }
    return 0;
}