#include <stdio.h>
#include<stdlib.h>

typedef struct node{
  int data;
  struct node *rchild,*lchild;
}BTNode,* BTREE;
   void BULIDBT(BTREE bt);
    void INORDER(BTREE bt);
    void RREORDER(BTREE bt);
    void POSTORDER(BTREE bt);
    int BTLEN(BTREE bt);
    int BTREELEN(BTREE bt);
void main(){
    printf("%s","Hello word !\n");
   
    BTREE bt=NULL;
    printf("建立二叉树\n");
     BULIDBT(bt);
    printf("二叉树的的节点数\n");
    int a= BTREELEN(bt);
    printf("%d\n",a);
     printf("深度\n");
    printf("%d\n",BTLEN(bt));


    printf("前序遍历\n");
    RREORDER(bt);
    printf("中序遍历\n");
    INORDER(bt);
    printf("后序遍历\n");
    POSTORDER(bt);
    printf("end\n");
}

void BULIDBT(BTREE bt){
    int n;
    scanf("%d",&n);
    if(n==0){
       bt=NULL;
    }else {
        bt = (BTREE)malloc(sizeof(struct node));
        bt->data=n;
        BULIDBT(bt->lchild);
        BULIDBT(bt->rchild);
    }
}


void INORDER(BTREE bt){
    if(bt==NULL){
        printf("NULL\n");
    }
    if(bt!=NULL){
        INORDER(bt->lchild);
        printf("%d,",bt->data);
        INORDER(bt->rchild);
    }
}

void RREORDER(BTREE bt){
    if(bt==NULL){
        printf("NULL\n");
    }
    if(bt!=NULL){
        printf("%d,",bt->data);
        RREORDER(bt->lchild);
        RREORDER(bt->rchild);
    }
}

void POSTORDER(BTREE bt){
    if(bt==NULL){
        printf("NULL\n");
    }
    if(bt!=NULL){

        POSTORDER(bt->lchild);
        POSTORDER(bt->rchild);
         printf("%d,",bt->data);
    }
}

// 鍙跺瓙鑺傜偣鏁?
int BTREELEN(BTREE bt){
 if(bt==NULL){
    return 0;
 }

 if(bt->lchild==NULL && bt->rchild==NULL){
    return 1;
 }
  printf("节点的值%d,",bt->data);
 BTREE q = bt->lchild;
 printf("左孩子节点的值%d,",q->data);
 BTREE p = bt->lchild;
  printf("有孩子节点的值%d,",p->data);
 return(BTREELEN(bt->lchild)+BTREELEN(bt->rchild));
}

// 鏍戠殑灞傛暟

int BTLEN(BTREE bt){
    int leftdep,rightdep;
    if(bt==NULL){
        return 0;
    }
    else{
        leftdep=BTLEN(bt->lchild);
        rightdep=BTLEN(bt->rchild);
        if(leftdep>rightdep){
            return leftdep+1;
        }else{
            return rightdep+1;
        }
    }
}


