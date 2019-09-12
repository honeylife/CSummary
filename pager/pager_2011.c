#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// 2011 年 C语言试卷

/**
 * 5个红球，6个白球，7个黑球中任意取出八个球，且必须有白球，要求输出所有可能 
 * */
void fun1(){
    int k;
    printf("red\twhite\tblack\n");
    for (int i = 0; i < 6; i++)
    {
       for (int j= 1; j <7; j++)
       {
           k=8-i-j;  // 这里这样处理，避免在嵌套一层for循环，次算法的时间复杂度为O(n^2)
           if (k>=0&&k<8)
           {
               printf("%d\t%d\t%d\n",i,j,k);
           }
       }
    } 

    // 总结，这里比来三个放循环要来的好，首先时间复杂度是明显的。
}

/**
 * 输入三条边，判断是否为三角形，是等边三角形还是等腰三角形
 * */
 void fun2(){
     int a,b,c;
     printf("please input a,b,c:\n");
     scanf("%d %d %d",&a,&b,&c);
     if (a+b>c&&a+c>b&&b+c>a)
     {
         printf("This is a Triangle\n");
     }else
     {
         printf("This is not a Triangle");
         return;
     }
     
     if (a==b&&b==c)
     {
        printf("This is a equilateral triangle \n");
        return;
     }
     
     if (a==b&&b!=c)
     {
          printf("This is a  isosceles triangle  \n");
     }
     if (a==c&&b!=c)
     {
         printf("This is a  isosceles triangle  \n");
     }
     
     if (b==c&&a!=b)
     {
         printf("This is a  isosceles triangle  \n");
     }
     
     
     
 }
 /**
  * 从键盘输入 员工信息，在member.bat 文件中查找，如果存在，则返回员工信息，如果没有在，在磁盘创建该文件
  * */
 void fun3(){
     FILE *fp;
     char *name,*fname;
     int flag=0;
     printf("please name:\n");
     gets(name);
    //  if ((fp=fopen("member.dat","r"))==NULL)
    //  {
    //      printf("file is error!");
    //      getch();
    //      exit(1);
    //  }
   fp=fopen("member.dat","r");
    while (!feof(fp))
    {
       fscanf(fp,"%s",fname);
       if (strcmp(fname,name)==0)
       {
           printf("%s exist",name);
            flag=1;
            break;
       }
       
    }
     fclose(fp);
    if (flag==0)
    {
        printf("create member.dat and join name\n");
        fp=fopen("member.dat","a");
        fprintf(fp,"%s",name);
        fclose(fp);
    }
    
    

     
     
 }

int main(int argc, char const *argv[])
{
    // fun1();
    // fun2();
    // fun3();
    fun3();
    return 0;
}

