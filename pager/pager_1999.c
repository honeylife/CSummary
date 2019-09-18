#include<stdio.h>
#include<stdlib.h>


typedef struct bNode
{
    int data;
    struct bNode *lchild,*rchild;
}BNode,*BTREE;


/**
 * 深度为h的二叉树，顺序存储结构BT[1,zh-1]中，建立链式结构的二叉树
 * */

BTREE CREATE(int BT[],int h){
    BTREE T=NULL,PTR[2*h-1];
    PTR[1]=(BTREE)malloc(sizeof(BNode));
    PTR[1]->data=BT[1];
    PTR[1]->lchild=NULL;
    PTR[1]->rchild=NULL;
    T=PTR[1];
    int j;
    for (int i = 2; i < 2*h-1; i++)
    {
        if (BT[i]!=0)
        {
             PTR[i]=(BTREE)malloc(sizeof(BNode));
             PTR[i]->data=BT[i];
             PTR[i]->lchild=NULL;
             PTR[i]->rchild=NULL;
            j = i/2;
            if (i-2*j==0)
            {
               PTR[j]->lchild=PTR[i];
            }else
            {
                PTR[j]->rchild=PTR[i];
            }
            
            
        }
        
    }
    
}

int main(int argc, char const *argv[])
{
    int h =3;
     int BT[10]={1,2,3,4}; //这里随便给出了一个满二叉树的结构
     CREATE(BT,2*h-1);
     
    return 0;
}
