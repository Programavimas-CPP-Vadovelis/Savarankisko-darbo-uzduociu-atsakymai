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
	char s;  // simbolis, kurį nuskaitysime iš failo
	//
	char ifv[16], rfv[16]; // duomenų ir rezultatų failų vardams
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
	while (is.get(s))
		if (s != ' ') os << s;
	//
	is.close();
	os.close();
	//
}
