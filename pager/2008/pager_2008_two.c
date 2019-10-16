#include <stdio.h>
#include <stdlib.h>
/**
 * 写一个非递归算法，判断判断是否为二叉排序树
*/
#define MAX 10
typedef struct bnode
{
    int data;
    struct bnode *lchild, *rchild;
} BNode, *BTREE;

/**
 * 利用中序遍历，中序遍历次序是有序序列
*/
int CHECKBT(BTREE BT)
{
    BTREE STACK[MAX], p = BT;
    int top = -1, key=0;
    if (BT == NULL)
    {
        return 0;
    }
    // STACK[0]=BT;
    // front=-1;
    // rear = 0;

    // while (front!=rear)
    // {
    //     q=QUEUCE[++front];

    //     if (q->lchild!=NULL)
    //     {
    //         QUEUCE[++rear]=q->lchild;
    //     }
    //     if (q->rchild!=NULL)
    //     {
    //        QUEUCE[++rear]=q->rchild;
    //     }

    // }

    do
    {
        while (p != NULL)
        {
            STACK[++top] = p;
            p = p->lchild;
        }
        p = STACK[top--];
        if (p->data < key)
        {
            return 0;
        }
        key = p->data;
        p = p->rchild;

    } while (!(p == NULL && top == -1));

    return 1;
}
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
