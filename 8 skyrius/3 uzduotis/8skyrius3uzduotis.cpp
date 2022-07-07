import <iostream>;
import <fstream>;
import <iomanip>;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
//
int main() {
	//
	char ifv[16], rfv[16]; // duomenų ir rezultatų failų vardams
	int seka[100],
		v[100]; // masyvas vėliavėlėms 0/1
 // 
	cout << "Iveskite duomenu failo varda iki 15 simboliu\n";
	cin >> setw(15) >> ifv;
	cout << "Duomenu seka yra faile " << ifv << endl;
	cout << "Iveskite rezultatu failo varda iki 15 simboliu\n";
	cin >> setw(15) >> rfv;
	cout << "Rezultatai bus faile  " << rfv << endl;
	//
	//
	std::ifstream is(ifv);
	std::ofstream os(rfv);
	if (is.fail()) {
		cout << "Nera duomenu sekos failo. Stop\n";
		return -1;
	}
	//
	//
	for (size_t i = 0; i < 100; i++) v[i] = 0;
	//
	int n = -1;
	while (!is.eof())  // skaityti iki pabaigos
		is >> seka[++n];
	cout << "Duomenu seka\n";
	for (size_t i = 0; i < n; i++)
		cout << setw(5) << seka[i];
	cout << endl;
	//
	//
	cout << "Vyraujantys sekos elementai:\n ";
	os << "Vyraujantys sekos elementai:\n";
	int k;
	int n3 = n / 3;
	for (size_t i = 0; i < n - 1; i++) {
		k = 1; // kiek yra tokių elementų
		for (size_t j = i + 1; j < n; j++) {
			if (v[i] != 1 && seka[i] == seka[j]) {
				k++;
				v[j] = 1; // kad pakartotinai 
				   // neskaičiuotume tų pat elementų
			}
		}
		if (k >= n3) {
			cout << setw(5) << seka[i];
			os << setw(5) << seka[i];
		}
	}
	cout << endl;
	os << endl;
	//
	is.close();
	os.close();
	//
}
