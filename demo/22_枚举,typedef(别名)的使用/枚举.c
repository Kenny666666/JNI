#include <stdio.h>
typedef int haha;//typedef�������Ǹ�������������� 
//typedef void* jobject;   void*��ʾû����ȷָ����һ��ʲô������������=java�е�object
enum WeekDay     //c�е�ö�٣�һ��������int���͵����� 
{
Monday=11,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday
};

// c  
//  
int main(void)
{
    
  haha i = 3; 
  printf("%d\n",i);
  //int day;
  enum WeekDay day1 = Monday;
  printf("%d\n",day1);
  enum WeekDay day2 = Tuesday;
  printf("%d\n",day2);
  enum WeekDay day3 = Wednesday;
  printf("%d\n",day3);
  enum WeekDay day4 = Thursday;
  printf("%d\n",day4);
  enum WeekDay day5 = Friday;
  printf("%d\n",day5);
  enum WeekDay day6 = Saturday;
  printf("%d\n",day6);
  enum WeekDay day7 = Sunday;
  printf("%d\n",day7);
  
  
  system("pause");
  return 0;
}
