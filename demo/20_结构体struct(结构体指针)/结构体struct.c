#include <stdio.h>    
#include <stdlib.h>
//c�еĽṹ���൱��java�е��� 
struct Student
{
	int age; //4
	float score; // 4/
	long id;  //4
	char sex ; //2   vc 6.0 14����ͬ�ı���������ݽṹ�������ṹ���еı������䲻ͬ��С�Ĵ�С������char��1byte��������������������4byte����Ϊ��ƫ�Ʒ���Ҳ��char����4byte 
};

 main() 
{ 
    //���ṹ���еı�����ֵ    
    struct Student st={80,55.6f,100010 ,'F'};   
    
    struct Student* pst;//����һ���ṹ���ָ�� 
    pst = &st;
      
    printf("age = %d\n",st.age);    
    printf("score = %f\n",st.score);     
    printf("id = %ld\n",st.id);    
     printf("sex = %c\n",st.sex);    
    // �ṹ��ĳ��� 
    printf("�ṹ��ĳ��� = %d\n",sizeof(st)); 
    
    //�ṹ���ָ��ʹ�úܷ��㣬�ܶ���д�������Ի�ȡָ�������ݵ�ֵ 
    printf("age = %d\n", (*pst).age);   
    printf("age = %d\n", pst->age); 
    
    system("pause");    // ����windows��ϵͳ������ �ó�����ִͣ��  ����۲�����ִ�н��  
          
          
}
