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
   //��ʽ���нṹ
typedef struct node
{
    void* data;                   //������ָ��
    struct node* next;            //ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
    Node* front;                   //��ͷ
    Node* rear;                    //��β
    size_t length;            //���г���
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
  *    @description : ��ʼ������
  *    @param         Q ����ָ��Q
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
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue* Q)
{
    if (Q == NULL)
    {
        printf("��������\n");
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
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
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
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
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
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue* Q)
{
    if (Q == NULL)
    {
        printf("��������\n");
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
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
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
 *    @description : ��������
 *    @param         q ָ��q

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


