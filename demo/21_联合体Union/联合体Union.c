#include <stdio.h> 

main(){ 
//������һ���ṹ��today������һ�ַ����д�� 
struct date { int year, month, day; } today; 
 
 // ������ �Ƕ���һ����ͬ���ڴ�ռ� ������������ (�����壺һ�����ݵļ���) 
union { long i; int k; char ii; } mix; 

// ����������þ���������ʾһ���������� ���ݵ���������Ϊ��һ���е�ĳһ���������� 
//ע�� :   ������������������ݻ��໥���� 

//�ṹ��ĳ���Ϊ�ṹ���������������ͳ���֮�� 
printf("date:%d\n",sizeof(struct date));  //12 

//������ĳ���Ϊ����������������͵ĳ���
printf("mix:%d\n",sizeof(mix)); 
 
mix.ii = 'A';
printf("k=%d\n",mix.k);
system("pause");
} 
