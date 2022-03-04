#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
#include "matrix.h"
using namespace std;

int main()
{
	setlocale(0, "RUS");
	int size;
	cout << "Введите размер матриц А и B: ";
	size = check_matrix_size();
	double** matrix_A = create_matrix(size), ** matrix_B = create_matrix(size), ** temp_matrix_A = create_matrix(size), ** temp_matrix_B = create_matrix(size);
	cout << "Введите матрицу A:\n";
	input(matrix_A, size);
	cout << "Введите матрицу B:\n";
	input(matrix_B, size);

	// После этого блока matrix_B = f(B*A) = B'
	temp_matrix_B = multiply_matrixs(matrix_B, matrix_A, size);
	free(matrix_B, size);
	matrix_B = calc_matrix_polinom(temp_matrix_B, size);
	free(temp_matrix_B, size);
	cout << "Матрица B': \n";
	output(matrix_B, size);

	// После этого блока matrix_A = f(A+3*E) = A'
	temp_matrix_A = summation_matrix_num(matrix_A, size, 3);
	free(matrix_A, size);
	matrix_A = calc_matrix_polinom(temp_matrix_A, size);
	free(temp_matrix_A, size);
	cout << "Матрица А': \n";
	output(matrix_A, size);

	//Блок высчитывает обратную матрицу для A', а в случае её отсутствия выводит сообщение об этом
	if (determinant(matrix_A, size) == 0)
		cout << "Обратной матрицы не существует!\n\n";
	else {
		cout << "Матрица, обратная к A':\n";
		output(revers_matrix(matrix_A, size), size);
	}

	// Решает систему уравнений 2X + Y = C1  и  X - 2Y = C2
	solve_matrix_equat_system(matrix_A, matrix_B, size);

	free(matrix_A, size);
	free(matrix_B, size);
	system("pause");
	return 0;
}