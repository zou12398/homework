#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include "DuLinkedList.h"

ElemType checkinput()															//��������Ƿ�Ϸ�
{
	ElemType result;
	ElemType input;
	while (1) {
		result = scanf("%d", &input);
		if (result == 0) {
			printf("���������������: ");
			while (getchar() != '\n');  // ������뻺����
		}
		else {
			break;
		}
	}
	return input;
}

DuLNode* SearchList1(DuLinkedList L, ElemType e)													//��ѯ����
{
	if (L == NULL)																			//�������Ϸ���
		return NULL;

	DuLNode* p = L->next;
	while (p != NULL)																		//��������
	{
		if (p->data == e)																	//�ж������Ƿ����
			return p;
		p = p->next;
	}
	printf("�޸ýڵ�\n");
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
		printf("��������Ҫ�Ĺ���:");
		ElemType result;
		while (1) {
			result = scanf("%3d", &choice);
			if (result == 0||choice<1||choice>7) {
				printf("���������������: ");
				while (getchar() != '\n');  // ������뻺����
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
			if (head == NULL)															//�ж��Ƿ��ʼ��
			{
				printf("δ��ʼ��\n");
				break;
			}
			DestroyList_DuL(L);
			break;
		case 3:
			if (head == NULL)
			{
				printf("δ��ʼ��\n");
				break;
			}
			printf("�������������:");
			DuLNode* p0 = (DuLNode*)malloc(sizeof(struct DuLNode));					//��������ڵ�
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
			printf("�����뱻����ڵ�����:");
			insert = checkinput();
			DuLNode* t1 = SearchList1(*L, insert);									//���������б�����ڵ�
			if (t1 != NULL)
				InsertBeforeList_DuL(t1, p0);
			break;
		case 4:
			if (head == NULL)
			{
				printf("δ��ʼ��\n");
				break;
			}
			printf("�������������:");
			DuLNode* p01 = (DuLNode*)malloc(sizeof(struct DuLNode));				//��������ڵ�
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
			printf("�����뱻����ڵ�����:");
			insert = checkinput();
			DuLNode* t2 = SearchList1(*L, insert);									//���������б�����ڵ�
			if (t2 != NULL)
				InsertAfterList_DuL(t2, p01);
			break;
		case 5:
			if (head == NULL)
			{
				printf("δ��ʼ��\n");
				break;
			}
			if (head->next == NULL)
			{
				printf("�޽ڵ�\n");
				break;
			}
			ElemType a = 0;
			ElemType* e = &a;
			printf("�����뱻ɾ���ڵ��ǰһ�ڵ�����:");
			insert = checkinput();
			DuLNode* t3 = SearchList1(*L, insert);								//���ұ�ɾ���ڵ��ǰһ�ڵ�
			if (t3 != NULL)
				DeleteList_DuL(t3, e);
			if (*e != 0)
				printf("ɾ���ڵ�����:%d\n", *e);
			break;
		case 6:
			if (head == NULL)
			{
				printf("δ��ʼ��\n");
				break;
			}
			if (head->next == NULL)
			{
				printf("�޽ڵ�\n");
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
