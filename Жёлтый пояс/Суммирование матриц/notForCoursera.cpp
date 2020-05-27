#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Matrix {
public:
	Matrix() {
		x = 0;
		y = 0;
	}

	Matrix(int num_row, int num_cols, string data) {
		x = num_row;
		y = num_cols;
		if (x < 0) {
			throw out_of_range("" + to_string(x));
		}
		else if (y < 0) {
			throw out_of_range("" + to_string(y));
		}
		for (int a = 0; a < x; a++) {
			vector<int> save;
			for (int b = 0; b < y; b++) {
				stringstream iss(data);
				int num;
				iss >> num;
				m.push_back(save);
				m[a].push_back(num);
			}
		}
	}
	Matrix(int num_row, int num_cols, vector<vector<int>> data) {
		x = num_row;
		y = num_cols;
		m = data;
	}

	void Reset(int newX, int newY) {
		x = newX;
		y = newY;
		if (x < 0) {
			throw out_of_range("" + to_string(x));
		}
		else if (y < 0) {
			throw out_of_range("" + to_string(y));
		}
		for (int a = 0; a < x; a++) {
			for (int b = 0; b < y; b++) {
				m[a].push_back(0);
			}
		}
	}

	int At(int fX, int fY) const {
		return m[fX][fY];
	}

	int& At(int fX, int fY) {
		return m[fX][fY];
	}

	int GetNumRows() const {
		return x;
	}

	int GetNumColumns() const {
		return y;
	}

	int GetNumber(int x, int y) const {
		return m[x][y];
	}

private:
	int x;
	int y;
	//vector<int> fX;
	//vector<int> fY;
	vector<vector<int>> m;
};

bool operator==(const Matrix m1, const Matrix m2) {
	if (m1.GetNumRows() != m2.GetNumRows() || m1.GetNumColumns() != m2.GetNumColumns()) {
		return false;
	}
	int x = m1.GetNumRows();
	int y = m1.GetNumColumns();

	for (int a = 0; a < x; a++) {
		for (int b = 0; b < y; b++) {
			if (m1.GetNumber(a, b) != m2.GetNumber(a, b)) {
				return false;
			}
		}
	}
	return true;
}

Matrix operator+(const Matrix m1, const Matrix m2) {
	if (m1.GetNumRows() != m2.GetNumRows()) {
		throw invalid_argument(to_string(m1.GetNumRows()) + " != " + to_string(m2.GetNumRows()));
	}
	else if (m1.GetNumColumns() != m2.GetNumColumns()) {
		throw invalid_argument(to_string(m1.GetNumColumns()) + " != " + to_string(m2.GetNumColumns()));
	}

	vector<vector<int>> m3;
	int x = m1.GetNumRows();
	int y = m1.GetNumColumns();

	for (int a = 0; a < x; a++) {
		vector<int> save;
		for (int b = 0; b < y; b++) {
			m3.push_back(save);
			m3[a].push_back(m1.GetNumber(a, b) + m2.GetNumber(a, b));
		}
	}
	return { x, y, m3 };
}

istream& operator>>(istream& stream, Matrix& m) {
	int x, y, num;
	stream >> x >> y;
	vector<vector<int>> m2;
	for (int a = 0; a < x; a++) {
		vector<int> save;
		for (int b = 0; b < y; b++) {
			stream >> num;
			m2.push_back(save);
			m2[a].push_back(num);
		}
	}
	m = { x, y, m2 };
	return stream;
}

ostream& operator<<(ostream& stream, const Matrix m) {
	int x = m.GetNumRows();
	int y = m.GetNumColumns();
	stream << x << " " << y << endl;
	for (int a = 0; a < x; a++) {
		for (int b = 0; b < y; b++) {
			stream << m.GetNumber(a, b) << " ";
		}
		stream << endl;
	}
	return stream;
}

int main() {
	Matrix one;
	Matrix two;
	try {
		cin >> one >> two;
		cout << one + two << endl;
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
	return 0;
}
