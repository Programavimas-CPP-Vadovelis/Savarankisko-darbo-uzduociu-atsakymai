import <iostream>;
using std::cout;
using std::cin;
using std::endl;
//
class MatrixBase {
protected:
	size_t n, m;     // matricos matai
	double** matrix; // matrica
public:
	// 
	MatrixBase() {
		cout << "Iveskite matricos matus\n";
		cin >> n >> m;
		matrix = new double* [n];
		for (size_t i = 0; i < n; i++)
			matrix[i] = new double[m];
		setNull();
	}
	// 
	MatrixBase(size_t nn, size_t mm) {
		n = nn;
		m = mm;
		matrix = new double* [n];
		for (size_t i = 0; i < n; i++)
			matrix[i] = new double[m];
		setNull();
	}
	//
	~MatrixBase() {
cout << "Destruktorius MatrixBase " << n << ' ' << m << endl; //kad matytumėt, kuris objektas sunaikinamas
		for (size_t i = 0; i < n; i++)
			delete[] matrix[i];
		delete[] matrix;
	}
	// 
	void setNull() {
		for (size_t i = 0; i < n; i++)
			for (size_t j = 0; j < m; j++)
				matrix[i][j] = 0.;
	}
	//
	void getData() {
		cout << "Iveskite matricos elementus eilutemis:\n";
		for (size_t i = 0; i < n; i++) {
			cout << i + 1 << "  eilute is " << m <<
 " elementu\n";
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
				cout << "  " << matrix[i][j] << "  ";
			cout << endl;
		}
	}
};
//
class Matrix : public MatrixBase {
public:
	Matrix() : MatrixBase() {}
	Matrix(int n, int m) : MatrixBase(n, m) {}
	~Matrix() {
		cout << "Destruktorius Matrix " << n << ' ' << m << endl; 
              //kad matytumėt, kuris objektas sunaikinamas
	}
	//
	void transpose(const Matrix& mInitial) {
		//jei argumentą perduosit reikšme - būtinai
		//reikės parašyti kopijuojantįjį konstruktorių
		for (size_t i = 0; i < n; i++) {
			for (size_t j = 0; j < m; j++) {
				matrix[i][j] = mInitial.matrix[j][i];
			}
		}
	}
	//
	double minValue() {
		double min = matrix[0][0];
		for (size_t i = 0; i < n; i++)
			for (size_t j = 0; j < m; j++)
				if (min > matrix[i][j])
					min = matrix[i][j];
		return min;
	}
};
//
//
int main() {
	size_t n, m; //pradinės matricos matai
	cout << "Iveskite pradines matricos matus\n";
	cin >> n >> m;
	//
	Matrix mInitial(n, m); //pradinė matrica
	//
	mInitial.getData();
	mInitial.showData("Pradine matrica");
	//
	Matrix mTransposed(m, n); //transponuota matrica - atvirkščių matų
	mTransposed.transpose(mInitial);
	mTransposed.showData("Transponuota matrica");
	//
	cout << "Maziausias matricos elementas yra "
				<< mTransposed.minValue() << endl;
	//
}
