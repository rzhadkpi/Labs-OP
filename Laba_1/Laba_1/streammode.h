#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#pragma once

int get_size(const std::string& filename);		// ������� ��� ����������� ������� ���� � ����
void stream_mode(const std::string& filename);  // ������� �������, ��� ������� ���� ������� �������
void fill_file(const std::string& filename);	// ������� ��� ���������� ����� �������
std::string get_name_of_file(const std::string& message);	// ������� ��� ��������� ����� �����
void print_file_s(const std::string filename);	// ������� ��� ������ ����� �����