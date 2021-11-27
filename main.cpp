#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include "crypt.h"

using namespace std;

// ������� ��� �������� ����������� ��������� ���������� ��������� ������
void check_count_arg(int count_arg, const char* argv[], char name_fin[], char name_fout[]) {
	if (count_arg == 1) {
		cout << "������� ���� ��� ������: ";
		cin >> name_fin;
		cout << "������� ���� ��� ������: ";
		cin >> name_fout;
	}
	else if (count_arg == 2) {
		strcpy(name_fin, argv[1]);
		cout << "������� ���� ��� ������: ";
		cin >> name_fout;
	}
	else {
		strcpy(name_fin, argv[1]);
		strcpy(name_fout, argv[2]);
	}
}

int main(int argc, const char* argv[]) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	unsigned char symbol;

	// ����� ������ ��� ������ � ������
	char name_fin[1000], name_fout[1000];
	check_count_arg(argc, argv, name_fin, name_fout);
	FILE* fin = fopen(name_fin, "r");
	FILE* fout = fopen(name_fout, "w");
	file_encryption(fin, fout);
	fclose(fout);

	// ���������, ��������� �� �������� ���� � �������������
	fout = fopen(name_fout, "r");
	bool res = correct_file_encryption(fin, fout);
	if (res)
		cout << "���� ���������� �����";
	else
		cout << "������������� ���� �� ��������� � ��������";
	fclose(fin);
	fclose(fout);
	return 0;
}