#include <stdio.h>
#include <stdlib.h>
#define A 10000
#define f 233   //查找a[f-1]也就是第f个数据
void Generate(int a[])  //生成数组   
{
    int i;  //此处曾经有行定义a[],这会导致主函数只能使用相应的名称的数组,无法使用b[]作为数组名
    for(i=0;i<A;i++)
        a[i]=rand();
}

int Rank (int a[]){    //冒泡排序
    int j,k,t;
    for(k=1;k<A;k++)
        for(j=0;j<A;j++)
            if(a[j]<a[j+1])
                {
                    t = a[j];
                    a[j] = a[j+1];
                    a[j+1] = t;
                }
    return a[A];
}

int main()
{
    int b[A],m;
    Generate(b);
    Rank(b);
    printf("数组从大到小排序\n");
    for(m=0;m<A;m++)
        printf("%d\n",b[m]);
    int *z = &b[f-1];
    printf("第%d个元素是%d,地址是%d",f,b[f-1],*z);
    return 0;
}