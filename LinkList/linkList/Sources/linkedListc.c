#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include "LinkedList.h"




ElemType main()
{
	char menu[12][50] =
	{ "------------------------------",
		"[1]DestroyList",
		"[2]InsertList",
		"[3]DeleteList",
		"[4]TraverseList",
		"[5]SearchList",
		"[6]ReverseList",
		"[7]IsLoopList",
		"[8]ReverseEvenList",
		"[9}FindMidNode",
		"------------------------------"
	};
	ElemType choice=0;
	ElemType result;
	LinkedList head = NULL;
	LinkedList* L = &head;
	
	
		for (int i = 0; i < 12; i++)
			printf("%s\n", menu[i]);
		printf("%s\n", InitList(L) ? "SUCCESS" : "ERROR");						//初始化并连接p1,p2,p3,p4，进行测试
		LNode* p1 = (LNode*)malloc(sizeof(struct LNode));
		LNode* p2 = (LNode*)malloc(sizeof(struct LNode));
		LNode* p3 = (LNode*)malloc(sizeof(struct LNode));
		LNode* p4 = (LNode*)malloc(sizeof(struct LNode));
		LNode* p5 = (LNode*)malloc(sizeof(struct LNode));
		p5->next = NULL;
		(*L)->next = p1;
		p1->next = p2;
		p2->next = p3;
		p3->next = p4;
		p4->next = NULL;
		p1->data = 1;
		p2->data = 2;
		p3->data = 3;
		p4->data = 4;
		for (LNode* p = (*L)->next; p != NULL; p = p->next)
			printf("%d\n", p->data);
		printf("请输入你要的功能:");
		while (1) {
			result = scanf("%3d", &choice);
			if (result == 0||choice>10||choice<1) {
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
			DestroyList(L);
			break;
		case 2:
			;
			printf("请输入存入数据:");
			while (1) {
				result = scanf("%d", &(p5->data));
				if (result == 0) {
					printf("输入错误，重新输入: ");
					while (getchar() != '\n');  // 清空输入缓冲区
				}
				else {
					break;
				}
			}
			InsertList(*L, p5);											//以L进行测试
			for (LNode* p = (*L)->next; p != NULL; p = p->next)
				printf("%d\n", p->data);
			break;
		case 3:
			;
			ElemType a;
			ElemType* e = &a;
			DeleteList(*L, e);
			for (LNode* p = (*L)->next; p != NULL; p = p->next)
				printf("%d\n", p->data);
			if (e != NULL)
				printf("e:%d\n", *e);
			break;
		case 4:
			;
			void (*traverse)(ElemType e) = &visit;
			TraverseList(*L, traverse);
			break;
		case 5:
			;
			ElemType sea;
			printf("请输入查找数据:");
			while (1) {
				result = scanf("%d", &sea);
				if (result == 0) {
					printf("输入错误，重新输入: ");
					while (getchar() != '\n');  // 清空输入缓冲区
				}
				else {
					break;
				}
			}
			printf("%s\n", SearchList(*L, sea) ? "SUCCESS" : "ERROR");
			break;
		case 6:
			ReverseList(L);
			for (LNode* p = (*L)->next; p != NULL; p = p->next)
				printf("%d\n", p->data);
			break;
		case 7:
			printf("%s\n", IsLoopList(*L) ? "SUCCESS" : "ERROR");		//非循环
			p4->next = p2;												//测试循环链表
			printf("%s\n", IsLoopList(*L) ? "SUCCESS" : "ERROR");		//循环
			break;
		case 8:
			ReverseEvenList(L);
			for (LNode* p = (*L)->next; p != NULL; p = p->next)
				printf("%d\n", p->data);
			break;
		case 9:
			printf("%d\n", FindMidNode(L)->data);
			p5->data = 5;
			p4->next = p5;
			printf("%d\n", FindMidNode(L)->data);
			for (LNode* p = (*L)->next; p != NULL; p = p->next)
				printf("%d\n", p->data);
			break;
		default:
			break;
		}
	
	return 0;
}


