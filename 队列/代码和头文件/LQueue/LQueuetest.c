#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LQueue.h"


void get_type();
void get_data();
void get_int(void** data);
void get_float(void** data);
void get_char(void** data);
void show();

char type;
char datatype[30];

int main()
{
	LQueue* Q = NULL;
	get_type();
	char menu[12][50] =
	{ "------------------------------",
	"[1]InitLQueue",
	"[2]DestoryLQueue",
	"[3]IsEmptyLQueue",
	"[4]GetHeadLQueue",
	"[5]LengthLQueue",
	"[6]EnLQueue",
	"[7]DeLQueue",
	"[8]ClearLQueue",
	"[9]TraverseLQueue",
	"[10]exit",
	"------------------------------"
	};
	while (1)
	{
		for (int i = 0; i < 12; i++)
			printf("%s\n", menu[i]);
		printf("请输入你要的功能:");
		int choice = 0;
		while (1) {
			int result;
			result = scanf("%3d", &choice);
			if (result == 0 || choice < 1 || choice>10) {
				printf("输入错误，重新输入: ");
				while (getchar() != '\n');  // 清空输入缓冲区
			}
			else {
				while (getchar() != '\n');  // 清空输入缓冲区
				break;
			}
		}
		switch (choice)
		{
		case 1:
			;
			Q = (LQueue*)malloc(sizeof(LQueue));
			InitLQueue(Q);
			break;
		case 2:
			if (Q == NULL)
			{
				printf("未初始化\n");
				break;
			}
			DestoryLQueue(Q);
			Q = NULL;
			break;
		case 3:
			if (Q == NULL)
			{
				printf("未初始化\n");
				break;
			}
			printf("%s\n", IsEmptyLQueue(Q) ? "TURE" : "FALSE");
			break;
		case 4:
			if (Q == NULL)
			{
				printf("未初始化\n");
				break;
			}
			void* data=NULL;
			printf("%s\n", GetHeadLQueue(Q,data) ? "TURE" : "FALSE");
			break;
		case 5:
			if (Q == NULL)
			{
				printf("未初始化\n");
				break;
			}
			int length=-1;
			printf("%s\n", LengthLQueue(Q,&length) ? "TURE" : "FALSE");
			if(length!=-1)
			printf("%d\n", length);
			break;
		case 6:
			if (Q == NULL)
			{
				printf("未初始化\n");
				break;
			}
			void* p = NULL;
			get_data(&p);
			printf("%s\n", EnLQueue(Q, p) ? "TURE" : "FALSE");
			break;
		case 7:
			if (Q == NULL)
			{
				printf("未初始化\n");
				break;
			}
			printf("%s\n", DeLQueue(Q) ? "TURE" : "FALSE");
			break;
		case 8:
			if (Q == NULL)
			{
				printf("未初始化\n");
				break;
			}
			ClearLQueue(Q);
			break;
		case 9:
			if (Q == NULL)
			{
				printf("未初始化\n");
				break;
			}
			void (*p1)(void* q) =&LPrint;
			printf("%s\n", TraverseLQueue(Q,p1,type) ? "TURE" : "FALSE");
			break;
		case 10:
			return 0;

		}
		system("pause");
		system("cls");
	}

	return 0;
}

void LPrint(void* q);
void get_type()
{
	while (1)
	{
		type = '\0';
		printf("Please give me what kind of the data you want to keep:\n");
		printf("'i' means int, 'f' means float while 'c' means char!\n");
		scanf("%c", &type);
		while (getchar() != '\n');
		if (type == 'i' || type == 'f' || type == 'c')
			break;
		else
		{
			system("cls");
			printf("Please don't give me others!\n");
		}
	}
}
void get_data(void** data)
{
	if (type == 'i')
		get_int(data);
	else if (type == 'f')
		get_float(data);
	else if (type == 'c')
		get_char(data);
}

void get_int(void** data)
{
	printf("Please give me a int number:\n");
	int* p = (int*)malloc(sizeof(int));
	char s[50];
	int flag = 1;
	while (1)
	{
		gets(s);
		if (*s == '-')
		{
			if (strlen(s) < 6)
			{
				int i;
				for (i = 1; i < 6 && s[i] != '\0'; i++)
					if (s[i] < '0' || s[i]>'9')
				{
					flag = 0;
					break;
				}
				if (flag == 1)
				{
					*p = 0;
					for (i = 1; i < 6 && s[i] != '\0'; i++)
						*p = (*p) * 10 + s[i] - '0';
					(*p) *= -1;
					*data = (void*)p;
					return;
				}
			}
		}
		else if (strlen(s) < 5)
		{
			int i;
			for (i = 0; i < 5 && s[i] != '\0'; i++)
				if (s[i] < '0' || s[i]>'9')
				{
					flag = 0;
					break;
				}
			if (flag == 1)
			{
				*p = 0;
				for (i = 0; i < 5 && s[i] != '\0'; i++)
					*p = (*p) * 10 + s[i] - '0';
				*data = (void*)p;
				return;
			}
		}
		printf("Please give me a right int number which is bigger than -10000 and smaller than 10000;\n");
	}
}

void get_float(void** data)
{
	printf("Please give me a float number:\n");
	float* p = (float*)malloc(sizeof(float));
	*p = 0.0;
	char s[50];
	int flag = 1;
	while (1)
	{
		gets(s);
		if (*s == '-')
		{
			if (strlen(s) < 10)
			{
				flag = 1;
				int i;
				for (i = 1; i < 10 && s[i] != '\0'; i++)
					if ((s[i] < '0' && s[i] != '.') || s[i] > '9')
				{
					flag = 0;
					break;
				}
				if (flag == 1)
				{
					*p = 0;
					for (i = 1; i < 10 && s[i] != '.'&&s[i]!='\0'; i++)
						*p = (*p) * 10 + s[i] - '0';
					i++;
					for (float j = 10.0; i < 10 && s[i] != '\0'; i++, j *= 10)
						*p = (*p) + (s[i] - '0') / j;
					(*p) *= -1;
					*data = (void*)p;
					return;
				}
			}
		}
		else if (strlen(s) < 9)
		{
			flag = 1;
			int i;
			for (i = 0; i < 9 && s[i] != '\0'; i++)
				if ((s[i] < '0' && s[i] != '.') || s[i]>'9')
				{
					flag = 0;
					break;
				}
			if (flag == 1)
			{
				*p = 0;
				for (i = 0; i < 9 && s[i] != '.' && s[i] != '\0'; i++)
					*p = (*p) * 10 + s[i] - '0';
				i++;
				for (float j = 10.0; i < 9 && s[i] != '\0'; i++, j *= 10)
					*p = (*p) + (s[i] - '0') / j;
				*data = (void*)p;
				return;
			}
		}
		printf("Please give me a right float number;\n");
	}
	
}

void get_char(void** data)
{
	printf("Please give me a char:\n");
	char* p = (char*)malloc(sizeof(char));
	*p = '0';
	char s[50];
	int flag = 1;
	while (1)
	{
		gets(s);
		if (strlen(s) < 2)
		{
			break;
		}
		printf("Please give me a right char;\n");
	}
	*p = s[0];
	*data = (void*)p;
	return;
}

