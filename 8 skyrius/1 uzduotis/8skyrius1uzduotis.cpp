import <iostream>;
import <fstream>;
import <iomanip>;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
//
int main() {
	int M[10][10];
	int m;
	//
	cout << "Iveskite matricos mata\n";
	cin >> m;
	if (m < 1 || m >10) {
		cout << m << "- netinkamas matricos dydis. Stop\n";
		return -1;
	}
	cout << "Matricos matas " << m << endl;
	// 
	int d;
	for (size_t  i = 0; i < m; i++) {
		if ((i + 1) % 2 != 0) // nelyginė eilutė
			d = 0;
		else                 // lyginė eilutė
			d = -m - 1;
		for (size_t  j = 0; j < m; j++)
			M[i][j] = (j + 1 + d) * (j + 1 + d);
	}
	//
	cout << "Suformuota matrica\n";
	for (size_t  i = 0; i < m; i++) {
		for (size_t  j = 0; j < m; j++)
			cout << setw(5) << M[i][j];
		cout << endl;
	}
	// 
	char fv[16]; // failo vardui iki 15 simbolių
	cout << "Iveskite rezultatu failo varda iki 15 simboliu\n";
	cin >> setw(15) >> fv;
	cout << "Rezultatai bus faile  " << fv << endl;
	std::ofstream os(fv);
	for (size_t  i = 0; i < m; i++) {
		for (size_t  j = 0; j < m; j++)
			os << setw(5) << M[i][j];
		os << endl;
	}
	os.close();
	//
}
