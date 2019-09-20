#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * 命令 sgrep 用来在文件中查找给定字符串，并输出串所在行及行号。命令格式为：
sgrep [−i] filename string
其中：
−i 表示查找时大小写无关，省略时表示大小写相关
filename 给定文件名
string 所要查找的字符串
用 C 语言实现该程序，该程序应具有一定的错误处理能力。（提示：使用命令行参数）
注意：除文件及 I/O 操作可使用库函数外，其它不允许使用库函数。
 * **/

int main(int argc, char const *argv[])
{
    FILE *fp;
    char *fName,*str;
    int flag=0; // 0 表示大小写无关，1 表示大小写有关
   if (argc ==2)
   {
       flag=1;
        fName=argv[0];
        str = argv[1];
   }else
   {
       flag=0;
       fName=argv[1];
        str = argv[2];
   }
   
   if ((fp=fopen(fName,"r"))==NULL)
   {
       printf("file is error!");
       getch();
       exit(1);
   }
   
    

    return 0;
}
