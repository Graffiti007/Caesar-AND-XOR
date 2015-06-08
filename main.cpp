#include <iostream> 
#include <string> 
#include <clocale>
#include <fstream>
#include <vector>

using namespace std;

#include "cesar.h"
#include "Sfiles.h"

void menu_prog();
void mode_cesar_shifr();
void mode_cesar_rasshifr();

int main()
{
	setlocale(LC_ALL, "Russian");
	menu_prog();
	return 0;
}

void menu_prog()
{
	cout << "==Меню программы Стаса==" << endl;
	cout << endl;
	cout << "Введите 1, чтобы зашифровать текст шифром Цезаря" << endl;
	cout << "Введите 2, чтобы расшифровать текст в файле, зашифрованного шифром Цезаря" << endl;
	cout << "Введите 0, чтобы закрыть программу" << endl;
	cout << endl;
	int good = 0;
	string key1;
	string s;
	string name;
	cin >> key1;
	if (key1 == "1")
	{
		mode_cesar_shifr();
	}
	else if (key1 == "2")
	{
		mode_cesar_rasshifr();
	}
	else if (key1 == "0")
	{
		cout << "Программа закрыта" << endl;
		exit(0);
	}
	else
	{
		cout << "Введена некорректная команда!" << endl;
		exit(4);
	}
}


void mode_cesar_shifr()
{
	int offset;
	cout << "Напишите положительное число и больше 0 - смещение текста" << endl;
	cin >> offset;

	if (offset <= 0)
	{
		cout << "Некорректное значение смещения! Необходимо написать положительное число больше 0!" << endl;
		return;
	}

	string name;
	cout << "Напишите полный путь к файлу с исходным текстом" << endl;
	cin >> name;
	cout << endl;
	
	if (file_read(name))
	{
		vector <string> text;
		text = inpute_file(name);

		for (int i = 0; i < text.size(); i++)
		{
			text[i] = Caesar (text[i], offset);
		}

		string name2;
		cout << "Напишите полный путь к файлу, в который хотите сохранить результат" << endl;
		cin >> name2;
		cout << endl;
		outpute_file(name2, text);
		cout << "Зашифрованный текст успешно сохранен в файл " << name2 << endl;
	}
	else 
	{
		cout << "Файла с именем " << name  <<" не существует"<< endl;
	}

}

void mode_cesar_rasshifr()
{
	string name;
	cout << "Напишите полный путь к файлу с зашифрованным текстом" << endl;
	cin >> name;
	cout << endl;

	string name2;
	cout << "Напишите полный путь к файлу, в который хотите сохранить результат" << endl;
	cin >> name2;
	cout << endl;
	if (file_read(name))
	{
		vector <string> text;
		text = inpute_file(name);
		vector <string> text_sdvig;
		text_sdvig = text;
		string inf;
		for (int j = 1; j < 26; j++)
		{
			for (int i = 0; i < text.size(); i++)
			{
				text_sdvig[i] = Caesar(text[i], j);
			}
			outpute_file(name2, text_sdvig, 2);
		}
		cout << "Предположительные расшифрованные тексты успешно сохранены в файл " << name2 << endl;
	}
	else
	{
		cout << "Файла с именем " << name << " не существует" << endl;
	}

}