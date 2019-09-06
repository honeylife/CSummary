/**已知长度为n的非空顺序表
A的数据元素按值的大小非递减
排列。写一算法，删除顺序表中
值相同的多余元素
*/

#include <stdio.h>
#include <stdlib.h>

void main(){
    int a[8]={20,32,34,34,45,45,67,78};
    int count =0;
    a[count]=a[0];
     printf("原数据为:\n");
     for(int i=0;i<8;i++){
       printf("%d,",a[i]);
    }
    for(int i=1;i<8;i++){
        if(a[count]!=a[i]){
            a[++count]=a[i];
        }
    }
     printf("\n输出的数据为:\n");
     for(int i=0;i<=count;i++){
       printf("%d,",a[i]);
    }

}
