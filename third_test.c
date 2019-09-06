#include <stdio.h>

#define MaxZise 20
// n阶魔方 ：将1~n^2个数填写到一个由n行n列的方阵中，
//使得每一行每一列及两个对角线上的数字之和分别等于同一个数。称这个方阵为一个n阶魔方
void MAGIC(int A[][MaxZise],int n){
    int i,j,num;
    // 初始化，默认为0
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            A[i][j]=0;
        }
        
    }
    i=0;
    j=n/2;  // i与j的初始位置
    for ( num = 0; num < n*n; num++)
    {
        if (i<0&&j<0||A[i][j]!=0)
        {
            i+=2;
            j++;
        }
        A[i--][j--]=num;
        if (i<0&&j>=0)
        {
            i=n-1;  // 修改i的位置
        }
        if (j<0&&i>=0)
        {
            j=n-1;  // 修改J的位置
        }
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
