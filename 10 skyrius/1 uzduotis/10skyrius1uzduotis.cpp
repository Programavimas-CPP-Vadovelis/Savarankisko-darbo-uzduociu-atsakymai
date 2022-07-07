import <iostream>;
import <iomanip>;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
//
void function(double* array, int, double* v, double* min, double* max);
//
int main() {
	double* x{ nullptr };  //pradinis masyvas ir jo
	size_t n;               //matas
	double average, min, max; //rezultatams
	//
	cout << "Iveskite masyvo mata\n";
	cin >> n;
	if (n == 0) {
		cout << "Masyvo matas turi buti >=1. Stop\n";
		return -1;
	}
	cout << "Masyve yra " << n << " elementai\n";
	//
	x = new double[n]; //dinaminė atmintis masyvui
	//
	cout << "Iveskite " << n << " realius skaicius\n";
	for (size_t i = 0; i < n; i++)
		cin >> *(x + i);
	cout << "Ivesti skaiciai: \n";
	for (size_t i = 0; i < n; i++)
		cout << setw(8) << *(x + i);
	cout << endl << endl;
	//
	function(x, n, &average, &min, &max);
	//
	cout << "Rezultatai:\nMasyvo elementu vidurkis " << average
		<< "\nMaziausias elementas " << min
		<< "\nDidziausias elementas " << max << endl << endl;
	//
}
//
void function(double* x, int n, double* v, double* min, double* max) {
	*v = 0.;
	*min = *x;
	*max = *x;
	for (size_t i = 0; i < n; i++) {
		*v += *(x + i);
		if (*min > *(x + i)) *min = *(x + i);
		if (*max < *(x + i)) *max = *(x + i);
	}
	*v /= n;
}
