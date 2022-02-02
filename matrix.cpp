#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;
#define SIZE 100

void readf_matrix(int &size, double matrix[SIZE][SIZE]){
    int i, j;
    string fname;
    
    cin >> fname;
    ifstream fin(fname.c_str());
    
    fin >> size;
    if (size != 0)
        for (i = 0; i < size; i++)
            for (j = 0; j < size; j++)
                fin >> matrix[i][j];
    else{
        cout << "����� ����� ��� ������ ���� �� ������ ������� 0�0" << endl;
        exit;
    }
}

//�������� ������� �� ����� (�� ������ �������� �������)
void multiplication_by_number(const int size, const double factor, double matrix[SIZE][SIZE], double result_matrix[SIZE][SIZE]){
    int i, j;
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            result_matrix[i][j] = matrix[i][j] * factor;
}

void copy_matrix(const int size, double matrix[SIZE][SIZE], double result_matrix[SIZE][SIZE]){
    int i, j;
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            result_matrix[i][j] = matrix[i][j];
}

//������������� ������� �� ������ ������� ������������ ���� ������
void multiplication_of_two_matrix(const int size, double matrix_1[SIZE][SIZE], double matrix_2[SIZE][SIZE], double result_matrix[SIZE][SIZE]){
    int i, j, k;
    double element;
    for (i = 0; i < size; i++){
        for (j  = 0; j < size; j++){
            element = 0;
            for (k = 0; k < size; k++)
                element += matrix_1[i][k] * matrix_2[k][j];
            result_matrix[i][j] = element;
        }
    }
}

//���������� ����� ���� ������
void calc_sum_two_matrix(const int size, double matrix_1[SIZE][SIZE], double matrix_2[SIZE][SIZE], double result_matrix[SIZE][SIZE]){
    int i, j;
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            result_matrix[i][j] = matrix_1[i][j] + matrix_2[i][j];
}

//���������� ����� ������� ������� �� i-��� j-��� �������� 
void make_minor(const int size, double matrix[SIZE][SIZE], const int str, const int col, double result_matrix[SIZE][SIZE]){
    int i, j;
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++){
            if (i < str){
                if (j < col)
                    result_matrix[i][j] = matrix[i][j];
                if (j > col)
                    result_matrix[i][j-1] = matrix[i][j];
            }
            if (i > str){
                if (j < col)
                    result_matrix[i-1][j] = matrix[i][j];
                if (j > col)
                    result_matrix[i-1][j-1] = matrix[i][j];
            }
        }
}

//��������� ������������ ���������� �������
double calc_determ(const int size, double matrix[SIZE][SIZE]){
    double det = 0;
    int degree = 1;
    //������� ������ �� ��������
    if(size == 1) 
        return matrix[0][0];
    //������� ������ �� ��������
    else if(size == 2) 
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    else{
        double temp_matrix[SIZE][SIZE];
        for (int j=  0; j < size; j++){
            make_minor(size, matrix, 0, j, temp_matrix);
            det = det + (degree * matrix[0][j] * calc_determ(size-1, temp_matrix));
            degree = -degree;
        }
    }
    return det;
}

//��������� �������� ������� (��������� ���������� ������������ �� 0 ��� ������)
bool calc_inverse_matrix(const int size, double matrix[SIZE][SIZE], double result_matrix[SIZE][SIZE]){
    int i, j;
    if (size == 1)
        if (matrix[0][0] != 0){
            result_matrix[0][0] = 1.0 / matrix[0][0];
            return true;
        }
        else{
            cout << "�� ���������� �������� �������" << endl;
            return false;
        }
    
    double determ = 0, temp_matrix[SIZE][SIZE];
    determ = calc_determ(size, matrix);
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++){
            make_minor(size, matrix, j, i, temp_matrix);
            result_matrix[i][j] = pow(-1, i+j) * calc_determ(size-1, temp_matrix) / determ;
        }
    return true;
}

//����� �������
void output_matrix(const int n, double matrix[SIZE][SIZE]){
    int i, j;
    string fname;
    cout << "������� �������� ����� ��� ������ ����������: " << endl;
    cin >> fname;
    ofstream fout(fname.c_str());
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++)
            fout << matrix[i][j] << " ";
        fout << endl;
    }
}