// HelloWord.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int power(int m,int n);

int setValue(int a);

int main()
{

	printf("10�� 100�η��Ľ����%d\n",power(10,5));

     int 	b = 100;

	setValue(b);


	
	printf("a ��ֵ��%d\n", setValue(b));
	printf("b ��ֵ��%d\n", b);

    return 0;

	
}

int setValue(int a) {

	a = 10;

	return a;
}

int power(int base ,int n) {

	int p=1;

	for (int i = 1; i <= n; i++)
	{
		p = p*base;
	}

	return p;
}


