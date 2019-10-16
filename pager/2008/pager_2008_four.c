#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/**
 * 命令行参数，替换文件中的字符串，
 *  >/replace file1  file2 old new  将file1中的old 都替换成 new 并且保存在file2中
 *  要求： 必须对文件有正确的检测性
*/
int main(int argc, char const *argv[])
{
    FILE *fp1,*fp2;
    char *fileName1,*fileName2,*old,*news;
    int len;
    char s[20];
    if (argc==5)
    {
      fileName1=argv[1];
      fileName2=argv[2];
      old=argv[3];
      news=argv[4];  
    }else
    {
        printf("error \n");
        getch();
        exit(-1);
    }
    if ((fp1=fopen(fileName1,"r"))==NULL)
    {
        fprintf(stderr,"error %s",fileName1);
        getch();
        exit(-1);
    }
     if ((fp2=fopen(fileName2,"w"))==NULL)
    {
        fprintf(stderr,"error %s",fileName2);
        getch();
        exit(-1);
    }
    len = strlen(old);
    int flag=0;
    while (fgets(s,len+1,fp1))
    {
        for (int i = 0; s[i]!='\0'; i++)
        {
            flag =0;
            if (s[i]==old[i])
            {
               flag=1; 
            }else
            {
                flag=0;
            }
            
        }
        puts(s);

        if (flag==1)
        {
            fputs(news,fp2);
        }else
        {
            fputs(s,fp2);
        }
        
        // 这里调用函数，如果题设要求可以使用此函数的时候，就可以用下面一段了。
        // if (strcmp(s,old)==0)
        // {
        //     fputs(news,fp2);
        // }else
        // {
        //      fputs(s,fp2);
        // }
    
        
    }
    
    fclose(fp1);
    fclose(fp2);
    
    
    return 0;
}
