/* Створити текстовий файл. Слова у тексті відділені пробілами та крапками.
Переписати у новий текстовий файл рядки тексту, що містять хоча б одну цифру.
У кожному рядку нового файлу визначити найдовшу послідовність однакових
цифр (вважати, що у рядку такі послідовності є). Якщо знайдена послідовність
цифр - не окрема лексема, переставити її на початок відповідного слова (для кож-
ного такого рядка). Визначити довжину слова, яке містить знайдену послідовність
цифр, і дописати відповідне значення після даного слова, відокремивши це зна-
чення круглими дужками. Наприклад, word 999923kod(9) say. Вивести вміст вхід-
ного і створеного файлів. */

#include <iostream> 
#include <fstream>
#include <string>
#include "choosemode.h"
#include "pointermode.h"
#include "streammode.h"

int main(int argc, char** argv) {

	int mode;
	FILE* fileC = nullptr;

	if (choose_mode(argc, argv, mode) == 0) {
		std::cout << "Error. You can use only: \"-mode FilePointer\" or \"-mode FileStream\"" << std::endl;
		return 0;
	}
	if (mode == 0) {
		std::cout << " ---FilePointer mode---" << std::endl;
		const char* filename_p = get_name_of_file();
		pointer_mode(fileC, filename_p);
	}
	else if (mode == 1) {
		std::cout << " ----FileStream mode---" << std::endl;
		std::string filename_s{ get_name_of_file("Enter name of file: ")};
		stream_mode(filename_s);
	}
	return 0;
}