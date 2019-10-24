#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/**
 * 一个有向图，顶点存储在G[0..n-1]中，用领接表存储，判断是否有拓扑排序
 * 
*/
typedef struct edge  // 边结点
{
    int adjvex;  // 改边的终止结点在顶点结点中的位置
    struct edge *next;
}ELink;

typedef struct ver{  // 顶点信息
    int indegree; // 记录入度
    int data; // 顶点的数据信息
    ELink *link; // 指向第一个边结点
}Vlink;

// 检测是不是拓扑排序 
int TOPO_TEST(Vlink G[],int n,int V[]){
    ELink *p;
    int i ,k;
    for ( i = 0; i < n; i++)  // 控制V【n】 的数据，依次遍历
    {
        for ( k = 0; i < n; i++) // 控制G【n】的数据，依次遍历
        {
            if (G[k].data==V[i])  // 表示如果 v[i]的信息是G[k]的信息，表示两个顶点的信息相同
            {
                if (G[k].indegree!=0) // 判断是不是入度为0 。如果不是0 这表示不是拓扑排序
                {
                    return 0;
                }
                p=G[k].link;  // 指向下一个顶点信息
                while (p!=NULL)  // 循环 G[k]所指的所有邻接表的顶点的入度减去1
                {
                    G[p->adjvex].indegree--; // 表示下一个顶点的入度减去1；
                    p=p->next;
                }
                break; // 表示一个顶点处理结束，立马结束，进行下一个V【i】顶点
            }
            
        }
        
    }
    
}

int fun(char *s,char *t){
    puts(s);
    puts(t);
    while (*t&&*s&&*s==*t)
    {
        s++;
        t++;
    }
    puts(s);
    puts(t);
    printf("%d\n",*s);
    printf("%d\n",*t);

    printf("%d\n",strlen(s));
    printf("%d\n",strlen(t));
    return *s-*t;
}
int main(int argc, char const *argv[])
{
    // int x=6;
    // x+=x-=x*x;
    // printf("%d\n",x);

    // char *p,*q;
    // p=(char *)malloc(sizeof(char)*20);
    // q=p;
    // scanf("%s%s",p,q);
    // printf("p=%sq=%s\n",p,q);

    // int a,k=3;
    // a=++ABC(k+1);
    // printf("%d,k=%d\n",a,k);

    char s[20]={"zhanghskghskg"};
    char b[10]={"hahah"};
int a =fun(s,b);
printf("%d\n",a);
    return 0;
}
