// CDemo.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"



void demo() {

	float weight;

	float value;

	printf("��������Ļƽ�����أ�");

	scanf("%f",&weight);

	value = weight * 1000 * 14.5811;


	printf("�����%.3f \n",value);
}

void demo2() {
	char ch = 'C';

	printf("zifu:%c \n",ch);
	printf("zifu:%d\n", ch);

}
//ת��
void  demo3() {

	printf("$______\b\b\b   ,,,,,\n");
}

int main()
{
	//int num;
	//num = 1;
	//printf("jieguo:%d",num);

	//demo();

	//demo2();

	demo3();

	system("pause");
    return 0;
}

