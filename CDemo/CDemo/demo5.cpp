#include "stdafx.h"


void demo() {

	int n = 4;

	size_t intsize;

	intsize = sizeof(int);

	printf("n的字节大小：%zd, sizeof n=:%zd   intsize=%zd\n", n, sizeof n, intsize);

	printf("自增运算符：%d\n", (2 + n++) * 6);
}

void pound(int n) {
	while (n-- >0)
	{
		printf("#");
		
	}
	printf("\n");
}

int main() {

	int times = 5;
	char ch = '!';
	float f = 8.0;

	pound(times);
	pound(ch);

	pound(f);


	//demo();
	

	system("pause");
	return 0;


}