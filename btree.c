# include<stdio.h>
# include<stdlib.h>
// 二叉树的深度

# define M 50
typedef struct node{
    int data;
    struct node *lchild,*rchild;
}BNode,*BTREE;

int DEPTHBT(BTREE T){
    BTREE STACK[M],p=T;
    int STACK2[M];
    int curdepth,maxdepth=0,top=-1;
    if (T!=NULL)
    {
        curdepth=1;
        do
        {
            while (p!=NULL)
            {
                STACK[++top]=p;
                STACK2[top]=curdepth;
                p=p->lchild;
                curdepth++;
            }
            p=STACK[top];
            curdepth=STACK2[top--];
            if (p->lchild==NULL&&p->rchild==NULL)
            {
                if (curdepth>maxdepth)
                {
                    maxdepth=curdepth;
                }
                
            }
            p=p->rchild;
            curdepth++;
            
        } while (!(p==NULL&&top==-1));
        
    }
    
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
