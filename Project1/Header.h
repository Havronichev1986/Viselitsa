#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "class.h"
using namespace std;
void description()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
	char text[] = "\n\n\t\t����� ���������� � ���� �������� !\n\n\t\t   �������� ������� ���������!\n";
	for (int i = 0; text[i]; i++)
	{
		cout << text[i];
		Sleep(10);
	}
}
void menu()
{
	Game game;
	bool exit = true;
	char text[] = "\n\t\t 1 - � ������� ����� �� 3� ����!\n\t\t 2 - � ������� ����� �� 5� ����!";
	for (int i = 0; text[i]; i++)
	{
		cout << text[i];
		Sleep(40);
	}
	while (exit)
	{
		switch (_getch())
		{
		case '1':
			system("cls");
			game.file1();
			game.randomWord1();
			game.play();
			system("pause");
			system("cls");
			break;
		case '2':
			system("cls");
			game.file2();
			game.randomWord2();
			game.play();
			system("pause");
			system("cls");
			break;
		case '0':
			exit = false;
			break;

		default:
			cout << "\n\t������! ������ ������ ���� ���, ���������� ��� ���!!!";
			break;
		}
	}
}