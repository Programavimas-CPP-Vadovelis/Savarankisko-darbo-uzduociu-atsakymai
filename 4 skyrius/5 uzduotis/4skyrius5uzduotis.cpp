import <iostream>;
import <iomanip>;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
//
int main() {
	int V[20];
	int n;
	//
	cout << "Iveskite vektoriaus mata\n";
	cin >> n;
	if (n < 4 || n >20) {
		cout << n << " - netinkamas vektoriaus matas. Stop\n";
		return -1;
	}
	cout << "Vektoriaus matas  " << n << endl;
	cout << "Iveskite vektoriaus elementus\n";
	for (size_t i = 0; i < n; i++) {
		cin >> V[i];
		if (V[i] < 1 || V[i]>4) {
		    cout << V[i]<<" - netinkama elemento reiksme. Stop\n";
		    return -2;
		}
	}
	cout << "Vektoriaus elementai:\n";
	for (size_t i = 0; i < n; i++)
		cout << setw(3) << V[i];
	cout << endl;
	//
	//
	int ipr = 0, // indeksas paskutiniam sutvarkytos sekos elementui žymėti
		laik;      // laikina ląstelė elementų sukeitimui
	int kgl = n / 4;  // sveikaskaitinė dalyba!- kiek ketvertukų telpa į seką
	bool v; // vėliavėlė rūšiavimui nutraukti, kai nebėra pilnos sekos 1,2,3,4
	for (size_t k = 0; k <= kgl; k++) { // ciklas per visus ketvirtukus
		v = true;
		for (size_t j = 1; j < 5; j++) { // ciklas 1,2,3,4
		    for (size_t i = ipr; i < n; i++) { // ciklas per dar nesutvarkytą sekos dalį
			    if (V[i] == j) { // taip: sukeisti rastąjį elementą su ipr'uoju
			       laik = V[i]; V[i] = V[ipr]; V[ipr] = laik;
			       ipr++;
			       v = false;
			       break; // pereiti prie kitos j reikšmės
			    }
		    }
		    if (v) break; // - nebebuvo pilnos sekos 1,2,3,4 - baigti rūšiavimą
		}
	}
	//
	//
	cout << endl;
	cout << "Rezultatai:\n";
	cout << "Isrusiuotas vektorius\n";
	for (size_t i = 0; i < n; i++)
		cout << setw(3) << V[i];
	cout << endl;
	//
}
