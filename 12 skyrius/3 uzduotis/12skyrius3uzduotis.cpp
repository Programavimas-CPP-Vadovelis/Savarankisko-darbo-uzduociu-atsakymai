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
	Matrix(int nn, int mm) {
		n = nn;
		m = mm;
		matrix = new double* [n];
		for (size_t i = 0; i < n; i++)
			matrix[i] = new double[m];
		setNull();
	}
	// destruktorius
	~Matrix() {
		cout << "Destruktorius\n"; //kad matytumėt,
			  //kiek objektų kuriama ir naikinama
		for (size_t i = 0; i < n; i++)
			delete[] matrix[i];
		delete[] matrix;
	}
	// kopijuojantysis konstruktorius
	Matrix(const Matrix& mSource) {
		cout << "Kopijavimas\n"; //kad matytumėt, jog tokio
			  //konstruktoriaus programoje būtinai reikia
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
	Matrix* operator+(Matrix a) {
		Matrix* md = new Matrix(n, m);
		for (size_t i = 0; i < n; i++) {
for (size_t j = 0; j < m; j++) {
(*md).matrix[i][j] = matrix[i][j] + a.matrix[i][j];
	}
		}
		return md; // grąžinamas lokalus duomuo!- tačiau
		// jis dinaminis - todėl gyvuos iki pat delete operacijos
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
	Matrix* r(nullptr); //rodyklė į rezultato matricą
	//
	a1.getData();
	a1.showData("Pirma pradine matrica");
	a2.getData();
	a2.showData("Antra pradine matrica");
	//
	// *r = a1 + a2
	//
	r = a1 + a2;
	//
	r->showData("Rezultato matrica");
	//
	delete r; //kad nebūtų atminties nuotėkio
	//
}
