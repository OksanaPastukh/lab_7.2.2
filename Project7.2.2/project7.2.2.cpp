// Lab_7_2_2.cpp
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;


/// <summary>
/// Створення масиву
/// </summary>
/// <param name="rowCount">Кількість рядків</param>
/// <param name="colCount">Кількість стовбців</param>
/// <param name="Low">Мінімальне значення елемента</param>
/// <param name="High">Максимальне значення елемента</param>
/// <returns></returns>
void CreateRow(int** a, const int colCount, const int row, const int Low, const int High, int col)
{
	a[row][col] = Low + rand() % (High - Low + 1);
	if (col < colCount - 1)
		CreateRow(a, colCount, row, Low, High, col + 1);
}
void CreateRows(int** a, const int rowCount, const int colCount, const int Low, const int High, int row)
{
	CreateRow(a, colCount, row, Low, High, 0);
	if (row < rowCount - 1)
		CreateRows(a, rowCount, colCount, Low, High, row + 1);
}

/// <summary>
/// Вивід масива
/// </summary>
/// <param name="a">масив</param>
/// <param name="rowCount">Кількість рядків</param>
/// <param name="colCount">Кількість стовбців</param>
void PrintRow(int** a, const int row, const int colCount, int col)
{
	cout << setw(4) << a[row][col];
	if (col < colCount - 1)
		PrintRow(a, row, colCount, col + 1);
	else
		cout << endl;
}
void PrintRows(int** a, const int rowCount, const int colCount, int row)
{

	PrintRow(a, row, colCount, 0);
	if (row < rowCount - 1)
		PrintRows(a, rowCount, colCount, row + 1);
	else
		cout << endl;
}

/// <summary>
/// Пошук індекса мінімального значення в рядку масива
/// </summary>
/// <param name="a">масив</param>
/// <param name="row">рядок де шукаємо</param>
/// <param name="colCount">Кількість стовбців</param>
/// <returns>індекс мінімального значення</returns>
void find_min_index(int** a, const int row, const int col, const int colCount, int* min_value, int* min_index)
{

	if (col < colCount - 1)
	{

		find_min_index(a, row, col + 1, colCount, min_value, min_index);
		if (a[row][col] < *min_value)
		{
			*min_value = a[row][col];
			*min_index = col;
		}
	}
	else
	{
		*min_value = a[row][col];
		*min_index = col;
	}
}
/// <summary>
/// Пошук індекса максимального  значення в рядку масива
/// </summary>
/// <param name="a">масив</param>
/// <param name="row">рядок де шукаємо</param>
/// <param name="colCount">Кількість стовбців</param>
/// <returns>індекс максимального значення</returns>
void find_max_index(int** a, const int row, const int col, const int colCount, int* max_value, int* max_index)
{

	if (col < colCount - 1)
	{

		find_max_index(a, row, col + 1, colCount, max_value, max_index);
		if (a[row][col] > * max_value)
		{
			*max_value = a[row][col];
			*max_index = col;
		}
	}
	else
	{
		*max_value = a[row][col];
		*max_index = col;
	}
}
/// <summary>
/// Обмін мінімального і максимального значення в рядку 
/// </summary>
/// <param name="a">масив</param>
/// <param name="row">рядок де міняємо</param>
/// <param name="min_index">індекс мінімального значення</param>
/// <param name="max_index">індекс максимального значення</param>
void swap(int** a, const int row, const int min_index, const int max_index)
{
	int tmp = a[row][min_index];
	a[row][min_index] = a[row][max_index];
	a[row][max_index] = tmp;

}
void change_value_in_row(int** a,int row, int rowCount,int colCount)
{
	int min_index;
	int max_index;
	int min_value;
	int max_value;
	find_min_index(a, row, 0, colCount, &min_value, &min_index);
	find_max_index(a, row, 0, colCount, &max_value, &max_index);
	swap(a, row, min_index, max_index);
	if (row < rowCount - 1)
	{
		change_value_in_row(a,row + 1, rowCount,colCount);
	}
}

int main()
{
	// Створення масива
	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 65;
	int rowCount;
	int colCount;
	cout << "k = "; cin >> rowCount;
	cout << "n = "; cin >> colCount;
	int** a = new int* [rowCount];
	for (int row = 0; row < rowCount; row++)
		a[row] = new int[colCount];
	CreateRows(a, rowCount, colCount, Low, High, 0);
	// Вивід масива
	PrintRows(a, rowCount, colCount, 0);
	// Для кожного рядку масиву
	change_value_in_row(a,0, rowCount,colCount);
	// Вивід результату
	cout << "New matrix" << endl;
	PrintRows(a, rowCount, colCount, 0);
	// Видалення масиву
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}