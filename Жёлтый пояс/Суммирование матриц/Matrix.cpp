#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix
class Matrix {
public:
	Matrix() {
		x = 0;
		y = 0;
	}

	Matrix(int num_row, int num_cols) {
		Reset(num_row, num_cols);
	}

	void Reset(int newX, int newY) {
		if (newX < 0) {
			throw out_of_range("num_rows must be >= 0");
		}
		if (newY < 0) {
			throw out_of_range("num_columns must be >= 0");
		}
		if (newX == 0 || newY == 0) {
			newX = newY = 0;
		}
		x = newX;
		y = newY;
		m.assign(newX, vector<int>(newY));
	}

	int& At(int fX, int fY) {
		return m.at(fX).at(fY);
	}

	int At(int fX, int fY) const {
		return m.at(fX).at(fY);
	}

	int GetNumRows() const {
		return x;
	}

	int GetNumColumns() const {
		return y;
	}

private:
	int x;
	int y;
	vector<vector<int>> m;
};

bool operator==(const Matrix& m1, const Matrix& m2) {
	if (m1.GetNumRows() != m2.GetNumRows()) {
		return false;
	}
	if (m1.GetNumColumns() != m2.GetNumColumns()) {
		return false;
	}

	for (int a = 0; a < m1.GetNumRows(); ++a) {
		for (int b = 0; b < m1.GetNumColumns(); ++b) {
			if (m1.At(a, b) != m2.At(a, b)) {
				return false;
			}
		}
	}
	return true;
}

Matrix operator+(const Matrix& m1, const Matrix& m2) {
	if (m1.GetNumRows() != m2.GetNumRows()) {
		throw invalid_argument("Mismatched number of rows");
	}
	if (m1.GetNumColumns() != m2.GetNumColumns()) {
		throw invalid_argument("Mismatched number of columns");
	}
	
	Matrix result(m1.GetNumRows(), m2.GetNumColumns());
	for (int a = 0; a < m1.GetNumRows(); ++a) {
		for (int b = 0; b < m1.GetNumColumns(); ++b) {
			result.At(a, b) = m1.At(a, b) + m2.At(a, b);
		}
	}
	return result;
}

istream& operator>>(istream& stream, Matrix& m) {
	int x, y;
	stream >> x >> y;

	m.Reset(x, y);
	for (int a = 0; a < x; ++a) {
		vector<int> save;
		for (int b = 0; b < y; ++b) {
			stream >> m.At(a, b);
		}
	}
	return stream;
}

ostream& operator<<(ostream& stream, const Matrix m) {
	stream << m.GetNumRows() << " " << m.GetNumColumns() << endl;
	for (int a = 0; a < m.GetNumRows(); a++) {
		for (int b = 0; b < m.GetNumColumns(); b++) {
			if (b > 0) {
				stream << " ";
			}
			stream << m.At(a,b);
		}
		stream << endl;
	}
	return stream;
}

int main() {
	Matrix one;
	Matrix two;

	cin >> one >> two;
	cout << one + two << endl;
	return 0;
}
