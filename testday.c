#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int days(int flag, int month);
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
    printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\n", "Mon", "Tuse", "Wed", "Thur", "Fri", "Sat", "Sun");

    int size = days(flag, month);
    for (int i = day, j = 1; i <= day + size && j <= size; i++, j++)
    {
        week = i % 7;
        if (i == day  && week != 1)
        {
            if (week == 0)
            {
                printf("\t\t\t\t\t\t");
            }

            for (int i = 0; i < week-2; i++)
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
        case 3:
        case 4:
        case 5:
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
    fun6();
    return 0;
}
