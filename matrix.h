#ifndef _MATRIX_
#define _MATRIX_

void readf_matrix(int &size, double matrix[SIZE][SIZE]);

//умножает матрицу на число (не меняет исходную матрицу)
void multiplication_by_number(const int size, const double factor, double matrix[SIZE][SIZE], double result_matrix[SIZE][SIZE]);

void copy_matrix(const int size, double matrix[SIZE][SIZE], double result_matrix[SIZE][SIZE]);

//функция по поиску матрицы произведения двух матриц
void multiplication_of_two_matrix(const int size, double matrix_1[SIZE][SIZE], double matrix_2[SIZE][SIZE], double result_matrix[SIZE][SIZE]);

//вычисление суммы двух матриц
void calc_sum_two_matrix(const int size, double matrix_1[SIZE][SIZE], double matrix_2[SIZE][SIZE], double result_matrix[SIZE][SIZE]);

//составляет минор входной матрицы по i-ому j-ому элементу 
void make_minor(const int size, double matrix[SIZE][SIZE], const int str, const int col, double result_matrix[SIZE][SIZE]);

//вычисляет определитель квадратной матрицы
double calc_determ(const int size, double matrix[SIZE][SIZE]);

//вычисляет обратную матрицу (проверить отличность определителя от 0 при вызове)
bool calc_inverse_matrix(const int size, double matrix[SIZE][SIZE], double result_matrix[SIZE][SIZE]);

//вывод матрицы
void output_matrix(const int n, double matrix[SIZE][SIZE]);

#endif //_MATRIX_