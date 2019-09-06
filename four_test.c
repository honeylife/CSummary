# include<stdio.h>
# define M 20

// 给出十进制的数，输出对应8进制的数

int CONVERSION(int num){
    int STACK[M],top=-1;
    do
    {
        STACK[++top]=num%8;
        num = num/8;
    } while (num!=0);
    while (top>=0)
    {
        printf("%d,",STACK[top--]);
    }
    
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
