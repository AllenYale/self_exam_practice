#include <stdio.h>

void change_num(int* x){
	*x = 456;
}

int main(){
//	int a = 100;
//	int* b = &a;
//	printf("%p \n", 100); //将100转换为16进制，作为地址值打印
//	printf("%p \n", a);//将100转换为16进制，作为地址值打印
//	printf("%p \n", &a);//打印 a地址 
//	printf("%p \n", b);//打印 a地址 
//	printf("%p \n", &b);//打印 指针变量b 的地址 
//	//通过指针b，修改变量a 
//	*b =101; 
//	printf("%d \n", a); //打印变量a 
//	printf("%d \n", *b);//通过b指针，打印变量a 

	int a = 123;
	change_num(&a);
	printf("%d \n", a);
	return 0;
}

