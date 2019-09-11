// /*
// 北航 2010年试卷 编程
//  * 求 s=a+aa+aaa+aaaa+aaa...a;
//  * 例如 2+22+222+2222+22222此时共有5的数相加；
//  * /
// 
#include <stdio.h>

int fun(int n,int a){
    int s=a;
    for (int i = 1; i < n; i++)
    {
       s=s*10+a;
    }
    return s;
    
}
int main(int argc, char const *argv[])
{
    int s=0,a,n; // n 相加数的个数，a表示重复数
    printf("please input a:\n");
    scanf("%d",&a);
    printf("please input n:\n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int sss=fun(i,a);
        printf("sss=%d\t",sss);
        s+=sss;
    }
    printf("\n");
    printf("s=%d",s);
    s=0;
    printf("\n");
    printf("s=%d",s);
    int count=1,tn;
    while (count<=n)
    {
       tn=tn+a;
       s=tn+s;
       a=a*10;
       ++count;
    }
   printf("\n");
    printf("s=%d",s);
    return 0;
}
