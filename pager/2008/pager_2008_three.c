#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 80  // 假设字符串最大的长度为80个字符
/**
 * 编写一个程序，从字符串的k位置开始，后面的全部复制到另一个字符串中
 * 要求：将复制过程编写成一个函数，并且采用指针完成
 *      在主函数中输入字符串与k的值，并在主函数中输出结果
 * */
void fun(int k, char *p, char *r)
{
    for (int i = 0; *p != '\0'; i++, p++)
    {
        if (i + 1 >= k)
        {

            *r = *p;
            r++;
        }
    }
    //  注意，必须在结束的时候，加上结束符‘\0’
    *r = '\0';
}

int main(int argc, char const *argv[])
{
    int k;
    char st[MaxSize], s1[MaxSize], *p = &st, *r = &s1;

    printf("input p:\n");
    scanf("%s", p);

    printf("input k:\n");
    scanf("%d", &k);
    while (k > strlen(p))
    {
        printf("input k in 1-%d:\n", strlen(p));
        scanf("%d", &k);
    }

    fun(k, p, r);
    puts(r);
    return 0;
}