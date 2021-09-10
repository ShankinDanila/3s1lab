#include <iostream>
#include "lab3s1.h"

using namespace lab1;
	int main() {
		int index = 0;
		Matrix* matr = Input(index);
		if (!matr) {
			std::cout << "incorrect data" << std::endl;
			return 1;
		}
		Output(matr);
		int* vector = new_vector(matr, index);
		Output_vector(vector, matr->hight);
		Erase(matr);
		return 0;
	}
