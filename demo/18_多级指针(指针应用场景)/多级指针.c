#include <stdio.h>    
#include <stdlib.h>
//�༶ָ��Ӧ�ó���(��Ϸ)�� 

//����java�� ��Ϸ���и�����Person p = new Person();
//Ȼ�������������и�����Pack pack = new Pack(); c��������Ƕ���ָ���� 
//����������ҩˮ SunWater sw = new SunWater();  c�������������ָ���� 
//java��Ҫ����ҩˮ�Ļ����� p.pack.sw ������
//c�еĶ༶ָ�� �� java �����еĳ�Ա���� һ��һ����Ӧ 
 main() 
{ 
        
    int i = 5; 
    int*  p = &i;  
    int** q = &p;
    int*** r = &q;
    
  printf("i=%d\n",*r);   //*r��Ӧ�ľ���q������q��û��ֵ����Ϊ0 
  printf("i=%d\n",**r);  //**r = *q��Ӧ�ľ���p������p��û��ֵ����Ϊ0   
  printf("i=%d\n",***r); //***r= *p��Ӧ�ľ���i������i��ֵΪ5���Դ�ӡΪ5
        
        
        
 system("pause");    // ����windows��ϵͳ������ �ó�����ִͣ��  ����۲�����ִ�н��  
           
          
}
