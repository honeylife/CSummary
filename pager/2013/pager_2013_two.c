#include<string.h>
#include<stdio.h>
#include<stdlib.h>
/**
 * 找出数组A【100】中的最小数，并且删除，用指针完成
 * 数组，键盘输入，数组引用，需要指针完成
 * */
#define  N 100
int main(int argc, char const *argv[])
{
    int n=N;
    int A[n],*p=A,temp;
    for (int i = 0; i < N; i++,p++)
    {
        scanf("%d",p);
    }
    temp=0;
    p=A;
    for (int i = 0; i < N; i++)
    {
        if (*(p+i)<*(p+temp)){
            temp=i;
        }
    }
    
    for (int i = temp; i < N-1; i++)
    {
        *(p+i)=*(p+i+1);
    }
 
   n--;
     for (int i = 0; i < n; i++)
    {
        printf("%d,",*(p+i));
    }
    

    return 0;
}
