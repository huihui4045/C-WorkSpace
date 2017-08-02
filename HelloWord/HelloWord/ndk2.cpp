#include "stdafx.h"

#include <stdlib.h>
#include "string.h"

//int main() {
//
//	/*
//	指针
//	int a = 10;
//	int *p;
//	p = &a;*/
//
//
//	/*
//	2、数组与指针
//	*/
//
//	int a[5];
//	int *p = a;
//
//
//
//
//
//	system("pause");
//
//	return 0;
//
//}

//int main() {
//
//	/*
//	//	2、数组与指针
//	//	*/
//	//
//	  int a[5] = {1,2,3,4,5};
//		int *p = a;
//
//		int i;
//
//		printf("%#x\n",a);
//		//a+5 表示a 移动到数组的第五个位置
//		for ( i = 0; p < a+5; p++)
//		{
//			*p = i;
//
//			i++;
//		}
//
//	system("pause");
//	
//		return 0;
//}
void swap(int a,int b);

void swap(int a, int b) {

	int temp;
	temp = a;
	a = b;
	a = temp;
}

void swap2(int *a, int *b) {

	int *temp;
	temp = a;
	a = b;
	b = temp;
}



//int main() {
//
//	/*
//	//	3、指针与函数参数
//	//	*/
//	//
//
//	int a, b;
//	a = 10;
//		b = 5;
//
//		printf("a address:%#x\n,b address:%#x\n",&a,&b);
//
//		swap(a,b);
//
//		printf("a :%d\n,b :%d\n", a, b);
//	
//
//	system("pause");
//
//	return 0;
//}

//指针数组

//void sort(char *name[],int n);
//
//int main() {
//
//	//指针数组
//	char *name[] = {"hello","huihui"," Gavin","lover"};
//
//	int i, n = 4;
//
//	sort(name,n);
//
//	for ( i = 0; i < n; i++)
//	{
//		printf("%s\n",name[i]);
//	}
//
//
//	system("pause");
//	
//		return 0;
//}
//
////指针数组
//void sort(char *name[], int n) {
//
//	char * temp;
//
//	int i, j;
//
//	for ( i = 0; i < n; i++)
//	{
//		for (j = 0;j < n - 1 - i;j++) {
//
//			if (strcmp(name[j], name[j+1]))
//			{
//				temp = name[j];
//
//				name[j] = name[j + 1];
//				name[j + 1] = temp;
//			}
//		}
//	}
//}

//二级指针

int main() {

	int a = 100;

	int *p;

	p = &a;
}
