#include<stdio.h>
#include<stdlib.h>

typedef struct bNode
{
    int data;
    struct bNode *lchild,*rchild;
}BNode,*BTREE;

int SEARCHINDEX(int INOD[],int item,int n);
void INSERTITEM(BTREE T,int item,int INOD[],int n);

/**
 * 
 *  已知中序遍历 和后序遍历，建立二叉树  非递归算法设计 
 *  分析：逐点插入法， 将后序插入到中序中
 *       假设后序POSOD[0..n-1],中序为 INOD[0..n-1]
 *     2、插入时，逆序遍历POSOD的每一个元素
 *     3、插入时，其实就是找，后序每一个元素在中序数据中的位置。
 * **/

// 主算法
BTREE CREATEBTRE(int n,int INOD[],int POSOD[]){
    BTREE T=NULL;
    int i;
    for ( i = n-1; i >0; i--)
    {
        INSERTITEM(T,POSOD[i],INOD,n);
    }

    // 假如给的前序遍历和中序遍历 又该如何做了，其他的逻辑一样，就是将前序序列插入到中序中。
    // 假设前序遍历的序列为PREOD[0..n-1];
    //  for ( i = 0; i<n; i++)
    // {
    //     INSERTITEM(T,PREOD[i],INOD,n);
    // }


    return T;

}

// 查询后序数据在中序中的位置 

int SEARCHINDEX(int INOD[],int item,int n){
    int i;
    for ( i = 0; i < n; i++)
    {
        if(INOD[i]==item)
            return i+1;
    }
    
}

// 插入的算法
void INSERTITEM(BTREE T,int item,int INOD[],int n){
    BTREE p,q;
    int index=0; // 用来判断位置
    p=(BTREE)malloc(sizeof(BNode));
    p->data=item;
    p->lchild=NULL;
    p->rchild=NULL;
    if (T==NULL)
    {
        T=p;
    }else
    {
        index = SEARCHINDEX(INOD,item,n); // 首先找到item在中序遍历的位置。
        q=T;
        while (1) // 从根节点开始找插入的位置
        {
            if (index<SEARCHINDEX(INOD,q->data,n))  // 表示在左子树
            {
                if (q->lchild!=NULL)
                {
                    q=q->lchild;
                }else
                {
                    q->lchild=p;
                    break;
                }
                
            }else    // 表示在右子树
            {
               if (q->rchild!=NULL)  // 如果右子树的结点不为空，继续遍历
                {
                    q=q->rchild;
                }else
                {
                    q->rchild=p;
                    break;
                }
            }
        
        }
        
    }
    
    
}

int main(int argc, char const *argv[])
{
    int INOD[]={1,2,3,4,5,6,7}; //这里随便给出了一个满二叉树的结构
    int PREOD[]={4,2,1,3,6,5,7};
    int POSON[]={1,3,2,5,7,6,4};
    BTREE bt = CREATEBTRE(7,INOD,POSON);
    return 0;
}
