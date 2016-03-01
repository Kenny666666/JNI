//c语言中什么样的数据类型就要用什么样的点位符来打印 
/*
%d  -  int
%ld – long int
%c  - char
%f -  float
%lf – double
%x – 十六进制输出 int 或者long int 或者short int
%o -  八进制输出
%s – 字符串

Int len;
Scanf(“%d”,&len);
*/
#include <stdio.h>    // java  import xxx.xx.pack    引用函数的声明  
#include <stdlib.h>
 main() // 程序的入口函数  
{    int i = 3;
     float f = 3.1415;
     double d = 6.2815;
     char c = 'A';   //通过单引号定义字符 
     short s = 2;   
       
     printf("int i=%d\n",i);
     printf("float f=%f\n",f);
     printf("char c=%c\n",c);
     printf("double d=%lf\n",d);
     printf("short s=%d\n",s);
     
     /*char arr[20] ; //定义一个长度为20的数组
     scanf("%s",arr);  // 从键盘接受一个字符串,放在arr数组里面 
     
     printf("s =%s\n",arr); 
       */
       
     int j ;
     scanf("%d", &j);//&代表的是取地址  
     printf("j=%d\n",j); 
        
     system("pause");    // 调用windows下系统的命令 让程序暂停执行  方便观察程序的执行结果  
}
