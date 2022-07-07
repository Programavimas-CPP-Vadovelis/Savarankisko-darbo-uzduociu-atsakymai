import <iostream>;
using std::cout;
using std::cin;
using std::endl;
//
//Sveiką dešimtainį skaičių į šešioliktainį keičiančios funkcijos prototipas
void DecimalToHexadecimal(unsigned int);
//
int main() {
unsigned  int nDesimtainisSkaitmuo = 0;
//
cout << "Iveskite desimtaini sveika skaiciu (Min = 1, Max = 4294967295): ";
cin >> nDesimtainisSkaitmuo;
DecimalToHexadecimal(nDesimtainisSkaitmuo);
//
}
// Funkcijos apibrėžimas
void DecimalToHexadecimal(unsigned int nDesimtainisSkaitmuo){
	unsigned  int nLiekana = 0;
	unsigned  int nDalmuo = 0;
	unsigned  int nLaikinasKintamasis = 0;
	char cSesioliktainisSkaitmuo[10];
	nDalmuo = nDesimtainisSkaitmuo;
	//
	int i = 1;
	while (nDalmuo != 0) {	// Ciklas kartojamas, kol dalmuo nėra lygus nuliui
        		nLaikinasKintamasis = nDalmuo % 16;// Skaičiuojama dalybos
// iš 16 liekana
		if (nLaikinasKintamasis < 10)
			//Dešimtainiai skaičiai ASCII lentelėje 
			nLaikinasKintamasis = nLaikinasKintamasis + 48;		
		else
			nLaikinasKintamasis = nLaikinasKintamasis + 55;
		//
		cSesioliktainisSkaitmuo[i++] = 
			static_cast<char>(nLaikinasKintamasis);
		nDalmuo = nDalmuo / 16;
	}
	//
	cout << "Desimtaini skaiciu: " << nDesimtainisSkaitmuo << " atitinka ";
	for (unsigned long int j = i - 1; j > 0; j--)
		cout << cSesioliktainisSkaitmuo[j];
	cout << " sesioliktainis skaicius \n";
}
