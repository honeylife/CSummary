#include<stdio.h>
#include<stdlib.h>
/**
 * 别写一个算法，实现：5+55+555+5555+555...
 * */
int main(int argc, char  **argv)
{
    int n, a,s=0,t=0,count=0;

   printf("input a and n:\n");
   scanf("%d %d",&a,&n);
    while (count<n)
    {
        t+=a;
        s+=t;
        a=a*10;
        count++;
    }
    printf("%d\n",s);

    return 0;
}
