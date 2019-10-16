#include <stdio.h>
#include <stdlib.h>
/**
 * 二叉树的链表，非递归算法求q结点所指的兄弟节点
*/

typedef struct bnode
{
    int data;
    struct bnode *lchild, *rchild;
} BNode, *BTREE;

#define MaxSize 10

// 层次遍历
BTREE SEARCHBTREE(BTREE BT, BTREE q)
{
    BTREE QUEUE[MaxSize], p = BT;
    int front = -1, rear = 0;
    if (BT == NULL)
    {
        return NULL;
    }
    QUEUE[0] = BT;
    while (front < rear)
    {
        p = QUEUE[++front];
       
       
        if (p->lchild != NULL)
        {
             if (q->lchild == p)
        {
            return q->rchild;
        }else{
            QUEUE[++rear] = p->lchild;}
        }
        if (p->rchild != NULL)
        {
             if (q->rchild == p)
        {
            return q->lchild;
        }else{
            QUEUE[++rear] = p->rchild;}
        }
    }

    return NULL;
}

// 前序遍历
BTREE SELECT(BTREE bt, BTREE p)
{
    BTREE STACK[MaxSize], q = bt;
    int top = -1;
    if (bt == NULL)
    {
        return NULL;
    }
    do
    {
        while (q != NULL)
        {
            if (q->lchild == p)
            {
                return q->rchild;
            }
            if (q->rchild == p)
            {
                return q->lchild;
            }

            STACK[++top] = p;
            p = p->lchild;
        }
        p = STACK[top--];
        p = p->rchild;

    } while (!(q == NULL && top == -1));
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
