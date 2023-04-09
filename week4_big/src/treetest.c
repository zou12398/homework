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
			printf("输入错误，重新输入: ");
			while (getchar() != '\n');  // 清空输入缓冲区
		}
		else {
			while (getchar() != '\n');  // 清空输入缓冲区
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
	"[1]查询",
	"[2]插入",
	"[3]删除",
	"[4]前序遍历(递归)",
	"[5]中序遍历(递归)",
	"[6]后序遍历(递归)",
	"[7]前序遍历(非递归)",
	"[8]中序遍历(非递归)",
	"[9]后序遍历(非递归)",
	"[10]层次遍历",
	"[11]退出",
	"------------------------------"
	};
	while (1)
	{

		for (int i = 0; i < 13; i++)
			printf("%s\n", menu[i]);
		printf("请输入你要的功能:");
		int choice = 0;
		while (1) {
			int result;
			result = scanf("%3d", &choice);
			if (result == 0 || choice < 1 || choice>12) {
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
			int sea;
			printf("请输入-10000到10000的数:");
			sea = checkinput();
			printf("%s\n", Search(T, sea) ? "SUCCESS" : "ERROR");
			break;
		case 2:
			;
			int ins;
			printf("请输入-10000到10000的数:");
			ins = checkinput();
			printf("%s\n", Insert(T, ins) ? "SUCCESS" : "ERROR");
			break;
		case 3:
			;
			int del;
			printf("请输入-10000到10000的数:");
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
