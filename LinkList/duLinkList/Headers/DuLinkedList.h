#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/***************************************************************************************
 *	File Name				:	duLinkedList.h
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

 /**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/

#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED

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
typedef struct DuLNode {
	ElemType data;
	struct DuLNode* prior, * next;
} DuLNode, * DuLinkedList;

// define status
typedef enum Status {
	ERROR,
	SUCCESS,
} Status;


/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList* L)
{
	if (L == NULL)																			//�жϲ����Ϸ���
	{
		return ERROR;
	}
	DuLinkedList h = (DuLinkedList)malloc(sizeof(struct DuLNode));
	*L = h;
	h->next = NULL;
	h->prior = NULL;
	if (*L != NULL)
		return SUCCESS;
	else
		return ERROR;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList* L)
{
	DuLNode* current = *L;						//��ǰ�ڵ�
	DuLNode* next = NULL;							//��һ���ڵ�
	while (current != NULL)
	{
		next = current->next;						//next��Ϊ��ǰ�ڵ����һ���ڵ�
		free(current);
		current = next;								//��ǰ�ڵ����
	}
	*L = NULL;
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q)
{
	if (p == NULL || q == NULL)																//�������Ϸ���
		return ERROR;
	if (p->prior == NULL)																	//�ж�p�Ƿ�Ϊͷ�ڵ�
	{
		p->next->prior = q;																	//p����һ���ڵ�ָ��q
		q->next = p->next;																	//���pΪͷ�ڵ㣬q���뵽p->next��p֮��
		p->next = q;
		q->prior = p;
		return SUCCESS;
	}
	p->prior->next = q;
	q->next = p;
	q->prior = p->prior;
	p->prior = q;
	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode* p, DuLNode* q)
{
	if (p == NULL || q == NULL)																//�������Ϸ���
		return ERROR;
	if (p->next == NULL)																	//���pΪĩ�ڵ㣬qֱ��������p��
	{
		p->next = q;
		q->next = NULL;
		q->prior = p;
		return SUCCESS;
	}
	p->next->prior = q;
	q->next = p->next;
	q->prior = p;
	p->next = q;
	return SUCCESS;
}


/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode* p, ElemType* e)
{
	if (p == NULL)																			//�������Ϸ���
		return ERROR;
	if (p->next == NULL)																	//���pΪĩ�ڵ�ֱ�ӷ���
	{
		e = NULL;
		return SUCCESS;
	}
	DuLNode* del = p->next;																	//delΪҪɾ���Ľڵ�
	*e = del->data;																			//��del��ֵ����*e
	DuLNode* after = p->next->next;
	free(del);
	p->next = after;
	if (after != NULL)																			//�ж�after�Ƿ�Ϊ��
		after->prior = p;
	return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */

void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
{
	if (L == NULL)																			//�������Ϸ���
		return;
	DuLNode* p = L->next;

	for (; p != NULL; p = p->next)
	{
		visit(p->data);
	}
}
void visit(ElemType e)
{
	printf("%d\n", e);
}




/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
