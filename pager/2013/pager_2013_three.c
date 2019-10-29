#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/**
 * 编写一个函数char * maxword（char *r,char *t） 求出两个串最长的公共单词，假设都是
 * 英语字母和空格组成  this is a book， my book ， 输出book
 * 要求:不能设置保存单词的存储空间
 * */
// 设置了存储空间，保存了单词，按照题设的要求是不需要保存单词，不过
// 这种保存了单词的，确实简单哈，
char *maxword(char *r, char *t)
{
    char r11[20], t11[20], s1[20];
    int i = 0, j = 0, k = 0;
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
// 不保存单词，这种方法，就需要记录每个单词的开始位置，
// 已经单词的长度了，具体的看下面代码

char *maxwords(char *r, char *t)
{
    char *pr = NULL, *pt = NULL, *ps = NULL, *s1=t;
    int i = 0, j = 0;
    int maxlen = 0;
    int flag=0;
    while (*r != '\0')
    {
        pr = r;
        i = 0;
        while (*r != ' ' && *r != '\0')
        {
            r++;
            i++;
        }
        pt = t;
        while (*pt != '\0')
        {
            j = 0;
            ps = pt;
            while (*pt != ' ' && *pt != '\0')
            {
                j++;
                pt++;
            }
            while (pr != r && *pr == *ps && i == j)
            {
               
                pr++;
                ps++;
            }
            if ( ps == pt && pr == r)
            {
                if (i > maxlen)
                {
                    maxlen = i;
                    int k = 0;
                    while (k < j)
                    {
            
                        s1[k] = *(t + strlen(t) - strlen(pt) - j + k);
                        k++;

                    }
                    s1[i]='\0';
                }
                flag=1;
            }
            if (*pt == '\0')
            {
                break;
            }

            pt++;
        }
        if (*r == '\0')
        {
            break;
        }
        r++;
    }
    if (flag==1)
    {
        return s1;
    }else
    {
        return NULL;
    }

}
int main(int argc, char const *argv[])
{
    char r[] = "this is a English book";
    char s[] = "English book";
    char *ss = maxwords(r, s);
    puts(ss);
    return 0;
}