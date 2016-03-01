#include <stdio.h>    
#include <stdlib.h>
 main() 
{  
   //如果没有指针，就只能这样表示字符串，并且必须用\0 结尾 
    char arr[20] ={'h','e','l','l','o','\0'};    
    
    // 利用char类型指针 方便的表示一个字符串  
    char* arr1= "hello world";
        
    printf("%s\n",arr1);    
        
    system("pause");    // 调用windows下系统的命令 让程序暂停执行  方便观察程序的执行结果  
          
}
