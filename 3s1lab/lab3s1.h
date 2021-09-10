namespace lab1 {

	struct Matrix {
		int* row;
		int* col;
		int* val;
		int hight;
		int width;
	};

	template <typename T>
	int getInt(T &elem) {
		std::cin >> elem;
		if (!std::cin.good()) {
			return -1;
		}
		return 1;
	}

	inline int sum_digits(int elem) {
		int result = 0;
		while (elem > 0) {
			result += elem % 10;
			elem /= 10;
		}
		return result;
	}

	Matrix* Input(int& index);
	void Output(Matrix* matr);
	void Erase(Matrix*&);
	Matrix* Memory(int, int);
	void Output_vector(int*, int);
	int* new_vector(Matrix*, int);
}