#include <stdio.h>
#include <stdlib.h>

#define len sizeof(BTNode)
#define MAXSize 100
typedef struct bNode
{
    int data;
    struct bNode *lchild, *rchild;

} BTNode, *BTREE;

// 建立二叉树链表结构
BTREE CTREATEBLINK(int BT[], int n)
{
    BTREE T = NULL, PRT[MAXSize];
    int j = 0;
    PRT[j] = (BTREE)malloc(len);
    PRT[j]->data = BT[0];
    PRT[j]->rchild = NULL;
    PRT[j]->lchild = NULL;
    T = PRT[j];
    for (int i = 1; i < n; i++)
    {
        if (BT[i] != 0)
        {
            PRT[i] = (BTREE)malloc(len);
            PRT[i]->data = BT[i];
            PRT[i]->rchild = NULL;
            PRT[i]->lchild = NULL;
            j = (i - 1) / 2;
            if (i - 2 * j - 1 == 0)
            {
                PRT[j]->lchild = PRT[i];
            }
            else
            {
                PRT[j]->rchild = PRT[i];
            }
        }
    }

    return T;
}

// 一分为二 数组

void search(int A[], int item, int n)
{
    int flag = 0;
    int temp;
    for (int i = 0, j = n; i <= j; )
    {
        if (flag == 0)
        {

            if (A[i] < item)
            {
                i++;
            }
            else
            {
                temp = A[i];
                flag = 1;
                printf("temp=%d,",temp);
            }
        }
        if (flag == 1)
        {
            if (A[j] > item)
            {
                j--;
            }
            else
            {
                A[i] = A[j];
                A[j] = temp;
                i++;
                j--;
                flag = 0;
                printf("i=%d,j=%d,\n", A[i], A[j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d,", A[i]);
    }
}

int main(int argc, char const *argv[])
{
    int A[] = {43, 56, 78, 89, 20, 11, 23, 45};
    search(A, 45, 8);
    return 0;
}
