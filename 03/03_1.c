#include <stdio.h>

// 定义一个函数指针类型FuncPointer，指向的函数接受一个float并返回一个float
typedef float (*FuncPointer)(float);

// Integrate_1函数，接受一个函数指针f，和两个float类型的参数a和b
float Integrate_1(FuncPointer f, float a, float b) {
    float result = 0;
    // 此处应实现具体的积分算法，这里仅为示例
    result = (f(a) + f(b)) * (b - a) / 2;  // 使用梯形规则进行简单积分估计
    return result;
}

// 示例函数，我们将传递给Integrate_1
float myFunction(float x) {
    return x*x + x + 1;  // 示例函数
}

int main() {
    float result = Integrate_1(myFunction, 0, 1);
    printf("The integral of the function from 0 to 1 is: %f\n", result);
    return 0;
}
