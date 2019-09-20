#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node
{
    int data;
    struct node *link;
} Node, *LinkList;

void CHANGE() {}

/**
 * 函数 void insert(char *s, char *t, int pos) 将字符串 t 插入到字符串 s 中，插入位置为 pos。请用 C
语言实现该函数。假设分配给字符串 s 的空间足够让字符串 t 插入。（说明：不得使用任何库函数。）
 * */

// 第一种插入方式， 先把s的pos以后的字符串链接到t上，然后在将t插入到s的pos位置
void insert(char *s, char *t, int pos)
{
    char *p, *q = t, *r;
    p = s + pos;
    while (*q != '\0')
    {
        q++;
    }
    while (*p != '\0')
    {
        *(q++) = *(p++);
    }
    p = s + pos;
    while (*t != '\0')
    {
        *(p++) = *(t++);
    }
    puts(s);
}

// 第二种插入方式  直接在pos位置插入t
void insertss(char *s, char *t, int pos)
{
    char *p  ,r[5];
    int i = 0, lent = 0;
    p = s + pos;
    while (*p != '\0')
    {
        r[i++]= *p++;
    }
    r[i]='\0';
    p = s + pos;
    while (*t != '\0')
    {
        *(p++) = *(t++);
        lent++;
    }
    i=0;
    p=s+pos+lent;

    while (r[i] != '\0')
    {
        *(p++) = r[i++];
    }
    puts(s);

}
int main(int argc, char const *argv[])
{
    char s[20] = "adbdsd";
    char t[10] = "a34";
    int pos = 4;
    // insert(s, t, pos);
      insertss(s, t, pos);
    return 0;
}
