import <iostream>;
using std::cout;
using std::cin;
using std::endl;
//
void countSymbols(char*, int*);
//
int main() {
	//
	char pString[1001];    //eilutei
	int nSymbols[128] = { 0 }; //simbolių skaičiams
	//
	cout << "Iveskite eilute. Eilutes pabaigos simbolis - #.\n";
	cin.get(pString, 1000, '#');
	cout << "\nEilute: \n" << pString << endl << endl;
	//
	countSymbols(pString, nSymbols);
	//
	for (size_t i = 0; i < 128; i++) {
if (nSymbols[i] > 0) {
	if (i == 10) {
cout << "Simboliu 'Enter'"<< " eiluteje yra " << 
	nSymbols[i] << endl;
	}
	else if (i == 32) {
cout << "Simboliu 'space'"<< " eiluteje yra " << 
     	  nSymbols[i] << endl;
	}
	else {
cout << "Simboliu " << static_cast<char>(i)
		<< " eiluteje yra " << nSymbols[i] << endl;
	}
}
	}
	//
}
//
void countSymbols(char* p, int* n) {
	//
	while (*p) { //kol rodyklė nenukreipta į eilutės
		  //pabaigos simbolį '\0'
		for (size_t iASCII = 0; iASCII < 128; iASCII++) {
			if (*p == static_cast<char>(iASCII)) {
				n[iASCII] += 1;
				break;
			}
		}
		p++; //rodyklę perstumiame link kito simbolio
	}
}
