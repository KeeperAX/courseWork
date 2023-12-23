#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <ctime>
using namespace std;
int creatMatrix();
void fillMatrix(int* matrix, int N);
void swapElements(int* matrix, int N);
void consoleOutmatrix(int* matrix, int N) { // Выводит матрицы
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << *(matrix + i * N + j) << "\t";
        }
        cout << endl;
    }
}
void actionMatrix(int* matrix, int N) {
    cout << "Введи символ.\n";
    char operation;
    cin >> operation;
    cout << "Введите число.\n";
    int number;
    cin >> number;
    system("cls");
    cout << "\tИзначальная матрица.\n";
    consoleOutmatrix(matrix, N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int* element = matrix + i * N + j;
            switch (operation) {
            case '+':
                *element += number;
                break;
            case '-':
                *element -= number;
                break;
            case '*':
                *element *= number;
                break;
            case '/':
                *element /= number;
                break;
            default:
                system("cls");
                cout << "Неверный синтаксис\n";
                actionMatrix(matrix, N);
            }
        }
    }
    cout << "\n\tИзмененная матрица.\n";
    consoleOutmatrix(matrix, N);
    cout << "\n[1] Пересобрать матрицу.\n[2] Заполнить матрицу заново.\n[3] Переставить блоки.\n[4] Сортировать матрицу.\n[5] Выполнить действия с матрицей.\n";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1: system("cls"); creatMatrix(); break;
    case 2: system("cls"); fillMatrix(matrix, N); break;
    case 3: system("cls"); swapElements(matrix, N); break;
    case 4: system("cls"); actionMatrix(matrix, N); break;
    default:system("cls"); cout << "\tНеверный синтаксис.\n"; actionMatrix(matrix, N); break;
    }
}
void quicksort(int* matrix, int low, int high, int N) {
    if (low < high) {
        int pivot = matrix[low];
        int left = low + 1, right = high;
        while (left <= right) {
            while (left <= high && matrix[left] < pivot) {
                left++;
            }
            while (right > low && matrix[right] > pivot) {
                right--;
            }
            if (left <= right) {
                swap(matrix[left], matrix[right]);
                left++;
                right--;
            }
        }
        swap(matrix[low], matrix[right]);
        quicksort(matrix, low, right - 1, N);
        quicksort(matrix, right + 1, high, N);
    }
}
void sortMatrix(int* matrix, int N) {
    system("cls");
    cout << "\tИсходная матрица.\n";
    consoleOutmatrix(matrix, N);
    int size = N * N;
    quicksort(matrix, 0, size - 1, N);
    cout << "\t\nОтсортированная матрица.\n";
    consoleOutmatrix(matrix, N);
    cout << "\n[1] Манипуляция матрицой.\n\n[2] Пересобрать матрицу.\n[3] Заполнить матрицу.\n[4] Переставить блоки.\n";
    int choice;
    cin >> choice;
    if (choice == 1) {
        system("cls");
        actionMatrix(matrix, N);
    }
    else if (choice == 2) {
        system("cls");
        creatMatrix();
    }
    else if (choice == 3) {
        system("cls");
        fillMatrix(matrix, N);
    }
    else if (choice == 4) {
        system("cls");
        swapElements(matrix, N);
    }
    else {
        system("cls");
        cout << "\tНеверный синтаксис.\n";
        sortMatrix(matrix, N);
    }
}
void swapElements(int* matrix, int N) {
    cout << "\nКак переставить блоки?\n[1] По кругу.\n[2] Крестом.\n[3] Вертикально.\n[4] Горизонтально.\n\n[5] Пересобрать матрицу.\n[6] Заполнить матрицу заново.\n";
    int choice;
    cin >> choice;
    system("cls");
    cout << "\tИзначальная матрица.\n";
    consoleOutmatrix(matrix, N);
    if (choice == 1) {
        for (int i = 0; i < N / 2; i++) {
            for (int j = 0; j < N / 2; j++) {
                //int key1 = *(matrix + i + j * N);
                int key2 = *(matrix + j + N / 2 + i * N);
                int key3 = *(matrix + j + N * (N / 2) + i * N);
                int key4 = *(matrix + j + N * N / 2 + (N / 2) + i * N);
                *(matrix + j + N / 2 + i * N) = *(matrix + i + j * N);
                *(matrix + j + N * N / 2 + (N / 2) + i * N) = key2;
                *(matrix + j + N * N / 2 + i * N) = key4;
                *(matrix + i + j * N) = key3;
            }
        }
    }
    else if (choice == 2) {
        for (int i = 0; i < N / 2; i++) {
            for (int j = 0; j < N / 2; j++) {
                swap(*(matrix + i + j * N), *(matrix + j + N / 2 + N * (N / 2) + i * N));
                swap(*(matrix + N / 2 + i + j * N), *(matrix + N * (N / 2) + i + j * N));
            }
        }
    }
    else if (choice == 3) {
        for (int i = 0; i < N / 2; i++) {
            for (int j = 0; j < N / 2; j++) {
                swap(*(matrix + i + j * N), *(matrix + N * N / 2 + i + j * N));
                swap(*(matrix + i + j * N + N / 2), *(matrix + N * N / 2 + i + j * N + N / 2));
            }
        }
    }
    else if (choice == 4) {
        for (int i = 0; i < N / 2; i++) {
            for (int j = 0; j < N / 2; j++) {
                swap(*(matrix + i + j * N), *(matrix + N / 2 + i + j * N));
                swap(*(matrix + i + j * N + N * N / 2), *(matrix + N / 2 + i + j * N + N * N / 2));
            }
        }
    }
    else if (choice == 5) {
        system("cls");
        creatMatrix();
    }
    else if (choice == 6) {
        system("cls");
        fillMatrix(matrix, N);
    }
    else {
        system("cls");
        cout << "\tНеверный синтаксис.\n";
        swapElements(matrix, N);
    }
    cout << "\n\tИзмененная матрица.\n";
    consoleOutmatrix(matrix, N);
    system("pause");
    sortMatrix(matrix, N);
}
void fillMatrix(int* matrix, int N) {
    cout << "Как хотите заполнить матрицу?\n[1] Спиралью.\n[2] Змейкой.\n\n[3] Пересобрать матрицу.\n";
    for (int i = 0; i < N; ++i) { // Заполнение матрицы нулями
        for (int j = 0; j < N; ++j) {
            *(matrix + i * N + j) = 0;
        }
    }
    int choice;
    cin >> choice;
    if (choice == 1) {
        int value = 1;
        int row = 0, col = 0;
        int rowStart = 0, rowEnd = N - 1;
        int colStart = 0, colEnd = N - 1;
        while (rowStart <= rowEnd && colStart <= colEnd) {
            // Заполнение верхней строки
            for (int i = colStart; i <= colEnd; i++) {
                *(matrix + rowStart * N + i) = rand() % (N * N) + 1;
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                consoleOutmatrix(matrix, N);
            }
            rowStart++;
            row++;
            // Заполнение правого столбца
            for (int i = rowStart; i <= rowEnd; ++i) {
                *(matrix + i * N + colEnd) = rand() % (N * N) + 1;
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                consoleOutmatrix(matrix, N);
            }
            colEnd--;
            // Заполнение нижней строки
            if (rowStart <= rowEnd) {
                for (int i = colEnd; i >= colStart; i--) {
                    *(matrix + rowEnd * N + i) = rand() % (N * N) + 1;
                    this_thread::sleep_for(chrono::milliseconds(400));
                    system("cls");
                    consoleOutmatrix(matrix, N);
                }
                rowEnd--;
                row--;
            }
            // Заполнение левого столбца
            if (colStart <= colEnd) {
                for (int i = rowEnd; i >= rowStart; i--) {
                    *(matrix + i * N + colStart) = rand() % (N * N) + 1;
                    this_thread::sleep_for(chrono::milliseconds(400));
                    system("cls");
                    consoleOutmatrix(matrix, N);
                }
                colStart++;
                col++;
            }
        }
    }
    else if (choice == 2) {
        int step = 0;
        while (step != N)
        {
            for (int i = 0; i < N; i++) {
                *(matrix + i * N + step) = rand() % (N * N) + 1;
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                consoleOutmatrix(matrix, N);
            }
            step++;
            for (int i = 0; i < N; i++) {
                *(matrix + (N - 1) * N + step - i * N) = rand() % (N * N) + 1;
                this_thread::sleep_for(chrono::milliseconds(400));
                system("cls");
                consoleOutmatrix(matrix, N);
            }
            step++;
        }
    }
    else if (choice == 3) {
        system("cls");
        creatMatrix();
    }
    else {
        system("cls");
        cout << "\tНеверный синтаксис\n";
        fillMatrix(matrix, N);
    }
    swapElements(matrix, N);
    sortMatrix(matrix, N);
}
int creatMatrix() {
    cout << "Выберите размер матрицы.\n[1] 6 на 6.\n[2] 8 на 8.\n[3] 10 на 10.\n\n[4] Выход из программы\n";
    int choice;
    cin >> choice;
    int N;
    switch (choice)
    {
    case 1: N = 6; break;
    case 2: N = 8; break;
    case 3: N = 10; break;
    case 4: return 0;
    default:system("cls"); cout << "\tНеверный синтаксис\n"; creatMatrix(); break;
    }
    int* matrix = new int[N * N]; //Выделение памяти 
    fillMatrix(matrix, N);
    delete[] matrix;
}
int main3() {
    setlocale(LC_ALL, "RU");
    srand(time(0));
    creatMatrix();
    return 0;
}
