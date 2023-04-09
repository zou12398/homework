#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
}Node,*NodePtr;


typedef struct BinarySortTree {
	NodePtr root;
} BinarySortTree, * BinarySortTreePtr;

typedef  struct StackNode
{
	NodePtr data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr 	 top;	  //栈顶指针
	int		 count;  //栈中元素个数
}LinkStack;

typedef enum Status {
	ERROR,
	SUCCESS
} Status;

Status Init(BinarySortTreePtr T)
{
	T->root = NULL;
	return SUCCESS;
}

Status Search(BinarySortTreePtr T, int sea)
{
	if (T == NULL||T->root==NULL)
		return ERROR;
	Node* p = T->root;
	while (p != NULL)
	{
		if (sea < p->data)
		{
			p = p->left;
		}
		else if (sea > p->data)
		{
			p = p->right;
		}
		else
		{
			return SUCCESS;
		}
	}
	return ERROR;
}

Status Insert(BinarySortTreePtr T, int data)
{
	if (T == NULL)
		return ERROR;
	Node* p = T->root;
	Node* p1 = T->root;
	while (p != NULL)
	{
		p1 = p;
		if (data < p->data)
		{
			p = p->left;
		}
		else if (data > p->data)
		{
			p = p->right;
		}
		else
		{
			return ERROR;
		}
		
	}
	Node* p2 = (Node*)malloc(sizeof(Node));
	p2->data = data;
	p2->left = NULL;
	p2->right = NULL;
	if (p1 == NULL)
	{
		T->root = p2;
		return SUCCESS;
	}
	if (data < p1->data )
	{
		p1->left = p2;
	}
	else if (data > p1->data )
	{
		p1->right = p2;
	}
	return SUCCESS;
}

Status Delete(BinarySortTreePtr T, int data)
{
	if (T == NULL || T->root == NULL)
		return ERROR;
	Node* p = T->root;
	Node* p1 = T->root;
	while (p != NULL)
	{
		p1 = p;
		if (data < p->data)
		{
			p = p->left;
		}
		else if (data > p->data)
		{
			p = p->right;
		}
		if (p->data == data)
			break;
	}

	if (p == NULL)
		return ERROR;

	if (p->left == NULL && p->right == NULL)
	{
		if (p == T->root)
		{
			T->root = NULL;
		}
		if (data < p1->data)
		{
			p1->left = NULL;
		}
		else if (data > p1->data)
		{
			p1->right = NULL;
		}
		free(p);
		return SUCCESS;
	}
	else if (p->left == NULL)
	{
		if (p == T->root)
		{
			T->root = p->right;
		}
		if (data < p1->data)
		{
			p1->left = p->right;
		}
		else if (data > p1->data)
		{
			p1->right = p->right;
		}
		free(p);
		return SUCCESS;
	}
	else if (p->right == NULL)
	{
		if (p == T->root)
		{
			T->root = p->left;
		}
		if (data < p1->data)
		{
			p1->left = p->left;
		}
		else if (data > p1->data)
		{
			p1->right = p->left;
		}
		free(p);
		return SUCCESS;
	}
	else
	{
		Node* c1 = p;
		Node* c = p->right;
		while (c->left != NULL)
		{
			c1 = c;
			c = c->left;
		}
		p->data = c->data;
		if (c->right != NULL&&c1!=p)
			c1->left = c->right;
		if (c->right != NULL && c1 == p)
			c1->right = c->right;
		free(c);
	}
	return SUCCESS;
}

void visit(int e)
{
	printf("%d\n", e);
}

Status PreorderTraverse(NodePtr T, void (*visit)(int e))
{
	if (T == NULL)
		return SUCCESS;
	visit(T->data);
	PreorderTraverse(T->left, visit);
	PreorderTraverse(T->right, visit);
	return SUCCESS;
}

Status InorderTraverse(NodePtr T, void (*visit)(int e))
{
	if (T == NULL)
		return SUCCESS;
	InorderTraverse(T->left, visit);
	visit(T->data);
	InorderTraverse(T->right, visit);
	return SUCCESS;
}

Status PostorderTraverse(NodePtr T, void (*visit)(int e))
{
	if (T == NULL)
		return SUCCESS;
	PostorderTraverse(T->left, visit);
	PostorderTraverse(T->right, visit);
	visit(T->data);
	return SUCCESS;
}






Status InitStack(LinkStack* S)										//初始化栈
{
	S->top = NULL;
	S->count = 0;
	return SUCCESS;
}

