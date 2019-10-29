#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/**
 * 编写一个函数char * maxword（char *r,char *t） 求出两个串最长的公共单词，假设都是
 * 英语字母和空格组成  this is a book， my book ， 输出book
 * 要求:不能设置保存单词的存储空间
 * */
char *maxword(char *r, char *t)
{
    char r11[20], t11[20], s1[20];
    int i = 0, j = 0, k = 0, kk = 0;
    int maxlen = 0;

    while (*r != '\0')
    {
        r11[0] = '\0';
        i = 0;
        while (*r != ' ' && *r != '\0')
        {
            r11[i++] = *r++;
        }

        r11[i] = '\0';
        k = 0;
        while (t[k] != '\0')
        {
            t11[0] = '\0';
            j = 0;
            while (t[k] != ' ' && t[k] != '\0')
            {
                t11[j++] = t[k++];
            }
            t11[j] = '\0';
            if (strcmp(r11, t11) == 0)
            {
                int len = strlen(r11);
                if (len > maxlen)
                {
                    maxlen = len;
                    s1[0] = '\0';
                    strcpy(s1, r11);
                }
            }

            k++;
        }
        r++;
    }
    puts(s1);
    return s1;
}
int main(int argc, char const *argv[])
{
    char r[] = "this is a English book";
    char s[] = "English book";
    char *ss;
    ss = maxword(r, s);
    puts(ss);
    return 0;
}