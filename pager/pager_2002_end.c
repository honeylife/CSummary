#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// #include<alloc.h>

/**
 * 命令 tail 用来打印文件中最后 n 行。命令格式为：
tail [−n] filename
其中：
−n: 要打印的行数，当省略此参数时，n 的缺省值为 10。
filename: 文件名
例如，命令 tail -20 example.txt 表示打印文件 example.txt 的最后 20 行。
请用 C 语言实现该程序，该程序应具有一定的错误处理能力，例如能处理非法命令参数和非法文
件名。
提示一：使用命令行参数；
提示二：可以使用下面的 C 库函数：
·int atoi(char *s) 将数字串转换为相应整数；
·fopen, fclose, printf, fprintf, exit； ·fgets(char *s, int n, FILE *fp) 从文件中读入一行；
·void *malloc(unsigned size), free 申请和释放内存；
·strlen 计算字符串长度；
·strcpy 将一个字符串拷贝到另一个字符串中。
除此之外，不允许使用其它库函数。
 * */
#define Line 10
#define MaxSize 81
typedef struct node
{
    char data[MaxSize];
    struct node *link;
} Node, *Linklist;
int main(int argc, char const *argv[])
{
    FILE *fp;
    int n = Line;
    char *fileName,  s[MaxSize];
    Linklist list = NULL, p = NULL, r;
    if (argc == 3 && argv[1][0] == '-')
    {
        n = atoi(argv[1] + 1);
        fileName = argv[2];
    }
    else if (argc == 2)
    {
        fileName = argv[1];
    }
    else
    {
        fprintf(stderr, "tail is error");
        exit(-1);
    }

    if ((fp = fopen(fileName, "r")) == NULL)
    {
        fprintf(stderr, "file is error\n");
        exit(-1);
    }
    // 建立循环链表
    for (int i = 0; i < n; i++)
    {
        p = (Linklist)malloc(sizeof(Node));
        p->data[0] = '\0';
        p->link = NULL;
        if (list == NULL)
        {
            list = p;
        }
        else
        {
            r->link = p;
        }
        r = p;
    }
    p->link = list;

    p = list;

    while (fgets(s, MaxSize, fp) != NULL)
    {
        strcpy(p->data, s);
        p = p->link;
    }
    r = p;
    p=p->link;
    while (p != r)
    {
        if (p->data[0]!= '\0')
        {
            puts(p->data);
        }
        p = p->link;
    }

    fclose(fp);

    return 0;
}
