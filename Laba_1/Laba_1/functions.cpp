#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"
#include "streammode.h"

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

bool has_point(char* word) {
	if (word[strlen(word) - 1] == '.' || word[strlen(word) - 2] == '.') return true;
	return false;
}


void find_max_digit_sequence(std::string& row, bool& flag) {
	int max_length = 0;
	int curr_length = 1;
	std::string substr = "";
	std::string sequence = "";

	for (int i = 0; i < row.length() - 1; i++) {
		if (row[i] == row[i + 1] && isdigit(row[i])) {
			curr_length++;
			substr += row[i];
		}

		if (max_length < curr_length) { 
			max_length = curr_length;
			sequence = substr;
		}

		if (row[i] == ' ' || row[i] == '.' || row[i] == '\n') {
			curr_length = 1;
			substr = "";
		}
	}
	sequence += sequence[0];

	size_t word_start = 0, word_end = 0;
	size_t start_pos = row.find(sequence);
	for (int i = start_pos; i >= 0; i--) {
		word_start = i;
		if (row[i] == ' ' || row[i] == '.' || row[i] == '\n')  {
			word_start = i + 1;
			break;
		}
	}

	for (int i = start_pos; i < row.length(); i++) {
		word_end = i;
		if (row[i] == ' ' || row[i] == '.' || row[i] == '\n') {
			word_end = i;
			break;
		}
	}
	
	if (sequence.length() > 1) {
	std::cout << "\nSequence start: " << start_pos << std::endl;
	std::cout << "Word start: " << word_start << std::endl;
	std::cout << "Word end: " << word_end << std::endl;
	std::cout << "Max sequence length in row: " << max_length << "\n";
	std::cout << "Sequence: " << sequence << std::endl;
		row.erase(row.begin() + start_pos, row.begin() + start_pos + max_length);
		row.insert(word_start, sequence);
		std::string add = "(";
		size_t word_length = word_end - word_start;
		word_start == 0 ? add += std::to_string(word_length) : add += std::to_string(word_length + 1);
		//add += std::to_string(word_length + 1);
		add += ")";

		if (word_end == row.length() - 1 ) {
			row.insert(word_end + 1, add);
		}
		else {
			row.insert(word_end, add);
		}
		std::cout << "\nNew row: " << row << std::endl;

	}
	else {
		std::cout << "No same numbers in a row" << std::endl;
		flag = false;
		return;
	}
}

void find_max_digit_sequence(char* row, int& positions_seq_in_word, int& positions_word_in_row, int& len_of_word, int& len_of_seq, bool& check) {
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

	if (max_size >= 1) {

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
		check = false;
	}
}
