//c语言中 数据类型比java少一些 在c语言中没有 boolean类型的数据 int 1 代表真  int 0 代表假 
//c语言中没有String类型的数据   c语言通过char型的数组来表示字符串
//c语言没有byte类型  用char的类型表示byte类型
 
#include <stdio.h>      
#include <stdlib.h>
// sizeof(); c语言的一个函数 可以把某种数据类型的长度获取出来 

main()   //程序的入口函数 
{
      printf("char的长度为%d\n",sizeof(char));
      printf("int的长度为%d\n",sizeof(int));
      printf("float的长度为%d\n",sizeof(float));
      printf("double的长度为%d\n",sizeof(double));
      printf("long的长度为%d\n",sizeof(long));
      printf("short的长度为%d\n",sizeof(short));
      
      //signed,unsigned,数据类型的修饰符
      //signed int ;代表的是有符号的int的数据
      //unsigned int;无符号的int数据
      printf("signed int的长度为%d\n",sizeof(signed int));
      printf("unsigned int的长度为%d\n",sizeof(unsigned int));
      
      //符号的修饰符 只能修饰 整数类型的数据如 long int
      //不能修饰 浮点类型的数据如 float double 
      //printf("signed float的长度为%d\n",sizeof(signed float)); 
      
      system("pause");    //调用windows下系统的命令 让程序暂停执行 方便观察程序的执行结果 
}
