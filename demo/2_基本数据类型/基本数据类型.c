// java数据类型 和长度int  4个字节 double  8个字节  float 4个字节 long 8个字节 
// short 2个字节 boolean  1个字节 char 2个字节 byte   1个字节 
// char, int, float, double, signed, unsigned, long, short and void
// c语言中 数据类型比java少一些 在c语言中没有 boolean类型的数据  int 1 代表真 0 代表假
// c 语言中没有String类型的数据   java中表示一个字符串 String  , c语言中表示字符串 通过char类型的数组来表示字符串
// c 语言没有byte类型   所有用char的类型表示byte类型 

#include <stdio.h>    
#include <stdlib.h>
// sizeof(); c语言的一个函数 可以把 某种数据类型的长度获取出来 int 
 main() 
{          // %d 类似sql语句的? 占位符  
            printf("char的长度为%d\n", sizeof(char));
            printf("int的长度为%d\n", sizeof(int));
            printf("float的长度为%d\n", sizeof(float));
            printf("double的长度为%d\n", sizeof(double));
            printf("long的长度为%d\n", sizeof(long));
            printf("short的长度为%d\n", sizeof(short));
            
            //signed, unsigned, 数据类型的修饰符
           // signed int ; 代表的是有符号的int的数据 
           // unsigned int ;  无符号的int数据 
              printf("signed int的长度为%d\n", sizeof( signed int));
              printf("unsigned int的长度为%d\n", sizeof( unsigned int));
        
           // 符号的修饰符 只能修饰 整数类型的数据 long int 
           // 不能修饰 浮点型的数据 float double  
           // printf("signed float的长度为%d\n", sizeof( signed float));
        
              system("pause");    // 调用windows下系统的命令 让程序暂停执行  方便观察程序的执行结果  
}

 
