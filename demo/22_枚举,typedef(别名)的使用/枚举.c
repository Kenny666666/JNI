#include <stdio.h>
typedef int haha;//typedef的作用是给数据类型起别名 
//typedef void* jobject;   void*表示没有明确指定是一个什么样的数据类型=java中的object
enum WeekDay     //c中的枚举：一组连续的int类型的整数 
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
