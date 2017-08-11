#include "stdafx.h"

#define SPACE ' '
void demo1() {

	char ch;
	
	

	while ((ch = getchar())!='\n')

	{
		if (ch == SPACE)
		{
			putchar(ch);
		}
		else
		{
			putchar(ch+1);
		}
		
	}

	putchar(ch);
}

int main() {


	demo1();

	system("pause");

	return 0;
}