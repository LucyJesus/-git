//5.约瑟夫环。班上有47人围成一圈，从你开始依次报数，报到某数M的人出列，最后只留下一个人。
//当M为何值时，最后是你自己留下来？

#include <stdio.h>
#define N 47
#define me 45
int a[N];

int s(){
    for(int i = 0;i<N;i++){
        if(a[me-1] && !a[i])
            return 1;
        }   
        return 0;
    
}


int main()
{
    int p = 0,m,left = N;
    for(int i = 0;i < N;i++){//赋值每一个人
        a[i] = i + 1;
    }
    for(m = 1;m < N;m++){
        for(int i = 0;left > 1;i = (i+1)%N){
            if(a[i]){
                p++;
                if(p == m){
                    a[i] = 0;
                    left--;
                    p = 0;
                }
            }
        }
    }
    printf("当M为%d时留下",m);
    return 0;
}


