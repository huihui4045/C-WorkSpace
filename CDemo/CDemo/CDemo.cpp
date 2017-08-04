// CDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"



void demo() {

	float weight;

	float value;

	printf("请输入你的黄金的体重：");

	scanf("%f",&weight);

	value = weight * 1000 * 14.5811;


	printf("结果：%.3f \n",value);
}

void demo2() {
	char ch = 'C';

	printf("zifu:%c \n",ch);
	printf("zifu:%d\n", ch);

}
//转义
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

