#pragma once

char* get_name_of_file();
void fill_file(FILE* file, const char* filename);                                                                                                                                                                  //я даун
int get_size(FILE* file, const char* filename);
void pointer_mode(FILE* file, const char* filename);
void parse_rows(FILE* file, const char* filename);
void write_rows(char** rows, int size, const char* filename);
void print_file_p(const char* filename);
void max_sequence_in_file(char** rows, int size, const char* filename);
void rewrite_row(char* row, int pos_of_word, int pos_of_seq, int len_of_seq, int len_of_word);
void rewrite_file(char** rows, int size, const char* filename);