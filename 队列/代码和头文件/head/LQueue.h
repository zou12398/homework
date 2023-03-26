#pragma once
#include<stdio.h>
#include <malloc.h>
#include <stdlib.h>
/***************************************************************************************
 *    File Name                :    LQueue.h
 *    CopyRight                :
 *
 *    SYSTEM                    :   Mac OS
 *    Create Data                :    2020.4.2
 *    Author/Corportation        :   Chuan Shi
 *
 *
 *--------------------------------Revision History--------------------------------------
 *    No    version        Data            Revised By            Item            Description
 *
 *
 ***************************************************************************************/

 /**************************************************************
  *    Multi-Include-Prevent Section
  **************************************************************/
#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED

  /**************************************************************
   *    Struct Define Section
   **************************************************************/
   //链式队列结构
typedef struct node
{
    void* data;                   //数据域指针
    struct node* next;            //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
    Node* front;                   //队头
    Node* rear;                    //队尾
    size_t length;            //队列长度
} LQueue;

typedef enum
{
    FALSE = 0, TRUE = 1
} Status;
char type;
char datatype[30];

/**************************************************************
 *    Prototype Declare Section
 **************************************************************/


 /**
  *  @name        : void InitLQueue(LQueue *Q)
  *    @description : 初始化队列
  *    @param         Q 队列指针Q
  *  @notice      : None
  */
void InitLQueue(LQueue* Q)
{
    Q->front = NULL;
    Q->rear = NULL;
    Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue* Q)
{
    if (Q == NULL)
    {
        printf("参数错误\n");
        return;
    }
    if (Q->front != NULL)
    {
        Node* p = Q->front;
        Q->front = Q->front->next;
        free(p);
    }
    Q->rear = NULL;
    Q->length = 0;
    free(Q);
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue* Q)
{
    if ( Q==NULL||Q->length == 0 || Q->front == NULL)
        return TRUE;
    return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue* Q, void* e)
{
    if (IsEmptyLQueue(Q) == 1)
        return FALSE;
    e = Q->front->data;
    return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue* Q,int* length)
{
    if (Q==NULL)
        return FALSE;
    *length = Q->length;
    return TRUE;

}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue* Q, void* data)
{
    if (Q==NULL||data==NULL)
        return FALSE;
    Node* p = (Node*)malloc(sizeof(Node));
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
    return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue* Q)
{
    if (IsEmptyLQueue(Q) == 1)
        return FALSE;
    Node* p = Q->front;
    Q->front = Q->front->next;
    free(p);
    Q->length--;
    return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue* Q)
{
    if (Q == NULL)
    {
        printf("参数错误\n");
        return;
    }
    if (Q->front != NULL)
    {
        Node* p = Q->front;
        Q->front = Q->front->next;
        free(p);
    }
    Q->rear = NULL;
    Q->length = 0;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q),char type)
{
    if (IsEmptyLQueue(Q) == 1||foo==NULL)
        return FALSE;
    Node* p = Q->front;
    for (; p != NULL; p = p->next)
    {
        foo(p->data,type);
    }
    return TRUE;
}


/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q

 *  @notice      : None
 */
void LPrint(void* q,char type)
{
    if (type == 'i')
        printf("%d\n", *(int*)q);
    if (type == 'f')
        printf("%f\n", *(float*)q);
    if (type == 'c')
        printf("%c\n", *(char*)q);
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // LQUEUE_H_INCLUDED


