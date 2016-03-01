#include <stdio.h>    
#include <stdlib.h>
//总结：数组是一块连续的内存空间，数组名  就是内存空间的首地址 
//      我们可以利用： 数据名[i] 或 *(数据名+i)  的方式访问数据中的元素 
 main() 
{  
  //java中定义数据 char[] arr = new char[20];   char arr[]
  
  //c语言中的数组定义
  int arr[5] = {1,2,3,4,5};
  
  printf("a[0]=%d\n",arr[0]);
  printf("a[4]=%d\n",arr[4]);
  
  //逻辑上错误的代码，c 中数组越界不会报错，只会输出0
  //printf("a[5]=%d\n",arr[5]); 
  //windows xp 非常的不安全，因为他很多代码都是这样写的，360报什么缓冲区越界补丁 
  
  //arr是一个什么东西呢？%#X以16进制的方式将arr打印出来 
  printf("arr地址=%#X\n",arr);
  
  //打印数组第一个元素的地址
   printf("arr[0]地址=%#X\n",&arr[0]);//通过实验：数组名arr 表示的就是这个 数组第一个元素arr[0] 的首地址
   
  //打印数组中的第二个元素的地址 
   printf("arr[1]地址=%#X\n",arr[1]);
  //打印数组中的第二个元素的地址的值   
   printf("arr[1]地址=%#X\n",*(arr+1)); 
   printf("arr[1]=%d\n",arr[1]);
   printf("arr[1]=%d\n",*(arr+1)); 
   //问题：arr[i] 与 *(arr+i) 代表的是同一个变量么？ 
   //答案：代表的是同一块内存空间 指向的是同一个变量 
    
    
  system("pause");    // 调用windows下系统的命令 让程序暂停执行  方便观察程序的执行结果  
          
          
}
