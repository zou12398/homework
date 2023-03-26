#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <malloc.h>
#include "stack.h"
#include <stdlib.h>

int checkinput() {
	int num;
	while (1)
	{
		ElemType result;
		result = scanf("%9d", &num);
		if (result == 0 ) {
			printf("���������������: ");
			while (getchar() != '\n');  // ������뻺����
		}
		else {
			while (getchar() != '\n');  // ������뻺����
			break;
		}
	}
	return num;
}

int main()
{
	LinkStack* S = NULL;
	char menu[11][50]=
	{ "------------------------------",
	"[1]InitStack",
	"[2]isEmptyStack",
	"[3]getTopStack",
	"[4]ClearLStack",
	"[5]destroyLStack",
	"[6]LStackLength",
	"[7]pushLStack",
	"[8]popLStack",
	"[9]exit",
	"------------------------------"
	};
	while (1)
	{
		for (int i = 0; i < 11; i++)
			printf("%s\n", menu[i]);
		printf("��������Ҫ�Ĺ���:");
		int choice = 0;
		while (1) {
			ElemType result;
			result = scanf("%3d", &choice);
			if (result == 0 || choice < 1 || choice>9) {
				printf("���������������: ");
				while (getchar() != '\n');  // ������뻺����
			}
			else {
				while (getchar() != '\n');  // ������뻺����
				break;
			}
		}
		switch (choice)
		{
		case 1:
			;
			/*LinkStack head ;
			S = &head;*/
			S = (LinkStack*)malloc(sizeof(LinkStack));
			printf("%s\n", InitStack(S) ? "SUCCESS" : "ERROR");
			break;
		case 2:
			if (S == NULL)
			{
				printf("δ��ʼ��\n");
				break;
			}
			printf("%s\n", isEmptyStack(S) ? "SUCCESS" : "ERROR");
			break;
		case 3:
			if (S == NULL)
			{
				printf("δ��ʼ��\n");
				break;
			}
			int e=0;
			if (getTopStack(S, &e))
			{
				printf("%d\n", e);
			}
			else
				printf("ERROR\n");
			break;
		case 4:
			if (S == NULL)
			{
				printf("δ��ʼ��\n");
				break;
			}
			printf("%s\n", clearStack(S) ? "SUCCESS" : "ERROR");
			break;
		case 5:
			if (S == NULL)
			{
				printf("δ��ʼ��\n");
				break;
			}
			int result = destroyStack(S);
			printf("%s\n", result ? "SUCCESS" : "ERROR");
			if (result == 1)
				S = NULL;
			break;
		case 6:
			if (S == NULL)
			{
				printf("δ��ʼ��\n");
				break;
			}
			int length;
			LStackLength(S, &length);
			printf("%d\n", length);
			break;
		case 7:
			if (S == NULL)
			{
				printf("δ��ʼ��\n");
				break;
			}
			printf("����������:");
			int a1 = checkinput();
			printf("%s\n", pushStack(S, a1) ? "SUCCESS" : "ERROR");
			break;
		case 8:
			if (S == NULL)
			{
				printf("δ��ʼ��\n");
				break;
			}
			int a2;
			printf("%s\n", popStack(S, &a2) ? "SUCCESS" : "ERROR");
			break;
		case 9:
			return 0;
		}
		system("pause");
		system("cls");
	}

	return 0;
}