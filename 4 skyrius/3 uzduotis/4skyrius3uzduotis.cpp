import <iostream>;
import <iomanip>;
using std::cout;
using std::cin;
using std::endl;
//
int main() {
	double V[10];
	int n, n_intervale = 0;
	double a, b, s_ne_intervale = 0.;
	//
	cout << "Iveskite vektoriaus mata\n";
	cin >> n;
	if (n < 1 || n >10) {
		cout << n << "- netinkamas vektoriaus dydis. Stop\n";
		return -1;
	}
	cout << "Vektoriaus matas " << n << endl;
	cout << "Iveskite intervalo rezius a < b\n";
	cin >> a >> b;
	if (a > b) {
	     cout << "Netinkamas intervalas (" << a << ',' << b << "). Stop\n";
	     return -2;
	}
	cout << "Intervalo reziai: (" << a << ',' << b << ')' << endl;
	cout << "Iveskite vektoriaus elementus\n";
	for (size_t i = 0; i < n; i++)
		cin >> V[i];
	cout << "Vektoriaus elementai\n";
	for (size_t i = 0; i < n; i++)
		cout << std::setw(10) << std::setprecision(5) << V[i];
	cout << endl;
	//
	for (size_t i = 0; i < n; i++)
		if (V[i] > a && V[i] < b)
			n_intervale++;
		else
			s_ne_intervale += V[i];
	//
	cout << endl;
	cout << "Rezultatai:\n";
	cout << "Duotajame intervale yra " << n_intervale << " elementu\n";
	cout << "Elementu ne intervale suma yra " << s_ne_intervale << endl;
	//
}
