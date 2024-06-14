#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// void ran(int n) {
//     int i, j;
//     int m[n][n+1]; 

//     srand(time(NULL));

//     // 填充矩阵
//     for (i = 0; i < n; i++) {
//         for (j = 0; j < n + 1; j++) {
//             m[i][j] = rand() % 21 - 10;  // 生成-10到10之间的随机数
//         }
//     }
//     printf("Generated %d x %d Matrix:\n", n, n+1);
//     for (i = 0; i < n; i++) {
//         for (j = 0; j < n + 1; j++) {
//             printf("%d\t", m[i][j]);
//         }
//         printf("\n");
//     }
// }

// 5至27行是抄的,因为不会写随机函数
int main() {
    int a,b,c,d,e,f;
    int x[2][3];
    printf("依次输入系数和常数:(用空格分开)");
    scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
    x[0][0] = a;
    x[0][1] = b;
    x[1][0] = c;
    x[1][1] = d;
    x[0][2] = e;
    x[1][2] = f;

    if(x[0][0] != 0 && x[1][0] != 0){
        
    }
    // printf("%d",x[0][0]);

    return 0;
}