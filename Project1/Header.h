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
	char text[] = "\n\n\t\tДОБРО ПОЖАЛОВАТЬ В ИГРУ ВИСЕЛИЦА !\n\n\t\t   Выберите уровень сложности!\n";
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
	char text[] = "\n\t\t 1 - й уровень слово из 3х букв!\n\t\t 2 - й уровень слово из 5и букв!";
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
			cout << "\n\tОшибка! Такого пункта меню нет, попробуйте еще раз!!!";
			break;
		}
	}
}