/**
��дһ�㷨�����㷨����ͨ����������
��n����������Ԫ�أ�����һ���������ظ�
Ԫ�ص�˳���(���費���Ǵ洢�ռ����
������)
��дһ�㷨�����㷨����ͨ����������
��n����������Ԫ�أ�����һ���������ظ�
Ԫ�ص�˳���(���費���Ǵ洢�ռ����
������)
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
    printf("���ݵĽ��:");

 for(int k = 0;k<i;k++){
        printf("%d,",a[k]);
    }

    printf("\n");
    printf("�������˳���\n");
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
