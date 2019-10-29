#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
/**
 * 顺序表A【1.。n】，第一趟最小元素在A【1】，最大元素在A【n】；
 *                  第二趟最小元素在A【2】，次最大元素在A【n-1】；
 *                   。。。。。
 * */
void printfun(int A[],int n);
void printfun(int A[],int n){
     for (int i = 0; i < n; i++)
    {
        printf("%d,",A[i]);
    }
    printf("\n");
    printf("================\n");
}
void fun(int A[],int n){
    printfun(A,n);
    int max,min,temp;
    for (int i = 0; i < n/2; i++)
    {
        min=max=i;
        for (int k = i+1; k < n-i; k++)
        {
            if (A[k]>A[max])
            {
                max=k;
            }
           if(A[k]<A[min]) {
                min=k;
            }
        }
        temp=A[i];
        A[i]=A[min];
        A[min]=temp;
        if (max!=i)
        {
            temp=A[n-i-1];
            A[n-i-1]=A[max];
            A[max]=temp;
        }else
        {
            temp=A[n-i-1];
            A[n-i-1]=A[min];
            A[min]=temp;

        }
    }

    printfun(A,n);
    
}
int main(int argc, char const *argv[])
{
    int A[8]={3,5,34,67,34,23,11,3};
    fun(A,8);
    return 0;
}
