#include "stdafx.h"
#include <string.h>
#include<limits.h>
#include<float.h>

#define PRAISE "吕鹏"
#define PI 3.1415

const int num = 21;

void demo1() {
	float num = 123.264;

	printf("结果：%8.2f\n", num);
	printf("字节大小：%d\n", sizeof('辉'));
	printf("字符串字节大小：%d\n", sizeof("辉"));
}

void demo2() {

	char name[20] = "huihui";

	


	printf("hello %s. %s\n",name,PRAISE);

	printf("名字字符长度： %d   名字字节长度：%d\n", strlen(name), sizeof(name));
	
	printf("PRAISE名字字符长度： %d   PRAISE名字字节长度：%d\n", strlen(PRAISE), sizeof(PRAISE));


	printf("打印结果：%x\n",17);

}

int main() {

	//demo1();
	demo2();


	system("pause");

	return 0;
}