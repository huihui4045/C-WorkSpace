#include "stdafx.h"


void demo() {

	long num;

	long sum = 0L;
	int status;

	printf("输入一个值：");

	printf("(q to quit):");

	status = scanf("%d",&num);

	printf("status=%d",status);

	while (status==1)
	{
		sum = sum + num;

		printf("输入下一个值：");

		status = scanf("%d", &num);

		printf("status=%d", status);
	}

	printf("结果：%ld.\n",sum);
}

void demo2() {

	int x = 1;
	int y = 0;

	y = x++*5;

	printf("y:%d\n",y);
}

int main() {


	//demo();

	demo2();

	system("pause");

	return 0;
}