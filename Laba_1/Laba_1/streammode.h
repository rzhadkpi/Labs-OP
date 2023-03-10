#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#pragma once

int get_size(const std::string& filename);		// функція для знаходження кількості рядкі у файлі
void stream_mode(const std::string& filename);  // основна функція, яка викликає інші допоміжні функції
void fill_file(const std::string& filename);	// функція для заповнення файла текстом
std::string get_name_of_file(const std::string& message);	// функція для отримання назви файла
void print_file_s(const std::string filename);	// функція для виводу вмісту файла