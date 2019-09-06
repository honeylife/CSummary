#include <stdio.h>

#define MaxSize 100
void maxandmin(int A[],int n){
    int max,min;
    max=min=A[0];
    for (int i = 1; i < n; i++)
    {
        if (max<A[i])
        {
           max=A[i];
        }else
            if (min>A[i])
            {
                min=A[i];
            }
            
                
    }

printf("max=%d,min=%d",max,min);
    
}

int selected(int A[],int n,int key,int i){
    int indext =0;
    if (i==n&&A[i]!=key)
    {
        return -1;
    }
    if (A[i]==key)
    {
      return i;
    }
    return selected(A,n,key,++i);
    
}
//  导致数组
void fun2(int A[],int n){
    int temp,i,j;
    for ( i = 0,j=n-1; i < j; i++,j--)
    {
       temp = A[i];
       A[i]=A[j];
       A[j]=temp;

    }
    
}
void printvule(int A[]){
    printf("\n");
     for (int i = 0; i < 8; i++)
    {
       printf("%d,",A[i]);
    }
    printf("\n");
}

void printvules(int A[],int n){
    printf("\n");
     for (int i = 0; i < n; i++)
    {
       printf("%d,",A[i]);
    }
    printf("\n");
}


// 删除奇数
int fun3(int A[],int n){

printf("删除奇数");
 int count=0;
 for (int i = 0; i < n; i++)
 {
     if (A[i]%2!=0)
     {
         A[i]=0;
     }
     
 }
 for (int i = 0; i < n; i++)
 {
     if (A[i]!=0)
     {
         A[count++]=A[i];
     }
     
 }

printf("count=%d",count);

 n=count;
 return n;
 
}

// 删除大于x 小于y 的数

int fun4(int A[],int n,int x,int y){
    int j=0;
    printf("=======fun4======\n");
    for (int i = 0; i < n; i++)
    {
        if (A[i]<x||A[i]>y)
        {
           A[j++]=A[i];
        }
        
    }

printvules(A,j);
    
}

// 创建线性表
void fun5(int n){
    int a,i=0;
    int A[MaxSize];
    int flag=0;
    printf("please input a values");
    scanf("%d",&a);
    A[i++]=a;
    while (i<n)
    {
        scanf("%d",&a);
        flag=0;
      for (int j = 0; j < i; j++)
      {
         if (A[j]==a)
         {
             flag=1;
            break;
         }
         
      }
      if (flag!=1)
      {
           A[i++]=a;
      }
      
      
    }
    printvules(A,i);
    
}

void fun6(int A[],int B[],int n,int m,int index){
    for (int i = 0; i < m+n; i++)
    {
        /* code */
    }
    
}

int main(int argc, char const *argv[])
{
    int A[]={1,3,4,0,6,9,3,11};
    printvule(A); 
    maxandmin(A,8);
    int a = selected(A,8,9,1);
    printf("a=%d",a);
    fun2(A,8);
    printvule(A); 
    int n = fun3(A,8);
    printvules(A,n);
    int array[]={1,2,3,4,5,6,7,8,9,10};
    printvules(array,10);
    fun4(array,10,4,8);

    fun5(4);
    
    return 0;
}
