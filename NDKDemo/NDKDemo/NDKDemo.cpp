// NDKDemo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
# include "huihui.h"
#include <stdlib.h>


int main()
{
	//指针的定义和运算
	//demo1();

	//数组与指针
	demo2();

	system("pause");
    return 0;


}

//数组与指针
void demo2() {

	/*long nc;

	nc = 0;

	while (getchar()!=EOF)
	{
		++nc;
	}

	printf("%ld\n",nc);*/

	int a[5] = {1,2,3,4,5};

	int *p = a;

	printf("a:%d\n",a);

	printArray(a);


	for ( int i = 0; p < a+5; i++)
	{
		*p = i;

		i++;
	}


	printArray(a);

}

void printArray(int base[])
{
	for (int i = 0; i < sizeof(base) / sizeof(base[0]); i++)
	{
		printf("数组第 %d 个值：%d\n",i,base[i]);
	}
}


//指针的定义和运算
void demo1() {

	int a = 10;

	int *p = &a;

	*p = *p + 10;

	printf("p:%d, a:%d \n",*p,a);

	int y = *p + 1;
	printf("y:%d\n\n",y);

	*p += 2;

	printf("=======\np:%d, a:%d \n", *p, a);

	//*p++;

	//printf("  *p++ 以后的值=======   p:%d, a:%d \n", *p, a);

	(*p)++;
	printf("  *p(*p)++ 以后的值=======   p:%d, a:%d \n", *p, a);

}

void fun(int a) {

	printf("%d\n",a);
}

