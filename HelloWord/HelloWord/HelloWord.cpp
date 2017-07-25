// HelloWord.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int power(int m,int n);

int setValue(int a);

int main()
{

	printf("10的 100次方的结果：%d\n",power(10,5));

     int 	b = 100;

	setValue(b);


	
	printf("a 的值：%d\n", setValue(b));
	printf("b 的值：%d\n", b);

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


