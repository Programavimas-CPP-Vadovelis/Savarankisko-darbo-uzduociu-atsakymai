import <iostream>;
using std::cout;
using std::cin;
using std::endl;
using std::bad_alloc;
//
template <typename type> // koncepcijos Integer apibrėžimas
concept Integer = requires (type t) {
	t % 2; // tik sveikieji duomenys palaiko %
};
//
template <Integer type> // „type“ privalo tenkinti Integer koncepciją
class Matrix {
private:
	size_t n, m;   // matricos matai
	type** matrix; // matrica
public:
	//klaidos klasė
	class Error {
	public:
		size_t errorN, errorM; //klaidingiems matams
		Error(size_t eN, size_t eM) : errorN(eN), errorM(eM) { }
	};
	//
	// konstruktorius be argumentų
	Matrix() {
		cout << "Iveskite matricos matus\n";
		cin >> n >> m;
		if (n < 1 || m < 1) throw Error(n, m); //blogi matricos matai
		matrix = new type * [n]; //
		for (size_t i = 0; i < n; i++) {
			matrix[i] = new type[m]; //jei nepavyks paskirti
			//atminties - rodyklei paskirti nulinę reikšmę
			if (matrix[i] == nullptr) { //jei įvyko klaida -        
				bad_alloc ba;
				throw ba;     //...sukelti bad_alloc
  					  // išimtį
			}
		}
		setNull();
	}
	// konstruktorius su argumentais
	Matrix(size_t nn, size_t mm) {
		if (nn < 1 || mm < 1) throw Error(nn, mm); //blogi matai
		n = nn;
		m = mm;
		matrix = new type * [n];
		for (size_t i = 0; i < n; i++) {
			matrix[i] = new type[m];
			if (matrix[i] == nullptr) { //kaip ir anksčiau –
					    // atminties klaidai
				bad_alloc ba;
				throw ba;
			}
		}
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
		matrix = new type * [n];
		for (size_t i = 0; i < n; i++) {
			matrix[i] = new type[m];
			if (matrix[i] == nullptr) { //atminties klaidai
				bad_alloc ba;
				throw ba;
			}
		}
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
				cout << "  " << matrix[i][j] << "  ";
			cout << endl;
		}
	}
	//
	Matrix* operator+(Matrix a) {
		Matrix* md = new Matrix(n, m); // galimą atminties klaidą	kontroliuoja pats konstruktorius
		for (size_t i = 0; i < n; i++) {
			for (size_t j = 0; j < m; j++) {
				(*md).matrix[i][j] = matrix[i][j] +
					a.matrix[i][j];
			}
		}
		return md;  // grąžinamas lokalus duomuo!- tačiau
			// jis dinaminis - todėl gyvuos iki pat delete
// operacijos
	}
	//
};
//
//
int main() {
	try {
		size_t n, m; // pradinių matricų matai
		//
		cout << "Iveskite pradines matricos matus\n";
		cin >> n >> m;
		//
		Matrix <int>  a1(n, m), a2(n, m); // pradinės matricos
		Matrix <int>* r{ nullptr }; // rodyklė į rezultato matricą
		//
		//Matrix <double> a3(n, m); // klaida: double formatas nepalaiko % operacijos
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
