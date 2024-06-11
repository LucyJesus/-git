#include <stdio.h>
#define N 47
#define me 45

int a[N];

// 检查只剩下一个人，且是第me个人
int last_man_standing() {
    int count = 0;
    int last_index = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] != 0) {
            count++;
            last_index = i;
        }
    }
    return (count == 1 && last_index == me - 1);  // me - 1因为数组是从0开始的
}

int main() {
    for (int m = 1; m <= N; m++) {  // 尝试每一个m从1到N
        // 初始化
        for (int i = 0; i < N; i++) {
            a[i] = i + 1;  // 每个人标记为他们的索引+1，确保没有人被标记为出列
        }

        int left = N;
        int p = 0;
        int i = 0;
        while (left > 1) {  // 至少需要两个人才能进行
            if (a[i] != 0) {
                p++;
                if (p == m) {
                    a[i] = 0;  // 这个人出列
                    left--;    // 圈中的人数减少
                    p = 0;     // 重置报数
                }
            }
            i = (i + 1) % N;  // 环形处理
        }

        if (last_man_standing()) {
            printf("当M为%d时，最后留下的是你自己。\n", m);
            return 0;
        }
    }

    printf("没有合适的M值使你最后留下。\n");
    return 1;
}