import <iostream>;
import <iomanip>;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
//
struct matrix {
	size_t n, m; //tikrieji matricos matai
	double a[10][10]; //matrica - iki 10x10
};

int main() {
	matrix a, b, r;

	/*
	   r =   a  *  b
	  nxm   n*k   k*m
	*/
	cout << "Iveskite pirmosios matricos matus\n";
	cin >> a.n >> a.m;
	cout << "Iveskite antrosios matricos stulpeliu skaiciu\n";
	cin >> b.m;
	if (a.n > 10 || a.m > 10 || b.m > 10) {
		cout << "Per dideli matricu matai. Stop\n";
		return -1;
	}
	cout << "Iveskite pirmaja matrica " << a.n << " x " << a.m << " eilutemis"
     << endl;
	for (size_t i = 0; i < a.n; i++)
		for (size_t j = 0; j < a.m; j++)
			cin >> a.a[i][j];
	cout << "Iveskite antraja matrica " << a.m << " x " << b.m << " eilutemis"
                << endl;
	for (size_t i = 0; i < a.m; i++)
		for (size_t j = 0; j < b.m; j++)
			cin >> b.a[i][j];
	cout << "Pirmoji dauginamoji matrica eilutemis:\n";
	for (size_t i = 0; i < a.n; i++) {
		for (size_t j = 0; j < a.m; j++)
			cout << setw(10) << a.a[i][j];
		cout << endl;
	}
	cout << "Antroji dauginamoji matrica eilutemis:\n";
	for (size_t i = 0; i < a.m; i++) {
		for (size_t j = 0; j < b.m; j++)
			cout << setw(10) << b.a[i][j];
		cout << endl;
	}
	//
	//
	for (size_t i = 0; i < a.n; i++) {
		for (size_t j = 0; j < a.m; j++) {
			r.a[i][j] = 0.; // skaliarinė sandauga - suma
			for (size_t l = 0; l < b.m; l++)
				r.a[i][j] += a.a[i][l] * b.a[l][j];
		}
	}
	//
	//
	cout << endl;
	cout << "Rezultatai:\n";
	cout << "Matricu sandauga eilutemis\n";
	for (size_t i = 0; i < a.n; i++) {
		for (size_t j = 0; j < b.m; j++)
			cout << setw(10) << r.a[i][j];
		cout << endl;
	}
	//
}
