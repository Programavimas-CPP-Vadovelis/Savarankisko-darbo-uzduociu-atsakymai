import <iostream>;
using std::cout;
using std::cin;
using std::endl;
//
int main() {
	double s1, s2, skirtumas;
	double s1ms2;
	//
	cout << "Iveskite du realius skaicius\n";
	cin >> s1 >> s2;
	cout << "Ivesti skaiciai: " << s1 << "  " << s2 << endl;
	cout << "Iveskite pirmojo ir antrojo skaiciu skirtuma\n";
	cin >> skirtumas;
	//
	s1ms2 = s1 - s2;
	if (abs(skirtumas - s1ms2) < 1.e-3)
		cout << "Atsakymas yra teisingas\n";
	else
		cout << "Atsakymas yra neteisingas\n";
	//
}
