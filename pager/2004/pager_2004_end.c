#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define Maxsize 81
#define Line 10
typedef struct node
{
    char data[Maxsize];
    struct node *link;
} Node, *LinkList;

int main(int argc, char const *argv[])
{
    FILE *fp;
    char s[Maxsize], *fileName;
    int n = Line;
    LinkList list = NULL, p, r;
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
        fprintf(stderr, "file is error！\n");
        getch();
        exit(-1);
    }

    if ((fp=fopen(fileName,"r"))==NULL)
    // if ((fp = fopen("d:\\work\\Cspace\\words.txt", "r")) == NULL)
    {
        fprintf(stderr, "file open error\n");
        // getch();
        exit(-1);
    }
    for (int i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(Node));
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

    while (fgets(s, Maxsize, fp))
    {
        strcpy(p->data, s);
        p = p->link;
    }

    r = p;
    p = p->link;
    while (r != p)
    {
        if (*(p->data) != '\0')
        {
            puts(p->data);
        }

        p = p->link;
    }

    fclose(fp);

    return 0;
}
