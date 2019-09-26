#include <stdio.h>
#include <stdlib.h>

/**
 * 计算，a+a*a+a*a*a...
 * */
float fun()
{
    float a, s = 0.0, t = 1;
    int n, i = 1;
    printf("please input a and n: a,n\n");
    scanf("%f,%d", &a, &n);

    while (i <= n)
    {
        t = t * a;
        s += t;
        i++;
    }

    printf("s=%0.2f\n", s);
    return s;
}

int main(int argc, char const *argv[])
{

    float s=fun();
    return 0;
}
