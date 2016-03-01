#include <stdio.h>    
#include <stdlib.h>
 main() 
{  
       int i = 3;
       double d = 3.141692;
       float f = 3.1423;
       char c = 'B';
       
       int* ip = &i;
       double* dp = &d;
       float* fp = &f;
       char* cp = &c;
       
       printf("int类型指针变量的长度为%d\n",sizeof(ip));
       printf("double类型指针变量的长度为%d\n",sizeof(dp));
       printf("float类型指针变量的长度为%d\n",sizeof(fp));
       printf("char类型指针变量的长度为%d\n",sizeof(cp));
       
        //在32位的操作系统上 因为程序 最大能使用的内存空间的地址  就是2的32次方
        //指针只需要4位 就可以表示出来所有的内存空间
        
        // 64位 并且编译器支持64位  那么指针长度是8位 
         
         system("pause");    // 调用windows下系统的命令 让程序暂停执行  方便观察程序的执行结果  
    
}
