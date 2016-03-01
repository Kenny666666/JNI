#include <stdio.h>    
#include <stdlib.h>
#include <malloc.h> 
// malloc memory allocate 内存申请 
 main() 
{  
   // 接受一个参数 申请多大(byte)的内存空间  
  int* p = (int*)malloc(sizeof(int)); // 在堆内存(heap)里面申请一块可以存放一个int类型数据的内存空间  
    
  *p = 4;  // 就是往 p 里面 存放的地址 表示的那块内存空间里面存放一个int类型的数据 4 
  
  
  
  printf("*p=%d\n",*p);  
        
        
system("pause");    // 调用windows下系统的命令 让程序暂停执行  方便观察程序的执行结果  
    
}
