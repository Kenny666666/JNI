//c������ �������ͱ�java��һЩ ��c������û�� boolean���͵����� int 1 ������  int 0 ����� 
//c������û��String���͵�����   c����ͨ��char�͵���������ʾ�ַ���
//c����û��byte����  ��char�����ͱ�ʾbyte����
 
#include <stdio.h>      
#include <stdlib.h>
// sizeof(); c���Ե�һ������ ���԰�ĳ���������͵ĳ��Ȼ�ȡ���� 

main()   //�������ں��� 
{
      printf("char�ĳ���Ϊ%d\n",sizeof(char));
      printf("int�ĳ���Ϊ%d\n",sizeof(int));
      printf("float�ĳ���Ϊ%d\n",sizeof(float));
      printf("double�ĳ���Ϊ%d\n",sizeof(double));
      printf("long�ĳ���Ϊ%d\n",sizeof(long));
      printf("short�ĳ���Ϊ%d\n",sizeof(short));
      
      //signed,unsigned,�������͵����η�
      //signed int ;��������з��ŵ�int������
      //unsigned int;�޷��ŵ�int����
      printf("signed int�ĳ���Ϊ%d\n",sizeof(signed int));
      printf("unsigned int�ĳ���Ϊ%d\n",sizeof(unsigned int));
      
      //���ŵ����η� ֻ������ �������͵������� long int
      //�������� �������͵������� float double 
      //printf("signed float�ĳ���Ϊ%d\n",sizeof(signed float)); 
      
      system("pause");    //����windows��ϵͳ������ �ó�����ִͣ�� ����۲�����ִ�н�� 
}
