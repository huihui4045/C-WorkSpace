#include "stdafx.h"


void demo() {

	long num;

	long sum = 0L;
	int status;

	printf("����һ��ֵ��");

	printf("(q to quit):");

	status = scanf("%d",&num);

	printf("status=%d",status);

	while (status==1)
	{
		sum = sum + num;

		printf("������һ��ֵ��");

		status = scanf("%d", &num);

		printf("status=%d", status);
	}

	printf("�����%ld.\n",sum);
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