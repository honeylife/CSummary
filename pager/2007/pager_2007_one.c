#include<stdio.h>
#define f(x) (x*x)

/**
 * 
 * 编写非递归算法，数据存储在A[1..n]中 二分查找，不大于item的最大元素，如果存在返回元素所在位置，否则返回0.
 * 
*/

int getKeyData(int A[],int n,int item){
    int low=1,high=n,mid;
    while (low<=high){
        mid=(low+high)/2;
        if (A[mid]==item&&mid!=1){
            // return mid -1;
            return mid ; // 这里应该直接返回 mid 因为数组是从1开始的
        }
        if (A[mid]>item){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return 0;
}
int main(int argc, char const *argv[])
{
  
    int A[5]={12,14,56,78,99};
    int index=getKeyData(A,5,56);
    return 0;
}
