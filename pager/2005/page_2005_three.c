#include<stdio.h>
#include<stdlib.h>

// 约瑟夫实验，共有n个人，从k的位置开始，间隔m个数，进行游戏，

typedef struct node
{
   int data;
   struct node *link;
}Node,*LinkList;

int main(int argc, char const *argv[])
{
   int n,m,k,i;
   LinkList list=NULL,p,r,q;
   printf("please input n,m,k:\n");
   scanf("%d,%d,%d",&n,&m,&k);
   // 建立循环链表
   for ( i = 1; i <= n; i++)
   {
      p=(LinkList)malloc(sizeof(Node));
      p->data=i;
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
   p->link=list;

   p=list;

//    初始位置，让指针指到k的位置
for ( i = 1; i < k; i++)
{
    r=p;
    p=p->link;
}

while (r!=p)
{
  for ( i = 1; i <m; i++)
  {
      r=p;
      p=p->link;
  }
  
  q=p;
  printf("%d,",q->data);
  r->link=p->link;
  p=p->link;
  free(q);
}

  printf("%d",p->data);
   
       return 0;
}
