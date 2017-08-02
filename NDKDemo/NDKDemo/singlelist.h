#include "stdafx.h"

typedef char EleType;

typedef struct Node {

	EleType data;

	struct  Node* next;
	

}ChainNode;

typedef struct {

	ChainNode *head;
}SingleList;

SingleList * onCreateSingleList(void);

 void onDestroySingleList(SingleList *);

 void onClearSingleList(SingleList *);

 int appendToSingleList(SingleList *,EleType);

 int insertToSingleList(SingleList *,int ,EleType);

 int deleteFromSingleList(SingleList *,int);

 int getElementFromSingleList(SingleList *,int ,EleType *);

 ChainNode *getAddress(SingleList *,int);

 ChainNode * newChainNode(EleType);

 int traverseList(SingleList *,int(*)(EleType *));

 //创建一个链表
 SingleList * onCreateSingleList(void) {
 
	 SingleList *list;

	 EleType *data = 0;

	 list= (SingleList *)malloc(sizeof(SingleList));
	 if (!list)
	 {
		 return 0;
	 }
	 list->head = newChainNode(*data);

	 if (!list->head)
	 {
		 free(list);

		 return 0;
	 }


	 return list;
 }

 void onDestroySingleList(SingleList * list) {

	 onClearSingleList(list);

	 free(list->head);

	 free(list);
 }

 void onClearSingleList(SingleList * list) {

	 while (deleteFromSingleList(list, 1));
	
 }


 int deleteFromSingleList(SingleList * list, int index) {
 
	 ChainNode *p;

	 ChainNode *p1;

	 if (!list->head->data) return 0;

	 p = getAddress(list,index-1);

	 p1 = p->next;

	 p->next = p->next->next;

	 free(p1);

	 return 1;
	 
 }


 ChainNode *getAddress(SingleList * list, int index) {
 
	 ChainNode *p;

	 int a;

	 if (index<0)
	 {
		 return 0;
	 }

	 p = list->head;

	 a = 0;

	 while (p && a<index) {
		 p= p->next;

		 a++;
	 }

	 return p;
 }





 
 //创建一个node
 ChainNode * newChainNode(EleType data) {

	 ChainNode *p;

	 p = (ChainNode *)malloc(sizeof(ChainNode));

	 if (!p)
	 {
		 return 0;
	 }

	 p->data = data;

	 p->data = NULL;

	 return p;
 }
