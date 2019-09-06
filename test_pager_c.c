#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int days(int flag, int month);
// 字符串 的获取
void chardstr()
{
    int a = 'A';
    char *p = &a;
    scanf("%c,", p);
    printf("p=%c\n", *p);
    printf("a=%d,\n", a);
    *p = 'O';
    printf("==========");
    printf("p=%c\n", *p);
    printf("a=%d,\n", a);
}

int fun(int i)
{
    static int n = 1;
    return n = n * i;
}

int fun2(int A[], int n)
{
    int i, j;
    for (i = 0, j = i; i < n; i++)
    {
        if (A[i] > A[j])
        {
            j = i;
        }
    }
    return j;
}

// 把560分钟用小时和分表示

void fun3()
{
    int month = 560;
    int hour, second;
    hour = month / 60;
    second = month % 60;
    printf("总共是%d小时%d分钟", hour, second);
}

// 定义一个20的数组，然后赋予1-50个的随机数，然后小到大排序，
fun4()
{
    int A[20];
    for (int i = 0; i < 20; i++)
    {
        A[i] = rand() % (50 - 1 + 1) + 1;
        printf("%d,", A[i]);
    }
    printf("\n");
    int temp;
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 20 - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 20; i++)
    {
        printf("%d,", A[i]);
    }
    printf("\n");
}

// 牛顿迭代求根的问题 ×⑹
fun5()
{
    double x, x1, f, f1;
    x1 = 1.5;
    do
    {
        x = x1;
        //  f=2*x*x*x-4*x*x+3*x-6;
        f = 2 * pow(x, 3) - 4 * pow(x, 2) + 3 * x - 6;
        //  f1=6*x*x-8*x+3;
        f1 = 6 * pow(x, 2) - 8 * x + 3;
        x1 = x - f / f1;
    } while (fabs(x - x1) <= 10e-5);

    printf("%5.2f", x1);
}

// 自2008年1月1日为星期二，判断2008年是否为闰年，输入任意一个月份，
//打印该年该月的日历，要求按周排齐，星期一排第一列
void fun6()
{
    int year = 2008;
    int flag = 0;
    int month, week, day = 2;
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        flag = 1;
        printf("2008 year is yes\n");
    }
    printf("please input 1-12\n");
    scanf("%d", &month);
    while (1)
    {
        if (month > 12 || month < 0)
        {

            printf("please input 1-12\n");
            scanf("%d", &month);
        }
        else
        {
            break;
        }
    }

    for (int i = 1; i <= month - 1; i++)
    {
        day += days(flag, i);
    }
    printf("\n");
    printf("%d\n", day);
    printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\n", "Mon", "Tuse", "Wed", "Thur", "Fri", "Sat", "Sun");

    int size = days(flag, month);
    for (int i = day, j = 1; i <= day + size && j <= size; i++, j++)
    {
        week = i % 7;
        if (i == day  && week != 1)
        {
            if (week == 0)
            {
                printf("\t\t\t\t\t");
            }

            for (int i = 0; i < week - 2; i++)
            {
                printf("\t");
            }
        }

        switch (week)
        {
        case 1:
            printf("%d", j);
            break;
        case 2:
            printf("\t%d", j);
            break;
        case 3:
            printf("\t%d", j);
            break;
        case 4:
            printf("\t%d", j);
            break;
        case 5:
            printf("\t%d", j);
            break;
        case 6:
            printf("\t%d", j);
            break;
        case 0:
            printf("\t%d\n", j);

            break;

        default:
            break;
        }
    }
}
int days(int flag, int month)
{
    switch (month)
    {
    case 1:
    case 5:
    case 3:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        if (flag == 1)
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
}
int main(int argc, char const *argv[])
{
    int A[] = {
        1,
        2,
        3,
        34,
        4,
    };
    // chardstr();
    // for (int i = 1; i < 5; i++)
    // {
    //    printf("%d,",fun(i));
    // }
    // int index= fun2(A,5);
    // printf("index=%d,",index);
    // fun3();
    // fun4();
    // fun5();
    fun6();
    return 0;
}
