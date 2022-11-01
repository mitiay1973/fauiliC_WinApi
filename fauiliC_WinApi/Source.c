#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <malloc.h>
#include <stdio.h>


int WINAPI WinMain(HINSTANCE hlnstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	system("chcp 1251>nul");
	DWORD d;
	LPCSTR str = calloc(100, 1);
	LPCSTR istr = calloc(100, 1);
	LPCSTR rez = "";

	HANDLE Otv = CreateFile(L"OTV.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	//GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL запись
	//GENERIC_READ | GENERIC_WRITE, FILE_SHARE_WRITE | FILE_SHARE_READ, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, 0 создание
	HANDLE Koef = CreateFile(L"zadacha.txt", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	/*GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL запись */
	//GENERIC_READ | GENERIC_WRITE, FILE_SHARE_WRITE | FILE_SHARE_READ, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, 0 создание
	if (Koef == INVALID_HANDLE_VALUE)
	{
		rez = " Ошибка открытия файла";
		WriteFile(Otv, rez, strlen(rez), &d, NULL);
		CloseHandle(Otv);

	}
	ReadFile(Koef, str, 100, &d, NULL);
	float a1 = 0, b1 = 0, c1 = 0;
	int cha = 0;
	double apr = 0;
	int ymna = 1;
	char* line;
	for (int i = 0; i < 255; i++)
	{
		line = str + i;
		if (*line != 32)
		{
			cha++;
		}
		else
		{
			break;
		}
	}
	for (int i = cha - 1; i >= 0; i--)
	{
		line = str + i;
		if (*line == 46)
		{
			int chha = 1;
			for (int j = 1; j < cha - i; j++)
			{
				chha = chha * 10;
			}
			a1 = a1 / chha;
			ymna = 1;
		}
		else
		{
			if (*str == 45)
			{
				if (*line != 45)
				{
					apr = *line - '0';
					a1 += apr * ymna;
					ymna = ymna * 10;
				}
				else
				{
					a1 = a1 * -1;
				}
			}
			else
			{
				apr = *line - '0';
				a1 += apr * ymna;
				ymna = ymna * 10;
			}
		}
	}

	int chb = cha;
	double bpr = 0;
	int ymnb = 1;
	for (int i = cha + 1; i < 255; i++)
	{
		line = str + i;
		if (*line != 32)
		{
			chb++;
		}
		else
		{
			break;
		}
	}
	for (int i = chb; i >= cha + 1; i--)
	{
		line = str + i;
		if (*line == 46)
		{
			int chhb = 1;
			for (int j = 1; j < chb + 1 - i; j++)
			{
				chhb = chhb * 10;
			}
			b1 = b1 / chhb;
			ymnb = 1;
		}
		else
		{
			if (*line == 45)
			{
				if (*line != 45)
				{
					bpr = *line - '0';
					b1 += bpr * ymnb;
					ymnb = ymnb * 10;
				}
				else
				{
					b1 = b1 * -1;
				}
			}
			else
			{
				bpr = *line - '0';
				b1 += bpr * ymnb;
				ymnb = ymnb * 10;
			}
		}
	}
	int chc = chb;
	double cpr = 0;
	int ymnc = 1;
	for (int i = chb + 1; i < 255; i++)
	{
		line = str + i;
		if (*line != 32)
		{
			chc++;
		}
		else
		{
			break;
		}
	}
	for (int i = chc; i >= chb + 1; i--)
	{
		line = str + i;
		if (*line == 46)
		{
			int chhc = 1;
			for (int j = 1; j < chc + 1 - i; j++)
			{
				chhc = chhc * 10;
			}
			c1 = c1 / chhc;
			ymnc = 1;
		}
		else
		{
			if (*line == 45)
			{
				if (*line != 45)
				{
					cpr = *line - '0';
					c1 += cpr * ymnc;
					ymnc = ymnc * 10;
				}
				else
				{
					c1 = c1 * -1;
				}
			}
			else
			{
				cpr = *line - '0';
				c1 += cpr * ymnc;
				ymnc = ymnc * 10;
			}
		}
	}
}
	//double number[3];
	//int i = 0;
	////istr = strtok(str[2], "");

	//while (istr != NULL)
	//{

	//	number[i] = atof(istr);
	//	istr = strtok(NULL, " ");
	//	i++;


	//}
	//if (i == 3)
	//{

	//	if (number[0] == -92559631349317830736831783200707727132248687965119994463780864.000000 ||
	//		number[1] == -92559631349317830736831783200707727132248687965119994463780864.000000 ||
	//		number[2] == -92559631349317830736831783200707727132248687965119994463780864.000000)
	//	{
	//		rez = "Не корректно введены данные";
	//		WriteFile(Koef, rez, strlen(rez), &d, NULL);
	//		CloseHandle(Koef);
	//	}
	//	if (number[0] == 0 || number[1] == 0 || number[2] == 0)
	//	{
	//		rez = "Все введенные данные равны 0";
	//		WriteFile(Koef, rez, strlen(rez), &d, NULL);
	//		CloseHandle(Koef);
	//	}
	//	//Quad(number[0], number[1], number[2]);
	//}
	//else
	//{
	//	rez = "Количество введенных данных не равно 3";
	//	WriteFile(Koef, rez, strlen(rez), &d, NULL);
	//	CloseHandle(Koef);
	//}
