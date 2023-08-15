/*
计算游戏 精简版 V0.1.0
作者: 黄明洋
Copyright(c) 2023 Huang Mingyang. All rights reserved.
*/
#include <iostream>
#include <fstream>
#include <cstdio>
#include <windows.h>
#include <strsafe.h>
#include <time.h>

using namespace std;

void begin();
void random(int&, int&, int);
void set_title_data(int, int);
bool Qadd(int, int);//加法
bool Qsub(int, int);//减法
bool Qmul(int, int);//乘法
bool Qdiv(int, int);//除法

int main()
{
	begin();//开始
	SYSTEMTIME sys;
	GetLocalTime(&sys);//获取系统时间
	int a, range = 10, rightsum = 0, wrongsum = 0;
	//range:题目取值范围 rightsum:做对的题数 wrongsum:做错的题数
	bool rnum;
	for (int i = 1;; i++)
	{
		range = int(10 + i * 0.2);
		srand(time(0));
		a = rand() % 4;
		switch (a)
		{
		case 0:
			rnum = Qadd(i, range);
			break;
		case 1:
			rnum = Qsub(i, range);
			break;
		case 2:
			rnum = Qmul(i, range);
			break;
		case 3:
			rnum = Qdiv(i, range);
			break;
		}
		if (rnum) rightsum++;
		else wrongsum++;
		set_title_data(rightsum, wrongsum);//正确题数,错误题数
	}
	return 0;
}

void begin()
{
	set_title_data(0, 0);
	printf("计算游戏 精简版 V0.1.0\n");
	printf("作者: 黄明洋\n");
	printf("Copyright(c) 2023 Huang Mingyang. All rights reserved.\n");
}

void random(int& a, int& b, int c)//数字1,数字2,范围
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);//获取系统时间
	srand(time(0));
	a = rand() % c;
	b = rand() % c;
}

void set_title_data(int rightsum, int wrongsum)//正确题数,错误题数
{
	TCHAR pszDest[30];
	size_t cchDest = 30;
	LPCTSTR pszFormat = TEXT("正确 %d 错误 %d");
	StringCchPrintf(pszDest, cchDest, pszFormat, rightsum, wrongsum);//目标缓冲区,目标缓冲区的大小,字符串格式
	SetConsoleTitle(pszDest);
}

bool Qadd(int Qnum, int range)//题号,范围
{
	int num[2] = {}, answer, solution;
	random(num[0], num[1], range);
	solution = num[0] + num[1];
	printf("\n(%d) %d + %d = ( )\n输入: ", Qnum, num[0], num[1]);
	cin >> answer;
	if (answer == solution)
	{
		printf("判定: 正确\n");
		return true;
	}
	else
	{
		printf("判定: 错误\n正确答案是: %d\n", solution);
		return false;
	}
}

bool Qsub(int Qnum, int range)//题号,范围
{
	int num[2] = {}, answer, solution;
	random(num[0], num[1], range);
	if (num[0] < num[1]) swap(num[0], num[1]);
	solution = num[0] - num[1];
	printf("\n(%d) %d - %d = ( )\n输入: ", Qnum, num[0], num[1]);
	cin >> answer;
	if (answer == solution)
	{
		printf("判定: 正确\n");
		return true;
	}
	else
	{
		printf("判定: 错误\n正确答案是: %d\n", solution);
		return false;
	}
}

bool Qmul(int Qnum, int range)//题号,范围
{
	int num[2] = {}, answer, solution;
	random(num[0], num[1], range);
	solution = num[0] * num[1];
	printf("\n(%d) %d × %d = ( )\n输入: ", Qnum, num[0], num[1]);
	cin >> answer;
	if (answer == solution)
	{
		printf("判定: 正确\n");
		return true;
	}
	else
	{
		printf("判定: 错误\n正确答案是: %d\n", solution);
		return false;
	}
}

bool Qdiv(int Qnum, int range)//题号,范围
{
	int num[2] = {}, answer, answer2, solution, mod;
	random(num[0], num[1], range);
	if (num[0] < num[1]) swap(num[0], num[1]);
	if (num[1] == 0) num[1]++;
	solution = num[0] / num[1];
	mod = num[0] % num[1];
	if (mod == 0)
	{
		printf("\n(%d) %d ÷ %d = ( )\n输入: ", Qnum, num[0], num[1]);
		cin >> answer;
		if (answer == solution)
		{
			printf("判定: 正确\n");
			return true;
		}
		else
		{
			printf("判定: 错误\n正确答案是: %d\n", solution);
			return false;
		}
	}
	else
	{
		printf("\n(%d) %d ÷ %d = ( ) ······ ( )\n", Qnum, num[0], num[1]);
		printf("商: ");
		cin >> answer;
		printf("余数: ");
		cin >> answer2;
		if (answer == solution && answer2 == mod)
		{
			printf("判定: 正确\n");
			return true;
		}
		else
		{
			printf("判定: 错误\n正确答案是: %d %d\n", solution, mod);
			return false;
		}
	}
}