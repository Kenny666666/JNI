#include <stdio.h>    
#include <stdlib.h>
// �� java ����ֵ���ݺ����ô��� ��? ���ǵ�������ʲô? 

// ��ʵ��java��ֻ��ֵ���� , û�����ô���  

// Person p = new Person();  p�����ŵ����� ����person����ĵ�ַ 
void swap1(int i,int j) 
{
     printf("�Ӻ��� i ��ַ%#X\n",&i); 
     printf("�Ӻ��� j ��ַ%#X\n",&j); 
     int temp;
     temp = i;
     i = j;
     j = temp;
     
}

void swap2(int* p,int* q) //���ݵ��β�Ϊi��j�����ĵ�ַ 
{
     //*p ����i    *q�������j 
     int temp;
     temp = *p;
     *p = *q;
     *q = temp;
     
}

main() 
{   
         int i = 3;
         int j = 5;
         printf("����ǰ\n");
         printf("i=%d\n",i);
         printf("j=%d\n",j);
         
         printf("������ i ��ַ%#X\n",&i); 
         printf("������ j ��ַ%#X\n",&j); 
         //������������ 
         /*
         int temp;
         temp = i;
         i = j;
         j = temp;
         */
         //�β�i �� j �������������i��j��������ͬ�ı��������Ե��ô˷��������ܽ������ǵ�ֵ 
         //swap1(i,j);
         
         // ʹ��ָ��ķ�ʽ�Ϳ��Խ����ǵ�ֵ�����ˣ�ͬjava�����ô�����һ���ĵ��� 
         //���ۣ�����ָ��  ������ �Ӻ��� �����޸� ������ ������� 
         swap2(&i,&j);
         
         printf("������\n");
         printf("i=%d\n",i);
         printf("j=%d\n",j);
         
         
         
         system("pause");    // ����windows��ϵͳ������ �ó�����ִͣ��  ����۲�����ִ�н��  
}
