// Programos variantas, kai objektai į metodą ir draugišką funkciją atiduodami adreso mechanizmu.
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
		cout << "\nDestruktorius " << n << ' ' << m << endl; 
         // kad matytumėt, kuris objektas sunaikinamas
		for (size_t i = 0; i < n; i++)
			delete[] matrix[i];
		delete[] matrix;
	}
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
	friend double minValue(const Matrix&); //draugiškos funkcijos prototipas
//
}; //klasės pabaiga
//
//
double minValue(const Matrix& m) { //draugiškos funkcijos realizacija argumentą taip pat reikia perduoti adresu
	double min = m.matrix[0][0]; //visi objekto m laukai - matomi
	for (size_t i = 0; i < m.n; i++)
		for (size_t j = 0; j < m.m; j++)
			if (min > m.matrix[i][j])
				min = m.matrix[i][j];
	return min;
}
//
//
int main() {
	int n, m; //pradinės matricos matai
	cout << "Iveskite pradines matricos matus\n";
	cin >> n >> m;
	//
	Matrix mInitial(n, m); //pradinė matrica
	//
	mInitial.getData();
	mInitial.showData("Pradine matrica");
	//
	Matrix mTransposed(m, n); //transponuota matrica - 
			   //atvirkščių matų
	mTransposed.transpose(mInitial);
	mTransposed.showData("Transponuota matrica");
	//
	cout << "Maziausias matricos elementas yra "
		<< minValue(mTransposed) << endl;
	//
}
