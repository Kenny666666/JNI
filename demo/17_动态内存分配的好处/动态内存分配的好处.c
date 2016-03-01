#include <stdio.h>    
#include <stdlib.h>
#include <malloc.h>
f(int** address){ //address 存放的是q的地址 
 

   int* p ;
   // malloc动态的在堆内存里面申请一块空间,sizeof(int)*3代表可以存放3个int类型的值 
    p = (int*)malloc(sizeof(int)*3); 
   *p = 3;
   *(p+1) = 4;    //这里的*(p+1) 表示偏移量,意思是p中第二个int类型的值为4                   
   *(p+2) = 5 ; //这里的*(p+2) 表示偏移量,意思是p中第三个int类型的值为5                
   printf("子函数里面 地址%#X\n",p); 
   *address  = p; 
   
   // 在子函数里面把p释放掉了动态申请的内存要手动释放掉，因为C中没有垃圾回收器 
   free(p);
} 

 main() 
{  
       int* q ; 
        
       f(&q); 
 
       printf("主函数里面 地址%#X\n",q); 
       printf("*q = %d\n",*(q+0));     // 因为在子函数中已经将*(q+0)手动释放掉了，所以也是残留的内存映像  
       //使用指针常见错误：不要使用已经回收掉的内存空间里面的数据  
       printf("*(q+1) = %d\n",*(q+1)); // 因为在子函数中已经将*(q+0)手动释放掉了，所以也是残留的内存映像  
       printf("*(q+2) = %d\n",*(q+2)); 
        
       //动态内存分配 程序员可以自己手工的决定一个变量的生命周期  
       //手工的释放调用内存空间  

        system("pause");    // 调用windows下系统的命令 让程序暂停执行  方便观察程序的执行结果  
          
          
}
