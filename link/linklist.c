#include <stdio.h>
//include <alloc.h>
#include <stdlib.h>
/**
亚瑟夫游戏
**/
typedef struct node{
 int data;
 struct node *link;
}LNode,*LinkList;
LinkList creatLink(int n);
void main(){
    int n,k,m; // n 为总数，k 从k开始报数，m 中间隔m个值；
    void fun(int n,int k,int m);
    printf("please input n,k,m\n");
    scanf("%d,%d,%d",&n,&k,&m);
    fun(n,k,m);
}

void fun(int n,int k,int m){
    LinkList list=NULL,p,q;
    int i =0;
    list= creatLink(n);
    p=list;
    while(p->link!=list){
        printf("%d,",p->data);
        p=p->link;
    }
     printf("%d\n",p->data);
    printf("\n刚开始让指针移动到开始报数的位置\n");
    for(i=1;i<k;i++){
        q=p;
        p=p->link;
    }

    while(p->link!=p){
        for(i=1;i<=m;i++){
            q=p;
            p=p->link;
        }

        q->link=p->link;
        printf("%d,",p->data);
        free(p);
        p=q;
    }
     printf("%d\n",p->data);
     printf("输出数据结束，game over！");

}

LinkList creatLink(int n){
    LinkList list=NULL, p,q;
      for(int i = 1;i<=n;i++){
         p = (LinkList)malloc(sizeof(LNode));
         p->data=i;
         p->link=NULL;
         if(list==NULL){
            list=p;
         } else{
            q->link=p;
         }
         q=p;
    }
    q->link=list;
    return list;
}

