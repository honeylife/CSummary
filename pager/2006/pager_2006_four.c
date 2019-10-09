#include <stdio.h>
#include <stdlib.h>

// 合并文件，fat.c ,命令，将文件file file2 file3 合并到fat.c上。
int main(int argc, char const *argv[])
{
    FILE *fp, *fp1, *fp2, *fp3;
    char s[80];
    if ((fp = fopen(argv[0], "w")) == NULL)
    {
        fprintf(stderr, "filename is error");
        exit(-1);
    }

    if ((fp1 = fopen(argv[1], "r")) != NULL)
    {
        while (fgets(s, 80, fp1))
        {
            fputs(s, fp);
        }
    }
    if ((fp2 = fopen(argv[2], "r")) != NULL)
    {
        while (fgets(s, 80, fp2))
        {
            fputs(s, fp);
        }
    }
    if ((fp3 = fopen(argv[3], "r")) != NULL)
    {
        while (fgets(s, 80, fp3))
        {
            fputs(s, fp);
        }
    }

    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    fclose(fp2);
    return 0;
}
