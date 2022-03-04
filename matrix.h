#ifndef _MATRIX_
#define _MATRIX_

#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
using namespace std;

// �������� �������� ������ �� �������������� ��������
double check_double();

// ���� ������� 
void input(double** matrix, int size);

// �������� �������� ������ �� ����������� ��������
int check_matrix_size();

// �������� �������
double** create_matrix(int size);

// ������� ������, ���������� ��������
void free(double** matr, int size);

// ����� ������� �� �����
void output(double** matr, int size);

// �������� ������ �� �������� ������ � �������
double** create_minor(double** matr, int size, int row, int col);

// ���������� ������������ �������
double determinant(double** matr, int size);

// ���������� �������� ������� (����� ������� ����� �������� �� det != 0)
double** revers_matrix(double** matr, int size);

// �������� ���� ������
double** summation_matrixs(double** matr1, double** matr2, int size);

// ����������� � ������� ����� 
double** summation_matrix_num(double** matr, int size, double num);

// ��������� ������� �� �����
double** multiply_matrix_num(double** matr, int size, double num);

// ��������� 2� ������
double** multiply_matrixs(double** matr1, double** matr2, int size);

// ���������� f(x) = x^3-6x^2-5x+10
double** calc_matrix_polinom(double** matrix, int size);

// ���������� �������� ������� ��������� 2X + Y = C1  �  X - 2Y = C2, ��� C1 = A', C2 = B' (A' � B' ����������� �� ������ ���� ������)
void solve_matrix_equat_system(double** C1, double** C2, int size);


#endif //_MATRIX_
