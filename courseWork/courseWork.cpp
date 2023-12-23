#include <iostream>
#include "LabWork№1.cpp"
#include "LabWork№2.cpp"
#include "LabWork№3.cpp"
#include "LabWork№4.cpp"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	while (true)
	{
		system("cls");
		cout << "Какую работу хотите открыть?\n[1] 1 Лабораторная.\n[2] 2 Лабораторная.\n[3] 3 Лаборатоная работа.\n[4] 4 Лабораторная работа.\n";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1: system("cls"); main1(); break;
		case 2: system("cls"); main2(); break;
		case 3: system("cls"); main3(); break;
		case 4: system("cls"); main4(); break;
		}
	}
    
}