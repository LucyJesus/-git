#include <stdio.h>
#define SY 2001
#define SM 1
#define SD 1
#define TY 2024
#define TM 6
#define TD 13
#define X 12


int RY(int y)//判断闰年
{
    if (y%4 == 0 && y%100 != 0 || y%400 == 0)
        return 1;
    else
        return 0;

}

int main()
{
    int p,i,j,k,count=0,b[X]={31,28,31,30,31,30,31,31,30,31,30,31};
    //计算整数年的天数和
    if(SY<TY)
    {  
        for(i=SY;i<TY-1;i++){
            count += 365;
            if(RY(i))
                count++;
        }
    //计算前面的不整年的天数
        if(RY(SY) && SM<2)
            count++;
        count += b[SM-1]-SD;
        for(j=SM;j<12;j++)
            count += b[j];
    //计算后面的不整年的天数
        if(RY(TY) && TM>2)
            count++;
        for(k=0;k<TM-1;k++)
            count += b[k];
        count += TD;
    }
    else{
        if(SM<TM){
            for(p=0;p<TM-1;p++)
                count += b[p];
            count +=TD;
        }
        else
            count = TD-SD;
    }
        
    //输出
    printf("%d",count);
    return 0;
}