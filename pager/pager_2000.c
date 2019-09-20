#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node
{
    int data;
    struct node *link;
} Node, *LinkList;


/**
 * 欧几里得算法  辗转相除法 求最大因子
 * */
int fun(int m, int n)
{
    if (n == 0)
    {
        return m;
    }
    if (m < n)
    {
        return fun(n, m);
    }

    return fun(n, m % n);
}

/**
 * 欧几里得算法  辗转相除法 求最大因子  非递归算法
 * */
int fun2(int m, int n)
{
    int temp;
    while (1)
    {
        if (m < n)
        {
            temp = m;
            m = n;
            n = temp;
        }

        if (n == 0)
        {
            return m;
        }
        else
        {
            int r = m % n;
            m = n;
            n = r;
        }
    }
}

int main(int argc, char const *argv[])
{

    int a = fun(12, 8);
    printf("%d\n", a);
    int aa = fun2(12, 8);
    printf("aa=%d\n", aa);
    return 0;
}
