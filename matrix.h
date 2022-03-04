#ifndef _MATRIX_
#define _MATRIX_

#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
using namespace std;

// Проверка введённых данных на действительное значение
double check_double();

// Ввод матрицы 
void input(double** matrix, int size);

// Проверка введённых данных на натуральное значение
int check_matrix_size();

// Создание матрицы
double** create_matrix(int size);

// Очитска памяти, занимаемой матрицей
void free(double** matr, int size);

// Вывод матрицы на экран
void output(double** matr, int size);

// Создание минора по заданным строке и столбцу
double** create_minor(double** matr, int size, int row, int col);

// Нахождение определителя матрицы
double determinant(double** matr, int size);

// Нахождение обратной матрицы (перед вызовом нужна проверка на det != 0)
double** revers_matrix(double** matr, int size);

// Сложение двух матриц
double** summation_matrixs(double** matr1, double** matr2, int size);

// Прибавление к матрице числа 
double** summation_matrix_num(double** matr, int size, double num);

// Умножение матрицы на число
double** multiply_matrix_num(double** matr, int size, double num);

// Умножение 2х матриц
double** multiply_matrixs(double** matr1, double** matr2, int size);

// Вычисление f(x) = x^3-6x^2-5x+10
double** calc_matrix_polinom(double** matrix, int size);

// Вычисление значения системы уравнений 2X + Y = C1  и  X - 2Y = C2, где C1 = A', C2 = B' (A' и B' вычисляются до вызова этой фукции)
void solve_matrix_equat_system(double** C1, double** C2, int size);


#endif //_MATRIX_
