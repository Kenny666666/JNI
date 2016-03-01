#include<stdio.h>
/**
 * c语言中的写文件跟java类似
 */
main(){
	//java
	//File file = new File("1.txt");
	//打开一个文件的c语言的函数

	//获取到文件的指针
	FILE* fp = fopen("1.txt","wt");//wt文本可写方式

	char* str = "haha write file";
	//fwrite(写文件)方法接收4个参数
	//第一个参数：写什么内容
	//第二个参数：一次数据写多长
	//第三个参数：写多少次
	//第四个参数：写到哪个文件里
	int len = fwrite(str,sizeof(char),15,fp);
	printf("写了多少次len =%d\n",len);
	//关闭文件句柄
	fclose(fp);
	system("pause");
}
