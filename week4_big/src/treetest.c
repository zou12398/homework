#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tree.h"

int checkinput() {
	int num;
	while (1)
	{
		int result;
		result = scanf("%6d", &num);
		if (result == 0||num<-10000||num>10000) {
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
	BinarySortTree head;
	BinarySortTreePtr T = &head;
	Init(T);
	void (*a)(int e) = &visit;
	char menu[13][50] =
	{ "------------------------------",
	"[1]��ѯ",
	"[2]����",
	"[3]ɾ��",
	"[4]ǰ�����(�ݹ�)",
	"[5]�������(�ݹ�)",
	"[6]�������(�ݹ�)",
	"[7]ǰ�����(�ǵݹ�)",
	"[8]�������(�ǵݹ�)",
	"[9]�������(�ǵݹ�)",
	"[10]��α���",
	"[11]�˳�",
	"------------------------------"
	};
	while (1)
	{

		for (int i = 0; i < 13; i++)
			printf("%s\n", menu[i]);
		printf("��������Ҫ�Ĺ���:");
		int choice = 0;
		while (1) {
			int result;
			result = scanf("%3d", &choice);
			if (result == 0 || choice < 1 || choice>12) {
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
			int sea;
			printf("������-10000��10000����:");
			sea = checkinput();
			printf("%s\n", Search(T, sea) ? "SUCCESS" : "ERROR");
			break;
		case 2:
			;
			int ins;
			printf("������-10000��10000����:");
			ins = checkinput();
			printf("%s\n", Insert(T, ins) ? "SUCCESS" : "ERROR");
			break;
		case 3:
			;
			int del;
			printf("������-10000��10000����:");
			del = checkinput();
			printf("%s\n", Delete(T, del) ? "SUCCESS" : "ERROR");
			break;
		case 4:
			PreorderTraverse(T->root, a);
			break;
		case 5:
			InorderTraverse(T->root, a);
			break;
		case 6:
			PostorderTraverse(T->root, a);
			break;
		case 7:
			Preorder(T, a);
			break;
		case 8:
			Inorder(T, a);
			break;
		case 9:
			Postorder(T, a);
			break;
		case 10:
			Levelorder(T, a);
			break;
		case 11:
			return 0;
		}
		system("pause");
		system("cls");
	}
	return 0;
}
