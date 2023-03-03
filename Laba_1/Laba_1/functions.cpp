#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "functions.h"

int count_words(char* row) {
	int result = 0;
	for (int i = 0; i < strlen(row); i++) {
		if (row[i] == '.' || row[i] == ' ' || row[i] == '\0' || row[i] == '\n') {
			result++;
		}
	}
	return result;
}

bool has_digits(char* row) {
	for (int i = 0; i < strlen(row); i++) {
		if (isdigit(row[i])) return true;
	}
	return false;
}

char** split_words(char* row) {
	int size = count_words(row),
		index = 0,
		res_index = 0;

	char** result = new char* [size];
	for (int i = 0; i < size; i++) {
		result[i] = new char[256];
	}

	char word[256];
	for (int i = 0; i < strlen(row); i++) {
		if (row[i] != ' ' && row[i] != '.' && row[i] != '\n' && row[i] != 0) {
			word[index++] = row[i];
			word[index] = '\0';
		}
		else {
			if (word[0] != 0) {
				strcpy(result[res_index++], word);
				word[0] = 0;
				index = 0;
			}
		}
	}

	//for (int i = 0; i < size; i++) {
	//	std::cout << result[i] << " => ";
	//}

	return result;
}

bool has_point(char* word) {
	if (word[strlen(word) - 1] == '.' || word[strlen(word) - 2] == '.') return true;
	return false;
}


void find_max_digit_sequence(char* row, int& positions_seq_in_word, int& positions_word_in_row, int& len_of_word, int& len_of_seq) {
	int max_size = 0;
	char* max_start = NULL;
	int pos_index = 0;
	char temp[300];
	strcpy(temp, row);

	char* word = strtok(temp, " \0\n.\r");
	int pos_word_in_row{ 0 };
	while (word != NULL) {
		char* start = word;
		for (int i = 0; i < strlen(word); i++) {
			if (isdigit(word[i])) {
				char* digit_start = word + i;
				int digit_size = 1;
				int j = i;
				while (j < strlen(word) - 1 && word[j] == word[j + 1]) {
					digit_size++;
					j++;
				}
				if (digit_size > max_size) {
					pos_index = i;
					max_size = digit_size;
					max_start = digit_start;
					positions_word_in_row = pos_word_in_row;
					word[strlen(word) - 1] == '\n' ? len_of_word = strlen(word) - 1 : len_of_word = strlen(word);
					if (has_point(word)) len_of_word--;
				}
			}
		}
		pos_word_in_row += strlen(word) + 1;
		word = strtok(NULL, " \0\n.\r");
	}

	if (max_size > 1) {

		std::cout << "\nMax sequence of same numbers: ";
		for (int i = 0; i < max_size; i++) {
			std::cout << *(max_start + i);
		}
		positions_seq_in_word = pos_index;
		len_of_seq = max_size;
		std::cout << "\nPosition of word with sequence in row: " << positions_word_in_row << '\n';
		std::cout << "Position of sequence in word: " << pos_index;
		std::cout << std::endl;
	}
	else {
		std::cout << "No same numbers\n";
	}
}