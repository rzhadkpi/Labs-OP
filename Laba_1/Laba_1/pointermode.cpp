#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "pointermode.h"
#include "functions.h"

char* get_name_of_file() {
	std::cout << "Enter the name of the file: ";
	char* filename = new char[100];
	std::cin.getline(filename, 100);
	return filename;
}

void fill_file(FILE* file, const char* filename) {
	file = fopen(filename, "a");
	if (file == NULL) {
		std::cout << "Error. Can not create file\n";
		return;
	}
	char* text = new char[301];
	std::cout << "Enter text to the file (enter \"stop\" to stop):\n";
	while (true) {
		std::cin.getline(text, 300);
		if (strcmp(text, "stop") == 0) {
			break;
		}
		fprintf(file, "%s\n", text);
	}
	delete[] text;
	fclose(file);
	std::cout << "\nThe text was added to the file\n\n";

	parse_rows(file, filename);
}

int get_size(FILE* file, const char* filename) {

	file = fopen(filename, "r");
	if (file == NULL) {
		std::cout << "Error. File not found." << std::endl;
		return -1;
	}

	int size = 0;
	char temp[300];
	while (fgets(temp, sizeof(temp), file) != NULL) {
		size++;
	}

	fclose(file);
	return size;
}

void pointer_mode(FILE* file, const char* filename) {
	fill_file(file, filename);
}


void parse_rows(FILE* file, const char* filename) {
	int size = get_size(file, filename), index = 0;
	if (size == -1) return;

	char** rows = new char* [size];
	char* buffer = new char[300];
	for (int i = 0; i < size; i++) {
		rows[i] = new char[300];
	}

	file = fopen(filename, "r");

	if (file == NULL) {
		std::cout << "Error. File not found." << std::endl;
		return;
	}

	std::cout << "Rows count: " << size << std::endl;
	int temp = 0;
	while (fgets(buffer, 300, file) != NULL) {
		if (index != size) strcpy(rows[index++], buffer);
	}

	fclose(file);

	write_rows(rows, size, filename);
}

void write_rows(char** rows, int size, const char* filename) {
	FILE* file = fopen("output.txt", "w");
	if (file == NULL) {
		std::cout << "Error. File not found." << std::endl;
		return;
	}
	std::cout << std::endl;
	for (int i = 0; i < size; i++) {
		if (has_digits(rows[i])) {
			fprintf(file, "%s", rows[i]);
		}
	}

	fclose(file);
	max_sequence_in_file(rows, size, filename);
}

void max_sequence_in_file(char** rows, int size, const char* filename) {
	FILE* file = fopen("output.txt", "r");
	if (file == NULL) {
		std::cout << "Error. File not found." << std::endl;
		return;
	}
	std::cout << std::endl;
	int* positions_seq_in_word = new int[size];
	int* positions_word_in_row = new int[size];
	int* len_of_seq = new int[size];
	int* len_of_word = new int[size];
	bool check;
	for (int i = 0; i < size; i++) {
		check = true;
		find_max_digit_sequence(rows[i], positions_seq_in_word[i], positions_word_in_row[i], len_of_word[i], len_of_seq[i], check);
		if (check) rewrite_row(rows[i], positions_seq_in_word[i], positions_word_in_row[i], len_of_word[i], len_of_seq[i]);
		else continue;
	}
	fclose(file);
	rewrite_file(rows, size, filename);
}

void rewrite_file(char** rows, int size, const char* filename) {
	FILE* file = fopen("output.txt", "w");
	if (file == NULL) {
		std::cout << "Error. File not found." << std::endl;
		return;
	}
	std::cout << std::endl;
	for (int i = 0; i < size; i++) {
		if (has_digits(rows[i]))
			fprintf(file, "%s", rows[i]);
	}
	fclose(file);
	print_file_p(filename);
	print_file_p("output.txt");
	free_memory(filename, rows, size);
}

void rewrite_row(char* row, int pos_of_seq, int pos_of_word, int len_of_word, int len_of_seq) {
	for (int i = 0; i < pos_of_seq; i++) {
		std::swap(row[pos_of_word + pos_of_seq - 1 - i], row[pos_of_word + pos_of_seq - 1 - i + len_of_seq]);
	}

	char temp1[300], temp2[300];
	strncpy(temp1, row, pos_of_word + len_of_word);
	temp1[pos_of_word + len_of_word] = '\0';
	strcpy(temp2, row + pos_of_word + len_of_word);
	sprintf(row, "%s(%d)%s", temp1, len_of_word, temp2);

	std::cout << "Row: " << row << '\n';
}

void print_file_p(const char* filename) {
	std::cout << "\nFile " << filename << ":\n";
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		std::cout << "Error. File not found\n";
		return;
	}
	char ch;
	while ((ch = fgetc(file)) != EOF) {
		std::cout << ch;
	}
	fclose(file);
}

void free_memory(const char* filename, char** rows, int size) {
	for (int i = 0; i < size; i++) {
		delete[] rows[i];
	}
	delete[] rows;
	delete[] filename;
}