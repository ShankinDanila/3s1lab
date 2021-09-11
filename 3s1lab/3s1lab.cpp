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
			std::cout << pr << std::endl;
			std::cout << "Enter number of columns: --> ";
			if (getInt(num_col) < 0) {
				pr = "You are wrong; repeat please!";
				return nullptr;
			}
		} while (num_rows < 1 && num_col < 1);

		int* line;
		try {
			line = new int[num_col * num_rows];
		}
		catch (const std::bad_alloc& ba)
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
					delete[] line;
					return nullptr;
				}
			} while (num < -1);
			line[i] = num;
			if (num != 0) {
				index++;
			}
		}

		Matrix* matrix;
		try {
			matrix = new Matrix;
		}
		catch (const std::bad_alloc& ba)
		{
			std::cout << "------ Error: " << ba.what() << std::endl;
			return nullptr;
		}
		try {
			matrix->massive = new Element[index];
		}
		catch (const std::bad_alloc& ba){
			std::cout << "------ Error: " << ba.what() << std::endl;
			return nullptr;
		}

		int counter = 0;
		for (int i = 0; i < num_col * num_rows; i++) {
			if (line[i] != 0) {
				matrix->massive[counter].val = line[i];
				int index_col = i % num_col;
				int index_row = i / num_col;
				matrix->massive[counter].col = index_col;
				matrix->massive[counter].row = index_row;
				counter++;
			}
		}
		matrix->hight = num_rows;
		matrix->width = num_col;
		delete[] line;
		return matrix;
	}
		
	//Matrix* Memory(int index, int num_col) {
	//	Matrix* matrix;
	//	try {
	//		matrix = new Matrix;
	//		//return matrix;
	//	}
	//	catch (const std::bad_alloc& ba)
	//	{
	//		std::cout << "------ Error: " << ba.what() << std::endl;
	//		return nullptr;
	//	}

	//	try {
	//		
	//	}
	//}

	void Output(Matrix* matrix) {
		int index = 0;
		for (int i = 0; i < matrix->hight * matrix->width; i++) {
			if (i % matrix->width == 0) {
				std::cout << std::endl;
			}
			if ((matrix->massive[index].col + matrix->massive[index].row * matrix->width) == i) {
				std::cout << " " << matrix->massive[index].val << ' ';
				index++;
			}
			else {
				std::cout << " " << 0 << ' ';
			}
		}
	}

	void Erase(Matrix*& matrix) {
		delete[] matrix->massive;
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
		catch (const std::bad_alloc& ba)
		{
			std::cout << "------ Error: " << ba.what() << std::endl;
			return nullptr;
		}

		for (int i = 0; i < index; i++) {
			if (matr->massive[i].col == 0) {
				sum_numbers = sum_digits(matr->massive[i].val);
				for (int j = 0; j < index; j++) {
					if (matr->massive[i].row == matr->massive[j].row && (sum_numbers == sum_digits(matr->massive[j].val))) {
						sum_elems += matr->massive[j].val;
					}
				}
				new_vector[matr->massive[i].row] = sum_elems;
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