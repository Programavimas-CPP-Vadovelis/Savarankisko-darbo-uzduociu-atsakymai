import <iostream>;
using std::cout;
using std::cin;
using std::endl;
//
class Matrix {
private:
	size_t n, m;     // matricos matai
	double** matrix; // matrica
public:
	// konstruktorius be argumentų
	Matrix() {
		cout << "Iveskite matricos matus\n";
		cin >> n >> m;
		matrix = new double* [n];
		for (size_t i = 0; i < n; i++)
			matrix[i] = new double[m];
		setNull();
	}
	// konstruktorius su argumentais
	Matrix(size_t nn, size_t mm) {
		n = nn;
		m = mm;
		matrix = new double* [n];
		for (size_t i = 0; i < n; i++)
			matrix[i] = new double[m];
		setNull();
	}
	// destruktorius
	~Matrix() {
		for (size_t i = 0; i < n; i++)
			delete[] matrix[i];
		delete[] matrix;
	}
	// kopijuojantysis konstruktorius
	Matrix(const Matrix& mSource) {
		n = mSource.n;
		m = mSource.m;
		matrix = new double* [n];
		for (size_t i = 0; i < n; i++)
			matrix[i] = new double[m];
		for (size_t i = 0; i < n; i++)
			for (size_t j = 0; j < m; j++)
				matrix[i][j] = mSource.matrix[i][j];
	}
	// metodai
	void setNull() {
		for (size_t i = 0; i < n; i++)
			for (size_t j = 0; j < m; j++)
				matrix[i][j] = 0.;
	}
	//
	void getData() {
		cout << "\nIveskite matricos elementus eilutemis:\n";
		for (size_t i = 0; i < n; i++) {
			cout << i + 1 << "  eilute is " << m 
<< " elementu\n";
			for (size_t j = 0; j < m; j++)
				cin >> matrix[i][j];
		}
	}
	//
	void showData(const char s[]) {
		cout << endl << endl;
		cout << s << endl;
		cout << "Matricos matai: " << n << "  " << m << endl;
		cout << "Matricos elementai eilutemis\n";
		for (size_t i = 0; i < n; i++) {
			cout << i + 1 << "  eilute:\n";
			for (size_t j = 0; j < m; j++)
				cout << matrix[i][j] << "  ";
			cout << endl;
		}
	}
	//
	void operator+=(const Matrix& a) {
		for (size_t i = 0; i < n; i++) {
			for (size_t j = 0; j < m; j++) {
				matrix[i][j] += a.matrix[i][j];
			}
		}
	}
	//
};
//
//
int main() {
	size_t n, m; //pradinių matricų matai
	cout << "Iveskite pradines matricos matus\n";
	cin >> n >> m;
	//
	Matrix a1(n, m), a2(n, m); //pradinės matricos
	//
	a1.getData();
	a1.showData("Pirma pradine matrica");
	a2.getData();
	a2.showData("Antra pradine matrica");
	//
	// a1 = a1 + a2
	//
	a1 += a2;
	//
	a1.showData("Rezultato matrica");
	//
}
