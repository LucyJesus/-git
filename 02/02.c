#include <stdio.h>
#include <math.h>
#define A 1000
int C(int n){
    int l;
    for(l=2;l<=sqrt(n);l++){
        if(n%l==0)
            return 0; 
    }
    return 1;
    
}


int main()
{
    int a[A]={0},i=1,j,c,d,k,p,q;
    a[0]=2;
    a[1]=3;
    for(j=1;;j++){
        p=6*j-1;
        q=6*j+1;
        if(C(p))
            a[++i]=p;//若是使用i++则初始i应该赋值为2
        if(C(q))
            a[++i]=q;
        if(a[A-1]>0)
            break;
    }
    for(k=0;k<A;k++)
        printf("%d\t%d\n",k+1,a[k]);
    return 0;
}

