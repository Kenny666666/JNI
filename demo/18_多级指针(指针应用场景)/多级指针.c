#include <stdio.h>    
#include <stdlib.h>
//多级指针应用场景(游戏)： 

//比如java： 游戏中有个人物Person p = new Person();
//然后人物身上又有个背包Pack pack = new Pack(); c中这里就是二级指针了 
//背包中又有药水 SunWater sw = new SunWater();  c中这里就是三级指针了 
//java中要调用药水的话就是 p.pack.sw 来调用
//c中的多级指针 与 java 对象中的成员变量 一级一级对应 
 main() 
{ 
        
    int i = 5; 
    int*  p = &i;  
    int** q = &p;
    int*** r = &q;
    
  printf("i=%d\n",*r);   //*r对应的就是q变量，q并没有值所以为0 
  printf("i=%d\n",**r);  //**r = *q对应的就是p变量，p并没有值所以为0   
  printf("i=%d\n",***r); //***r= *p对应的就是i变量，i的值为5所以打印为5
        
        
        
 system("pause");    // 调用windows下系统的命令 让程序暂停执行  方便观察程序的执行结果  
           
          
}
