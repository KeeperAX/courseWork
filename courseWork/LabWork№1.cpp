#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;
void size();
void binNum();
void binFloat();
void exit();
int main1() {
	setlocale(LC_ALL, "RU");
	bool flag = true;
	do
	{
		flag = true;
		if (flag)
		{
			cout << "{1}Кол-во байт отводимые на тип данных.\n";
			cout << "{2}Двоичное представление в памяти целого числа.\n";
			cout << "{3}Вывести на экран двоичное представление в памяти типа float.\n";
			cout << "{4}Выход из программы\n";
		}
		int choice;
		cin >> choice;
		if (choice > 4)
		{
			system("cls");
			cout << "\tОшибка. Введите число от 1 до 4.\n";
			flag = false;
			continue;
		}
		else if (choice < 1)
		{
			system("cls");
			cout << "\tОшибка. Введите число от 1 до 4.\n";
			flag = false;
			continue;
		}
		else {
			flag = true;
		}
		switch (choice)
		{
		case(1): system("cls"); size(); break;
		case(2): system("cls"); binNum(); break;
		case(3): system("cls"); binFloat(); break;
		case(4): system("cls"); return 0; break;
		}
	} while (true);
	
}
void size() {
	do
	{
		cout << "int: " << sizeof(int) << "\n";
		cout << "short int: " << sizeof(short int) << "\n";
		cout << "long int: " << sizeof(long int) << "\n";
		cout << "float: " << sizeof(float) << "\n";
		cout << "double: " << sizeof(double) << "\n";
		cout << "long double: " << sizeof(long double) << "\n";
		cout << "char: " << sizeof(char) << "\n";
		cout << "bool: " << sizeof(bool) << "\n\n";
		cout << "Выберите следующее действие:\n";
		cout << "1. Вернуться к главному меню\n";
		cout << "2. Выйти из программы\n";
		int choice;
		cin >> choice;
		if (choice == 1) {
			system("cls");
			break;
		}
		else if (choice == 2) {
			return;
		}
		else {
			system("cls");
			cout << "\tОшибка\n";
			continue;
		}
	} while (true);
}
void binNum() {
	do
	{
		cout << "Введите целое число.\n";
		int num, change, mas[sizeof(int) * 8];
		cin >> num;
		unsigned int raz = sizeof(int) * 8; // Количество разрядов
		unsigned int mask = 1 << raz - 1; // Маска побитового сравнения
		for (int i = 1; i <= raz; i++)
		{
			putchar(num & mask ? '1' : '0'); // если 1, то возвращается 1, иначе 0
			mas[i - 1] = (num & mask ? 1 : 0);
			num <<= 1;
			if (i % 8 == 0 || i == 1)
			{
				putchar(' ');// Разделитель
			}
		}
		cout << "\n\n";
		cout << "Выберите следующее действие:\n";
		cout << "1. Вернуться к главному меню\n";
		cout << "2. Изменение битов\n";
		cout << "3. Выйти из программы\n";
		int choice, channum;
		cin >> choice;
		if (choice == 1) {
			system("cls");
			break;
		}
		else if (choice == 2) {
			cout << "Введите порядковый номер бита\n";
			cin >> change;
			if (change > (sizeof(int) * 8))
			{
				system("cls");
				cout << "Вы ввели число за диапазоном\n";
				continue;
			}
			else
			{
				cout << "Введите число, на которое хотите заменить(0,1)\n";
				cin >> channum;
				if (channum > 2)
				{
					system("cls");
					cout << "Вы ввели число за диапазоном\n";
					continue;
				}
				else
				{
					mas[change] = channum;
					for (int i = 0; i < sizeof(int) * 8; i++)
					{
						if (i % 8 == 0 || i == 1)
						{
							putchar(' ');
						}
						cout << mas[i];

					}
				}

			}
			cout << "\n\n";
			cout << "Выберите следующее действие:\n";
			cout << "1. Вернуться к главному меню\n";
			cout << "2. Выйти из программы\n";
			int choice;
			cin >> choice;
			if (choice == 1) {
				system("cls");
				break;
			}
			else if (choice == 2) {
				return;
			}
			else {
				system("cls");
				cout << "\tОшибка\n";
				continue;
			}

		}
		else if (choice == 3) {
			return;
		}
		else {
			system("cls");
			cout << "\tОшибка\n";
			continue;
		}
	} while (true);

}
void binFloat() {
	do
	{
		int mas[sizeof(float) * 8];
		cout << "Введите вещественное число.\n";
		unsigned int raz = sizeof(float) * 8; // Количество разрядов
		unsigned int mask = 1 << raz - 1; // Маска побитового сравнения
		union
		{
			int num;
			float float_num;
		};
		cin >> float_num;
		while (float_num != 0) {

			for (int i = 1; i <= raz; i++)
			{
				putchar(num & mask ? '1' : '0'); // если 1, то возвращается 1, иначе 0
				mas[i - 1] = (num & mask ? 1 : 0);
				num <<= 1;
				if (i == 1 || i == 2 || i == 9)
					putchar(' ');// Разделитель
			}

		}
		cout << "\n\n";
		cout << "Выберите следующее действие:\n";
		cout << "1. Вернуться к главному меню\n";
		cout << "2. Изменение битов\n";
		cout << "3. Выйти из программы\n";
		int choice, channum, change;
		cin >> choice;
		if (choice == 1) {
			system("cls");
			break;
		}
		else if (choice == 2) {
			cout << "Введите порядковый номер бита\n";
			cin >> change;
			if (change > (sizeof(int) * 8))
			{
				system("cls");
				cout << "Вы ввели число за диапазоном\n";
				continue;
			}
			else
			{
				cout << "Введите число, на которое хотите заменить(0,1)\n";
				cin >> channum;
				if (channum > 2)
				{
					system("cls");
					cout << "Вы ввели число за диапазоном\n";
					continue;
				}
				else
				{
					mas[change] = channum;
					for (int i = 0; i < sizeof(int) * 8; i++)
					{
						if (i % 8 == 0 || i == 1)
						{
							putchar(' ');
						}
						cout << mas[i];

					}
				}

			}
			cout << "\n\n";
			cout << "Выберите следующее действие:\n";
			cout << "1. Вернуться к главному меню\n";
			cout << "2. Выйти из программы\n";
			int choice;
			cin >> choice;
			if (choice == 1) {
				system("cls");
				break;
			}
			else if (choice == 2) {
				return;
			}
			else {
				system("cls");
				cout << "\tОшибка\n";
				continue;
			}

		}
		else if (choice == 3) {
			return;
		}
		else {
			system("cls");
			cout << "\tОшибка\n";
			continue;
		}
	} while (true);
}
void exit()
{
	return;
}