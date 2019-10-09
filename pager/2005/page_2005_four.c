#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXLINE 81
// 改变文件中字母的大小写，将所有的小写转换成大写 
int main(int argc, char const *argv[])
{
    FILE *fp,*fp2;
    char *filename;
    char s[MAXLINE];
    // if (argc==2)
    // {
    //    filename=argv[1];
    // }else
    // {
    //     fprintf(stderr,"file name is error：\n");
    //     exit(1);
    // }
    
    if ((fp=fopen("d:\\work\\Cspace\\w.txt","r"))==NULL)
    {
        fprintf(stderr,"file name is error：\n");
        exit(1);
    }
    
    // fp2=fopen(strcat(filename,"s"),"w");

 while (fgets(s,MAXLINE,fp))
    {
        puts(s);
        // fputs(s,fp2);
    }
    // 一行一行的读
    rewind(fp);
    // while (fgets(s,MAXLINE,fp))
    // {
      
    //     for(int i=0;s[i]!='\0';i++){
    //         if (s[i]>='a'&&s[i]<='z')
    //         {
    //             s[i]=s[i]-32;
    //         }
            
    //     }
    //     puts(s);
    // }

    // 这是一个字母一个字母读，然后判断
    char ch;
    while ((ch=fgetc(fp))!=EOF)
    {
        putchar(toupper(ch));
    }
    
    
    
    fclose(fp);
    // fclose(fp2);
    return 0;
}
