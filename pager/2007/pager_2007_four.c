#include<stdio.h>
#include<stdlib.h>
/**
 * 采用命令行，连续输出n个素数：
 * 如：outprime 10 
 * 2.3.5.7.11.，13,17,19,23,29
*/
int main(int argc, char const *argv[])
{
    int n=10, count=0,len=2,i=2;
    // if (argc!=2)
    // {
    //     printf("error!\n");
    //     exit(-1);
    // }
    // n=atoi(argv[1]);
   while (count<n)
   {
    
    for ( i = 2; i < len; i++)
    {
        if (len%i==0)
        {
           break;
        }
        
    }
    if (len==i)
    {
       printf("%d,",len);
       count++;
    }
    len++;
      
   }
   
    
    
    return 0;
}
