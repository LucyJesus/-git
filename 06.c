#include <stdio.h>
#define m 4
#define n 3
#define p 4
int main()
{
    int a[m][n]={0,1,2,3,4,5,6,7,8,9,10,11},j,i,o,q;
    //for(i=0;i<m;i++)
      //  for(j=0;j<n;j++)
        //    a[i][j]=j;
    for(o=0;o<m;o++)
        for(q=0;q<n;q++)
            printf("%d\n",a[o][q]);
    return 0;
}