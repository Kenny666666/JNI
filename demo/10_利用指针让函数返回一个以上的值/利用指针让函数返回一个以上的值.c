#include <stdio.h>    
#include <stdlib.h>
 // public List<Person> getPersons() {}; 
 // public byte[] getbytes(){};
 
 /*
 如何让子函数 更改主函数里面的数据  
 如何让子函数 返回一个以上的值 
 1.子函数的形参 为 主函数中要修改的变量的地址 
 2. 调用子函数的时候 把要修改的变量的地址 传递给子函数 
 3. 在子函数里面 修改这个地址里面存放的变量的内容 
 4. 主函数使用这个变量的时候 里面的值就发生了变化  
  
 */
 
 int f(int* p, int* q){
    *p =  33;
    *q = 55;
 }

//C语言中函数只能返回基本数据类型的数据 ，不能和java一样 
 main() 
{   
    
    int i = 3;
    int j = 5;
    f(&i,&j);
    printf("i=%d\n",i);
    printf("j=%d\n",j);
    
    system("pause");    // 调用windows下系统的命令 让程序暂停执行  方便观察程序的执行结果  
          
          
}
