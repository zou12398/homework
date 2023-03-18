#pragma once
/***************************************************************************************
 *	File Name				:	linkedList.h
 *	CopyRight				:	2020 QG Studio
 *	SYSTEM					:   win10
 *	Create Data				:	2020.3.28
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/
#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
 /**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

/**************************************************************
*	Macro Define Section
**************************************************************/

#define OVERFLOW -1

/**************************************************************
*	Struct Define Section
**************************************************************/

// define element type
typedef int ElemType;

// define struct of linked list
typedef struct LNode {
	ElemType data;
	struct LNode* next;
} LNode, * LinkedList;

// define Status
typedef enum Status {
	ERROR,
	SUCCESS
} Status;


/**************************************************************
*	Prototype Declare Section
**************************************************************/


/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */

Status InitList(LinkedList* L)													//��ʼ������
{
	if (L == NULL) {
		return ERROR;
	}
	LinkedList h = (LinkedList)malloc(sizeof(struct LNode));
	*L = h;
	h->next = NULL;
	if (*L != NULL)
		return SUCCESS;
	else
		return ERROR;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList* L)																//ɾ������
{
	LNode* current = *L;						//��ǰ�ڵ�
	LNode* next = NULL;							//��һ���ڵ�
	while (current != NULL)
	{
		next = current->next;						//next��Ϊ��ǰ�ڵ����һ���ڵ�
		free(current);
		current = next;								//��ǰ�ڵ����
	}
	*L = NULL;
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode* p, LNode* q)														//��������
{
	if (p == NULL || q == NULL)																//�������Ϸ���
		return ERROR;
	if (p->next == NULL)
	{
		p->next = q;
		return SUCCESS;
	}
	q->next = p->next;																		//�½ڵ�ָ���ҽڵ�
	p->next = q;																			//��ڵ�ָ���½ڵ�
	return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode* p, ElemType* e)													//ɾ���ڵ�
{
	if (p == NULL)																			//�������Ϸ���
		return ERROR;
	if (p->next == NULL)
	{
		e = NULL;
		return SUCCESS;
	}
	LNode* del = p->next;																	//delָ��Ҫɾ���Ľڵ�
	*e = del->data;																			//��ɾ���ڵ�����ݴ���e
	LNode* after = p->next->next;															//afterָ���ҽڵ�
	free(del);																				//�ͷ�del
	p->next = after;																		//��ڵ�ָ���ҽڵ�
	return SUCCESS;
}
/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void visit(ElemType e)
{
	printf("%d\n", e);
}
void TraverseList(LinkedList L, void (*visit)(ElemType e))									//��������
{
	if (L == NULL)
		return;
	LNode* p = L->next;

	for (; p != NULL; p = p->next)
	{
		visit(p->data);
	}
}


/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e)													//��ѯ����
{
	if (L == NULL)																			//�������Ϸ���
		return ERROR;

	LNode* p = L->next;
	while (p != NULL)																		//��������
	{
		if (p->data == e)																	//�ж������Ƿ����
			return SUCCESS;
		p = p->next;
	}
	return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList* L)															//��ת����
{
	if (*L == NULL)
		return ERROR;
	if ((*L)->next == NULL || (*L)->next->next == NULL)
		return SUCCESS;
	LNode* p1 = (*L)->next->next->next;									//p1Ϊ�ҽڵ�
	LNode* p2 = (*L)->next->next;										//p2Ϊ�нڵ�
	LNode* p3 = (*L)->next;												//p3Ϊ��ڵ�
	p3->next = NULL;
	while (p1 != NULL)													//�ж��Ƿ�������
	{
		p2->next = p3;													//�нڵ�ָ����ڵ�
		p3 = p2;														//��ڵ�����
		p2 = p1;														//�нڵ�����
		p1 = p1->next;													//�ҽڵ�����
	}
	p2->next = p3;														//ѭ������ʱĩ�ڵ㻹δת��
	(*L)->next = p2;													//ͷ�ڵ�ָ��ĩ�ڵ�
	return SUCCESS;


}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L)																//�ж�ѭ������
{
	if (L == NULL)
		return ERROR;
	LNode* p1 = L;
	LNode* p2 = L;
	while (p2->next != NULL&&p2!=NULL&& p2->next->next!=NULL)								//�ж��Ƿ�Ϊѭ������
	{
		p1 = p1->next;																		//p1����һ��
		p2 = p2->next->next;																//p2��������
		if (p1 == p2)																		
		{
			return SUCCESS;
		}
	}
	return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList* L)														//ż����ת
{
	if (*L == NULL || (*L)->next == NULL || (*L)->next->next == NULL)						//�жϲ����Ϸ���
		return *L;
	LNode* p1 = (*L);
	LNode* p2 = (*L)->next;
	LNode* p3 = (*L)->next->next;
	while (p3 != NULL)																		//�ж��Ƿ�����ĩβ
	{
		if ((p3->data) % 2 == 0)															//�ж��Ƿ�Ϊż��
		{
			p2->next = p3->next;															//�нڵ�ָ���ҽڵ����һ�ڵ�
			p3->next = p2;																	//�ҽڵ�ָ���нڵ�
			p1->next = p3;																	//��ڵ�ָ���ҽڵ�
			p3 = p2->next;																	//�ҽڵ�����2λ
			p1 = p1->next;																	//��ڵ�����һλ
		}
		else
		{
			p1 = p1->next;																	//��ż��ʱ���ڵ�����һλ
			p2 = p2->next;
			p3 = p3->next;
		}
	}
	return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList* L)														
{
	if (*L == NULL || (*L)->next == NULL)												//�жϲ����Ϸ���
		return *L;
	LNode* p1 = *L;
	LNode* p2 = *L;
	while (1)
	{
		if (p2 == NULL)																	//�жϳ�ͷ�ڵ���������Ƿ�Ϊ����
			return p1->next;
		if (p2->next == NULL)															//�жϳ�ͷ�ڵ���������Ƿ�Ϊż��
			return p1;
		p1 = p1->next;																	//p1����һλ
		p2 = p2->next->next;															//p2������λ
	}
	return p1;
}

/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
