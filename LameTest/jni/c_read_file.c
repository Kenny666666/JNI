#include<stdio.h>
/**
 * c语言中的读文件
 */
main(){
	//java
	//File file = new File("1.txt");
	//打开一个文件的c语言的函数

	//获取到文件的指针
	FILE* fp = fopen("1.txt","rt");//rt文本可读方式

	char arr[20] ={};//必须要赋初值，否则后面剩下的空间会出现乱码如：arr[18]、arr[19]一些位置数据为空的时候
	//fread(读文件)方法接收4个参数
	//第一个参数：读出来的内容放在哪里
	//第二个参数：一次数据读的数据的长度
	//第三个参数：读多少次
	//第四个参数：读到哪个文件里
	int read = fread(arr,sizeof(char),15,fp);
	printf("arr =%s\n",arr);
	printf("读了%d个char类型\n",read);
	//关闭文件句柄
	fclose(fp);
	system("pause");
}
