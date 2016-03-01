/*1.定义int　(*pf)(int x,　int y);
2.赋值 pf = add;
3.引用 pf(3,5);
*/
#include <stdio.h>    
#include <stdlib.h>

int add(int x , int y){
    
    return x+y;
    
}
//函数的指针定义：指针指的是一块内存地址，那么函数的指针指的就是函数的内存地址 
 main() 
{ 
      //定义一个函数的指针的声明，指针名字叫pf  返回值 int 接受参数两个int  
       int (*pf) (int x, int y); 
       pf = add; 
       
       printf("result=%d\n", pf(3,6)); 
      
       system("pause");    // 调用windows下系统的命令 让程序暂停执行  方便观察程序的执行结果  
          
          
}
