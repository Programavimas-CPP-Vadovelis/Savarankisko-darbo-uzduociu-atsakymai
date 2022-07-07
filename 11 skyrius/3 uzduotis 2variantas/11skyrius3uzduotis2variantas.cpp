 // Programos variantas, kai objektai į metodą ir draugišką funkciją atiduodami reikšmės mechanizmu – tada būtinas kopijuojantysis konstruktorius, o objektų bekopijuojant sukuriama dvigubai tiek, kiek pirmojo programos varianto atveju.
import <iostream>;
using std::cout;
using std::cin;
using std::endl;
//
class Matrix {
private:
	int n, m;         
	double** matrix; 
public:
	Matrix() {
		cout << "Iveskite matricos matus\n";
		cin >> n >> m;
		matrix = new double* [n];
		for (size_t i = 0; i < n; i++)
			matrix[i] = new double[m];
		setNull();
	}
	// 
	Matrix(int nn, int mm) {
		n = nn;
		m = mm;
		matrix = new double* [n];
		for (size_t i = 0; i < n; i++)
			matrix[i] = new double[m];
		setNull();
	}
	// 
	~Matrix() {
		cout << "Destruktorius " << n << ' ' << m << endl; 
		for (size_t i = 0; i < n; i++)
			delete[] matrix[i];
		delete[] matrix;
	}
	// kopijuojantysis konstruktorius
	Matrix(const Matrix& mSource) {
		cout << "\nKopijavimas " << mSource.n << ' ' << 
mSource.m << endl; //kad matytumėt, kuris objektas kopijuojamas ir kiek objektų papildomai sukuriama bei vėliau sunaikinama destruktoriumi
		n = mSource.n;   //kopijuojami kintamieji statinėje 
		m = mSource.m;   //atmintyje
		matrix = new double* [n]; // skiriama dinaminė atmintis...
		for (size_t i = 0; i < n; i++)
			matrix[i] = new double[m];
		for (size_t i = 0; i < n; i++)    //...ir tik tada kopijuojama			for (size_t j = 0; j < m; j++)
				matrix[i][j] = mSource.matrix[i][j];
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
				cout << matrix[i][j] << "  ";
			cout << endl;
		}
	}
	//
	void transpose(Matrix mInitial) {
		// argumentas perduodamas reikšme 
		for (size_t i = 0; i < n; i++) {
			for (size_t j = 0; j < m; j++) {
				matrix[i][j] = mInitial.matrix[j][i];
			}
		}
	}
	//
	friend double minValue(Matrix); 
//
};
//
//
double minValue(Matrix m) { //draugiškos funkcijos realizacija
	//argumentas taip pat perduodamas reikšme
	double min = m.matrix[0][0]; 
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
	Matrix mInitial(n, m);
	//
	mInitial.getData();
	mInitial.showData("Pradine matrica");
	//
	Matrix mTransposed(m, n); 
	//
	mTransposed.transpose(mInitial);
	mTransposed.showData("Transponuota matrica");
	//
	cout << "Maziausias matricos elementas yra "
		<< minValue(mTransposed) << endl;
	//
}
