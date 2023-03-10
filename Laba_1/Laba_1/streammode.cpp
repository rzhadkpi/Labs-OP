#include "streammode.h" 
#include "functions.h"

/*
	Створити текстовий файл. слова у текстi вiддiленi пробiлами та крапками.
	Переписати у новий текстовий файл рядки тексту, оо мiстять хоча б одну цифру.
	У кожному рядку нового файлу визначити найдовшу послiдовнiсть однакових
	цифр (вважати, що у рядку такi послiдовностi є). якщо знайдена послiдовнiсть
	цифр - не окрема лексема, переставити її на початок вiдповiдного слова (для кож-
	ного такого рядка). визначити довжину слова, яке мiстить знайдену послiдовнiсть
	цифр, i дописати вiдповiдне значення пiсля даного слова, вiдокремивши це зна-
	чення круглими дужками. наприклад, wоrd 999923kоd(9) say.
	вивести вмiст вхiдного i створеного файлiв.
*/

std::string get_name_of_file(const std::string& message) {
	std::cout << message;
	std::string filename;
	std::getline(std::cin, filename);
	return filename;
}

int get_size(const std::string& filename) {
	int size = 0;

	std::ifstream in(filename);
	if (!in.is_open()) {
		std::cout << "Error while opening the file." << std::endl;
		return -1;
	}

	std::string temp;
	while (std::getline(in, temp)) {
		size++;
	}

	return size;
}

void stream_mode(const std::string& filename) {
	fill_file(filename);
	print_file_s(filename);
	print_file_s("output.txt");
}

void fill_file(const std::string& filename) {

	void parse_rows(const std::string& filename);

	std::ofstream out(filename);
	if (!out.is_open()) {
		std::cout << "Error. File is not open" << std::endl;
		return;
	}
	std::string text;
	std::cout << "Enter text to the file (enter \"stop\" to stop):\n";

	while (true) {
		std::getline(std::cin, text);
		if (text == "stop") break;
		out << text << "\n";
	}

	out.close();

	parse_rows(filename);
}

void parse_rows(const std::string& filename) {
	std::ifstream in(filename);
	int size, index = 0;
	std::string* rows;
	std::string row;

	if (!in.is_open()) {
		std::cout << "Error while opening the file." << std::endl;
		return;
	}

	size = get_size(filename);
	if (size == -1) return;

	rows = new std::string[size];
	std::cout << "\nRows count: " << size << std::endl;
	while (std::getline(in, row)) {
		rows[index++] = row;
	}

	std::ofstream out("output.txt");
	if (!out) {
		std::cout << "Error. Can not open file.\n";
		return;
	}
	bool flag;
	for (int i = 0; i < size; i++) {
		flag = true;
		find_max_digit_sequence(rows[i], flag);
		if (flag) out << rows[i] << '\n';
	}

	out.close();
	in.close();
}

void print_file_s(const std::string filename) {
	std::cout << "\nFile " << filename << ":\n";
	std::ifstream inf(filename);
	while (inf)
	{
		std::string str;
		std::getline(inf, str);
		std::cout << str << '\n';
	}

	inf.close();
}