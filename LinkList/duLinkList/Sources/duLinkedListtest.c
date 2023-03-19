#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include "DuLinkedList.h"

ElemType main()
{
	char menu[7][50] =
	{ "------------------------------",
		"[1]DestroyList_DuL",
		"[2]InsertBeforeList_DuL",
		"[3]InsertAfterList_DuL",
		"[4]DeleteList_DuL",
		"[5]TraverseList_DuL",
		"------------------------------"

	};
	DuLinkedList head;
	DuLinkedList* L = &head;
	printf("%s\n", InitList_DuL(L)?"SUCCESS":"ERROR");
	DuLNode* p1 = (DuLNode*)malloc(sizeof(struct DuLNode));				//初始化链表并连接p1,p2,p3,p4
	(*L)->next = p1;
	p1->data = 1;
	p1->next = NULL;
	p1->prior = L;
	DuLNode* p2 = (DuLNode*)malloc(sizeof(struct DuLNode));
	p1->next = p2;
	p2->data = 2;
	p2->next = NULL;
	p2->prior = p1;
	DuLNode* p3 = (DuLNode*)malloc(sizeof(struct DuLNode));
	p2->next = p3;
	p3->data = 3;
	p3->next = NULL;
	p3->prior = p2;
	DuLNode* p4 = (DuLNode*)malloc(sizeof(struct DuLNode));
	p3->next = p4;
	p4->data = 4;
	p4->next = NULL;
	p4->prior = p3;
	DuLNode* p5 = (DuLNode*)malloc(sizeof(struct DuLNode));
	p5->next = NULL;
	p5->prior = NULL;
	p5->data = 5;
	for (DuLNode* p = (*L)->next; p != NULL; p = p->next)
		printf("%d\n", p->data);
	for (int i = 0; i < 7; i++)
		printf("%s\n", menu[i]);
	ElemType choice = 0;
	ElemType result;
	printf("请输入你要的功能:");
	while (1) {
		result = scanf("%3d", &choice);
		if (result == 0 || choice > 5 || choice < 1) {
			printf("输入错误，重新输入: ");
			while (getchar() != '\n');  // 清空输入缓冲区
		}
		else {
			break;
		}
	}
	switch (choice)
	{
	case 1:
		DestroyList_DuL(L);
		break;
	case 2:
		InsertBeforeList_DuL(*L, p5);
		for (DuLNode* p = (*L)->next; p != NULL; p = p->next)
			printf("%d\n", p->data);
		break;
	case 3:
		InsertAfterList_DuL(p2, p5);
		for (DuLNode* p = (*L)->next; p != NULL; p = p->next)
			printf("%d\n", p->data);
		break;
	case 4:
		;
		ElemType a;
		ElemType* e = &a;
		DeleteList_DuL(p1, e);
		for (DuLNode* p = (*L)->next; p != NULL; p = p->next)
			printf("%d\n", p->data);
		if (e != NULL)
			printf("e:%d\n", *e);
		break;
	case 5:
		;
		void (*traverse)(ElemType e) = &visit;
		TraverseList_DuL(*L, traverse);
		break;
	default:
		break;
	}
	return 0;
}
