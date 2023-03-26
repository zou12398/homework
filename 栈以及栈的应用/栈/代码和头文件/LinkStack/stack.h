#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <malloc.h>
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef int ElemType;

//��ʽ�ṹ
typedef  struct StackNode
{
	ElemType data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr 	 top;	  //ջ��ָ��
	int		 count;  //ջ��Ԫ�ظ���
}LinkStack;

typedef enum Status {
	ERROR,
	SUCCESS
} Status;

Status InitStack(LinkStack* S)										//��ʼ��ջ
{
	S->top = NULL;
	S->count = 0;
	return SUCCESS;
}

Status isEmptyStack(LinkStack* S)												//�ж��Ƿ�Ϊ��
{
	if (S==NULL||S->count==0||S->top==NULL)
		return SUCCESS;
	else
		return ERROR;
}

Status getTopStack(LinkStack* S, ElemType* e)							//��ȡջ��Ԫ��
{
	if (S == NULL || S->count == 0 || S->top == NULL)
		return ERROR;
	*e = S->top->data;
	return SUCCESS;
}

Status clearStack(LinkStack* S)												//���ջ
{
	if (S == NULL || S->count == 0 || S->top == NULL)
		return ERROR;
	if (S->count != 0)
	{
		StackNode* p1;
		for (; S->count > 0; S->count--)
		{
			p1 = S->top;
			S->top = S->top->next;
			free(p1);
		}
	}
	return SUCCESS;
}

Status destroyStack(LinkStack* S)													//����ջ
{
	if (S == NULL)
		return ERROR;
	if (S->count != 0)
	{
		StackNode* p1;
		for (; S->count > 0; S->count--)
		{
			p1 = S->top;
			S->top = S->top->next;
			free(p1);
		}
	}
	free(S);
	return SUCCESS;
}

Status LStackLength(LinkStack* S, int* length)//���ջ����
{
	if (S == NULL)
		return ERROR;
	*length = S->count;
	return SUCCESS;
}

Status pushStack(LinkStack* S, ElemType e)												//��ջ
{
	if (S == NULL)
		return ERROR;
	StackNode* p = (StackNode*)malloc(sizeof(struct StackNode));
	p->next = S->top;
	p->data = e;
	S->top = p;
	S->count++;
	return SUCCESS;
}


Status popStack(LinkStack* S, ElemType* e)												//��ջ
{
	if (S == NULL||S->count==0)
		return ERROR;
	StackNode* p1 = S->top;
	*e = S->top->data;
	S->top = S->top->next;
	free(p1);
	S->count--;
	return SUCCESS;
}


Status  printStack(LinkStack* S) 
{
	if (S == NULL || S->count == 0 || S->top == NULL)
		return ERROR;
	StackNode* p = S->top;
	while (p!=NULL) 
	{
		printf("%d\n", p->data);
		p = p->next;
	}
	return SUCCESS;
}

#endif 