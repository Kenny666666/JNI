/*1.����int��(*pf)(int x,��int y);
2.��ֵ pf = add;
3.���� pf(3,5);
*/
#include <stdio.h>    
#include <stdlib.h>

int add(int x , int y){
    
    return x+y;
    
}
//������ָ�붨�壺ָ��ָ����һ���ڴ��ַ����ô������ָ��ָ�ľ��Ǻ������ڴ��ַ 
 main() 
{ 
      //����һ��������ָ���������ָ�����ֽ�pf  ����ֵ int ���ܲ�������int  
       int (*pf) (int x, int y); 
       pf = add; 
       
       printf("result=%d\n", pf(3,6)); 
      
       system("pause");    // ����windows��ϵͳ������ �ó�����ִͣ��  ����۲�����ִ�н��  
          
          
}
