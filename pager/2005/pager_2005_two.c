#include <string.h>
#include <stdlib.h>
#include <stdio.h>
// 输入n 输出n以内的素数
int main(int argc, char const *argv[])
{
    int n;
    printf("please input n:\n");
    scanf("%d", &n);
    int flag = 0;
    printf("%d,%d,",2,3);
    for (int i = 2; i <= n; i++)
    {
        flag = 0;
        for (int j = 2; j <=i/2 ; j++)
        {
            if (i % j == 0)
            {
                flag=0;
                break;
            }
            else
            {
                flag = 1;
            }
        }
        if (flag == 1)
        {
            printf("%d,", i);
        }
    }

    return 0;
}
