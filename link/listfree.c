/**
��֪���������һ��������ָ��Ϊlist����дһ���ٸ�����ķǵݹ��㷨��
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}LNode,*LinkList;

LinkList CREATELIST();
LinkList DELETELISTS(LinkList list);
LinkList DELETELIST(LinkList list);
int SELECTED(LinkList list);
LinkList INSERTLIST(LinkList list);
LinkList INSERTEND(LinkList list);
LinkList CHANGEOVER(LinkList list);
void PRINTELE(int k);
void main(){
 LinkList list=NULL;
 list = CREATELIST(list);
 SELECTED(list);
 list=DELETELISTS(list);
 SELECTED(list);
 list= INSERTLIST(list);
 SELECTED(list);
 list= INSERTEND(list);
 SELECTED(list);
  list= CHANGEOVER(list);
 SELECTED(list);

 PRINTELE(5);

}

LinkList DELETELIST(LinkList list){
    LinkList p;
    p=list;
    while(list!=NULL){
        list = list->link;
        free(p);
        p=list;

    }

    return list;
}
/**
��֪����ͷ���ķǿ����������һ��������ָ��Ϊlist��
��дһ�㷨��ɾ��������������������ͬ�Ķ����㡣
*/

LinkList DELETELISTS(LinkList list){
    LinkList ls,p,r,q;
    ls=list;
    p=list;
    printf("ɾ����������ͬ��Ԫ��\n");
    while(p!=NULL){
       q=p;
       r=q->link;
       while(r!=NULL){
          if(r->data==p->data){
           printf("ɾ���Ľڵ�Ϊdata=%d\n",r->data);
            q->link=r->link;
            free(r);
          }else{
           q=r;
          }
           r=q->link;
       }
       p=p->link;
    }
    printf("ɾ����������ͬ��Ԫ�سɹ�\n");
    return ls;
}
/**����������
*/
LinkList CREATELIST( LinkList lst){
  LinkList list, p,q;
  list = lst;
  int n;
  printf("������10������������99����\n");
 while(n!=99){
    scanf("%d",&n);
    p=(LinkList)malloc(sizeof(LNode));
    p->data=n;
    p->link=NULL;
    if(list==NULL){
        list = p;
    }else{
      q->link=p;
    }
    q=p;
 }
 printf("�������ɹ�\n");
 return list;
}

/**
����������
*/

int SELECTED(LinkList list){
    LinkList lt;
    lt =list;
    int count;
    printf("��������\n");
    while(lt!=NULL){
        printf("%d,",lt->data);
        count++;
        lt=lt->link;
    }
    printf("\n");
    return count;
}

/**
��֪�ǿ����������һ������ָ
��Ϊlist����дһ���㷨��������������
����ֵ��С���Ǹ����Ƶ��������ǰ�ˡ�
**/

LinkList INSERTLIST(LinkList list){
    LinkList p,q,r,s;
    p=list;
    int flag = 0;
    int key = p->data;
    q=p;
    r=p;
    p=p->link;
    printf("��Сֵ�����һ��Ԫ��\n");
    while(p!=NULL){
        if(key>p->data){
          key=p->data;
          r=q;
          s=p;

        }
        // ��������ȼ�
        //q=q->link;  q=p;
         q=p;
         p=p->link;

    }
    printf("�ƶ��Ľڵ�Ϊr=%d\n",r->data);
    if(s==list){
        printf("��һ���������Сֵ�������ƶ�\n");
    }else{
        r->link=s->link;
        s->link=list;
        list = s;
    }

    return list;
}

/**
��֪�ǿ����������һ������ָ
��Ϊlist,��дһ���㷨,��������������
��ֵ�����Ǹ�����Ƶ����������档
*/

LinkList INSERTEND(LinkList list){
    LinkList p,q,r,s;
    p=list;
    r=p;
    q=p;
    p=p->link;
    printf("���ֵ�������Ԫ��\n");
    while(p!=NULL){
        if(r->data<p->data){
            r=p;
            s=q;
        }
        q=p;
        p=p->link;
    }
    printf("�ƶ��Ľڵ�Ϊr=%d\n",r->data);
    if(r!=q){
        if(r!=list){
        s->link=r->link;
    }else{
        printf("�ƶ���һ����Ϊr=%d\n",r->data);
        list=list->link;
    }
     printf("���Ľڵ�Ϊq=%d\n",q->data);
        r->link=NULL;
        q->link=r;
    }


    return list;

}
/**
�͵���תһ����������
*/

LinkList CHANGEOVER(LinkList list){
    LinkList p,q,r;
    if(list==NULL){
        printf("����Ϊ��\n");
        return NULL;
    }
    p=list;
    q=p;
    p=p->link;
    q->link=NULL;
    printf("�͵���תһ����������\n");
    while(p!=NULL){
       r=p->link;
       p->link=q;
       q=p;
       p=r;

    }
    list =q;
}

/**
��������һ���������ݣ�����Ctrl+z��Ϊ���������
��дһ�㷨�����㷨���δ�ӡ���k������Ԫ��(�������Ԫ�ظ�������k)��
*/
void PRINTELE(int k){
    LinkList list=NULL,p,q;
    int n;
    list = (LinkList)malloc(sizeof(LNode));
    list->data=0;
    q =list;
    printf("��ӡ���k����\n");
    for(int i=1;i<k;i++){
        p=(LinkList)malloc(sizeof(LNode));
        p->data=0;
        q->link=p;
        q=p;

    }
    p->link=list;
    p=list;
    printf("��������������\n");
    while(scanf("%d",&n)>0){
        p->data=n;
        printf("%d,",n);
        p=p->link;
    }
    q=p;
    printf("\n");
    do{
        if(p->data!=0){
             printf("%d,",p->data);
        }
        p=p->link;
    }while(q!=p);
    printf("\n");
}
