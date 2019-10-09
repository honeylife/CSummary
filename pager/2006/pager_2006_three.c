#include<stdio.h>
// 同构数 比如5 就是。 1-1000以内的同构数

void fun(){

    for (int i = 2; i < 1000; i++)
    {
        int s=i*i-i;
       if (i<10&&s%10==0)
       {
          printf("%d,",i);
       }
       
        if (i<100&&s%100==0)
       {
          printf("%d,",i);
       }
       
        if (i<1000&&s%1000==0)
       {
          printf("%d,",i);
       }
    }
    
}

int main(int argc, char const *argv[])
{
    fun();
    return 0;
}
