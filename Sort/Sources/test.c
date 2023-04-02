#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include"sort.h"

int main()
{
	/*int a[20] = { 2 ,2 ,1 ,1 ,2 ,1 ,0 ,0 ,1 ,2 ,2 ,2 ,1 ,0 ,1 ,2, 1, 2, 0 ,0 };
	ColorSort(a, 20);
	for (int i = 0; i < 20; i++)
		printf("%d ", a[i]);*/
	menu();
	return 0;
}

int menu()
{
	char menu1[11][50] =
	{ "------------------------------",
	"[1]插入",
	"[2]归并",
	"[3]快排(随机)",
	"[4]快排(三枢轴)",
	"[5]计数",
	"[6]基数计数",
	"[7]颜色排序",
	"[8]第k大/小的数",
	"[9]exit",
	"------------------------------"
	};
	while (1)
	{
		for (int i = 0; i < 11; i++)
			printf("%s\n", menu1[i]);
		printf("请选择功能:");
		int choice = 0;
		while (1) {
			int result;
			result = scanf("%3d", &choice);
			if (result == 0 || choice < 1 || choice>9) {
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
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
			testmenu(choice);
			break;
		case 7:
			;
			int a1[20];
			for (int i = 0; i < 20; i++)
			{
				a1[i] = rand() % 3;
				printf("%d ", a1[i]);
			}
			printf("\n");
			ColorSort(a1, 20);
			for (int i = 0; i < 20; i++)
				printf("%d ", a1[i]);
			break;
		case 8:
			;
			int a[20];
			for (int i = 0; i < 20; i++)
			{
				a[i] = rand();
				printf("%d ", a[i]);
			}
			int k, n;
			printf("\n");
			printf("在上述数组中，请输入要几大/小的数(0到20):");
			while (1) {
				int result;
				result = scanf("%3d", &k);
				if (result == 0 || k < 1 || k>20) {
					printf("输入错误，重新输入: ");
					while (getchar() != '\n');  // 清空输入缓冲区
				}
				else {
					while (getchar() != '\n');  // 清空输入缓冲区
					break;
				}
			}
			printf("大请输入1，小则输入0:");
			while (1) {
				int result;
				result = scanf("%2d", &n);
				if (result == 0 || n < 0 || n>1) {
					printf("输入错误，重新输入: ");
					while (getchar() != '\n');  // 清空输入缓冲区
				}
				else {
					while (getchar() != '\n');  // 清空输入缓冲区
					break;
				}
			}
			printf("%d\n", search(a, 20, k, n));
			break;
		case 9:
			return;
		}
		system("pause");
		system("cls");
	}
}

int testmenu(int choice)
{
	char menu2[7][50] =
	{ "------------------------------",
	"[1]大数据",
	"[2]小数据",
	"[3]生产数据",
	"[4]读取数据",
	"[5]exit",
	"------------------------------"
	};
	while (1)
	{
		for (int i = 0; i < 7;i++)
			printf("%s\n", menu2[i]);
		printf("请选择功能:"); 
		int c = 0;
		while (1) {
			int result;
			result = scanf("%3d", &c);
			if (result == 0 || c < 1 || c>5) {
				printf("输入错误，重新输入: ");
				while (getchar() != '\n');  // 清空输入缓冲区
			}
			else {
				while (getchar() != '\n');  // 清空输入缓冲区
				break;
			}
		}
		switch (c)
		{
		case 1:
			;
			int* a1 = (int*)malloc(sizeof(int) * 10000);
			int* b1 = (int*)malloc(sizeof(int) * 10000);
			int* a2 = (int*)malloc(sizeof(int) * 50000);
			int* b2 = (int*)malloc(sizeof(int) * 50000);
			int* a3 = (int*)malloc(sizeof(int) * 200000);
			int* b3 = (int*)malloc(sizeof(int) * 200000);
			for (int i = 0; i < 10000; i++)
				a1[i] = rand();
			for (int i = 0; i < 50000; i++)
				a2[i] = rand();
			for (int i = 0; i < 200000; i++)
				a3[i] = rand();
			switch (choice)
			{
			case 1:
				;
				clock_t start1 = clock();
				insertSort(a1, 10000);
				clock_t diff1 = clock() - start1;
				printf("%d ms\n", diff1);

				clock_t start2 = clock();
				insertSort(a2, 50000);
				clock_t diff2 = clock() - start2;
				printf("%d ms\n", diff2);

				clock_t start3 = clock();
				insertSort(a3, 200000);
				clock_t diff3 = clock() - start3;
				printf("%d ms\n", diff3);
				break;
			case 2:
				;
				clock_t start4 = clock();
				MergeSort(a1,0,9999,b1);
				clock_t diff4 = clock() - start4;
				printf("%d ms\n", diff4);

				clock_t start5 = clock();
				MergeSort(a2, 0, 49999, b2);
				clock_t diff5 = clock() - start5;
				printf("%d ms\n", diff5);

				clock_t start6 = clock();
				MergeSort(a3, 0, 199999, b3);
				clock_t diff6 = clock() - start6;
				printf("%d ms\n", diff6);
				break;
			case 3:
				;
				clock_t start7 = clock();
				QuickSort_Recursion(a1,0,9999);
				clock_t diff7 = clock() - start7;
				printf("%d ms\n", diff7);

				clock_t start8 = clock();
				QuickSort_Recursion(a2, 0, 49999);
				clock_t diff8 = clock() - start8;
				printf("%d ms\n", diff8);

				clock_t start9 = clock();
				QuickSort_Recursion(a3, 0, 199999);
				clock_t diff9 = clock() - start9;
				printf("%d ms\n", diff9);
				break;
			case 4:
				;
				clock_t start10 = clock();
				Partition(a1, 0, 9999);
				clock_t diff10 = clock() - start10;
				printf("%d ms\n", diff10);

				clock_t start11 = clock();
				Partition(a2, 0, 49999);
				clock_t diff11 = clock() - start11;
				printf("%d ms\n", diff11);

				clock_t start12 = clock();
				Partition(a3, 0, 199999);
				clock_t diff12 = clock() - start12;
				printf("%d ms\n", diff12);
				break;
			case 5:
				;
				clock_t start13 = clock();
				CountSort(a1, 10000);
				clock_t diff13 = clock() - start13;
				printf("%d ms\n", diff13);

				clock_t start14 = clock();
				CountSort(a2, 50000);
				clock_t diff14 = clock() - start14;
				printf("%d ms\n", diff14);

				clock_t start15 = clock();
				CountSort(a3, 200000);
				clock_t diff15 = clock() - start15;
				printf("%d ms\n", diff15);
				break;
			case 6:
				;
				clock_t start16 = clock();
				RadixCountSort(a1, 10000);
				clock_t diff16 = clock() - start16;
				printf("%d ms\n", diff16);

				clock_t start17 = clock();
				RadixCountSort(a2, 50000);
				clock_t diff17 = clock() - start17;
				printf("%d ms\n", diff17);

				clock_t start18 = clock();
				RadixCountSort(a3, 200000);
				clock_t diff18 = clock() - start18;
				printf("%d ms\n", diff18);
				break;
			}
			free(a1);
			free(a2);
			free(a3);
			free(b1);
			free(b2);
			free(b3);
			break;
		case 2:
			;
			int a[100];
			int b[100];
			switch (choice)
			{
			case 1:
				;
				clock_t start1 = clock();
				for (int i = 0; i < 100000; i++)
				{
					for (int j = 0; j < 100; j++)
						a[j] = rand();
					insertSort(a, 100);
				}
				clock_t diff1 = clock() - start1;
				printf("%d ms\n", diff1);
				break;
			case 2:
				;
				clock_t start2 = clock();
				for (int i = 0; i < 100000; i++)
				{
					for (int j = 0; j < 100; j++)
						a[j] = rand();
					MergeSort(a, 0, 99, b);
				}
				clock_t diff2 = clock() - start2;
				printf("%d ms\n", diff2);
				break;
			case 3:
				;
				clock_t start3 = clock();
				for (int i = 0; i < 100000; i++)
				{
					for (int j = 0; j < 100; j++)
						a[j] = rand();
					QuickSort_Recursion(a, 0, 99);
				}
				clock_t diff3 = clock() - start3;
				printf("%d ms\n", diff3);
				break;
			case 4:
				;
				clock_t start4 = clock();
				for (int i = 0; i < 100000; i++)
				{
					for (int j = 0; j < 100; j++)
						a[j] = rand();
					Partition(a, 0, 99);
				}
				clock_t diff4 = clock() - start4;
				printf("%d ms\n", diff4);
				break;
			case 5:
				;
				clock_t start5 = clock();
				for (int i = 0; i < 100000; i++)
				{
					for (int j = 0; j < 100; j++)
						a[j] = rand();
					CountSort(a, 100);
				}
				clock_t diff5 = clock() - start5;
				printf("%d ms\n", diff5);
				break;
			case 6:
				;
				clock_t start6 = clock();
				for (int i = 0; i < 100000; i++)
				{
					for (int j = 0; j < 100; j++)
						a[j] = rand();
					RadixCountSort(a, 100);
				}
				clock_t diff6 = clock() - start6;
				printf("%d ms\n", diff6);
				break;
			}
			break;
		case 3:
			;
			FILE * fp1=NULL;
			char f1[100];
			while (fp1 == NULL)
			{
				printf("请输入文件路径:\n");
				gets(f1);
				fp1 = fopen(f1, "w");
				if (fp1 == NULL)
					printf("输入错误");
			}
			int min1 = 0, max1 = 0,num1=0;
			printf("请输入生成数据个数(1到10000):");
			while (1) {
				int result;
				result = scanf("%5d", &num1);
				if (result == 0 || num1 < 1 || num1>10000) {
					printf("输入错误，重新输入: ");
					while (getchar() != '\n');  // 清空输入缓冲区
				}
				else {
					while (getchar() != '\n');  // 清空输入缓冲区
					break;
				}
			}
			printf("请输入数据最小值(0到10000):");
			while (1) {
				int result;
				result = scanf("%5d", &min1);
				if (result == 0 || min1 < 0 || min1>10000) {
					printf("输入错误，重新输入: ");
					while (getchar() != '\n');  // 清空输入缓冲区
				}
				else {
					while (getchar() != '\n');  // 清空输入缓冲区
					break;
				}
			}
			printf("请输入数据最大值(0到10000):");
			while (1) {
				int result;
				result = scanf("%5d", &max1);
				if (result == 0 || max1 < min1 || max1>10000) {
					printf("输入错误，重新输入: ");
					while (getchar() != '\n');  // 清空输入缓冲区
				}
				else {
					while (getchar() != '\n');  // 清空输入缓冲区
					break;
				}
			}
			int* save = (int*)malloc(sizeof(int) * num1);
			for (int i = 0; i < num1; i++)
			{
				save[i] = rand() % (max1 - min1 + 1) + min1;
				fprintf(fp1, "%d ", save[i]);
			}
			free(save);
			fclose(fp1);
			break;
		case 4:
			;
			FILE* fp = NULL;
			char f[100];
			while (fp == NULL)
			{
				printf("请输入文件路径及名称:\n");
				gets(f);
				fp = fopen(f, "r");
				if (fp == NULL)
					printf("无法打开文件\n");
			}
			int min = 0, max = 0, num = 0;
			printf("请输入读取数据个数(1到10000):");
			while (1) {
				int result;
				result = scanf("%5d", &num);
				if (result == 0 || num < 1 || num>10000) {
					printf("输入错误，重新输入: ");
					while (getchar() != '\n');  // 清空输入缓冲区
				}
				else {
					while (getchar() != '\n');  // 清空输入缓冲区
					break;
				}
			}
			printf("请输入数据最小值(0到10000):");
			while (1) {
				int result;
				result = scanf("%5d", &min);
				if (result == 0 || min < 0 || min>10000) {
					printf("输入错误，重新输入: ");
					while (getchar() != '\n');  // 清空输入缓冲区
				}
				else {
					while (getchar() != '\n');  // 清空输入缓冲区
					break;
				}
			}
			printf("请输入数据最大值(0到10000):");
			while (1) {
				int result;
				result = scanf("%5d", &max);
				if (result == 0 || max < min || max>10000) {
					printf("输入错误，重新输入: ");
					while (getchar() != '\n');  // 清空输入缓冲区
				}
				else {
					while (getchar() != '\n');  // 清空输入缓冲区
					break;
				}
			}
			int* get = (int*)malloc(sizeof(int) * num);
			int* c = (int*)malloc(sizeof(int) * num);
			int size = 0;
			for (int i = 0; !feof(fp)&&i<num; i++)
			{
				fscanf(fp, "%d", &get[i]);
				if (get[i]<min || get[i]>max)
				{
					i--;
					continue;
				}
				size++;
			}
			if (size == 0)
			{
				printf("无数据\n");
				break;
			}
			get[size - 1] = 0;
			size--;
			switch (choice)
			{
			case 1:
				insertSort(get, size);
				break;
			case 2:
				MergeSort(get, 0, size - 1, c);
				break;
			case 3:
				QuickSort_Recursion(get, 0, size - 1);
				break;
			case 4:
				Partition(get, 0, size - 1);
				break;
			case 5:
				CountSort(get, size);
				break;
			case 6:
				RadixCountSort(get, size);
				break;
			}
			for (int i = 0; i < size; i++)
				printf("%d ", get[i]);
			free(get);
			fclose(fp);
			break;
		case 5:
			return;
		}
		system("pause");
		system("cls");
	}

}