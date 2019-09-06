#include <stdio.h>
int fun(int i){
    printf("i=%d,",i);
    if (i==0)
    {
       return 1;
    }else {
        int n =fun(i-1)+1;
        printf("n=%d,",i);
        return n;
    }
    
}
int main(int argc, char const *argv[])
{
    int n= fun(4);
    printf("%d",n);
    return 0;
}
