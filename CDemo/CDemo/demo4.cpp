#include "stdafx.h"
#include <string.h>
#include<limits.h>
#include<float.h>

#define PRAISE "����"
#define PI 3.1415

const int num = 21;

void demo1() {
	float num = 123.264;

	printf("�����%8.2f\n", num);
	printf("�ֽڴ�С��%d\n", sizeof('��'));
	printf("�ַ����ֽڴ�С��%d\n", sizeof("��"));
}

void demo2() {

	char name[20] = "huihui";

	


	printf("hello %s. %s\n",name,PRAISE);

	printf("�����ַ����ȣ� %d   �����ֽڳ��ȣ�%d\n", strlen(name), sizeof(name));
	
	printf("PRAISE�����ַ����ȣ� %d   PRAISE�����ֽڳ��ȣ�%d\n", strlen(PRAISE), sizeof(PRAISE));


	printf("��ӡ�����%x\n",17);

}

int main() {

	//demo1();
	demo2();


	system("pause");

	return 0;
}