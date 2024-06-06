//5.约瑟夫环。班上有47人围成一圈，从你开始依次报数，报到某数M的人出列，最后只留下一个人。
//当M为何值时，最后是你自己留下来？

#include <stdio.h>
#define N 47
#define me 45

int main()
{
    int a[N],i,start = me,m,p = start;
    for(i=0;i<N;i++){
        a[i]=1;
        printf("%d\n",a[i]);
    }

    for(m = 1;m <= N;m++){
        for(i = 0;;i++){
            if(a[p]){
                if(p==N)
                    p = 0;
                else
                    p++;
            }
            else{
                if(p==N)
                    p = 0;
                else 
                    p+=2;
            }
            if(i==m-1){
                a[m-1]=0;
                break;
            }
        }
    }
    
    return 0;
}