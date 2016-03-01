#include <stdio.h>    
#include <stdlib.h>
//c中的结构体相当于java中的类 
struct Student
{
	int age; //4
	float score; // 4/
	long id;  //4
	char sex ; //2   vc 6.0 14，不同的编译器会根据结构体来给结构体中的变量分配不同大小的大小，本来char是1byte，编译器发现其它都是4byte所以为了偏移方便也给char分了4byte 
};

 main() 
{ 
    //给结构体中的变量赋值    
    struct Student st={80,55.6f,100010 ,'F'};   
    
    struct Student* pst;//定义一个结构体的指针 
    pst = &st;
      
    printf("age = %d\n",st.age);    
    printf("score = %f\n",st.score);     
    printf("id = %ld\n",st.id);    
     printf("sex = %c\n",st.sex);    
    // 结构体的长度 
    printf("结构体的长度 = %d\n",sizeof(st)); 
    
    //结构体的指针使用很方便，很多种写法都可以获取指针内数据的值 
    printf("age = %d\n", (*pst).age);   
    printf("age = %d\n", pst->age); 
    
    system("pause");    // 调用windows下系统的命令 让程序暂停执行  方便观察程序的执行结果  
          
          
}
