#include <stdio.h>

void change_num(int* x){
	*x = 456;
}

int main(){
//	int a = 100;
//	int* b = &a;
//	printf("%p \n", 100); //��100ת��Ϊ16���ƣ���Ϊ��ֵַ��ӡ
//	printf("%p \n", a);//��100ת��Ϊ16���ƣ���Ϊ��ֵַ��ӡ
//	printf("%p \n", &a);//��ӡ a��ַ 
//	printf("%p \n", b);//��ӡ a��ַ 
//	printf("%p \n", &b);//��ӡ ָ�����b �ĵ�ַ 
//	//ͨ��ָ��b���޸ı���a 
//	*b =101; 
//	printf("%d \n", a); //��ӡ����a 
//	printf("%d \n", *b);//ͨ��bָ�룬��ӡ����a 

	int a = 123;
	change_num(&a);
	printf("%d \n", a);
	return 0;
}

