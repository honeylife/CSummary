#include<stdio.h>
#include<stdlib.h>
# define M 20
typedef struct node{
    int data;
    struct node *link;
}Node,*Linklist;

typedef struct bNode{
    int data;
    struct bNode *lchild,*rchild;
}BNode,*BTREE;

typedef struct QNode
{
    BNode data;
    int front,rear;
}QNode,QUEUELink;

Linklist DELETE(Linklist list){
    Linklist p,q ,r;
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
   return list;
}

//求双亲结点。

BTREE getparent(BTREE T ,int key){
    BTREE q,p;
    p=T;
    int flag;
    int flag2 =0; 
    BTREE STACK1[M];
    int top =-1,STACK2[M];
    do
    {
        while (p!=NULL)
        {
            STACK1[++top]=p;
            p=p->lchild;
            STACK2[top]=0;
        }
        p=STACK1[top];
        flag=STACK2[top--];
        if (flag==0)
        {
            STACK1[++top]=p;
            STACK2[top]=1;
             if (flag2==1)
            {
                return p;
            }
            p=p->rchild;
        }else{
            if (flag2==1)
            {
                return p;
            }
            
            printf("%d",p->data);
            if (p->data==key)
            {
                flag2=1;
            }
            
        }
        
        
    } while (!(p==NULL||top==-1));
    
 return NULL;
}


// 链式结构 简单选择排序的算法

void SELECTLIST(Linklist list){
    Linklist p,q;
    p=list;
    int temp;
    while (p!=NULL){
       q = p->link;
       while (q!=NULL){
         if (p->data>q->data){
             temp = p->data;
             p->data=q->data;
             q->data=temp;
         }
         q=q->link;
       }
       p=p->link;
    }
}

// 创建链表
Linklist CREATLIST(int A[],int n){
    Linklist list = NULL,p,r;

    for (int i = 0; i < n; i++)
    {
        p=(Linklist)malloc(sizeof(Node));
        p->data = A[i];
        p->link=NULL;
        if (list ==NULL)
        {
            list =p;
        }else
        {
            r->link=p;
        }
        r=p;
        
    }
    return list;
    
}

// 遍历链表
void PRINT(Linklist list){
    Linklist p = list;
    printf("\n");
    while (p!=NULL)
    {
       printf("%d,",p->data);
       p=p->link;
    }
    printf("\n");
}

// 求结点在排序二叉树的层次
// int BTREEKEY(BTREE T,int key){
//     BTREE QUEUE[M];
//     int front=-1,rear = -1;
//     do
//     {
//         /* code */
//     } while (/* condition */);
    
// }

// 求二叉树中所有结点的值
    int TOTALCOUNT(BTREE T){

        BTREE STACK[M],p=T;
        int top=-1;
        int count=0;
        do
        {
            while (p!=NULL)
            {
                STACK[++top]=p;
                p=p->lchild;
            }
            p=STACK[top--];
            count+=p->data;
            if (p->rchild!=NULL)
            {
                p=p->rchild;
            }
            
        } while (!(p==NULL||top==-1));
        
    }

// 设计将所有的奇数移到偶数之前
void TRANCATION(int A[],int  n){
     printf("change before data:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d,",A[i]);
    }
    printf("\n");
    int temp=0;
    int flag=0;
    int flagj=0;

    for (int i = 0,j=n-1; i<=j; )
    {
       if (A[i]%2!=0)
       {
         i++;
       }else
       {
           flag=1;
       }
       
       if (A[j]%2==0)
       {
           j--;
       }else
       {
           flagj=1;
       }
       
       if (flag ==1&&flagj==1)
       {    
       temp = A[i];
       A[i]=A[j];
       A[j]=temp;
       i++;
       j--;
       flag=0;
       flagj=0;
       }
       
       
    }
    
    printf("change after data:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d,",A[i]);
    }
    
}
//判断单链表中元素是不是递增


int main(int argc, char const *argv[])
{
  int A[]={12,34,45,23,11,23,34,56,78,90};
//   Linklist list =  CREATLIST(A,10);
//   PRINT(list);
//   SELECTLIST(list);
//   PRINT(list);
TRANCATION(A,10);
    return 0;
}
