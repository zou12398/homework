#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include "LinkedList.h"



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

LNode* SearchList1(LinkedList L, ElemType e)													//查询链表
{
	if (L == NULL)																			//检查参数合法性
		return NULL;

	LNode* p = L->next;
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
	ElemType checkinput();
	char menu[13][50] =
	{ "------------------------------",
		"[1]InitList",
		"[2]DestroyList",
		"[3]InsertList",
		"[4]DeleteList",
		"[5]TraverseList",
		"[6]SearchList",
		"[7]ReverseList",
		"[8]IsLoopList",
		"[9]ReverseEvenList",
		"[10]FindMidNode",
		"[11]exit",
		"------------------------------"
	};
	ElemType choice = 0;
	LinkedList head = NULL;
	LinkedList* L = &head;
	int insert;

	while (1)
	{
		int check = 0;
		for (int i = 0; i < 13; i++)
			printf("%s\n", menu[i]);
		printf("请输入你要的功能:");
		choice = 0;
		while (choice < 1 || choice>11)
		{
			if (check != 0)
				printf("输入错误，重新输入: ");
			choice = checkinput();
			check++;
		}
		switch (choice)
		{
		case 1:
			printf("%s\n", InitList(L) ? "SUCCESS" : "ERROR");						//初始化并连接p1,p2,p3,p4，进行测试
			LNode* p1 = (LNode*)malloc(sizeof(struct LNode));
			LNode* p2 = (LNode*)malloc(sizeof(struct LNode));
			LNode* p3 = (LNode*)malloc(sizeof(struct LNode));
			LNode* p4 = (LNode*)malloc(sizeof(struct LNode));
			(*L)->next = p1;
			p1->next = p2;
			p2->next = p3;
			p3->next = p4;
			p4->next = NULL;
			p1->data = 1;
			p2->data = 2;
			p3->data = 3;
			p4->data = 4;
			break;
		case 2:
			if (head == NULL)
			{
				printf("未初始化\n");
				break;
			}
			DestroyList(L);
			break;
		case 3:
			;
			if (head == NULL)
			{
				printf("未初始化\n");
				break;
			}
			printf("请输入存入数据:");
			LNode* p0 = (LNode*)malloc(sizeof(struct LNode));
			p0->next = NULL;
			p0->data = checkinput();
			printf("请输入被插入节点数据:");
			insert = checkinput();
			LNode* t1 = SearchList1(*L, insert);
			if (t1 != NULL)
				InsertList(t1, p0);
			break;
		case 4:
			;
			if (head == NULL)
			{
				printf("未初始化\n");
				break;
			}
			ElemType a = 0;
			ElemType* e = &a;
			printf("请输入被删除节点的前一节点数据:");
			insert = checkinput();
			LNode* t2 = SearchList1(*L, insert);
			if (t2 != NULL)
				DeleteList(t2, e);
			if (*e != 0)
				printf("删除节点数据:%d\n", *e);
			break;
		case 5:
			;
			if (head == NULL)
			{
				printf("未初始化\n");
				break;
			}
			void (*traverse)(ElemType e) = &visit;
			TraverseList(*L, traverse);
			break;
		case 6:
			;
			if (head == NULL)
			{
				printf("未初始化\n");
				break;
			}
			ElemType sea = 0;
			printf("请输入查找数据:");
			sea = checkinput();
			printf("%s\n", SearchList(*L, sea) ? "SUCCESS" : "ERROR");
			break;
		case 7:
			if (head == NULL)
			{
				printf("未初始化\n");
				break;
			}
			ReverseList(L);
			break;
		case 8:
			if (head == NULL)
			{
				printf("未初始化\n");
				break;
			}
			printf("%s\n", IsLoopList(*L) ? "SUCCESS" : "ERROR");		//非循环
			break;
		case 9:
			if (head == NULL)
			{
				printf("未初始化\n");
				break;
			}
			ReverseEvenList(L);
			break;
		case 10:
			;
			if (head == NULL)
			{
				printf("未初始化\n");
				break;
			}
			LNode* t3 = FindMidNode(L);
			printf("%d\n", t3->data);
			break;
		case 11:
			return 0;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}


