// /*
// 北航 2010年试卷 编程

// 
#include <stdio.h>
#define  M 3
#define  N 3

int fun(int n,int a);


//  * 求 s=a+aa+aaa+aaaa+aaa...a;
//  * 例如 2+22+222+2222+22222此时共有5的数相加；
//  * /
void one(){
     int s=0,a,n; // n 相加数的个数，a表示重复数
    printf("please input a:\n");
    scanf("%d",&a);
    printf("please input n:\n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        s+=fun(i,a);
    }
    printf("\n");
    printf("s=%d",s);
    s=0;
 
    //   此上方法的时间复杂度O(n^2)
    //---------------------------------------
    // 方法二
    int count=1,t=0;
    while (count<=n)
    {
       t=t+a;
       s=t+s;
       a=a*10;
       ++count;
    }
   printf("\n");
    printf("s=%d",s);

    // 此方法的时间复杂度为O(n)
    // 明显此方法是最优解。
}
int fun(int n,int a){
    int s=a;
    for (int i = 1; i < n; i++)
    {
       s=s*10+a;
    }
    return s;
    
}

// 打印二维数组中，每行的最大的数组 ,
// 要求键盘输入二维数组，M,N 宏定义

void two(){
    int A[M][N],temp;
    for (int i = 0; i < M; i++)
    {
       for (int j = 0; j < N; j++)
       {
           scanf("%d",&A[i][j]);
       }
    
    }
 printf(" Output two-dimensional array \n");
    // 其实这里没必要 写，为了看清楚，就打印一下吧。
     for (int i = 0; i < M; i++)
    {
       for (int j = 0; j < N; j++)
       {
          printf("%d\t",A[i][j]);
       }
       printf("\n");
    
    }

 printf(" Output max data \n");
 for (int i = 0; i < M; i++)
    {
        temp=A[i][0];
       for (int j = 0; j < N; j++)
       {
         if (temp<A[i][j])
         {
           temp=A[i][j];
         }
         
       }
       printf("%d line max data:%d\n",i+1,temp);
    
    }

    // 分析，明显时间复杂为 O(n^2),
    // 主要考察初始化二维数组， 求取最大值为题，比较基础的题了额。
    
    
}



int main(int argc, char const *argv[])
{
    // one();
    two();
    return 0;
}
