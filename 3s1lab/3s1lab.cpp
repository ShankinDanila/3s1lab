#include <iostream>
#include "lab3s1.h"

namespace lab1 {
	Matrix* Input(int& index) {
		const char* pr = "";
		int num_rows, num_col;

		do {
			std::cout << pr << std::endl;
			std::cout << "Enter number of rows: --> ";
			if (getInt(num_rows) < 0) {
				pr = "You are wrong; repeat please!";
				return nullptr;
			}
		} while (num_rows < 1);

		do {
			std::cout << pr << std::endl;
			std::cout << "Enter number of columns: --> ";
			if (getInt(num_col) < 0) {
				pr = "You are wrong; repeat please!";
				return nullptr;
			}
		} while (num_col < 1);

		int* line;
		try {
			line = new int[num_col * num_rows];
		}
		catch (std::bad_alloc& ba)
		{
			std::cout << "------ Error: " << ba.what() << std::endl;
			return nullptr;
		}

		std::cout << "Enter " << num_col * num_rows << " numbers" << std::endl;
		for (int i = 0; i < num_col * num_rows; i++) {
			int num;
			do {
				std::cout << pr << std::endl;
				if (getInt(num) < 0) {
					pr = "You are wrong; repeat please!";
					return nullptr;
				}
			} while (num < -1);
			line[i] = num;
			if (num != 0) {
				index++;
			}
		}
		/*try {
			Matrix* matrix = new Matrix;
			matrix->val = new int[index];
			matrix->col = new int[index];
			matrix->row = new int[num_col];
		}
		catch (std::bad_alloc& ba)
		{
			std::cout << "------ Error: " << ba.what() << std::endl;
			return nullptr;
		}*/
		Matrix* matrix = Memory(index, num_col);
		int counter = 0;
		for (int i = 0; i < num_col * num_rows; i++) {
			if (line[i] != 0) {
				matrix->val[counter] = line[i];
				int index_col = i % num_col;
				int index_row = i / num_col;
				matrix->col[counter] = index_col;
				matrix->row[counter] = index_row;
				counter++;
			}
		}
		matrix->hight = num_rows;
		matrix->width = num_col;
		delete[] line;
		return matrix;
	}
		
	Matrix* Memory(int index, int num_col) {
		try {
			Matrix* matrix = new Matrix;
			matrix->val = new int[index];
			matrix->col = new int[index];
			matrix->row = new int[index];
			return matrix;
		}
		catch (std::bad_alloc& ba)
		{
			std::cout << "------ Error: " << ba.what() << std::endl;
			return nullptr;
		}
	}

	void Output(Matrix* matrix) {
		int index = 0;
		for (int i = 0; i < matrix->hight * matrix->width; i++) {
			if (i % matrix->width == 0) {
				std::cout << std::endl;
			}
			if ((matrix->col[index] + matrix->row[index] * matrix->width) == i) {
				std::cout << " " << matrix->val[index] << ' ';
				index++;
			}
			else {
				std::cout << " " << 0 << ' ';
			}
		}
	}

	void Erase(Matrix*& matrix) {
		delete[] matrix->val;
		delete[] matrix->col;
		delete[] matrix->row;
		delete matrix;
		return;
	}

	int* new_vector(Matrix* matr, int index) {
		int* new_vector;
		int sum_elems = 0;
		int sum_numbers = 0;
		int counter = 0;
		try{
			new_vector = new int[matr->hight]();
		}
		catch (std::bad_alloc& ba)
		{
			std::cout << "------ Error: " << ba.what() << std::endl;
			return nullptr;
		}

		for (int i = 0; i < index; i++) {
			if (matr->col[i] == 0) {
				sum_numbers = sum_digits(matr->val[i]);
				for (int j = 0; j < index; j++) {
					if (matr->row[j] == matr->row[i] && (sum_numbers == sum_digits(matr->val[j]))) {
						sum_elems += matr->val[j];
					}
				}
				new_vector[matr->row[i]] = sum_elems;
				sum_elems = 0;
			}
		}
		return new_vector;
	}

	void Output_vector(int* new_vector, int hight) {
		std::cout << std::endl << "New vector: ";
		for (int i = 0; i < hight; i++) {
			std::cout << new_vector[i] << " ";
		}
		delete[] new_vector;
		return;
	}
}