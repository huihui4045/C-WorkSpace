#include "stdafx.h"
#include <string.h>

int main() {


	int n = 4;

	size_t intsize;

	intsize = sizeof(int);

	printf("n���ֽڴ�С��%zd, sizeof n=:%zd   intsize=%zd",n,sizeof n,intsize);

	printf("�����������%d\n",(2+ n++)*6);

	system("pause");
	return 0;


}