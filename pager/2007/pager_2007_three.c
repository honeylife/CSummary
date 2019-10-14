#include<stdlib.h>
#include<stdio.h>
/**
 * 
 * 请写一算法，当输入任意正整数n时，输出螺旋式数字方针
 * 1 2 3   4  5
 *            6
 *            7
 *            8
 *13 12 11 10 9    
 * 
 * */
 int calculate(int n, int i, int j);

 int calculate(int n, int i, int j)
{
    // (i, j)位置的数值
    int k = 0;
    // 用来计算(i, j)的外有几个完整的“圈”
    int mini = i < n - i ? i : n - i;
    int minj = j < n - j ? j : n - j;
    int min = mini < minj ? mini : minj;
    int h;

    // h用来控制层数
    for (h = 0; h < min; ++h) {
        // 内层的圈要比临近外层的圈的边长小2
        k += (n - 2 * h) * 4;
    }

    // (i, j)位于同层的上方
    if (i == min) {
        // 直接取得j坐标的位置，注意需要减掉min，因为外围已经计算过了
        k += j - min + 1;
    }
    // (i, j)位于同层的右侧
    else if (j == n - min) {
        // 需要加上上方边长的长度
        k += (n - 2 * min) + (i - min) + 1;
    }
    // (i, j)位于同层的下方
    else if (i == n - min) {
        // 需要加上上方和右侧的长度
        k += (n - 2 * min) * 2 + (n - min - j) + 1;
    }
    // (i, j)位于同层的左侧
    else if (j == min) {
        // 需要加上上方、右侧和下方的长度
        k += (n - 2 * min) * 3 + (n - min - i) + 1;
    }

    return k;
}

void fun(int n){
    int a[n][n];
    for (int i =0; i < n; i++)
    {
        for (int j =0; j < n; j++)
        {
           printf("%3d ", calculate(n - 1, i, j));

        }
        printf("\n");
        
    }
    
}
int main(int argc, char const *argv[])
{
    int n;
    printf("input n:\n");
    scanf("%d",&n);
    fun(n);
    return 0;
}
