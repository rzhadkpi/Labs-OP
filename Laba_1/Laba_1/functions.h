#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string.h>
#include <iomanip>


bool has_digits(char* row);		// ������� ��� �������� �� � ����� � �����
int count_words(char* row);		// ������� ��� ����������� ������� ��� � �����
void find_max_digit_sequence(std::string& row, bool& flag);		// ������� ��� ����������� �������� ����������� ����� � ����� (�++ �����)
void find_max_digit_sequence(char* row, int& positions_seq_in_word, int& positions_word_in_row, int& len_of_word, int& len_of_seq, bool& check);   // ������� ��� ����������� �������� ����������� ����� � ����� (� �����)