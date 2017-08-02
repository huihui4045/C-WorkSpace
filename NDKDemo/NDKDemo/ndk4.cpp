#include "stdafx.h"


struct Student
{
	char name[20];
	int age;
}Lucy = { "lucy1",200 };

//匿名结构体 锁定结构体的变量的数量
struct 
{
	char name[20];
	int age;
	char gender[10];
	int classId;
}stud3，stud4;


void demo1() {
	struct  Student stu1 = { "lucy",20 };

	struct Student stu2;
	strcpy(stu2.name, "tom");
	stu1.age = 30;

	printf("名字:%s 年龄：%d\n", stu1.name, stu1.age);
}

void demo2() {

	Student stu[3] = { {"lucy",23},{"lilei",27},{"hanmei",30} };

	Student s[5];

	for (int  i = 0; i < 5; i++)
	{
		s[i].age = 20 + i;

		strcpy(s[i].name,"lucy");
	}

	for (int i = 0; i < 5; i++)
	{
		printf("名字:%s 年龄：%d\n", s[i].name, s[i].age);
	}


}

int main() {

	demo1();

	demo2();

	system("pause");

	return 0;
}