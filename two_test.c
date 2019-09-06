#include <stdio.h>
#include<stdlib.h>

#define maxSize 20

typedef struct node
{
   int data;
   struct node *link;
}BNode,*LinkList;

typedef struct DNode
{
    int data;
    int freq; // 存储访问的次数
    struct DNode *llink,*rlink;
}DNode,*DLinklist;


int  fun1(int A[],int B[],int n,int m,int index){
    int i;
    for ( i = n-1; i >=index-1 ; i--)
    {
        A[m+i]=A[i];
    }
    for ( int j = 0; j< m;j++)
    {
        A[++i]=B[j];
    }
   
   return m+n; // 返回表长
}

// 删除链表中值域最大的的节点
LinkList DELETEMAX(LinkList list){
    LinkList p,q,s,r;
    p=list;
    r=p;
    p=p->link;
    while (p!=NULL){
        if (q->data<p->data)
        {
           q=p;
           s=r;
        }
        r=p;
        p=p->link;  
    }
    if (q==p)
    {
       list = list->link;
    }else
    {
       s->link=q->link;
    }
    
    free(q);
    return list;
}
// 交换P所指结点与其下一个结点的位置
LinkList EXCHANGE(LinkList list,LinkList p){
    LinkList q = list;
    if (p==q)
    {
        list=list->link;
        p->link=p->link->link;
        list->link=p;
    }else
    {
        while (q->link!=p)
        {
           q=q->link;
        }
        // 这里的顺序不能换，避免断链。
        q->link=p->link;
        p->link=p->link->link;
        q->link->link=p;
        
    }
    

    return list ;
    
}


// 已知非空线性表第一个结点由list指出。请写一算法，将链表中中最小的结点移到链表最前面。
LinkList MINHEAD(LinkList list){
    LinkList p,r,s,q;
    p=list;
    r=p;
    q=p;
    p=p->link;
    while (p!=NULL){
        if (q->data>p->data)
        {
            s=r;
            q=p;
        }
        r=p;
        p=p->link;
        if (q!=list)
        {
           s->link=q->link;
           q->link=list;
           list=q;
        }
        
        
    }
    return list;
}
// 返回链表中倒数第K个结点

LinkList SEARCHBNODE(LinkList list ,int k){
    LinkList p,q;
    if (list!=NULL&&k>0)
    {
       p=list;
       for (int i = 0; i < k; i++)
       {
          p=p->link;
          if (p==NULL)
          {
             printf("链表中不存在这样的K点");
             return NULL;
          }
          
       }
       q=list;
       while (p->link!=NULL)
       {
           p=p->link;
           q=q->link;
       }
       
    }
    return q;
    
}

// 删除链表中数据域相同的其他结点

void DELETE3(LinkList list){
    LinkList p,q,r;
    p=list;
    r=p;
    p=p->link;
    int flag=0;
    while (p!=NULL)
    {
        q=list;
        while (q!=p)
        {
           if (q->data!=p->data)
           {
              q=q->link;
           }else
           {
               flag=1;
               break;
           }
        }
        if (flag==1)
        {
           r->link=p->link;
           free(p);
           p=r->link;
           flag=0;
        }else
        {
            r=p;
            p=p->link;
        }
    }  
}

