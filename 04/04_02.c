#include <stdio.h>
#define d 100000
float f(float x){
    return 3*x*x*x-4*x*x-7*x-6;
}

float qie(float x){
    float t = 1.0/d, dif,p;
    dif = (f(x+t)-f(x))/t;//x处导数
    p = -f(x)/dif+x;//新的x点
    return p;
}
int main()
{
    int i;
    float a,b,c,e,w;
    printf("请输入某个区间和初值点");
    scanf("%f %f %f",&a,&b,&c);
    if(f(a)*f(b)>0){
        printf("该区间无零点");
    }
    else{
        e = qie(c);
        for(i = 1;;i++){
            e = qie(e);
            if(f(e)<1e-9)
                break;
        }
        printf("零点为%.9f",e);
    }
    return 0; 
}