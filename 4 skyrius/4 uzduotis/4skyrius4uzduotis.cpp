import <iostream>;
import <format>;
using std::cout;
using std::cin;
using std::endl;
using std::format;
//
int main() {
	double a[10][10], b[10][10], r[10][10];
	int n, m, k;
	/*
	   r =   a  *  b
	  nxm   n*k   k*m
	*/
	cout << "Iveskite pirmosios matricos matus\n";
	cin >> n >> k;
	cout << "Iveskite antrosios matricos stulpeliu skaiciu\n";
	cin >> m;
	if (n > 10 || m > 10 || k > 10) {
		cout << "Per dideli matricu matai. Stop\n";
		return -1;
	}
	cout << format("Iveskite pirmaja matrica {} x {} eilutemis\n", n, k);
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < k; j++)
			cin >> a[i][j];
	cout << format("Iveskite antraja matrica {} x {} eilutemis\n", k, m);
	for (size_t i = 0; i < k; i++)
		for (size_t j = 0; j < m; j++)
			cin >> b[i][j];
	cout << "\nPirmoji dauginamoji matrica eilutemis:\n";
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < k; j++)
			cout << format("{:#10.2f}", a[i][j]);
		cout << endl;
	}
	cout << "\nAntroji dauginamoji matrica eilutemis:\n";
	for (size_t i = 0; i < k; i++) {
		for (size_t j = 0; j < m; j++)
			cout << format("{:#10.2f}", b[i][j]);
		cout << endl;
	}
	//
	//
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			r[i][j] = 0.; // skaliarinė sandauga - suma
			for (size_t l = 0; l < k; l++)
				r[i][j] += a[i][l] * b[l][j];
		}
	}
	//
	cout << "\nRezultatai:\n";
	cout << "Matricu sandauga eilutemis\n";
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++)
			cout << format("{:#10.2f}", r[i][j]);
		cout << endl;
	}
	//
}
