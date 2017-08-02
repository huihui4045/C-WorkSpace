#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>

#include "string.h"
#include <Windows.h>

struct Man
{
	int age;
	char *name;
	int(*Msg)(char *,int);
};
//函数指针
int message(char *str,int age) {

	MessageBox(0,TEXT("Hello"),TEXT("LiLei"),0);

	return 0;
}


void demo1() {
	Man man;
	man.age = 30;
	man.name = "吴京";
	man.Msg = message;
	man.Msg(man.name,man.age);
}


//结构体中添加结构体指针成员变量

struct Node
{
	int data;
	Node *next;
};

void enqueNode(Node *head,int data) {

	Node *node = (Node *)malloc(sizeof(struct Node));

	if (node==NULL) {
		return;
	}
	node->data = data;
	node->next= NULL;
	Node *p = head;
	while (p->next!=NULL) {
		p = p->next;
	}
	p->next = node;

}

void demo2() {

	int num = 10;
	int i = 0;
	Node *list;

	list = (Node*)malloc(sizeof(struct Node));

	list->data = 0;
	list->next = NULL;
	for (i  = 0; i < num; i++)
	{
		enqueNode(list,i+1);
	}

	while (list->next!=NULL) {
		printf("%d\n",list->data);
		list = list->next;
	}
}


int main() {

	//demo1();

	demo2();

	system("pause");

	return 0;
}