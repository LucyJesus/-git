#include <stdio.h>

int main()
{
    int a[4]={0,1,2,3};
    int* b = &a;
    printf("%d\t%d\n",b,&a[0]);
    int b = 2;
    printf("%d",b);
    return 0;
}