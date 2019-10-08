#include <stdio.h>
#include <stdlib.h>

typedef struct bnode
{
    int data;
    struct node *lchild, *rchild;
} BNode, *BTREE;

// 判断二叉树是否相似，相似是具有相同的拓扑结构

/**
 * 分析 ： 层次遍历，
 * */

int CHECKBTREE(BTREE bt1, BTREE bt2){

    if (bt1 == NULL && bt2 == NULL){
        return 1;
    }
    // 相似的条件
    if (bt1 != NULL && bt2 != NULL &&
        CHECKBTREE(bt1->lchild, bt2->lchild) && CHECKBTREE(bt1->rchild, bt2->rchild)) {
        return 1;
    }


    /**
     *  等价的条件
     *  if (bt1 != NULL && bt2 != NULL &&bt1->data==bt2->data&&
        CHECKBTREE(bt1->lchild, bt2->lchild) && CHECKBTREE(bt1->rchild, bt2->rchild)) {
        return 1;
    }
     * */
    return 0;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}


// // 歌单 网易云音乐 「适合撩妹」节奏感强劲的车载音乐