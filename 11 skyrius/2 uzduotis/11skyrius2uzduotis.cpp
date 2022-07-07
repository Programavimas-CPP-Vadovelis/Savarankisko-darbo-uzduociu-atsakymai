import <iostream>;
using std::cout;
using std::cin;
using std::endl;
//
class Matrix {
private:
	int n, m;         // matricos matai
	double** matrix; // matrica
public:
	// konstruktorius be argumentų
	Matrix() {
		cout << "Iveskite matricos matus\n";
		cin >> n >> m;
		// dinaminė atmintis matricai
		matrix = new double* [n];
		for (size_t i = 0; i < n; i++)
			matrix[i] = new double[m];
		// nulinių reikšmių prieskyra
		setNull();
	};
	// destruktorius
	~Matrix() {
		for (size_t i = 0; i < n; i++)
			delete[] matrix[i];
		delete[] matrix;
	};
	// metodai
	void setNull() {
		for (size_t i = 0; i < n; i++)
			for (size_t j = 0; j < m; j++)
				matrix[i][j] = 0.;
	}
	//
	void getData() {
		cout << "Iveskite matricos elementus eilutemis:\n";
		for (size_t i = 0; i < n; i++) {
			cout << i + 1 << "  eilute\n";
			for (size_t j = 0; j < m; j++)
				cin >> matrix[i][j];
		}
	}
	//
	void showData() {
		cout << endl << endl;
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
};
//
int main() {
	//
	Matrix m;
	//
	m.getData();
	m.showData();
	//
}
