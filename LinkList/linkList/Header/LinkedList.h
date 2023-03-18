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

Status InitList(LinkedList* L)													//初始化链表
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
void DestroyList(LinkedList* L)																//删除链表
{
	LNode* current = *L;						//当前节点
	LNode* next = NULL;							//下一个节点
	while (current != NULL)
	{
		next = current->next;						//next变为当前节点的下一个节点
		free(current);
		current = next;								//当前节点后移
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
Status InsertList(LNode* p, LNode* q)														//插入链表
{
	if (p == NULL || q == NULL)																//检查参数合法性
		return ERROR;
	if (p->next == NULL)
	{
		p->next = q;
		return SUCCESS;
	}
	q->next = p->next;																		//新节点指向右节点
	p->next = q;																			//左节点指向新节点
	return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode* p, ElemType* e)													//删除节点
{
	if (p == NULL)																			//检查参数合法性
		return ERROR;
	if (p->next == NULL)
	{
		e = NULL;
		return SUCCESS;
	}
	LNode* del = p->next;																	//del指向要删除的节点
	*e = del->data;																			//把删除节点的数据存入e
	LNode* after = p->next->next;															//after指向右节点
	free(del);																				//释放del
	p->next = after;																		//左节点指向右节点
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
void TraverseList(LinkedList L, void (*visit)(ElemType e))									//遍历链表
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
Status SearchList(LinkedList L, ElemType e)													//查询链表
{
	if (L == NULL)																			//检查参数合法性
		return ERROR;

	LNode* p = L->next;
	while (p != NULL)																		//遍历链表
	{
		if (p->data == e)																	//判断数据是否相等
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
Status ReverseList(LinkedList* L)															//反转链表
{
	if (*L == NULL)
		return ERROR;
	if ((*L)->next == NULL || (*L)->next->next == NULL)
		return SUCCESS;
	LNode* p1 = (*L)->next->next->next;									//p1为右节点
	LNode* p2 = (*L)->next->next;										//p2为中节点
	LNode* p3 = (*L)->next;												//p3为左节点
	p3->next = NULL;
	while (p1 != NULL)													//判断是否遍历完毕
	{
		p2->next = p3;													//中节点指向左节点
		p3 = p2;														//左节点右移
		p2 = p1;														//中节点右移
		p1 = p1->next;													//右节点右移
	}
	p2->next = p3;														//循环结束时末节点还未转向
	(*L)->next = p2;													//头节点指向末节点
	return SUCCESS;


}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L)																//判断循环链表
{
	if (L == NULL)
		return ERROR;
	LNode* p1 = L;
	LNode* p2 = L;
	while (p2->next != NULL&&p2!=NULL&& p2->next->next!=NULL)								//判断是否为循环链表
	{
		p1 = p1->next;																		//p1右移一格
		p2 = p2->next->next;																//p2右移两格
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
LNode* ReverseEvenList(LinkedList* L)														//偶数逆转
{
	if (*L == NULL || (*L)->next == NULL || (*L)->next->next == NULL)						//判断参数合法性
		return *L;
	LNode* p1 = (*L);
	LNode* p2 = (*L)->next;
	LNode* p3 = (*L)->next->next;
	while (p3 != NULL)																		//判断是否到链表末尾
	{
		if ((p3->data) % 2 == 0)															//判断是否为偶数
		{
			p2->next = p3->next;															//中节点指向右节点的下一节点
			p3->next = p2;																	//右节点指向中节点
			p1->next = p3;																	//左节点指向右节点
			p3 = p2->next;																	//右节点右移2位
			p1 = p1->next;																	//左节点右移一位
		}
		else
		{
			p1 = p1->next;																	//非偶数时，节点右移一位
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
	if (*L == NULL || (*L)->next == NULL)												//判断参数合法性
		return *L;
	LNode* p1 = *L;
	LNode* p2 = *L;
	while (1)
	{
		if (p2 == NULL)																	//判断出头节点外的链表是否为单数
			return p1->next;
		if (p2->next == NULL)															//判断出头节点外的链表是否为偶数
			return p1;
		p1 = p1->next;																	//p1右移一位
		p2 = p2->next->next;															//p2右移两位
	}
	return p1;
}

/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
