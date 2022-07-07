import <iostream>;
using std::cout;
using std::cin;
using std::endl;
// Vieno kintamojo funkcijos, kurios grafikas bus piešiamas, prototipas
double function(int);
//
int main() {
int nUpperBound, nArgumentIncrementValue, iFunctionValue;
cout << "Funkcijos grafikas braizomas intervale [0, x] laipsniu\n";
cout << "Iveskite intervalo riba x sveikuoju skaiciumi, laipsniais):\n";
cin >> nUpperBound;
cout << "Iveskite argumento kitimo zingsni sveikuoju skaiciumi, laipsniais.\n";
cout << "Rekomenduojamas zingsnis - 15 laipsniu\n";
cin >> nArgumentIncrementValue;
cout << "\n\n\n";
for (size_t iArgument = 0; iArgument <= nUpperBound; 
iArgument += nArgumentIncrementValue){
//Funkcijos grafikas teikiamas intervale nuo -10 iki 10 simbolių
//Standartinė funkcija „round“ skiriama reikšmių apvalinimui
//Senesnėse C++ kompiliatoriaus versijose taikykite funkciją "floor"

	iFunctionValue = static_cast<int>(round(10. * function(iArgument)));

	for (size_t j = 0; j <= 20 + iFunctionValue; j++) cout << " ";
	cout << "*" << endl;
}
}
//
double function(int iFunctionArgument)
{
	double dValueInRadians = static_cast<double>(iFunctionArgument) * 3.14159265358979 / 180.;
	double dFunctionValue = sin(dValueInRadians);
	return dFunctionValue;
}
