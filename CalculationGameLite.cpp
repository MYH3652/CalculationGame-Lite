/*
������Ϸ ����� V0.1.0
����: ������
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
bool Qadd(int, int);//�ӷ�
bool Qsub(int, int);//����
bool Qmul(int, int);//�˷�
bool Qdiv(int, int);//����

int main()
{
	begin();//��ʼ
	SYSTEMTIME sys;
	GetLocalTime(&sys);//��ȡϵͳʱ��
	int a, range = 10, rightsum = 0, wrongsum = 0;
	//range:��Ŀȡֵ��Χ rightsum:���Ե����� wrongsum:���������
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
		set_title_data(rightsum, wrongsum);//��ȷ����,��������
	}
	return 0;
}

void begin()
{
	set_title_data(0, 0);
	printf("������Ϸ ����� V0.1.0\n");
	printf("����: ������\n");
	printf("Copyright(c) 2023 Huang Mingyang. All rights reserved.\n");
}

void random(int& a, int& b, int c)//����1,����2,��Χ
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);//��ȡϵͳʱ��
	srand(time(0));
	a = rand() % c;
	b = rand() % c;
}

void set_title_data(int rightsum, int wrongsum)//��ȷ����,��������
{
	TCHAR pszDest[30];
	size_t cchDest = 30;
	LPCTSTR pszFormat = TEXT("��ȷ %d ���� %d");
	StringCchPrintf(pszDest, cchDest, pszFormat, rightsum, wrongsum);//Ŀ�껺����,Ŀ�껺�����Ĵ�С,�ַ�����ʽ
	SetConsoleTitle(pszDest);
}

bool Qadd(int Qnum, int range)//���,��Χ
{
	int num[2] = {}, answer, solution;
	random(num[0], num[1], range);
	solution = num[0] + num[1];
	printf("\n(%d) %d + %d = ( )\n����: ", Qnum, num[0], num[1]);
	cin >> answer;
	if (answer == solution)
	{
		printf("�ж�: ��ȷ\n");
		return true;
	}
	else
	{
		printf("�ж�: ����\n��ȷ����: %d\n", solution);
		return false;
	}
}

bool Qsub(int Qnum, int range)//���,��Χ
{
	int num[2] = {}, answer, solution;
	random(num[0], num[1], range);
	if (num[0] < num[1]) swap(num[0], num[1]);
	solution = num[0] - num[1];
	printf("\n(%d) %d - %d = ( )\n����: ", Qnum, num[0], num[1]);
	cin >> answer;
	if (answer == solution)
	{
		printf("�ж�: ��ȷ\n");
		return true;
	}
	else
	{
		printf("�ж�: ����\n��ȷ����: %d\n", solution);
		return false;
	}
}

bool Qmul(int Qnum, int range)//���,��Χ
{
	int num[2] = {}, answer, solution;
	random(num[0], num[1], range);
	solution = num[0] * num[1];
	printf("\n(%d) %d �� %d = ( )\n����: ", Qnum, num[0], num[1]);
	cin >> answer;
	if (answer == solution)
	{
		printf("�ж�: ��ȷ\n");
		return true;
	}
	else
	{
		printf("�ж�: ����\n��ȷ����: %d\n", solution);
		return false;
	}
}

bool Qdiv(int Qnum, int range)//���,��Χ
{
	int num[2] = {}, answer, answer2, solution, mod;
	random(num[0], num[1], range);
	if (num[0] < num[1]) swap(num[0], num[1]);
	if (num[1] == 0) num[1]++;
	solution = num[0] / num[1];
	mod = num[0] % num[1];
	if (mod == 0)
	{
		printf("\n(%d) %d �� %d = ( )\n����: ", Qnum, num[0], num[1]);
		cin >> answer;
		if (answer == solution)
		{
			printf("�ж�: ��ȷ\n");
			return true;
		}
		else
		{
			printf("�ж�: ����\n��ȷ����: %d\n", solution);
			return false;
		}
	}
	else
	{
		printf("\n(%d) %d �� %d = ( ) ������������ ( )\n", Qnum, num[0], num[1]);
		printf("��: ");
		cin >> answer;
		printf("����: ");
		cin >> answer2;
		if (answer == solution && answer2 == mod)
		{
			printf("�ж�: ��ȷ\n");
			return true;
		}
		else
		{
			printf("�ж�: ����\n��ȷ����: %d %d\n", solution, mod);
			return false;
		}
	}
}