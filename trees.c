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
    printf("����������\n");
     BULIDBT(bt);
    printf("�������ĵĽڵ���\n");
    int a= BTREELEN(bt);
    printf("%d\n",a);
     printf("���\n");
    printf("%d\n",BTLEN(bt));


    printf("ǰ�����\n");
    RREORDER(bt);
    printf("�������\n");
    INORDER(bt);
    printf("�������\n");
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

// 叶子节点�?
int BTREELEN(BTREE bt){
 if(bt==NULL){
    return 0;
 }

 if(bt->lchild==NULL && bt->rchild==NULL){
    return 1;
 }
  printf("�ڵ��ֵ%d,",bt->data);
 BTREE q = bt->lchild;
 printf("���ӽڵ��ֵ%d,",q->data);
 BTREE p = bt->lchild;
  printf("�к��ӽڵ��ֵ%d,",p->data);
 return(BTREELEN(bt->lchild)+BTREELEN(bt->rchild));
}

// 树的层数

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


