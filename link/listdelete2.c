/**��֪����Ϊn�ķǿ�˳���
A������Ԫ�ذ�ֵ�Ĵ�С�ǵݼ�
���С�дһ�㷨��ɾ��˳�����
ֵ��ͬ�Ķ���Ԫ��
*/

#include <stdio.h>
#include <stdlib.h>

void main(){
    int a[8]={20,32,34,34,45,45,67,78};
    int count =0;
    a[count]=a[0];
     printf("ԭ����Ϊ:\n");
     for(int i=0;i<8;i++){
       printf("%d,",a[i]);
    }
    for(int i=1;i<8;i++){
        if(a[count]!=a[i]){
            a[++count]=a[i];
        }
    }
     printf("\n���������Ϊ:\n");
     for(int i=0;i<=count;i++){
       printf("%d,",a[i]);
    }

}
