# include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    int a=0,b=0;
    printf("%d",(a=2,b=1,a++,b++,a+b));
    int x=2;
    printf("x=%d,\n",--x);
    char ss[10]="1234567\0\0";
    printf("%d",strlen(ss));
   printf("\n");
    for (int i = 0; i < 20; i++)
    {
        if ((i+1)%8==0)
        {
           printf("\n");
        }
        printf("%d\t",i);
        
    }
    
    return 0;
}
