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
	char ifv1[16], ifv2[16], rfv[16]; // duomenų ir rezultatų failų vardams
	int seka1[100], seka2[100];
	// 
	cout << "Iveskite duomenu failu vardus iki 15 simboliu\n";
	cin >> setw(15) >> ifv1 >> ifv2;
	cout << "Pirmoji seka yra faile " << ifv1 << endl;
	cout << "Antroji seka yra faile " << ifv2 << endl;
	cout << "Iveskite rezultatu failo varda iki 15 simboliu\n";
	cin >> setw(15) >> rfv;
	cout << "Rezultatai bus faile  " << rfv << endl;
	//
	//
	std::ifstream is1(ifv1), is2(ifv2);
	std::ofstream os(rfv);
	if (is1.fail()) {
		cout << "Nera pirmosios sekos failo. Stop\n";
		return -1;
	}
	if (is2.fail()) {
		cout << "Nera antrosios sekos failo. Stop\n";
		return -2;
	}
	//
	//
	int i1 = -1; // masyvo pirmai sekai saugoti indeksas
	int i2 = -1; // antrai sekai
	//
	while (!is1.eof())  // skaityti iki pabaigos
		is1 >> seka1[++i1];
	cout << "Pirmoji seka\n";
	for (size_t i = 0; i < i1; i++)
		cout << setw(5) << seka1[i];
	cout << endl;
	//
	while (!is2.eof())
		is2 >> seka2[++i2];
	cout << "Antroji seka\n";
	for (size_t i = 0; i < i2; i++)
		cout << setw(5) << seka2[i];
	cout << endl;
	//
	//
	cout << "Rezultatai yra faile " << rfv << endl;
	os << "Pasikartojantys seku elementai:\n";
	for (size_t i = 0; i < i1; i++) {
		for (size_t j = 0; j < i2; j++)
			if (seka1[i] == seka2[j]) {
				os << setw(5) << seka1[i];
				break;
			}
	}
	os << endl;
	//
	is1.close();
	is2.close();
	os.close();
	//
}
