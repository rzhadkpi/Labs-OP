#pragma once

char* get_name_of_file();	// функція для отримання назви файла
void fill_file(FILE* file, const char* filename);	 // функція для заповнення файла текстом
int get_size(FILE* file, const char* filename);		// функція для знаходження кількості рядкі у файлі
void pointer_mode(FILE* file, const char* filename);	// основна функція, яка викликає інші допоміжні функції
void parse_rows(FILE* file, const char* filename);		// функція для розбиття тексту файла на рядки
void write_rows(char** rows, int size, const char* filename);	// функція для запису тексту у файлу розбитого на рядки
void print_file_p(const char* filename);	// функція для виводу вмісту файла
void max_sequence_in_file(char** rows, int size, const char* filename);		// функція для знаходження найбільших послідовностей у файлі
void rewrite_row(char* row, int pos_of_word, int pos_of_seq, int len_of_seq, int len_of_word);	 // функція для переписання рядка (відповідно до завдання)
void rewrite_file(char** rows, int size, const char* filename);	  //  функція для переписання усіх рядків у файлі (відповідно до завдання)
void free_memory(const char* filename, char** rows, int size);	 // функція вивільнення пам'яті