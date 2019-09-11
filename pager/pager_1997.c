# include<stdio.h>
int main(int argc, char const *argv[])
{
    /* code */
    int a,b,x=2;
    printf("%d",(a=2)&&(b=-2));
    printf("x=%d,",x*=x+1);
    int k=0;
    // while (k=1)
    // {
    //     k++;
    //     printf("%d",k);
    // }
    // printf("%d",k);

    // for (int i = 0; i < 4; i++,i++)
   
    //    for (int j = 0;j < 3; j++);
    
    // printf("*");

int n;
char ch;
// for (ch=getchar(); ch!='\n'; n++){
// printf("n=%d,",n);
// };

int i,j=2;
int *p;
p=&i;
 *p= *(&j);
 printf("%d,",*p);

 char s[20]="beijing";
 char *q;
 q=s;
 printf("q=%c,",*q);

    return 0;
}