LinkList CREATELIST(int A[],int n){
    LinkList list=NULL,q,p;
    for (int i = 0; i < n; i++)
    {
        q=(LinkList)malloc(sizeof(BNode));
        q->data=A[i];
        q->link=NULL;
        if (list==NULL)
        {
            list=q;
        }else
        {
           p->link=q;
        }
        
       p=q; 
    }
    return list;
    
}
void PRINTLU(LinkList list){
    LinkList p=list;
    printf("\n");
    while (p!=NULL)
    {
       printf("%d,",p->data);
        p=p->link;
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
// 输出最后K个结点
void PRINTENDK(int k){
    LinkList list=NULL,p,r;
    int a;
    for (int i = 1; i <= k; i++)
    {
        p=(LinkList)malloc(sizeof(BNode));
        p->data=0;
        if (list ==NULL)
        {
            list=p;
        }else{
            r->link=p;
        }
        r=p;
    }
    p->link=list;
    p=list;
    while (scanf("%d",&a)>0)
    {
       p->data=a;
       p=p->link;
    }
    for (int i = 1; i <=k; i++)
    {
        if (p->data!=0)
        {
           printf("%d,",p->data);
        }
        p=p->link;  
    }
    
}

// 逆转链表的链接方向
void CHANGEOVER(LinkList list){
    LinkList p,q,r;
    p=list->link;
    q=list;
    while (p!=list)
    {
       r=q;
       q=p;
       p=p->link;
       q->link=r;
    }
    list->link=q;

}
// 合并单向循环链表

LinkList MERGELIST(LinkList rear){
    LinkList p,q,r,s;
    q=rear->link;
    p=(LinkList)malloc(sizeof(BNode));
    p->data = q->data;  // 复制q所指的数据信息
    r=p;  // 记录第一个元素的位置
    p->link=rear->link; // 将第一个元素插入链表末尾
    rear->link=p;
    q=q->link;     // 指向第二个元素
    while (q!=rear)
    {
        s = q->link;   // q所指的指针下移
        p=(LinkList)malloc(sizeof(BNode));  // 申请空间
        p->data=q->data;   // 复制q所指的数据信息
        p->link=rear->link;  // 将p插入rear所指的后面
        rear->link=p;
        q=s;            // 获得下一个处理的结点
    }

    rear=r; // 将尾指针指向r的位置，尾指针。
    return rear;
    
}

// 双向链表的访问，双向链表的排序
int LOCATE(DLinklist list,int x){
    DLinklist q,p;
    p=list->rlink;
    while (p!=NULL&&p->data!=x)
    {
       p = p->rlink;  // 判断指针下移
    }
    if (p==NULL)
    {
        return 0;  // 如果为空，说明没有和X相等的这个结点
    }else
    {
        p->freq++;  // 访问的次数加一
        q=p->llink;  // q 指向p 所指的前驱结点
        while (q!=list&&q->freq<p->freq)  // q与p的访问次数比较 条件成立需要移动指针
        {
            p->llink=q->llink;
            p->llink->rlink=p;
            q->rlink=p->rlink;
            if (p->rlink!=NULL)
            {
                q->rlink->llink=q;
            }
            q->llink=p;
            p->rlink=q;
            q=p->llink; //  q指向p的前驱结点
            
        }
        
    }
    return 1;
}

// 建立双向循环链表  反方向输出数据
DLinklist CREATEDLIN(int n){
    DLinklist list=NULL,p,q;
    list=(DLinklist)malloc(sizeof(DNode));
    list->llink=NULL;
    list->rlink=NULL;
    q=list;
    printf("input Start\n");
    for (int i = 1; i <=n; i++)
    {
         p=(DLinklist)malloc(sizeof(DNode));
         scanf("%d",&(p->data));
         p->rlink=NULL;
         p->llink=q;
         q->rlink=p;
         q=p;
    }

    list->llink=p;
    p->rlink=list; // 头尾相连，构成循环链表
    
    q=list->llink;
    while (q!=list)
    {
        printf("%d,",q->data);
        q=q->llink;
    }
    
    return list;
}

// 答案给出，求双向链表最后的数组
void CREATEDLIN2(int n){
       DLinklist list=NULL,p;
    list=(DLinklist)malloc(sizeof(DNode));
    list->llink=list;
    list->rlink=list;
    // list=p;
    // q=list;
    printf("input Start\n");
    for (int i = 1; i <=n; i++)
    {
         p=(DLinklist)malloc(sizeof(DNode));
         scanf("%d",&(p->data));
         p->llink=list;
         p->rlink=list->rlink;
         list->rlink->llink=p;
         list->rlink=p;
    }
    p=list->rlink;
    while (p!=list)
    {
        printf("%d,",p->data);
        p=p->rlink;
    }
    printf("\n");
}

// > 0 前移 ，<0 后移
int PRINT(DLinklist list){
    DLinklist p,q;
    p=list->rlink;
    if (p==list)
    {
        return 0;
    }
    while (p!=list)
    {
        if(p->data<0){
            p=p->rlink;
        }else
        {
            q=p;
            p->llink->rlink=p->rlink;
            p->rlink->llink=p->llink;
            p=p->rlink;

            q->rlink=list->rlink;
            q->llink=list;
            list->rlink->llink=q;
            list->rlink=q;
        }
        
    }
    printf("\n");
     p=list->rlink;
    while (p!=list)
    {
        printf("%d,",p->data);
        p=p->rlink;
    }
    return 1;
}
// 双向循环链表>0前移，<0 后移
int PRINTVAL(DLinklist list){
     DLinklist p=list->rlink,q=list->llink;
     int temp;
    if (p==list)
    {
        return 0;
    }
    printf("\n");
    while (p!=q)
    {
       while (p->data>0&&p!=list)
       {
           p=p->rlink;
       }
       while (q->data<0&&q!=list)
       {
           q=q->llink;
       }
       
       if (q->rlink!=p)
       {
          temp = p->data;
          p->data=q->data;
          q->data=temp;
          p=p->rlink;
          q=q->llink;
          if (q->rlink==p||(p==list&&q==list))
          {
             return 1;
          }
          
       }else
       {
           return 1;
       }
    }

    
}

// 刪除鏈錶中多余的结点
void DELETE(LinkList list){
    LinkList p,q ,r;
    p=list;
   while (p!=NULL) { 
       r=p;
       q=p->link;
       while(q!=NULL){
           if (q->data==p->data){
               r->link=q->link;
               free(q);
               q=r->link;
           }else{
               r=q;
               q=q->link;
           }
       }
       p=p->link;
   }
}


// 合并两个 有序的单链表，让其有序
LinkList MARGELIST(LinkList l1,LinkList l2){
    LinkList list ,p,q,r,s;
    q=l2;
    list =l1;
    p=list;
    r=p;
    while (p!=NULL&&q!=NULL) {
       
          if (p->data<q->data){
              r=p;
              p=p->link;
          }else{
              s=q;
              q=q->link;
              s->link=p;
              if (r==p) {
                  r=s;
                  list=r;
              }else{
                 r->link=s; 
                  r=s;  
              }
          }

    }
    if (q!=NULL){
        r->link=q;
    }
    
    return list;
}

int main(int argc, char const *argv[])
{
    int A[]={1,2,2,3,4,6};
    int B[]={2,3,9};

// printvules(A,6);
// printvules(B,3);
// fun1(A,B,6,3,3);
LinkList list1 = CREATELIST(A,6);

LinkList list2 = CREATELIST(B,3);
PRINTLU(list1);
// DELETE(list);
PRINTLU(list2);
LinkList list = MARGELIST(list2,list1);
PRINTLU(list);
// DELETE3(list);
// PRINTLU(list);1
// printf("input a!! \n");
// PRINTENDK(5);
// DLinklist dlist = CREATEDLIN(6);
// PRINT(dlist);
// CREATEDLIN2(5);
// PRINTVAL(dlist);
// printf("\n");
//   DLinklist p=dlist->rlink;
//     while (p!=dlist)
//     {
//         printf("%d,",p->data);
//         p=p->rlink;
//     }
    return 0;
}
