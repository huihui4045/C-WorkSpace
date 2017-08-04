#include "stdafx.h"
#include <string.h>

int main() {


	int n = 4;

	size_t intsize;

	intsize = sizeof(int);

	printf("n的字节大小：%zd, sizeof n=:%zd   intsize=%zd",n,sizeof n,intsize);

	printf("自增运算符：%d\n",(2+ n++)*6);

	system("pause");
	return 0;


}