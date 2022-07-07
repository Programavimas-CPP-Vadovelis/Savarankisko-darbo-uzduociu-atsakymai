import <iostream>;
using std::cout;
using std::cin;
using std::endl;
//
int main() {
	int miestai[10];
	int msk; // miestų skaičius
	int bsk, anr, ask; // bendras gyventojų skaičius, antrojo pagal dydį miesto numeris ir jo gyventojų skaičius
	//
	cout << "Iveskite miestu skaiciu\n";
	cin >> msk;
	if (msk < 2) {
		cout << msk << " - netinkamas miestu skaicius. Stop\n";
		return -1;
	}
	cout << "Miestu yra " << msk << endl;
	cout << "Iveskite miestu gyventoju skaicius\n";
	for (size_t i = 0; i < msk; i++)
		cin >> miestai[i];
	cout << "Miesto Nr. ir gyventoju skaicius\n";
	for (size_t i = 0; i < msk; i++)
		cout << i + 1 << "  " << miestai[i] << endl;
	cout << endl;
	//
	bsk = 0.;
	int pnr = 0; // prielaidos: didžiausio miesto Nr.
	int psk = miestai[0]; // ir gyventojų skaičius
	//
	for (size_t i = 0; i < msk; i++) {
		bsk += miestai[i];
		if (psk < miestai[i]) {
			psk = miestai[i];
			pnr = i;
		}
	}
	//
	anr = 0; // prielaidos antram miestui
	ask = miestai[0];
	if (anr == pnr) {
		anr = 1;
		ask = miestai[1];
	}
	for (size_t i = 0; i < msk; i++) {
		if (i == pnr) continue;
		if (ask < miestai[i]) {
			ask = miestai[i];
			anr = i;
		}
	}
	cout << "Bendras gyventoju skaicius miestuose " << bsk << endl
	<< "Antrojo pagal gyventoju skaiciu miesto numeris " << anr + 1 << endl
	<< "jo gyventoju skaicius " << ask << endl;
}
