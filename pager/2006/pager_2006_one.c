#include<stdio.h>
#include<stdlib.h>

typedef struct bnode{
    int data;
    struct bnode *rchild,*lchild;
}BTNode,*BTREE;

// 复制二叉树，
BTREE COPYBTREE(BTREE bt1){
    BTREE bt2;
    if (bt1==NULL)
    {
       return NULL;
    }else
    {
        bt2 =(BTREE) malloc(sizeof(BTNode));
        bt2->data=bt1->data;
        bt2->lchild=COPYBTREE(bt1->lchild);
        bt2->rchild=COPYBTREE(bt2->rchild);
    }
    return bt2;
    
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
