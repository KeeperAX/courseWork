#include <iostream>
#include <ctime>
#include <chrono> 
#include <algorithm>
#include <iomanip>

using namespace std;
using namespace chrono;


int menu(int(&arr)[100]);
void sorting(int(&arr)[100]);
void MaxAndMin(int(&arr)[100]);
void average(int(&arr)[100]);
void sortingLess(int(&arr)[100]);
void sortingMore(int(&arr)[100]);
void search(int(&arr)[100]);
void swapElements(int(&arr)[100]);
void idz(int(&arr)[100]);

int main2() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	while (true)
	{
		cout << "\tЦелочисленный массив размерности N = 100. В диапазоне от -99 до 99.\n";
		int arr[100], choose;
		for (int i = 0; i < 100; i++)
		{
			arr[i] = rand() % 199 - 99;
		}
		for (int i = 0; i < 100; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n\n[1] Продолжить.\n";
		cout << "[2] Пересобрать массив.\n";
		cin >> choose;
		if (choose == 1) {
			system("cls");
			menu(arr);
			break;
		}
		else if (choose == 2) {
			system("cls");
			continue;
		}
		else {
			system("cls");
			cout << "\t\t\tОшибка в ввода.\n\t\t Массив будет пересобран.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}


	}
	return 0;
}
int menu(int(&arr)[100]) {
	while (true) {
		cout << "[1]Отсортировать массив от меньшего к большему.\n";
		cout << "[2]Максимальный и минимальный элемент массива.\n";
		cout << "[3]Среднее значение.\n";
		cout << "[4]Вывод количество элементов в отсортированном массиве, которые МЕНЬШЕ числа заданного пользователем.\n";
		cout << "[5]Вывод количество элементов в отсортированном массиве, которые БОЛЬШЕ числа заданного пользователем.\n";
		cout << "[6]Поиск числа в массиве бинарным способом(*).\n";
		cout << "[7]Замена чисел по индексу.\n";
		cout << "[8]ИДЗ№1\n";
		cout << "\n[9]Пересобрать массив.\n";
		cout << "[10]Выйти из программы.";
		int chooseMenu;
		cin >> chooseMenu;
		if (chooseMenu >= 1 && chooseMenu <= 10) {
			switch (chooseMenu) {
			case 1: system("cls"); sorting(arr); break;
			case 2: system("cls"); MaxAndMin(arr); break;
			case 3: system("cls"); average(arr); break;
			case 4: system("cls"); sortingLess(arr); break;
			case 5: system("cls"); sortingMore(arr); break;
			case 6: system("cls"); search(arr); break;
			case 7: system("cls"); swapElements(arr); break;
			case 8: system("cls"); idz(arr); break;
			case 9: system("cls"); main2(); break;
			case 10: return 0;
			}
		}
		else {
			system("cls");
			cout << "\t\t\tОшибка в вводе.\n\t\t Возврат в меню.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
	}
	return 0;
}
void sorting(int(&arr)[100]) {
	int sortArr[100], chooseSortting;
	for (int i = 0; i < 100; i++)
	{
		sortArr[i] = arr[i];
	}
	auto startTime = high_resolution_clock::now();
	for (int i = 0; i < 100 - 1; i++) {
		for (int j = 0; j < 100 - 1 - i; j++) {
			if (sortArr[j] > sortArr[j + 1]) {
				swap(sortArr[j], sortArr[j + 1]);
			}
		}
	}
	auto endTime = high_resolution_clock::now();
	duration<double> dur = endTime - startTime;
	cout << "\tОтсортированный массив.\n";
	for (int i = 0; i < 100; i++)
	{
		cout << sortArr[i] << " ";
	}
	cout << fixed << "\nВремя сортировки: " << setprecision(7) << dur.count() << " секунд.";
	cout << "\n\nВыберите дальненийшие действия\n";
	cout << "[1]Выполнить следующее действие.\n";
	cout << "[2]Вернуться в меню.\n";
	cout << "[3]Завершить программу.\n";
	cin >> chooseSortting;
	if (chooseSortting >= 1 && chooseSortting <= 3) {
		switch (chooseSortting)
		{
		case 1: MaxAndMin(arr); break;
		case 2: system("cls"); menu(arr); break;
		case 3: exit(0);
		}
	}
	else {
		system("cls");
		cout << "\t\t\tОшибка в ввода.\n\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return;
	}


}
void MaxAndMin(int(&arr)[100]) {
	int sortArr[100];
	for (int i = 0; i < 100; i++)
	{
		sortArr[i] = arr[i];
	}
	for (int i = 0; i < 100 - 1; i++) {
		for (int j = 0; j < 100 - 1 - i; j++) {
			if (sortArr[j] > sortArr[j + 1]) {
				swap(sortArr[j], sortArr[j + 1]);
			}
		}
	}
	cout << "\nМаксимальное и минимальное число сортированного массива и не сортированного массива\n";
	int sortArrMax = sortArr[0], arrMax = arr[0];
	int sortArrMin = sortArr[0], arrMin = arr[0];
	auto startTimeS = high_resolution_clock::now();
	for (int i = 0; i < 100; i++)
	{
		sortArrMax = max(sortArrMax, sortArr[i]);
		sortArrMin = min(sortArrMin, sortArr[i]);
	}
	auto endTimeS = high_resolution_clock::now();
	duration<double> durS = endTimeS - startTimeS;
	cout << "Максимальное число - " << sortArrMax << "\n";
	cout << "Минимальное число - " << sortArrMin << "\n";
	cout << fixed << "\nВремя поиск в сортированном массиве: " << setprecision(7) << durS.count() << " секунд.\n";
	auto startTimeNS = high_resolution_clock::now();
	for (int i = 0; i < 100; i++)
	{
		arrMin = min(arrMin, arr[i]);
		arrMax = max(arrMax, arr[i]);
	}
	auto endTimeNS = high_resolution_clock::now();
	duration<double> durNS = endTimeNS - startTimeNS;
	cout << fixed << "Время поиск в несортированном массиве: " << setprecision(7) << durNS.count() << " секунд.";
	cout << "\n\nВыберите дальненийшие действия\n";
	cout << "[1]Выполнить следующее действие.\n";
	cout << "[2]Вернуться в меню.\n";
	cout << "[3]Завершить программу.\n";
	int chooseMaxMin;
	cin >> chooseMaxMin;
	if (chooseMaxMin >= 1 && chooseMaxMin <= 3) {
		switch (chooseMaxMin)
		{
		case 1: average(arr); break;
		case 2: system("cls"); menu(arr); break;
		case 3: exit(0);
		}
	}
	else {
		system("cls");
		cout << "\t\t\tОшибка в ввода.\n\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return;
	}
}
void average(int(&arr)[100]) {
	int sortArr[100], arrMin = arr[0], arrMax = arr[0], sred, count = 0;
	for (int i = 0; i < 100; i++)
	{
		sortArr[i] = arr[i];
	}
	for (int i = 0; i < 100 - 1; i++) {
		for (int j = 0; j < 100 - 1 - i; j++) {
			if (sortArr[j] > sortArr[j + 1]) {
				swap(sortArr[j], sortArr[j + 1]);
			}
		}
	}
	for (int i = 0; i < 100; i++)
	{
		arrMin = min(arrMin, arr[i]);
		arrMax = max(arrMax, arr[i]);
	}
	sred = (arrMin + arrMax) / 2;
	cout << "Индекс элементов равное среднему значанию в несортированном массиве: ";
	auto startTimeNS = high_resolution_clock::now();
	for (int i = 0; i < 100; i++)
	{
		if (arr[i] == sred) {
			count += 1;
			cout << i << " ";
		}
	}
	auto endTimeNS = high_resolution_clock::now();
	duration<double> durNS = endTimeNS - startTimeNS;
	cout << "\nИндекс элементов равное среднему значанию в сортированном массиве: ";
	auto startTimeS = high_resolution_clock::now();
	for (int i = 0; i < 100; i++)
	{
		if (sortArr[i] == sred) {
			cout << i << " ";
		}
	}
	auto endTimeS = high_resolution_clock::now();
	duration<double> durS = endTimeS - startTimeS;
	cout << "\nКол-во элементов: " << count;
	cout << fixed << "\nВремя поиск в несортированном массиве: " << setprecision(7) << durNS.count() << " секунд.\n";
	cout << fixed << "Время поиск в сортированном массиве: " << setprecision(7) << durS.count() << " секунд.\n";
	cout << "\n\nВыберите дальненийшие действия\n";
	cout << "[1]Выполнить следующее действие.\n";
	cout << "[2]Вернуться в меню.\n";
	cout << "[3]Завершить программу.\n";
	int chooseAverage;
	cin >> chooseAverage;
	if (chooseAverage >= 1 && chooseAverage <= 3) {
		switch (chooseAverage)
		{
		case 1: sortingLess(arr); break;
		case 2: system("cls"); menu(arr); break;
		case 3: exit(0);
		}
	}
	else {
		system("cls");
		cout << "\t\t\tОшибка в ввода.\n\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return;
	}
	
}
void sortingLess(int(&arr)[100]) {
	int sortArr[100], count = 0, num;
	for (int i = 0; i < 100; i++)
	{
		sortArr[i] = arr[i];
	}
	for (int i = 0; i < 100 - 1; i++) {
		for (int j = 0; j < 100 - 1 - i; j++) {
			if (sortArr[j] > sortArr[j + 1]) {
				swap(sortArr[j], sortArr[j + 1]);
			}
		}
	}
	cout << "Введите число: ";
	cin >> num;
	for (int i = 0; i < 100; i++)
	{
		if (sortArr[i] <= num) {
			count++;
		}
	}
	cout << "\nКол-во элементов меньши " << num << ": " << count;
	cout << "\n\nВыберите дальненийшие действия\n";
	cout << "[1]Выполнить следующее действие.\n";
	cout << "[2]Вернуться в меню.\n";
	cout << "[3]Завершить программу.\n";
	int chooseSortingLess;
	cin >> chooseSortingLess;
	if (chooseSortingLess >= 1 && chooseSortingLess <= 3) {
		switch (chooseSortingLess)
		{
		case 1: sortingMore(arr); break;
		case 2: system("cls"); menu(arr); break;
		case 3: exit(0);
		}
	}
	else {
		system("cls");
		cout << "\t\t\tОшибка в ввода.\n\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return;
	}
}
void sortingMore(int(&arr)[100]) {
	int sortArr[100], count = 0, num;
	for (int i = 0; i < 100; i++)
	{
		sortArr[i] = arr[i];
	}
	for (int i = 0; i < 100 - 1; i++) {
		for (int j = 0; j < 100 - 1 - i; j++) {
			if (sortArr[j] > sortArr[j + 1]) {
				swap(sortArr[j], sortArr[j + 1]);
			}
		}
	}
	cout << "Введите число: ";
	cin >> num;
	for (int i = 0; i < 100; i++)
	{
		if (sortArr[i] >= num) {
			count++;
		}
	}
	cout << "\nКол-во элементов больше " << num << ": " << count;
	cout << "\n\nВыберите дальненийшие действия\n";
	cout << "[1]Выполнить следующее действие.\n";
	cout << "[2]Вернуться в меню.\n";
	cout << "[3]Завершить программу.\n";
	int chooseSearch;
	cin >> chooseSearch;
	if (chooseSearch >= 1 && chooseSearch <= 3) {
		switch (chooseSearch)
		{
		case 1: search(arr); break;
		case 2: system("cls"); menu(arr); break;
		case 3: exit(0);
		}
	}
	else {
		system("cls");
		cout << "\t\t\tОшибка в ввода.\n\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return;
	}
}
void search(int(&arr)[100]) {
	int sortArr[100], num;
	for (int i = 0; i < 100; i++)
	{
		sortArr[i] = arr[i];
	}
	for (int i = 0; i < 100 - 1; i++) {
		for (int j = 0; j < 100 - 1 - i; j++) {
			if (sortArr[j] > sortArr[j + 1]) {
				swap(sortArr[j], sortArr[j + 1]);
			}
		}
	}
	cout << "Введите число которое хотите найти: ";
	cin >> num;
	auto startTime = high_resolution_clock::now();
	if (num <= 99 && num >= -99)
	{
		int left = 0, right = 99, result = -1;
		while (left <= right) {
			int mid = left + (right - left) / 2;

			if (sortArr[mid] == num) {
				result = mid; 
				break;
			}

			if (sortArr[mid] < num) {
				left = mid + 1; 
			}
			else {
				right = mid - 1; 
			}
		}
		auto endTime = high_resolution_clock::now();
		duration<double> dur = endTime - startTime;
		auto startTimef = high_resolution_clock::now();
		for (int i = 0; i < 100; i++)
		{
			if (sortArr[i] == num) {
				//cout << "\nЭлемент найден на индексе " << i << "\n";
				break;
			}
		}
		auto endTimef = high_resolution_clock::now();
		duration<double> durf = endTimef - startTimef;
		cout << fixed << "\nВремя поиска методом перебора: " << setprecision(7) << durf.count() << " секунд.";
		if (num != -1) {
			cout << "\nЭлемент найден на индексе " << result << "\n";
			cout << fixed << "\nВремя поиска бинарный способом: " << setprecision(7) << dur.count() << " секунд.";
		}
		else {
			cout << "\nЭлемент не найден" << "\n";
		}
		cout << "\n\nВыберите дальненийшие действия\n";
		cout << "[1]Выполнить следующее действие.\n";
		cout << "[2]Вернуться в меню.\n";
		cout << "[3]Завершить программу.\n";
		int chooseSearch;
		cin >> chooseSearch;
		if (chooseSearch >= 1 && chooseSearch <= 3) {
			switch (chooseSearch)
			{
			case 1:	swapElements(arr); break;
			case 2: system("cls"); menu(arr); break;
			case 3: exit(0);
			}
		}
		else {
			system("cls");
			cout << "\t\t\tОшибка в ввода.\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return;
		}

	}
	else {
		system("cls");
		cout << "\t\t\tОшибка в ввода.\n\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return;
	}
}
void swapElements(int(&arr)[100]) {
	int choose, oneSwap, twoSwap, chooseSwap;
	cout << "\tС каким массивам производить замену?\n";
	cout << "[1]Несортированный\n";
	cout << "[2]Cортированный\n";
	cin >> choose;
	system("cls");
	if (choose == 1) {
		do
		{
			for (int i = 0; i < 100; i++)
			{
				cout << arr[i] << " ";
			}
			cout << "\nВведите два числа, индексы которых хотите заменить(без запятой с пробелом): ";
			cin >> oneSwap >> twoSwap;
			cout << "\n\n";
			auto startTime = high_resolution_clock::now();
			swap(arr[oneSwap], arr[twoSwap]);
			auto endTime = high_resolution_clock::now();
			duration<double> dur = endTime - startTime;
			for (int i = 0; i < 100; i++)
			{
				cout << arr[i] << " ";
			}
			cout << fixed << "\nВремя сортировки: " << setprecision(10) << dur.count() << " секунд.";
			cout << "\n\nВыберите дальненийшие действия\n";
			cout << "[1]Продолжить замену чисел.\n";
			cout << "[2]Следующеее действие\n";
			cout << "[3]Вернуться в меню.\n";
			cout << "[4]Завершить программу.\n";
			cin >> chooseSwap;
			if (chooseSwap >= 1 && chooseSwap <= 4) {
				switch (chooseSwap)
				{
				case 1: system("cls"); break;
				case 2: system("cls"); menu(arr); break;;
				case 3: exit(0);
				}
			}
			else {
				system("cls");
				cout << "\t\t\tОшибка в ввода.\n\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				return;
			}
		} while (true);

	}
	if (choose == 2)
	{
		do
		{
			int sortArr[100], count = 0, num;
			for (int i = 0; i < 100; i++)
			{
				sortArr[i] = arr[i];
			}
			for (int i = 0; i < 100 - 1; i++) {
				for (int j = 0; j < 100 - 1 - i; j++) {
					if (sortArr[j] > sortArr[j + 1]) {
						swap(sortArr[j], sortArr[j + 1]);
					}
				}
			}
			for (int i = 0; i < 100; i++)
			{
				cout << sortArr[i] << " ";
			}
			cout << "\nВведите два числа, индексы которых хотите заменить(без запятой с пробелом): ";
			cin >> oneSwap >> twoSwap;
			cout << "\n\n";
			auto startTime = high_resolution_clock::now();
			swap(sortArr[oneSwap], sortArr[twoSwap]);
			auto endTime = high_resolution_clock::now();
			duration<double> dur = endTime - startTime;
			for (int i = 0; i < 100; i++)
			{
				cout << sortArr[i] << " ";
			}
			cout << fixed << "\nВремя сортировки: " << setprecision(10) << dur.count() << " секунд.";
			cout << "\n\nВыберите дальненийшие действия\n";
			cout << "[1]Продолжить замену чисел.\n";
			cout << "[2]Вернуться в меню.\n";
			cout << "[3]Завершить программу.\n";
			cin >> chooseSwap;
			if (chooseSwap >= 1 && chooseSwap <= 4) {
				switch (chooseSwap)
				{
				case 1: system("cls"); break;
				case 2: system("cls"); idz(arr); break;
				case 3: system("cls"); menu(arr); break;;
				case 4: exit(0);
				}
			}
			else {
				system("cls");
				cout << "\t\t\tОшибка в ввода.\n\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				return;
			}
		} while (true);
	}
	else {
		system("cls");
		cout << "\t\t\tОшибка ввода.\n\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return;
	}
}
void idz(int(&arr)[100]) {
	int sortArr[100], chooseSwap, num;
	for (int i = 0; i < 100; i++)
	{
		sortArr[i] = arr[i];
	}
	for (int i = 0; i < 100 - 1; i++) {
		for (int j = 0; j < 100 - 1 - i; j++) {
			if (sortArr[j] > sortArr[j + 1]) {
				swap(sortArr[j], sortArr[j + 1]);
			}
		}
	}

	cout << "\t Отсортированный массив\n";
	for (int i = 0; i < 100; i++)
	{
		cout << sortArr[i]<<" ";
	}
	cout << endl;

	num = sortArr[0] + sortArr[99];
	for (int i = 0; i < 99; i++)
	{
		sortArr[i] = sortArr[i] + sortArr[i + 1];
	}
	sortArr[99] = num;
	cout << "\n\t Массив\n";
	for (int i = 0; i < 100; i++)
	{
		cout << sortArr[i] << " ";
	}
	cout << "\n\tПеремешанный массив\n";
	int CounterOne=0, CounterTwo=0, CounterThree=0, CounterFour=0, CounterFive=0, CounterSix=0, CounterSeven=0, CounterEight=0, CounterNine=0;
	for (int i = 0; i < 100-1; i++)
	{
		cout << sortArr[rand() % 100] << " ";
		if (sortArr[i] % 1==0)
		{
			CounterOne+=1;
		}
		if (sortArr[i] % 2 == 0)
		{
			CounterTwo+=1;
		}
		if (sortArr[i] % 3 == 0)
		{
			CounterThree+=1;
		}
		if (sortArr[i] % 4 == 0)
		{
			CounterFour+=1;
		}
		if (sortArr[i] % 5 == 0)
		{
			CounterFive+=1;
		}
		if (sortArr[i] % 6 == 0)
		{
			CounterSix+=1;
		}
		if (sortArr[i] % 7 == 0)
		{
			CounterSeven+=1;
		}
		if (sortArr[i] % 8 == 0)
		{
			CounterEight +=1;
		}
		if (sortArr[i] % 9 == 0)
		{
			CounterNine+=1;
		}
	}
	cout << "\nЧисло элементов, что делятся на 1: " << CounterOne << endl;
	cout << "Число элементов, что делятся на 2: " << CounterTwo << endl;
	cout << "Число элементов, что делятся на 3: " << CounterThree << endl;
	cout << "Число элементов, что делятся на 4: " << CounterFour << endl;
	cout << "Число элементов, что делятся на 5: " << CounterFive << endl;
	cout << "Число элементов, что делятся на 6: " << CounterSix << endl;
	cout << "Число элементов, что делятся на 7: " << CounterSeven << endl;
	cout << "Число элементов, что делятся на 8: " << CounterEight << endl;
	cout << "Число элементов, что делятся на 9: " << CounterNine << endl;

	cout << "\n\nВыберите дальненийшие действия\n";
	cout << "[1]Вернуться в меню.\n";
	cout << "[2]Завершить программу.\n";
	cin >> chooseSwap;
	if (chooseSwap >= 1 && chooseSwap <= 2) {
		switch (chooseSwap)
		{
		case 1: system("cls"); break;
		case 2: exit(0);
		}
	}
	else {
		system("cls");
		cout << "\t\t\tОшибка в ввода.\n\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return;
	}
}
