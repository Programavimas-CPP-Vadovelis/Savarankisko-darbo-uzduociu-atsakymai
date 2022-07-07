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
	{ }
	CommonFraction(int s, int ip, int n, int d) :
	sign(s), intPart(ip), numerator(n), denominator(d) {
if (abs(sign) != 1) {
	cout << "Blogai ivestas trupmenos zenklas. Stop\n";
	exit(-1); // return konstruktoriuje negalimas
}
if (numerator < 0 || denominator < 0) {
   cout << "Skaitiklis ir vardiklis - tik neneigiami. Stop\n";
exit(-2);
}
if (numerator != 0 && denominator == 0) {
   cout << "Nenulineje trupmenineje dalyje vardiklis != 0. Stop\n";
exit(-3);
}
}
	~CommonFraction() {}
public:	 //metodu prototipai
	void printFraction(const char[]);
	void getFraction();
	void addition(CommonFraction, CommonFraction);
	void subtraction(CommonFraction, CommonFraction);
	void multiplication(CommonFraction, CommonFraction);
	void division(CommonFraction, CommonFraction);
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
	r.addition(f1, f2);
	r.printFraction("Sudeties rezultatas: ");
	//
	r.subtraction(f1, f2);
	r.printFraction("Atimties rezultatas: ");
	//
	r.multiplication(f1, f2);
	r.printFraction("Daugybos rezultatas: ");
	//
	r.division(f1, f2);
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
		exit(-4);
	}
	if (denominator == 0) {
		cout << "Blogai ivestas trupmenos vardiklis. Stop\n";
		exit(-5);
	}
	if (numerator != 0 && denominator == 0) {
	   cout << "Nenulineje trupmenineje dalyje vardiklis != 0. Stop\n";		 	exit(-6);
	}
}
//
void CommonFraction::addition(CommonFraction f1, CommonFraction f2) {

	// r = f1 + f2

	f1.numerator = f1.sign * (f1.numerator + f1.intPart * f1.denominator);
	f2.numerator = f2.sign * (f2.numerator + f2.intPart * f2.denominator);
	denominator = f1.denominator * f2.denominator;
	numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
	//
	sign = +1;
	if (numerator < 0) {
		sign = -1;
		numerator *= -1;
	}
	intPart = 0;
	if (numerator > denominator) {
		intPart = numerator / denominator; //sveikaskaitė dalyba!
		numerator = numerator % denominator;
	}
	//gal trupmena dar prastinasi?	
	for (size_t i = numerator; i >= 2; i--) {
		if (numerator % i == 0 && denominator % i == 0) {
			numerator /= i;
			denominator /= i;
		}
	}
}

void CommonFraction::subtraction(CommonFraction f1, CommonFraction f2) {

	// r = f1 - f2

	f1.numerator = f1.sign * (f1.numerator + f1.intPart * f1.denominator);
	f2.numerator = f2.sign * (f2.numerator + f2.intPart * f2.denominator);
	denominator = f1.denominator * f2.denominator;
	numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
	//
	sign = +1;
	if (numerator < 0) {
		sign = -1;
		numerator *= -1;
	}
	intPart = 0;
	if (numerator > denominator) {
		intPart = numerator / denominator; //sveikaskaitė dalyba!
		numerator = numerator % denominator;
	}
	//gal trupmena dar prastinasi?	
	for (size_t i = numerator; i >= 2; i--) {
		if (numerator % i == 0 && denominator % i == 0) {
			numerator /= i;
			denominator /= i;
		}
	}
}

void CommonFraction::multiplication(CommonFraction f1, CommonFraction f2) {

	// r = f1 * f2

	f1.numerator = f1.sign * (f1.numerator + f1.intPart * f1.denominator);
	f2.numerator = f2.sign * (f2.numerator + f2.intPart * f2.denominator);
	numerator = f1.numerator * f2.numerator;
	denominator = f1.denominator * f2.denominator;
	//
	sign = +1;
	if (numerator < 0) {
		sign = -1;
		numerator *= -1;
	}
	intPart = 0;
	if (numerator > denominator) {
		intPart = numerator / denominator; //sveikaskaitė dalyba!
		numerator = numerator % denominator;
	}
	//gal trupmena dar prastinasi?	
	for (size_t i = numerator; i >= 2; i--) {
		if (numerator % i == 0 && denominator % i == 0) {
			numerator /= i;
			denominator /= i;
		}
	}
}

void CommonFraction::division(CommonFraction f1, CommonFraction f2) {

	// r = f1 / f2

	if (f2.intPart == 0 && f2.numerator == 0) {
		cout << "Dalyba is nulio. Stop\n";
		f2.printFraction("Ivesta trupmena: ");
		exit(-4);
	}
	//
	f1.numerator = f1.sign * (f1.numerator + f1.intPart * f1.denominator);
	f2.numerator = f2.sign * (f2.numerator + f2.intPart * f2.denominator);
	numerator = f1.numerator * f2.denominator;
	denominator = f1.denominator * f2.numerator;
	//
	sign = +1;
	if (numerator < 0 && denominator>0 || numerator > 0 && denominator < 0)
		sign = -1;
	denominator = abs(denominator);
	numerator = abs(numerator);
	//
	intPart = 0;
	if (numerator > denominator) {
		intPart = numerator / denominator; //sveikaskaitė dalyba!
		numerator = numerator % denominator;
	}
	//gal trupmena dar prastinasi?	
	for (size_t i = numerator; i >= 2; i--) {
		if (numerator % i == 0 && denominator % i == 0) {
			numerator /= i;
			denominator /= i;
		}
	}
}
