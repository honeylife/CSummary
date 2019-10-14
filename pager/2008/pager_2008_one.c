#include<stdlib.h>
#include<stdio.h>
/**
 * 依次输出从键盘输入元素的最后K个元素，并假设k<=元素个数
 * 要求：Ctrl+z 结束输入
 *      不能使用数组。
 * */
typedef struct node
{
    int data;
    struct node *link;
}Node,*Linklist;


int main(int argc, char const *argv[])
{
    Linklist list=NULL,p,r;
    int n=0,k=0;
    printf("input k:\n");
    scanf("%d",&k);
    printf("creat linklist \n");
    // 创建单链表
    while (scanf("%d",&n))
    {
       p=(Linklist)malloc(sizeof(Node));
       p->data=n;
       p->link=NULL;
       if (list==NULL)
       {
           list=p;
       }else
       {
           r->link=p;
       }
       r=p;
    }

    p=list;
    for (int i = 0; i < k; i++)
    {
       r=p; 
       p=p->link; 

    }

    p=list;
    while (r->link!=NULL)
    {
      r=r->link;
      p=p->link;
    }
    while (p!=NULL)
    {
        printf("%d,",p->data);
        p=p->link;
    }
    return 0;
}
