#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int checkstr(char *s, char *t, int flag,int lenstr)
{
    char *q;
    for (; *(s + lenstr); s++)
    {
        if (flag)  // 不区分大小写
        {
          for (q = t; (*s == *q||*s-32==*q||*s+32==*q) && *q; s++, q++)
            ;

        }else  //区分大小写
        {
            for (q = t; *s == *q && *q; s++, q++)
            ;
        }
        
        if (!*q)
        {
            return 1;
        }
    }

    return 0;
}
int main(int argc, char const *argv[])
{
    
    char *s="abcdesdff";
    char *t="EsDf";
    int flag =0;
    int len = 4;
    int index =    checkstr(s,t,flag,len);
    printf("%d",index);
    return 0;
}
