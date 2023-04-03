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
	char menu2[5][50] =
	{ "------------------------------",
	"[1]大数据",
	"[2]小数据",
	"[3]exit",
	"------------------------------"
	};
	while (1)
	{
		for (int i = 0; i < 5;i++)
			printf("%s\n", menu2[i]);
		printf("请选择功能:"); 
		int c = 0;
		while (1) {
			int result;
			result = scanf("%3d", &c);
			if (result == 0 || c < 1 || c>3) {
				printf("输入错误，重新输入: ");
				while (getchar() != '\n');  // 清空输入缓冲区
			}
			else {
				while (getchar() != '\n');  // 清空输入缓冲区
				break;
			}
		}
		FILE* fp1=NULL, *fp2=NULL, *fp3=NULL;
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
			fp1 = fopen("test1.txt", "w");
			fp2 = fopen("test2.txt", "w");
			fp3 = fopen("test3.txt", "w");
			if (fp1 == NULL || fp2 == NULL || fp3 == NULL)
			{
				printf("无法打开文件");
				break;
			}
			for (int i = 0; i < 10000; i++)
			{
				a1[i] = rand();
				fprintf(fp1, "%d ", a1[i]);
			}
			for (int i = 0; i < 50000; i++)
			{
				a2[i] = rand();
				fprintf(fp2, "%d ", a2[i]);
			}
			for (int i = 0; i < 200000; i++)
			{
				a3[i] = rand();
				fprintf(fp3, "%d ", a3[i]);
			}
			fclose(fp1);
			fclose(fp2);
			fclose(fp3);
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
			fp1 = fopen("test11.txt", "w");
			fp2 = fopen("test22.txt", "w");
			fp3 = fopen("test33.txt", "w");
			if (fp1 == NULL || fp2 == NULL || fp3 == NULL)
			{
				printf("无法打开文件");
				break;
			}
			for (int i = 0; i < 10000; i++)
			{
				fprintf(fp1, "%d ", a1[i]);
			}
			for (int i = 0; i < 50000; i++)
			{
				fprintf(fp2, "%d ", a2[i]);
			}
			for (int i = 0; i < 200000; i++)
			{
				fprintf(fp3, "%d ", a3[i]);
			}
			fclose(fp1);
			fclose(fp2);
			fclose(fp3);
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
			FILE* fp4=NULL,*fp5=NULL;
			fp4 = fopen("test4.txt", "w");
			if (fp4 == NULL )
			{
				printf("无法打开文件");
				break;
			}
			for (int i = 0; i < 100000; i++)
			{
				for (int j = 0; j < 100; j++)
					fprintf(fp4, "%d ", rand());
			}
			fclose(fp4);
			fp4 = fopen("test4.txt", "r");
			fp5 = fopen("test44.txt", "w");
			if (fp4 == NULL||fp5==NULL)
			{
				printf("无法打开文件");
				break;
			}
			switch (choice)
			{
			case 1:
				;
				clock_t start1 = clock();
				for (int i = 0; i < 100000; i++)
				{
					for (int j = 0; j < 100; j++)
						fscanf(fp4, "%d", &a[j]);
					insertSort(a, 100);
					for (int j = 0; j < 100; j++)
					{
						fprintf(fp5, "%d ", a[j]);
					}
					fprintf(fp5, "\n");
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
						fscanf(fp4, "%d", &a[j]);
					MergeSort(a, 0, 99, b);
					for (int j = 0; j < 100; j++)
					{
						fprintf(fp5, "%d ", a[j]);
					}
					fprintf(fp5, "\n");
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
						fscanf(fp4, "%d", &a[j]);
					QuickSort_Recursion(a, 0, 99);
					for (int j = 0; j < 100; j++)
					{
						fprintf(fp5, "%d ", a[j]);
					}
					fprintf(fp5, "\n");
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
						fscanf(fp4, "%d", &a[j]);
					Partition(a, 0, 99);
					for (int j = 0; j < 100; j++)
					{
						fprintf(fp5, "%d ", a[j]);
					}
					fprintf(fp5, "\n");
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
						fscanf(fp4, "%d", &a[j]);
					CountSort(a, 100);
					for (int j = 0; j < 100; j++)
					{
						fprintf(fp5, "%d ", a[j]);
					}
					fprintf(fp5, "\n");
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
						fscanf(fp4, "%d", &a[j]);
					RadixCountSort(a, 100);
					for (int j = 0; j < 100; j++)
					{
						fprintf(fp5, "%d ", a[j]);
					}
					fprintf(fp5, "\n");
				}
				clock_t diff6 = clock() - start6;
				printf("%d ms\n", diff6);
				break;
			}
			fclose(fp4);
			fclose(fp5);
			break;
		case 3:
			return;
		}
		system("pause");
		system("cls");
	}

}