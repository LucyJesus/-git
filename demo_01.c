#include <stdio.h>

// 判断是否为闰年的函数
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 计算从指定日期到2024年5月4日的天数
int daysFrom(int year, int month, int day) {
    // 每月的天数，注意索引0为空，因为月份从1开始
    int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // 今天的日期
    int todayYear = 2024;
    int todayMonth = 5;
    int todayDay = 4;

    // 如果给定日期在今天之后，返回错误
    if (year > todayYear || (year == todayYear && month > todayMonth) ||
        (year == todayYear && month == todayMonth && day > todayDay)) {
        return -1; // 无效的日期
    }

    int totalDays = 0;

    // 如果是同一年
    if (year == todayYear) {
        for (int m = month; m < todayMonth; m++) {
            totalDays += daysInMonth[m];
            // 考虑闰年2月的情况
            if (m == 2 && isLeapYear(year)) {
                totalDays += 1;
            }
        }
        // 加上5月的天数差
        totalDays += todayDay - day;
    } else {
        // 处理起始年份剩余天数
        totalDays += daysInMonth[month] - day;
        if (month == 2 && isLeapYear(year)) totalDays += 1;
        for (int m = month + 1; m <= 12; m++) {
            totalDays += daysInMonth[m];
            if (m == 2 && isLeapYear(year)) totalDays += 1;
        }

        // 计算完整年份的天数
        for (int y = year + 1; y < todayYear; y++) {
            totalDays += isLeapYear(y) ? 366 : 365;
        }

        // 计算最后一年到目标月之前的天数
        for (int m = 1; m < todayMonth; m++) {
            totalDays += daysInMonth[m];
            if (m == 2 && isLeapYear(todayYear)) totalDays += 1;
        }
        // 加上目标月的天数
        totalDays += todayDay - 1;
    }

    return totalDays;
}

int main() {
    int year, month, day;
    
    // 输入一个日期
    printf("Enter a date (YYYY MM DD): ");
    scanf("%d %d %d", &year, &month, &day);
    
    // 计算天数并输出结果
    int result = daysFrom(year, month, day);
    if (result == -1) {
        printf("Entered date is invalid or in the future.\n");
    } else {
        printf("Days from %d-%d-%d to 2024-05-04: %d\n", year, month, day, result);
    }

    return 0;
}