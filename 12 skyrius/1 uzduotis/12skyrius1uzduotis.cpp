import <iostream>;
using std::cout;
using std::cin;
using std::endl;
//
class CommonFraction {
private:
	int sign;        //trupmenos ženklas
	int intPart;     //sveikoji trupmenos dalis
	int numerator,   //trupmenos skaitiklis
		denominator; //ir vardiklis
public:  //konstruktoriai ir destruktorius
	CommonFraction() : sign(1), intPart(0), numerator(0), denominator(1)
	{}
	CommonFraction(int s, int ip, int n, int d) :
		sign(s), intPart(ip), numerator(n), denominator(d) {
		if (abs(sign) != 1) {
			cout << "Blogai ivestas trupmenos zenklas. Stop\n";
			exit(-1);
		}
	}
	~CommonFraction() {}
public:	 //metodu prototipai
	void printFraction(const char[]);
	void getFraction();
	CommonFraction operator+ (CommonFraction);
	CommonFraction operator- (CommonFraction);
	CommonFraction operator* (CommonFraction);
	CommonFraction operator/ (CommonFraction);
};
//
int main()
{
	CommonFraction f1, f2, //pradinės trupmenos
		r;        //rezultato trupmena
//
	f1.getFraction();
	f1.printFraction("Pirmoji trupmena: ");
	f2.getFraction();
	f2.printFraction("Antroji trupmena: ");
	cout << endl;
	//
	r = f1 + f2;
	r.printFraction("Sudeties rezultatas: ");
	//
	r = f1 - f2;
	r.printFraction("Atimties rezultatas: ");
	//
	r = f1 * f2;
	r.printFraction("Daugybos rezultatas: ");
	//
	r = f1 / f2;
	r.printFraction("Dalybos rezultatas:  ");
	//
}
//
// Metodu realizacijos
//
void CommonFraction::printFraction(const char s[]) {
	cout << s;
	if (sign < 0)
		cout << '-';
	if (intPart != 0)
		cout << intPart;
	if (numerator != 0)
		cout << ' ' << numerator << "/" << denominator;
	if (intPart == 0 && numerator == 0)
		cout << '0';
	cout << endl;
}
//
void CommonFraction::getFraction() {
	cout << "Trupmena iveskite sveikaisiais skaiciais\n";
	cout << "Trupmenos zenkla iveskite taip: -1/+1\n\n";
	cout << "Iveskite zenkla, sveikaja dali, skaitikli ir vardikli:\n";
	//
	cin >> sign >> intPart >> numerator >> denominator;
	//
	if (abs(sign) != 1) {
		cout << "Blogai ivestas trupmenos zenklas. Stop\n";
		exit(-2);
	}
	if (denominator == 0) {
		cout << "Blogai ivestas trupmenos vardiklis. Stop\n";
		exit(-3);
	}

}
//
CommonFraction CommonFraction::operator+(CommonFraction f) {

	// r = <darbinis objektas> + f
	// „f“ perduodame reikšme, kad metode objektui padaryti pokyčiai
	// nepaveiktų atitinkamo programos objekto laukų. 
// Klasės laukai nėra dinaminiai,
	// todėl kopijuojantįjį konstruktorių perrašyti nebūtina

f.numerator = f.sign * (f.numerator + f.intPart * f.denominator);
//objekto-argumento
	int dnumerator = sign * (numerator + intPart * denominator); 
//darbinio objekto
	int rdenominator = f.denominator * denominator;
                 	//rezultato
	int rnumerator = f.numerator * denominator + dnumerator * f.denominator;
//rezultato
	//
	int rsign = +1;  //rezultato
	if (rnumerator < 0) {
		rsign = -1;
		rnumerator *= -1;
	}
	int rintPart = 0;  //rezultato
	if (rnumerator > rdenominator) {
		rintPart = rnumerator / rdenominator; //sveikaskaitė dalyba!
		rnumerator = rnumerator % rdenominator;
	}
	//gal trupmena dar prastinasi?	
	for (size_t i = rnumerator; i >= 2; i--) {
		if (rnumerator % i == 0 && rdenominator % i == 0) {
			rnumerator /= i;
			rdenominator /= i;
		}
	}
	return CommonFraction(rsign, rintPart, rnumerator, rdenominator);
}

CommonFraction CommonFraction::operator-(CommonFraction f) {

	// r = <darbinis objektas> - f  

	int dnumerator = sign * (numerator + intPart * denominator);
	f.numerator = f.sign * (f.numerator + f.intPart * f.denominator);
	int rdenominator = denominator * f.denominator;
	int rnumerator = dnumerator * f.denominator - f.numerator * denominator;
	//
	int rsign = +1;
	if (rnumerator < 0) {
		rsign = -1;
		rnumerator *= -1;
	}
	int rintPart = 0;
	if (rnumerator > rdenominator) {
		rintPart = rnumerator / rdenominator; //sveikaskaitė dalyba!
		rnumerator = rnumerator % rdenominator;
	}
	//gal trupmena dar prastinasi?	
	for (size_t i = rnumerator; i >= 2; i--) {
		if (rnumerator % i == 0 && rdenominator % i == 0) {
			rnumerator /= i;
			rdenominator /= i;
		}
	}
	return CommonFraction(rsign, rintPart, rnumerator, rdenominator);
}

CommonFraction CommonFraction::operator*(CommonFraction f) {

	// r = <darbinis objektas> * f

	int dnumerator = sign * (numerator + intPart * denominator);
	f.numerator = f.sign * (f.numerator + f.intPart * f.denominator);
	int rnumerator = dnumerator * f.numerator;
	int rdenominator = denominator * f.denominator;
	//
	int rsign = +1;
	if (rnumerator < 0) {
		rsign = -1;
		rnumerator *= -1;
	}
	int rintPart = 0;
	if (rnumerator > rdenominator) {
		rintPart = rnumerator / rdenominator; //sveikaskaitė dalyba!
		rnumerator = rnumerator % rdenominator;
	}
	//gal trupmena dar prastinasi?	
	for (size_t i = rnumerator; i >= 2; i--) {
		if (rnumerator % i == 0 && rdenominator % i == 0) {
			rnumerator /= i;
			rdenominator /= i;
		}
	}
	return CommonFraction(rsign, rintPart, rnumerator, rdenominator);
}

CommonFraction CommonFraction::operator/(CommonFraction f) {

	// r = <darbinis objektas> / f

	if (f.intPart == 0 && f.numerator == 0) {
		cout << "Dalyba is nulio. Stop\n";
		f.printFraction("Ivesta trupmena: ");
		exit(-4);
	}
	//
	int dnumerator = sign * (numerator + intPart * denominator);
	f.numerator = f.sign * (f.numerator + f.intPart * f.denominator);
	int rnumerator = dnumerator * f.denominator;
	int rdenominator = denominator * f.numerator;
	//
	int rsign = +1;
	if (rnumerator < 0 && rdenominator>0 || rnumerator > 0 && rdenominator < 0)
		rsign = -1;
	rdenominator = abs(rdenominator);
	rnumerator = abs(rnumerator);
	//
	int rintPart = 0;
	if (rnumerator > rdenominator) {
		rintPart = rnumerator / rdenominator; //sveikaskaitė dalyba!
		rnumerator = rnumerator % rdenominator;
	}
	//gal trupmena dar prastinasi?	
	for (size_t i = rnumerator; i >= 2; i--) {
		if (rnumerator % i == 0 && rdenominator % i == 0) {
			rnumerator /= i;
			rdenominator /= i;
		}
	}
	return CommonFraction(rsign, rintPart, rnumerator, rdenominator);
}
