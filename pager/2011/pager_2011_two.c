#include <stdio.h>
/**
 * 编写一个C程序，将数组A[0..n-1]中的元素统一移动k个位置
 * 如 20   40   50   79   90   98   120  140  移动3个位置之后，变成
 *    98   120  140  20   40   50   79   90
 *   
*/
void fun0(int A[], int n);
void fun0(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d,", A[i]);
    }
    printf("\n");
    printf("===================================\n");
    

}
void fun(int A[], int n, int k)
{
    int temp;
    for (int i = 0; i < k; i++)
    {
        temp = A[i];
        A[i] = A[n - k + i];
        A[n - k + i] = temp;
    }
     fun0(A, n);
    
}

int fun2(int A[], int n, int k)
{
    for (int i = 0; i < k; i++)
    {
        int temp = A[i];
        int s;
        for (int j = i + k; j < n; j = j + k)
        {
            s = A[j];
            A[j] = temp;
            temp = s;
        }
    }
}
// 前后倒置，分别倒置三次，就是所要的结果呢。
int fun1(int A[], int n, int k)
{
    int temp = 0;
    int i = 0;
     fun0(A, n);
    for ( i = 0; i < (n - k) / 2; i++)
    {
        temp = A[i];
        A[i] = A[n - k - i-1];
        A[n - k - i-1] = temp;
    }

    fun0(A, n);
    for (  i = 0; i < k / 2; i++)
    {
        temp = A[n - k + i];
        A[n - k + i] = A[n - i - 1];
        A[n - i - 1] = temp;
    }
     fun0(A, n);
     for (  i = 0; i < n/2; i++)
     {
         temp=A[i];
         A[i]=A[n-i-1];
         A[n-i-1]=temp;
     }
      fun0(A, n);
}
int main(int argc, char const *argv[])
{
    int A[] = {20, 40, 50, 79, 90, 98, 120, 140};

   
    fun(A, 8, 3);
    return 0;
}
