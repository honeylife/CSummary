/**
请写一算法，该算法对于通过键盘输入
的n个整型数据元素，建立一个不包含重复
元素的顺序表。(假设不考虑存储空间溢出
的问题)
请写一算法，该算法对于通过键盘输入
的n个整型数据元素，建立一个不包含重复
元素的顺序表。(假设不考虑存储空间溢出
的问题)
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
void main(){

    int a[MAXSIZE];
    printf("please input array a:\n");
    int n=0,i=0;
    int flag = 0;
    while(n!=99&&i<MAXSIZE){
        scanf("%d",&n);
        for(int j = 0;j<i;j++){
        if(a[j]==n){
            flag = 1;
            break;
           }
        }
        if(flag==0){
          a[i++]=n;
        }
       flag=0;
    }
    printf("数据的结果:");

 for(int k = 0;k<i;k++){
        printf("%d,",a[k]);
    }

    printf("\n");
    printf("排序，输出顺序表\n");
    int temp;
    for(int j=0;j<i;j++){
        for(int k=j+1;k<i;k++){
            if(a[k]>a[j]){
                temp = a[j];
                a[j]=a[k];
                a[k]=temp;
            }
        }
        printf("%d,",a[j]);
    }


}
