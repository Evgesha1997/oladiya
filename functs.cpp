#include <iostream>
#include <stdio.h>
#include "crypt.h"

using namespace std;

// Кодирование букв
char encrypt_symbol(char symbol) {
	if (towlower(symbol) == 'ё' or (int(symbol) > -1 and (int(symbol) < -64)))
		return symbol;
	int new_symbol = int(symbol) + 5;
	if ((new_symbol <= -1 && symbol >= -32) || (new_symbol <= -33 && symbol < -32))
		return char(int(symbol) + 5);
	else
		return char(int(symbol) - 27);

}

// Функция шифрует переданный файл fin и записывает результат в файл fout
void file_encryption(FILE* fin, FILE* fout) {
	char cur_char, encrypt_char;
	while (true) {
		cur_char = getc(fin);
		if (feof(fin))
			return;
		encrypt_char = encrypt_symbol(cur_char);
		putc(encrypt_char, fout);
	}
	return;
}

// Дешифруем букву
char decrypt_symbol(char symbol) {
	if (not isalpha(symbol) or (towlower(symbol) == 'ё'))
		return symbol;
	int new_symbol = int(symbol) - 5;
	if ((new_symbol >= -32 && symbol >= -32) || (new_symbol >= -64 && symbol < -32))
		return char(int(symbol) - 5);
	else
		return char(int(symbol) + 27);
}

// Функция дешифрует зашифрованный файл и проверяет, совпадает ли с исходным
bool correct_file_encryption(FILE* fin, FILE* fout) {
	char ch_text, ch_crtext, res;
	while (true) {
		ch_text = getc(fin);
		if (feof(fin))
			return true;
		ch_crtext = getc(fout);
		res = decrypt_symbol(ch_crtext);
		if (ch_text != res)
			return false;
	}
}