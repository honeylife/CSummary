#include<stdio.h>

// 2011 年 C语言试卷

/**
 * 5个红球，6个白球，7个黑球中任意取出八个球，且必须有白球，要求输出所有可能 
 * */
void fun1(){
    int k;
    printf("red\twhite\tblack\n");
    for (int i = 0; i < 6; i++)
    {
       for (int j= 1; j <7; j++)
       {
           k=8-i-j;  // 这里这样处理，避免在嵌套一层for循环，次算法的时间复杂度为O(n^2)
           if (k>=0&&k<8)
           {
               printf("%d\t%d\t%d\n",i,j,k);
           }
       }
    } 

    // 总结，这里比来三个放循环要来的好，首先时间复杂度是明显的。
}

int main(int argc, char const *argv[])
{
    fun1();
    return 0;
}

