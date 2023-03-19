#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include "DuLinkedList.h"

ElemType checkinput()															//检查输入是否合法
{
	ElemType result;
	ElemType input;
	while (1) {
		result = scanf("%3d", &input);
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
	DuLinkedList head;
	DuLinkedList* L = &head;
	ElemType choice = 0;
	int insert;
	while (1)
	{
		int check = 0;
		for (int i = 0; i < 9; i++)
			printf("%s\n", menu[i]);
		choice = 0;
		printf("请输入你要的功能:");
		while (choice < 1 || choice>7)
		{
			if (check != 0)
				printf("输入错误，重新输入: ");
			choice = checkinput();
			check++;
		}

		switch (choice)
		{
		case 1:
			;
			printf("%s\n", InitList_DuL(L) ? "SUCCESS" : "ERROR");
			DuLNode* p1 = (DuLNode*)malloc(sizeof(struct DuLNode));				//初始化链表并连接p1,p2,p3,p4
			(*L)->next = p1;
			p1->data = 1;
			p1->next = NULL;
			p1->prior = *L;
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
