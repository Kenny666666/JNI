#include <stdio.h>    
#include <stdlib.h>
#define pi 3.1415   // #define pi 3.1415 C语言中的宏定义，相当于java中的全局变量 

// 写一个子函数 打印数组里面的每一个元素 

void printArr(int* arr, int len){ // arr是数组的首地址  len数组的长度  
     int i=0;
     for(;i<len;i++){ // 在c99 的语法格式下  for循环的初始化条件 不能写在 for 循环的括号里面  
        // printf("arr[%d]=%d\n",i,arr[i]);  // arr[i] 和  *(arr+i) 代表的含义相同 
        printf("arr[%d]=%d\n",i, *(arr+i));
     }
} 

 
main() 
{  
        //int arr[10]={1,2,3,4,5};
          
        //printArr(&arr[0],10);
       
        //1 .定义一个数组  缺陷 数组的长度 必须事先申请好 
        //int arr[1000];   //  这一句代码一旦执行 ,就立刻会在内存里面申请 5个内存空间 每个内存空间的大小可以存放一个int类型的数据  
        // 没有办法动态的增加这一块空间的大小, 也没办法减小这一块内存空间  
        //2. 循环赋值
        //3. 打印数组里面的内容 
        int* arr = (int* )malloc(sizeof(int)*10); 
        //realloc给指针重新分配长度 
        arr =  realloc(arr,sizeof(int)*8); //空间的长度为12了 
        
        int i =0;
        for(;i<5;i++){
           printf("请输入arr[%d]=的值\n",i);
           scanf("%d",arr+i);                            
        }
        
        printArr(arr,5);
        
        system("pause");    // 调用windows下系统的命令 让程序暂停执行  方便观察程序的执行结果  
          
     
     
         // 作业: 从键盘接受一个数组 数组的大小 
       
         // 动态的更改 数组的大小增加2 
            
}
