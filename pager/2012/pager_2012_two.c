#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/**
 * 判断某个字符在字符串中的首次位置 ，然后删除该字符
 * 要求：如果未找到，给出相应的信息， 如果找到则删除该字符，并且显示删除前后的字符串
 * */
int main(int argc, char const *argv[])
{
    char str[80],ch;
    int flag=0,i;
    printf("INput str:\n");
    gets(str);
    printf("input ch:\n");
    scanf("%c",&ch);
    for ( i = 0; str[i]!='\0'; i++){
        if (str[i]==ch){
           flag=1;
            break;
        }
        
    }
    if (flag==0){
        printf("no char %c\n",ch);
    }else{
        puts(str);
        printf("position is %d\n",i+1);
        for (; str[i]!='\0'; i++)
        {
            str[i]=str[i+1];
        }
        str[i]='\0';
        puts(str);

    }
    
    
    
    return 0;
}
