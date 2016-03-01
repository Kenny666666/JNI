#include <stdio.h>    
#include <stdlib.h>
// 问 java 中有值传递和引用传递 吗? 他们的区别是什么? 

// 其实在java中只有值传递 , 没有引用传递  

// Person p = new Person();  p里面存放的内容 就是person对象的地址 
void swap1(int i,int j) 
{
     printf("子函数 i 地址%#X\n",&i); 
     printf("子函数 j 地址%#X\n",&j); 
     int temp;
     temp = i;
     i = j;
     j = temp;
     
}

void swap2(int* p,int* q) //传递的形参为i和j变量的地址 
{
     //*p 代表i    *q代表就是j 
     int temp;
     temp = *p;
     *p = *q;
     *q = temp;
     
}

main() 
{   
         int i = 3;
         int j = 5;
         printf("交换前\n");
         printf("i=%d\n",i);
         printf("j=%d\n",j);
         
         printf("主函数 i 地址%#X\n",&i); 
         printf("主函数 j 地址%#X\n",&j); 
         //交换两个数字 
         /*
         int temp;
         temp = i;
         i = j;
         j = temp;
         */
         //形参i 和 j 跟主函数里面的i和j是两个不同的变量，所以调用此方法并不能交换他们的值 
         //swap1(i,j);
         
         // 使用指针的方式就可以将他们的值交换了，同java的引用传递是一样的道理 
         //结论：利用指针  可以在 子函数 里面修改 主函数 面的数据 
         swap2(&i,&j);
         
         printf("交换后\n");
         printf("i=%d\n",i);
         printf("j=%d\n",j);
         
         
         
         system("pause");    // 调用windows下系统的命令 让程序暂停执行  方便观察程序的执行结果  
}
