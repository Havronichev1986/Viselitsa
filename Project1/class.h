#pragma once
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <vector>
#include <ctime>
using namespace std;
class File
{
public:
	void file1()
	{
		ofstream file("EasyLevel");
		if (file.is_open())
		{
			file << "пух" << endl;
			file << "лед" << endl;
			file << "мох" << endl;
			file.close();
		}
		else
		{
			cout << "Не удалось открыть файл для сохранения данных.\n";
		}
	}
	void file2()
	{
		ofstream file("NormalLevel");
		if (file.is_open())
		{
			file << "ветер" << endl;
			file << "метод" << endl;
			file << "чижик" << endl;
			file.close();
		}
		else
		{
			cout << "Не удалось открыть файл для сохранения данных.\n";
		}
	}
};
class Game : public File
{
private:
	string word;
	string w;
	vector<string>words;
	int letterFill;
	char letter; // буква
	int attempts = 0; // попытки
	int MAX_TRIES = 9; // макс попыток
	string hidden; // скрытое слово
	//char mas[];
public:
	string randomWord1()
	{
		ifstream newFile("EasyLevel");
		if (!newFile.is_open())
		{
			cout << "\n\tНеудалось открыть файл для чтения!!! ";
		}
		else
		{
			while (getline(newFile, word)) {
				words.push_back(word);
			}
			newFile.close();
		}
		srand(time(NULL));
		int randomIndex = rand() % words.size();
		w = words[randomIndex];
		return words[randomIndex];
	}
	string randomWord2()
	{
		ifstream newFile("NormalLevel");
		if (!newFile.is_open())
		{
			cout << "\n\tНеудалось открыть файл для чтения!!! ";
		}
		else
		{
			while (getline(newFile, word)) {
				words.push_back(word);
			}
			newFile.close();
		}
		srand(time(NULL));
		int randomIndex = rand() % words.size();
		w = words[randomIndex];
		return words[randomIndex];
	}
	void kartunku(int attempts)
	{
		vector <string> vec = {
			"\n\t  ----------- \n"
			"\t           |  \n"
			"\t           |  \n"
			"\t           |  \n"
			"\t           |  \n"
			"\t           |  \n"
			"\t           |  \n"
			"\t  =========== \n"
			"\t**************\n",
			"\t  ----------- \n"
			"\t      |    |  \n"
			"\t           |  \n"
			"\t           |  \n"
			"\t           |  \n"
			"\t           |  \n"
			"\t           |  \n"
			"\t  =========== \n"
			"\t**************\n",
			"\t  ----------- \n"
			"\t      |    |  \n"
			"\t      O    |  \n"
			"\t           |  \n"
			"\t           |  \n"
			"\t           |  \n"
			"\t           |  \n"
			"\t  =========== \n"
			"\t**************\n",
			"\t  ----------- \n"
			"\t      |    |  \n"
			"\t      O    |  \n"
			"\t      |    |  \n"
			"\t           |  \n"
			"\t           |  \n"
			"\t           |  \n"
			"\t  =========== \n"
			"\t**************\n",
			"\t  ----------- \n"
			"\t      |    |  \n"
			"\t      O    |  \n"
			"\t      |\\   |  \n"
			"\t           |  \n"
			"\t           |  \n"
			"\t           |  \n"
			"\t  =========== \n"
			"\t**************\n",
			"\t  ----------- \n"
			"\t      |    |  \n"
			"\t      O    |  \n"
			"\t     /|\\   |  \n"
			"\t           |  \n"
			"\t           |  \n"
			"\t           |  \n"
			"\t  =========== \n"
			"\t**************\n",
			"\t  ----------- \n"
			"\t      |    |  \n"
			"\t      O    |  \n"
			"\t     /|\\   |  \n"
			"\t      |    |  \n"
			"\t           |  \n"
			"\t           |  \n"
			"\t  =========== \n"
			"\t**************\n",
			"\t  ----------- \n"
			"\t      |    |  \n"
			"\t      O    |  \n"
			"\t     /|\\   |  \n"
			"\t      |    |  \n"
			"\t     /     |  \n"
			"\t           |  \n"
			"\t  =========== \n"
			"\t**************\n",
			"\t  ----------- \n"
			"\t      |    |  \n"
			"\t      O    |  \n"
			"\t     /|\\   |  \n"
			"\t      |    |  \n"
			"\t     / \\   |  \n"
			"\t           |  \n"
			"\t  =========== \n"
			"\t**************\n"
		};
		cout << vec[attempts] << endl;
	}
	void pobeda()
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN);
			char text[] = "\n\t****    *    ****   ****   ***      *    \n"
				            "\t*  *  *   *  *      *      * *     * *   \n"
				            "\t*  *  *   *  ****   ***  *******  *****  \n"
				            "\t*  *  *   *  *  *   *    *     * *     * \n"
				            "\t*  *    *    ****   **** *     **       *\n";
			for (int i = 0; text[i]; i++)
			{
				cout << text[i];
				
				Sleep(25);
			}
		}
	void GameOver()
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		char text[] = "\n\n\t     ****      *      *       *   *****             *   *      *  *****  *****\n"
			"\t   *          * *     *  * *  *   *                * *   *    *   *      *    *\n"
			"\t  *  ***     *   *    *   *   *   ***             *   *   *  *    ***    *****\n"
			"\t  *     *   *******   *       *   *                * *     **     *      *  *\n"
			"\t    ****   *       *  *       *   *****             *       *     *****  *   **\n";
		for (int i = 0; text[i]; i++)
		{
			cout << text[i];
			Sleep(10);
		}
	}
	void play()
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		unsigned int start_time = clock();
		hidden = string(w.length(), '*');
		while (attempts < MAX_TRIES)
		{
			letterFill = 0;
			cout << "\n\t" << hidden << endl;
			cout << "" << endl;
			cout << "\n\tВведите букву: ";
			cin >> letter;
			system("cls");
			for (int i = 0; i < w.length(); i++)
			{
				if (letter == hidden[i])
				{
					cout << "\n\tВы уже вводили эту букву\n";
					kartunku(attempts);
					letterFill++;
					break;
				}
				if (letter == w[i])
				{
					hidden[i] = letter;
					letterFill++;
				}
			}
			for (int i = 0; i < w.length(); i++)
			{
				if (letterFill == 0)
				{
					cout << "\n\tПопробуйте еще раз\n";
					kartunku(attempts);
					attempts++;
					break;
				}
				else
				{
					cout << "\n\tПродолжаем!!!\n";
					break;
				}
			}
			if (w == hidden)
			{
				system("cls");
				cout << w << endl;
				pobeda();
				break;
			}
			cout << "\n\tОсталось попыток: " << MAX_TRIES - attempts << endl;
		}
		if (attempts == MAX_TRIES)
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			system("cls");
			GameOver();
			SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE);
			cout << "\n\tЗагаданное слово было: " << "\t" << w << endl;
		}
		unsigned int end_time = clock();
		unsigned int search_time = end_time - start_time;
		unsigned int sec = search_time / 1000;
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout << "\n\tВремя в игре: " << sec << " сек " << endl;
	}
};