#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include "DuLinkedList.h"

ElemType checkinput()															//检查输入是否合法
{
	ElemType result;
	ElemType input;
	while (1) {
		result = scanf("%d", &input);
		if (result == 0) {
			printf("输入错误，重新输入: ");
			while (getchar() != '\n');  // 清空输入缓冲区
		}
		else {
			break;
		}
	}
	return input;
}

DuLNode* SearchList1(DuLinkedList L, ElemType e)													//查询链表
{
	if (L == NULL)																			//检查参数合法性
		return NULL;

	DuLNode* p = L->next;
	while (p != NULL)																		//遍历链表
	{
		if (p->data == e)																	//判断数据是否相等
			return p;
		p = p->next;
	}
	printf("无该节点\n");
	return NULL;
}

ElemType main()
{
	char menu[9][50] =
	{ "------------------------------",
		"[1]InitList_DuL",
		"[2]DestroyList_DuL",
		"[3]InsertBeforeList_DuL",
		"[4]InsertAfterList_DuL",
		"[5]DeleteList_DuL",
		"[6]TraverseList_DuL",
		"[7]exit",
		"------------------------------"

	};
	DuLinkedList head=NULL;
	DuLinkedList* L = &head;
	ElemType choice = 0;
	int insert;
	while (1)
	{
		int a = 0;
		int check = 0;
		for (int i = 0; i < 9; i++)
			printf("%s\n", menu[i]);
		choice = 0;
		printf("请输入你要的功能:");
		ElemType result;
		while (1) {
			result = scanf("%3d", &choice);
			if (result == 0||choice<1||choice>7) {
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
			;
			printf("%s\n", InitList_DuL(L) ? "SUCCESS" : "ERROR");
			break;
		case 2:
			if (head == NULL)															//判断是否初始化
			{
				printf("未初始化\n");
				break;
			}
			DestroyList_DuL(L);
			break;
		case 3:
			if (head == NULL)
			{
				printf("未初始化\n");
				break;
			}
			printf("请输入存入数据:");
			DuLNode* p0 = (DuLNode*)malloc(sizeof(struct DuLNode));					//创建插入节点
			p0->next = NULL;
			p0->prior = NULL;
			p0->data = checkinput();
			if (head->next == NULL)
			{
				head->next = p0;
				p0->prior = head;
				a = 1;
			}
			if (a == 1)
				break;
			printf("请输入被插入节点数据:");
			insert = checkinput();
			DuLNode* t1 = SearchList1(*L, insert);									//查找链表中被插入节点
			if (t1 != NULL)
				InsertBeforeList_DuL(t1, p0);
			break;
		case 4:
			if (head == NULL)
			{
				printf("未初始化\n");
				break;
			}
			printf("请输入存入数据:");
			DuLNode* p01 = (DuLNode*)malloc(sizeof(struct DuLNode));				//创建插入节点
			p01->next = NULL;
			p01->prior = NULL;
			p01->data = checkinput();
			if (head->next == NULL)
			{
				head->next = p01;
				p01->prior = head;
				a = 1;
			}
			if (a == 1)
				break;
			printf("请输入被插入节点数据:");
			insert = checkinput();
			DuLNode* t2 = SearchList1(*L, insert);									//查找链表中被插入节点
			if (t2 != NULL)
				InsertAfterList_DuL(t2, p01);
			break;
		case 5:
			if (head == NULL)
			{
				printf("未初始化\n");
				break;
			}
			if (head->next == NULL)
			{
				printf("无节点\n");
				break;
			}
			ElemType a = 0;
			ElemType* e = &a;
			printf("请输入被删除节点的前一节点数据:");
			insert = checkinput();
			DuLNode* t3 = SearchList1(*L, insert);								//查找被删除节点的前一节点
			if (t3 != NULL)
				DeleteList_DuL(t3, e);
			if (*e != 0)
				printf("删除节点数据:%d\n", *e);
			break;
		case 6:
			if (head == NULL)
			{
				printf("未初始化\n");
				break;
			}
			if (head->next == NULL)
			{
				printf("无节点\n");
				break;
			}
			void (*traverse)(ElemType e) = &visit;
			TraverseList_DuL(*L, traverse);
			break;
		case 7:
			return 0;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}
