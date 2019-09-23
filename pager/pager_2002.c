#include <stdio.h>
#include <stdlib.h>

/**
 * 请设计一个时间复杂度为 O(n)，空间复杂度不超过 O(2) 的算法，该算法将数组 A[0 : 1] n − 中所有
元素循环右移 k 个位置。
 * */
void fun1(int A[], int n, int k)
{
    int temp;
    for (int i = n - 1; i >= 0; i--)
    {
        A[i + k] = A[i];
        A[i] = 0;
    }
}

/**
 * 已知某二叉树采用广义表形式作为输入，请写一非递归算法，建立该二叉树的二叉链表存储结构。
设该链接点构造为 ，根结点地址为 T。
关于采用广义表形式表示二叉树的约定如下：
lchild data rchild
(1) 表中的一个字母表示一个结点的数据信息；
(2) 每个根结点作为由子树构成的表的构成的表的名字放在表的前面；
(3) 每个结点的左子树与右子树之间用逗号分开；若只有右子树而无左子树，则逗号不能省略；
(4) 整个广义表的末尾由一个特殊符号 @ 作为表的结束标志。
例如：(A (B(D),C(F(,E),G))@ 表示某一棵二叉树，该二叉树的根结点数据信息为 A。其中，数
据信息为 F 的结点只有右子树，而无左子树。
 * */
void fun2()
{
}
/**
 * 在下面给出的 C 函数实现中的空白处填上适当的内容，使其完成正确的功能。
函数说明：函数 void ftoa(double f, char s[]) 将浮点数 f 转换成相应的字符串，并存放在 s 中，该
函数最多只能转换小数点后四位，如 123.45 将转换成“123.45”，−123.456789 将转换成“−123.4567”。

 * */
void ftoa(double f, char s[]){
    int i, j, len, c, n;
    double sign;
    if ((sign = f) < 0)
        f = -f;
    n = (int)f;
    i = 0;
    do{
        s[i++] = n % 10 +'0' ;
    } while ((n=n/10)>0);
    if (sign < 0)
        s[i++]='-';
    len = i;
    for (i = 0, j = len - 1; i<len/2;j--) {
        c = s[i];
        s[i++]=s[j];
        s[j] = c;
    }
    f -= (int)f;
    s[len++] = '.';
    for (i = 0; i < 4; i++) {
        f *= 10;
        s[len++] = ((int) f)%10+'0';
    }
    while (s[len - 1] =='0')
        len--;
    s[len] ='\0';
    printf("%s",s);
}
void fun3() {}
int main(int argc, char const *argv[])
{
    int A[10] = {1, 2, 4, 5, 6};
    fun1(A, 5, 3);
    char s[10];
    ftoa(-123.434345,s);
    return 0;
}
