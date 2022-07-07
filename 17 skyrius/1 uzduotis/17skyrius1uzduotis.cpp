import <iostream>;
using std::cout;
using std::cin;
using std::endl;
using std::bad_alloc;
//
template <typename type>
concept Integer = requires (type t) {
	t % 2;
};
//
template <Integer type>
class Matrix {
private:
	size_t n, m;   
	type** matrix; 
public:
	//
	class Error {
	public:
		size_t errorN, errorM; 
		Error(size_t eN, size_t eM) : errorN(eN), errorM(eM) { }
	};
	//
	// konstruktorius be argumentų
	Matrix() {
		cout << "\nKonstruktorius be argumentų: "; 
		cout << "iveskite matricos matus\n";
		cin >> n >> m;
		if (n < 1 || m < 1) throw Error(n, m); 
		matrix = new type * [n]; 
		for (size_t i = 0; i < n; i++) {
			matrix[i] = new type[m]; 
			if (matrix[i] == nullptr) {        
				bad_alloc ba;
				throw ba;     
			}
		}
		setNull();
	}
	// konstruktorius su argumentais
	Matrix(size_t nn, size_t mm) {
		cout << "\nKonstruktorius su argumentais: ";
		cout << "matricos matai " << nn << "  " << mm << endl; 
		if (nn < 1 || mm < 1) throw Error(nn, mm); 
		n = nn;
		m = mm;
		matrix = new type * [n];
		for (size_t i = 0; i < n; i++) {
			matrix[i] = new type[m];
			if (matrix[i] == nullptr) { 
				bad_alloc ba;
				throw ba;
			}
		}
		setNull();
	}
	// destruktorius
	~Matrix() {
		if (matrix != nullptr) {
			cout << "\nDestruktorius duomenims:\n";
			for (size_t i = 0; i < n; i++)
				for (size_t j = 0; j < m; j++)
				      cout << matrix[i][j] << "  ";
			cout << endl;
			//
			for (size_t i = 0; i < n; i++)
				delete[] matrix[i];
			delete[] matrix;
		}
	}
	// kopijos konstruktorius
	Matrix(const Matrix& mSource) {
		cout << "\nGilusis kopijavimas: kopijuojami duomenys \n"; 
		for (size_t i = 0; i < mSource.n; i++)
			for (size_t j = 0; j < mSource.m; j++)
				cout << mSource.matrix[i][j] << "  ";
		cout << endl;
		//
		n = mSource.n;
		m = mSource.m;
		matrix = new type * [n];
		for (size_t i = 0; i < n; i++) {
			matrix[i] = new type[m];
			if (matrix[i] == nullptr) { 
				bad_alloc ba;
				throw ba;
			}
		}
		for (size_t i = 0; i < n; i++)
			for (size_t j = 0; j < m; j++)
				matrix[i][j] = mSource.matrix[i][j];
	}
	// kreipties konstruktorius
	Matrix(Matrix&& mSource) {
		cout << "\nSeklusis kopijavimas: kopijuojami duomenys\n"; 
		for (size_t i = 0; i < mSource.n; i++)
			for (size_t j = 0; j < mSource.m; j++)
				cout<<mSource.matrix[i][j]<<"  ";
		cout << endl;
		//
		n = mSource.n;
		m = mSource.m;
		matrix = mSource.matrix;
		//
		mSource.matrix = nullptr;
	}
	// 
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
		cout << "\nMatricos matai: " << n << "  " << m << endl;
		cout << "Matricos elementai eilutemis\n";
		for (size_t i = 0; i < n; i++) {
			cout << i + 1 << "  eilute:\n";
			for (size_t j = 0; j < m; j++)
				cout << "  " << matrix[i][j] << "  ";
			cout << endl;
		}
	}
	//
	// metodas +
	Matrix operator+(const Matrix& a) {
		Matrix md(a.n, a.m); 
		for (size_t i = 0; i < n; i++) {
			for (size_t j = 0; j < m; j++) {
				md.matrix[i][j] = matrix[i][j] +
					a.matrix[i][j];
			}
		}
		return md;  
	}
	//
	// Prieskyra-kreiptis
	Matrix& operator=(Matrix&& mSource) noexcept {
		cout << "\nPrieskyros-kreipties operatorius duomenims\n"; 
		for (size_t i = 0; i < mSource.n; i++)
			for (size_t j = 0; j < mSource.m; j++)
				cout<<mSource.matrix[i][j]<<"  ";
		cout << endl;
		if (this != &mSource) {
			for (size_t i = 0; i < n; i++)
				delete[] matrix[i];
			delete[] matrix;
			//
			n = mSource.n; 
m = mSource.m;
			matrix = mSource.matrix; 
			//
			mSource.n = 0; 
mSource.m = 0;
			mSource.matrix = nullptr;
		}
		return *this;
	}
	// 
};
//
//
int main() {
	try {
		size_t n, m; 
		//
		cout << "Iveskite pradines matricos matus\n";
		cin >> n >> m;
		//
		Matrix <int>  a1(n, m), a2(n, m); // pradinės matricos
		Matrix<int>  r(n, m);             // rezultato matrica
		//
		a1.getData();
		a1.showData("Pirma pradine matrica");
		a2.getData();
		a2.showData("Antra pradine matrica");
		//
		r = a1 + a2;
		//
		r.showData("Rezultato matrica");
		//
	}
	catch (bad_alloc& ba) {
		cout << "Nepavyko paskirti dinamines atminties\n"
		     << "Informacija apie klaida: \n"
		     << ba.what() << endl;
	}
	catch (Matrix<int>::Error& e) {
		cout << "Klaidingi matricos matai: "
		     << e.errorN << " x " << e.errorM << endl;
	}
	//
}
