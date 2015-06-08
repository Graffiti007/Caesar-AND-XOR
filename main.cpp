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
	cout << "==���� ��������� �����==" << endl;
	cout << endl;
	cout << "������� 1, ����� ����������� ����� ������ ������" << endl;
	cout << "������� 2, ����� ������������ ����� � �����, �������������� ������ ������" << endl;
	cout << "������� 0, ����� ������� ���������" << endl;
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
		cout << "��������� �������" << endl;
		exit(0);
	}
	else
	{
		cout << "������� ������������ �������!" << endl;
		exit(4);
	}
}


void mode_cesar_shifr()
{
	int offset;
	cout << "�������� ������������� ����� � ������ 0 - �������� ������" << endl;
	cin >> offset;

	if (offset <= 0)
	{
		cout << "������������ �������� ��������! ���������� �������� ������������� ����� ������ 0!" << endl;
		return;
	}

	string name;
	cout << "�������� ������ ���� � ����� � �������� �������" << endl;
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
		cout << "�������� ������ ���� � �����, � ������� ������ ��������� ���������" << endl;
		cin >> name2;
		cout << endl;
		outpute_file(name2, text);
		cout << "������������� ����� ������� �������� � ���� " << name2 << endl;
	}
	else 
	{
		cout << "����� � ������ " << name  <<" �� ����������"<< endl;
	}

}

void mode_cesar_rasshifr()
{
	string name;
	cout << "�������� ������ ���� � ����� � ������������� �������" << endl;
	cin >> name;
	cout << endl;

	string name2;
	cout << "�������� ������ ���� � �����, � ������� ������ ��������� ���������" << endl;
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
		cout << "����������������� �������������� ������ ������� ��������� � ���� " << name2 << endl;
	}
	else
	{
		cout << "����� � ������ " << name << " �� ����������" << endl;
	}

}