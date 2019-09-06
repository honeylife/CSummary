/**
已知线性链表第一个链结点的指针为list，请写一销毁该链表的非递归算法。
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}LNode,*LinkList;

LinkList CREATELIST();
LinkList DELETELISTS(LinkList list);
LinkList DELETELIST(LinkList list);
int SELECTED(LinkList list);
LinkList INSERTLIST(LinkList list);
LinkList INSERTEND(LinkList list);
LinkList CHANGEOVER(LinkList list);
void PRINTELE(int k);
void main(){
 LinkList list=NULL;
 list = CREATELIST(list);
 SELECTED(list);
 list=DELETELISTS(list);
 SELECTED(list);
 list= INSERTLIST(list);
 SELECTED(list);
 list= INSERTEND(list);
 SELECTED(list);
  list= CHANGEOVER(list);
 SELECTED(list);

 PRINTELE(5);

}

LinkList DELETELIST(LinkList list){
    LinkList p;
    p=list;
    while(list!=NULL){
        list = list->link;
        free(p);
        p=list;

    }

    return list;
}
/**
已知不带头结点的非空线性链表第一个链结点的指针为list，
请写一算法，删除链表中数据域内容相同的多余结点。
*/

LinkList DELETELISTS(LinkList list){
    LinkList ls,p,r,q;
    ls=list;
    p=list;
    printf("删除链表中相同的元素\n");
    while(p!=NULL){
       q=p;
       r=q->link;
       while(r!=NULL){
          if(r->data==p->data){
           printf("删除的节点为data=%d\n",r->data);
            q->link=r->link;
            free(r);
          }else{
           q=r;
          }
           r=q->link;
       }
       p=p->link;
    }
    printf("删除链表中相同的元素成功\n");
    return ls;
}
/**创建单链表
*/
LinkList CREATELIST( LinkList lst){
  LinkList list, p,q;
  list = lst;
  int n;
  printf("请输入10个数建立链表，99结束\n");
 while(n!=99){
    scanf("%d",&n);
    p=(LinkList)malloc(sizeof(LNode));
    p->data=n;
    p->link=NULL;
    if(list==NULL){
        list = p;
    }else{
      q->link=p;
    }
    q=p;
 }
 printf("链表建立成功\n");
 return list;
}

/**
遍历单链表
*/

int SELECTED(LinkList list){
    LinkList lt;
    lt =list;
    int count;
    printf("遍历链表\n");
    while(lt!=NULL){
        printf("%d,",lt->data);
        count++;
        lt=lt->link;
    }
    printf("\n");
    return count;
}

/**
已知非空线性链表第一个结点的指
针为list，请写一个算法，将该链表中数
据域值最小的那个点移到链表的最前端。
**/

LinkList INSERTLIST(LinkList list){
    LinkList p,q,r,s;
    p=list;
    int flag = 0;
    int key = p->data;
    q=p;
    r=p;
    p=p->link;
    printf("最小值调入第一个元素\n");
    while(p!=NULL){
        if(key>p->data){
          key=p->data;
          r=q;
          s=p;

        }
        // 下面两句等价
        //q=q->link;  q=p;
         q=p;
         p=p->link;

    }
    printf("移动的节点为r=%d\n",r->data);
    if(s==list){
        printf("第一个点就是最小值，不用移动\n");
    }else{
        r->link=s->link;
        s->link=list;
        list = s;
    }

    return list;
}

/**
已知非空线性链表第一个结点的指
针为list,请写一个算法,将该链表中数据
域值最大的那个结点移到链表的最后面。
*/

LinkList INSERTEND(LinkList list){
    LinkList p,q,r,s;
    p=list;
    r=p;
    q=p;
    p=p->link;
    printf("最大值调入最后元素\n");
    while(p!=NULL){
        if(r->data<p->data){
            r=p;
            s=q;
        }
        q=p;
        p=p->link;
    }
    printf("移动的节点为r=%d\n",r->data);
    if(r!=q){
        if(r!=list){
        s->link=r->link;
    }else{
        printf("移动第一个点为r=%d\n",r->data);
        list=list->link;
    }
     printf("最后的节点为q=%d\n",q->data);
        r->link=NULL;
        q->link=r;
    }


    return list;

}
/**
就地逆转一个线性链表。
*/

LinkList CHANGEOVER(LinkList list){
    LinkList p,q,r;
    if(list==NULL){
        printf("链表为空\n");
        return NULL;
    }
    p=list;
    q=p;
    p=p->link;
    q->link=NULL;
    printf("就地逆转一个线性链表。\n");
    while(p!=NULL){
       r=p->link;
       p->link=q;
       q=p;
       p=r;

    }
    list =q;
}

/**
依次输入一组整型数据，并以Ctrl+z作为输入结束，
请写一算法，该算法依次打印最后k个数据元素(设输入的元素个数超过k)。
*/
void PRINTELE(int k){
    LinkList list=NULL,p,q;
    int n;
    list = (LinkList)malloc(sizeof(LNode));
    list->data=0;
    q =list;
    printf("打印最后k个数\n");
    for(int i=1;i<k;i++){
        p=(LinkList)malloc(sizeof(LNode));
        p->data=0;
        q->link=p;
        q=p;

    }
    p->link=list;
    p=list;
    printf("请输入整数数组\n");
    while(scanf("%d",&n)>0){
        p->data=n;
        printf("%d,",n);
        p=p->link;
    }
    q=p;
    printf("\n");
    do{
        if(p->data!=0){
             printf("%d,",p->data);
        }
        p=p->link;
    }while(q!=p);
    printf("\n");
}
