#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>

void Quad(float a, float b, float c)
{
	float Disckiriminant, x1, x2;
	HANDLE OTV = CreateFile(L"OTV.txt", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	DWORD d;
	LPCSTR rez = malloc(100);
	if ((a != 0) && (b != 0) && (c != 0))
	{
		Disckiriminant = b * b - 4 * a * c;
		if (Disckiriminant < 0)
		{
			sprintf(rez, "������������ = %f ������ ���\n ", &Disckiriminant);
			WriteFile(OTV, rez, strlen(rez), &d, NULL);
			CloseHandle(OTV);
		}
		else if (Disckiriminant == 0)
		{
			x1 = -b / (2 * a);
			sprintf(rez, "������������ = %f \n ���-�� ������:1 \n x1: %f", &Disckiriminant, &x1);
			WriteFile(OTV, rez, strlen(rez), &d, NULL);
			CloseHandle(OTV);
		}
		else if (Disckiriminant > 0)
		{
			x1 = (-b + sqrt(Disckiriminant)) / (2 * a);
			x2 = (-b - sqrt(Disckiriminant)) / (2 * a);
			sprintf(rez, "������������ = %f \n ���-�� ������:2 \n x1: %f x2: %f", Disckiriminant, x1, x2);
			WriteFile(OTV, rez, strlen(rez), &d, NULL);
			CloseHandle(OTV);
		}
	}
	else if ((c == 0) && (b == 0))
	{
		x1 = 0;
		sprintf(rez, "������ ����� = %f", &x1);
		WriteFile(OTV, rez, strlen(rez), &d, NULL);
		CloseHandle(OTV);
	}
	else if (b == 0)
	{

		if (-c / a < 0)
		{
			sprintf(rez, "������ ���");
			WriteFile(OTV, rez, strlen(rez), &d, NULL);
			CloseHandle(OTV);
		}
		else
		{
			x1 = sqrt((-c / a));
			sprintf(rez, "������ ������ = %f � -%f", &x1, &x1);
			WriteFile(OTV, rez, strlen(rez), &d, NULL);
			CloseHandle(OTV);
		}
	}
	else if (c == 0)
	{
		x1 = -b / a;
		x2 = 0;
		sprintf(rez, "������ ������ = %f � %f", &x1, &x2);
		WriteFile(OTV, rez, strlen(rez), &d, NULL);
		CloseHandle(OTV);
	}
	else if (a == 0)
	{
		x1 = -c / b;
		sprintf(rez, "������ ����� = %f", &x1);
		WriteFile(OTV, rez, strlen(rez), &d, NULL);
		CloseHandle(OTV);

	}
}

int WINAPI WinMain(HINSTANCE hlnstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	system("chcp 1251>nul");
	DWORD d;

	HANDLE OTV = CreateFile(L"OTV.txt", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL );
	//GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL ������
	//GENERIC_READ | GENERIC_WRITE, FILE_SHARE_WRITE | FILE_SHARE_READ, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, 0 ��������

	HANDLE Koef = CreateFile(L"zadacha.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	/*GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL ������ */
	//GENERIC_READ | GENERIC_WRITE, FILE_SHARE_WRITE | FILE_SHARE_READ, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, 0 ��������

	LPCSTR rez = "";
	if (Koef == INVALID_HANDLE_VALUE)
	{
		rez = " ������ �������� �����";
		WriteFile(OTV, rez, strlen(rez), &d, NULL);
		CloseHandle(OTV);
		return;
	}


	LPCSTR str = calloc(100, 1);


	ReadFile(Koef, str, 100, &d, NULL);
	double number[3];
	int i = 0;
	char* istr;
	istr = strtok(str, " ");
	if (ReadFile(Koef, str, 100, &d, NULL) == NULL)
	{
		rez = "�� ������� ������� ������ � �����";
		WriteFile(OTV, rez, strlen(rez), &d, NULL);
		CloseHandle(OTV);
	}
	else
	{
		while (istr != NULL)
		{

			number[i] = atof(istr);
			istr = strtok(NULL, " ");
			i++;


		}
		if (i == 3)
		{

			if (number[0] == -92559631349317830736831783200707727132248687965119994463780864.000000 ||
				number[1] == -92559631349317830736831783200707727132248687965119994463780864.000000 ||
				number[2] == -92559631349317830736831783200707727132248687965119994463780864.000000)
			{
				rez = "�� ��������� ������� ������";
				WriteFile(OTV, rez, strlen(rez), &d, NULL);
				CloseHandle(OTV);
			}
			if (number[0] == 0 || number[1] == 0 || number[2] == 0)
			{
				rez = "��� ��������� ������ ����� 0";
				WriteFile(OTV, rez, strlen(rez), &d, NULL);
				CloseHandle(OTV);
			}
			Quad(number[0], number[1], number[2]);
		}
		else
		{
			rez = "���������� ��������� ������ �� ����� 3";
				WriteFile(OTV, rez, strlen(rez), &d, NULL);
			CloseHandle(OTV);
		}
	}
}
