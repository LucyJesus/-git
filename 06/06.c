#include <stdio.h>
#define m 4
#define n 3
#define p 4
int main()
{
    int a[m][n]={1,2,3,4,5,6,7,8,9,10,11,12},b[n][p]={1,2,3,4,5,6,7,8,9,10,11,12},c[m][p]={0},i,j,k,o,q;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            for(k=0;k<p;k++)
                c[i][k]+=a[i][j]*b[j][k];

    for(o=0;o<m;o++)
        for(q=0;q<p;q++)
            printf("%d\n",c[o][q]);
    return 0;
}