Status isEmptyStack(LinkStack* S)												//判断是否为空
{
	if (S == NULL || S->count == 0 || S->top == NULL)
		return SUCCESS;
	else
		return ERROR;
}

Node* getTopStack(LinkStack* S )							//获取栈顶元素
{
	if (S == NULL || S->count == 0 || S->top == NULL)
		return NULL;
	Node*e = S->top->data;
	return e;
}

Status pushStack(LinkStack* S, Node* e)												//入栈
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


Node* popStack(LinkStack* S)												//出栈
{
	if (S == NULL || S->count == 0)
		return NULL;
	StackNode* p1 = S->top;
	Node* e;
	e = S->top->data;
	S->top = S->top->next;
	free(p1);
	S->count--;
	return e;
}

Status Preorder(BinarySortTreePtr T, void (*visit)(int e))
{
	if (T == NULL||T->root==NULL)
		return ERROR;
	LinkStack St;
	LinkStack* S = &St;
	Node* p = T->root;
	InitStack(S);
	pushStack(S, p);
	while (!isEmptyStack(S))
	{
		Node* p1= popStack(S);
		visit(p1->data);
		if (p1->right != NULL)
			pushStack(S, p1->right);
		if (p1->left != NULL)
			pushStack(S, p1->left);
	}
	return SUCCESS;
}

Status Inorder(BinarySortTreePtr T, void (*visit)(int e))
{
	if (T == NULL || T->root == NULL)
		return ERROR;
	LinkStack St;
	LinkStack* S = &St;
	InitStack(S);
	Node* n = T->root;
	while (n != NULL || !isEmptyStack(S))
	{
		while (n != NULL)
		{
			pushStack(S, n);
			n = n->left;
		}
		n = popStack(S);
		visit(n->data);
		n = n->right;
	}
	return SUCCESS;
}

Status Postorder(BinarySortTreePtr T, void (*visit)(int e))
{
	if (T == NULL || T->root == NULL)
		return ERROR;
	LinkStack St;
	LinkStack* S = &St;
	InitStack(S);
	Node* n = T->root;
	Node* v = T->root;

	while (n != NULL || !isEmptyStack(S))
	{
		while (n != NULL)
		{
			pushStack(S, n);
			n = n->left;
		}
		n = getTopStack(S);
		if (n->right && n->right != v)
		{
			n = n->right;
		}
		else
		{
			visit(n->data);
			v = n;
			n = NULL;
			popStack(S);
		}
	}
	return SUCCESS;
}







typedef struct node
{
	NodePtr data;                   //数据域指针
	struct node* next;            //指向当前结点的下一结点
} Nodeq;

typedef struct Lqueue
{
	Nodeq* front;                   //队头
	Nodeq* rear;                    //队尾
	size_t length;            //队列长度
} LQueue;
 
void InitLQueue(LQueue* Q)
{
	Q->front = NULL;
	Q->rear = NULL;
	Q->length = 0;
}

Status IsEmptyLQueue(const LQueue* Q)
{
	if (Q == NULL || Q->length == 0 || Q->front == NULL)
		return SUCCESS;
	return ERROR;
}

Status EnLQueue(LQueue* Q, Node* data)
{
	if (Q == NULL || data == NULL)
		return ERROR;
	Nodeq* p = (Nodeq*)malloc(sizeof(Nodeq));
	p->data = data;
	p->next = NULL;
	if (Q->front == NULL)
	{
		Q->front = p;
		Q->rear = p;
		Q->length++;
	}
	else
	{
		Q->rear->next = p;
		Q->rear = p;
		Q->length++;
	}
	return SUCCESS;
}

Node* DeLQueue(LQueue* Q)
{
	if (IsEmptyLQueue(Q) == 1)
		return NULL;
	Nodeq* p = Q->front;
	Q->front = Q->front->next;
	Node* e = p->data;
	free(p);
	Q->length--;
	return e;
}

Status Levelorder(BinarySortTreePtr T, void(*visit)(int e))
{
	if (T == NULL || T->root == NULL)
		return ERROR;
	LQueue head;
	LQueue* Q = &head;
	InitLQueue(Q);
	EnLQueue(Q, T->root);
	while (!IsEmptyLQueue(Q))
	{
		Node* p = DeLQueue(Q);
		visit(p->data);
		if (p->left)
			EnLQueue(Q, p->left);
		if (p->right)
			EnLQueue(Q, p->right);
	}
}