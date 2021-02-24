#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;
void Create(int** a, const int rowCount, const int colCount,
	const int Low, const int High, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
int SumRows(int** a, const int rowCount, const int colCount, int rowNo, int& S);
void SumRow(int** a, const int rowNo, const int colCount, int colNo, int& S);
int NumIndex(int** a, const int rowCount, const int colCount, int rowNo, int& k);
void Index(int** a, const int rowNo, const int colCount, int colNo, int& k);
void ToZero(int** a, const int rowCount, const int colCount, int rowNo);
void FindToZero(int** a, const int rowNo, const int colCount, int colNo);

int main()
{
	srand((unsigned)time(NULL));

	int Low = -6;
	int High = 31;

	int rowCount = 7;
	int colCount = 5;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Create(a, rowCount, colCount, Low, High, 0, 0);
	Print(a, rowCount, colCount, 0, 0);
	int S = 0;
	int k = 0;
	NumIndex(a, rowCount, colCount, 0, k);
	SumRows(a, rowCount, colCount, 0, S);
	ToZero(a, rowCount, colCount, 0);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Print(a, rowCount, colCount, 0, 0);
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}

void Create(int** a, const int rowCount, const int colCount,
	const int Low, const int High, int i, int j)
{
	a[i][j] = Low + rand() % (High - Low + 1);
	if (j < colCount - 1)
		Create(a, rowCount, colCount, Low, High, i, j + 1);
	else
		if (i < rowCount - 1)
			Create(a, rowCount, colCount, Low, High, i + 1, 0);
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
		Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;
}

void SumRow(int** a, const int rowNo, const int colCount, int colNo, int& S)
{
	if ((rowNo % 3 != 0 || colNo % 3 != 0) && a[rowNo][colNo] > 0) {
		S += a[rowNo][colNo];
	}
	if (colNo < colCount - 1) {
		SumRow(a, rowNo, colCount, colNo + 1, S);
	}
}

int SumRows(int** a, const int rowCount, const int colCount, int rowNo, int& S)
{
	SumRow(a, rowNo, colCount, 0, S);
	if (rowNo < rowCount - 1) {
		SumRows(a, rowCount, colCount, rowNo + 1, S);
	}
	return S;
}

void Index(int** a, const int rowNo, const int colCount, int colNo, int& k)
{
	if ((rowNo % 3 != 0 || colNo % 3 != 0) && a[rowNo][colNo] > 0) {
		k++;
	}
	if (colNo < colCount - 1) {
		Index(a, rowNo, colCount, colNo + 1, k);
	}
}

int NumIndex(int** a, const int rowCount, const int colCount, int rowNo, int& k)
{
	Index(a, rowNo, colCount, 0, k);
	if (rowNo < rowCount - 1) {
		NumIndex(a, rowCount, colCount, rowNo + 1, k);
	}
	return k;
}

void FindToZero(int** a, const int rowNo, const int colCount, int colNo)
{
	if ((rowNo % 3 != 0 || colNo % 3 != 0) && a[rowNo][colNo] > 0) 
	{
		a[rowNo][colNo] = 0;
	}
	if (colNo < colCount - 1) {
		FindToZero(a, rowNo, colCount, colNo + 1);
	}
}

void ToZero(int** a, const int rowCount, const int colCount, int rowNo)
{
	FindToZero(a, rowNo, colCount, 0);
	if (rowNo < rowCount - 1) {
		ToZero(a, rowCount, colCount, rowNo + 1);
	}
}



