//5.约瑟夫环。班上有47人围成一圈，从你开始依次报数，报到某数M的人出列，最后只留下一个人。
//当M为何值时，最后是你自己留下来？

#include <stdio.h>
#define N 47
#define me 45

int a[N];

int s() {
    for (int i = 0; i < N; i++) {
        if (i == me - 1){
            if (a[i] == 0) 
                return 0;
        }
        else{
            if (a[i] != 0)
                return 0;
        }
    }
    return 1; // 如果只有第me个人没出列，返回1,否则0
}

int main() {
    int m = 1; // 初始化m
    while (1) {
        int p = 0, left = N;
        for (int i = 0; i < N; i++) {
            a[i] = 1; // 重置所有人为未出列状态
        }
        int i = 0;
        while (left > 1) {
            if (a[i]) {
                p++;
                if (p == m) {
                    a[i] = 0; 
                    left--;
                    p = 0;
                }
            }
            i = (i + 1) % N;
        }
        if (s()) { 
            printf("使得第%d个人最后留下来的m为：%d\n", me, m);
            break;
        }
        m++; 
    }
    return 0;
}