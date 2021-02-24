#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;
void CreateMtrx(int** a, const int rowCount, const int colCount, const int Low, const int High);
void PrintMtrx(int** a, const int rowCount, const int colCount);
int Sum(int** a, const int rowCount, const int colCount, int S);
int IndexNum(int** a, const int rowCount, const int colCount, int k);
void ToZero(int** a, const int rowCount, const int colCount);

int main()
{
    srand((unsigned)time(NULL));


    int Low = -6; // Нижня границя чисел матриці
    int High = 31; // Верхня границя чисел матриці

    int rowCount = 7; // Рядки матриці
    int colCount = 5; // Стовпці матриці

    int** a = new int* [rowCount];

    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    CreateMtrx(a, rowCount, colCount, Low, High);
    PrintMtrx(a, rowCount, colCount);

    int S = 0; // Сума елементів, які підходять під критерій;
    int k = 0; // Скільки елементів підходять під критерій

    S = Sum(a, rowCount, colCount, S);
    k = IndexNum(a, rowCount, colCount, S);

    cout << "S = " << S << endl;
    cout << "k = " << k << endl;

    ToZero(a, rowCount, colCount); // Заміняє елементи, які підходять під критерій на 0
    PrintMtrx(a, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void CreateMtrx(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void PrintMtrx(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}
int Sum(int** a, const int rowCount, const int colCount, int S)
{
    S = 0;
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            if ((i % 3 != 0 || j % 3 != 0) && a[i][j] > 0)
            {
                S += a[i][j];
            }
    return S;
}

int IndexNum(int** a, const int rowCount, const int colCount, int k)
{
    k = 0;
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            if ((i % 3 != 0 || j % 3 != 0) && a[i][j] > 0)
            {
                k++;
            }

    return k;
}

void ToZero(int** a, const int rowCount, const int colCount)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            if ((i % 3 != 0 || j % 3 != 0) && a[i][j] > 0)
            {
                a[i][j] = 0;
            }

}