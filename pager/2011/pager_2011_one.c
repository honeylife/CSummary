#include<stdio.h>
int fun(int n){
    if (n==1)
    {
        return 1;
    }
    return n+fun(n-1);
}
int main(int argc, char const *argv[])
{
    int n;
    printf("input n:\n");
    scanf("%d",&n);
    printf("\n");
    printf("%d",fun(n));
    return 0;
}
