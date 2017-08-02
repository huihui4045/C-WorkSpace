#include "stdafx.h"

#include <stdlib.h>
/**
*ÄÚ´æ·ÖÅä
*/
int const num = 10;


void chardemo() {

	char ch1[10] = {'c','h','i','n','a'};

    char ch2[10] = "china";


	printf("%s\n", ch2);
}


int main() {

	//int aa[num];
	//int *a = (int *)malloc(sizeof(int)*1024*20);

	//printf("%d\n",sizeof(*a));

	chardemo();

	system("pause");

	return 0;
}