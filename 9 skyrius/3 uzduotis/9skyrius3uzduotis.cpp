import <iostream>;
import <fstream>;
import <iomanip>;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
//
struct CommonFraction {
	int sign;        //trupmenos ženklas
	int intPart;     //sveikoji trupmenos dalis
	int numerator,   //trupmenos skaitiklis
		denominator; //ir vardiklis
};
//funkcijų sudėčiai, atimčiai, daugybai, dalybai ir...
CommonFraction addition(CommonFraction, CommonFraction);
CommonFraction subtraction(CommonFraction, CommonFraction);
CommonFraction multiplication(CommonFraction, CommonFraction);
CommonFraction division(CommonFraction, CommonFraction);
//...spausdinimui prototipai
void printFraction(const char[], CommonFraction);

int main() {
	CommonFraction f1, f2; //pradinės trupmenos
	//
	cout << "Trupmenas iveskite sveikaisiais skaiciais\n";
	cout << "Trupmenos zenkla iveskite taip: -1/+1\n\n";
	cout << "Iveskite pirmaja trupmena:\n";
	//
	cin >> f1.sign >> f1.intPart >> f1.numerator >> f1.denominator;
	cout << "Iveskite antraja trupmena:\n";
	cin >> f2.sign >> f2.intPart >> f2.numerator >> f2.denominator;
	if (abs(f1.sign) != 1 || abs(f2.sign) != 1) {
		cout << "Blogai ivestas trupmenos zenklas. Stop\n";
		return -1;
	}
	if (f1.denominator == 0 || f2.denominator == 0) {
		cout << "Blogai ivestas trupmenos vardiklis. Stop\n";
		return -2;
	}
	if (f1.numerator < 0 || f1.denominator < 0 || f2.numerator < 0 ||
    f2.denominator < 0) {
		cout << "Skaitiklis ir vardiklis - tik neneigiami. Stop\n";
		return -3;
	}
	if (f2.intPart == 0 && f2.numerator == 0) {
		cout << "Dalyba is nulines antrosios trupmenos. Stop\n";
		printFraction("Ivesta trupmena: ", f2);
		return -4;
	}
	//
	printFraction("Pirmoji trupmena ", f1);
	printFraction("Antroji trupmena ", f2);
	cout << endl;
	//
	printFraction("Sudeties rezultatas: ", addition(f1, f2));
	printFraction("Atimties rezultatas: ", subtraction(f1, f2));
	printFraction("Daugybos rezultatas: ", multiplication(f1, f2));
	printFraction("Dalybos rezultatas:  ", division(f1, f2));
	//
}

void printFraction(const char s[], CommonFraction f) {
	cout << s;
	if (f.sign < 0)
		cout << '-';
	if (f.intPart != 0)
		cout << f.intPart;
	if (f.numerator != 0)
		cout << ' ' << f.numerator << "/" << f.denominator;
	if (f.intPart == 0 && f.numerator == 0)
		cout << '0';
	cout << endl;
}

CommonFraction addition(CommonFraction f1, CommonFraction f2) {

	// r = f1 + f2

	CommonFraction r;
	//
	f1.numerator = f1.sign * (f1.numerator + f1.intPart * f1.denominator);
	f2.numerator = f2.sign * (f2.numerator + f2.intPart * f2.denominator);
	r.denominator = f1.denominator * f2.denominator;
	r.numerator = f1.numerator * f2.denominator + f2.numerator * 
						f1.denominator;
	//
	r.sign = +1;
	if (r.numerator < 0) {
		r.sign = -1;
		r.numerator *= -1;
	}
	r.intPart = 0;
	if (r.numerator > r.denominator) {
		r.intPart = r.numerator / r.denominator; //sveikaskaitė dalyba!
		r.numerator = r.numerator % r.denominator;
	}
	//gal trupmena dar prastinasi?	
	for (size_t i = r.numerator; i >= 2; i--) {
		if (r.numerator % i == 0 && r.denominator % i == 0) {
			r.numerator /= i;
			r.denominator /= i;
		}
	}
	return r;
}

CommonFraction subtraction(CommonFraction f1, CommonFraction f2) {

	// r = f1 - f2

	CommonFraction r;
	//
	f1.numerator = f1.sign * (f1.numerator + f1.intPart * f1.denominator);
	f2.numerator = f2.sign * (f2.numerator + f2.intPart * f2.denominator);
	r.denominator = f1.denominator * f2.denominator;
	r.numerator = f1.numerator * f2.denominator - f2.numerator * 
						f1.denominator;
	//
	r.sign = +1;
	if (r.numerator < 0) {
		r.sign = -1;
		r.numerator *= -1;
	}
	r.intPart = 0;
	if (r.numerator > r.denominator) {
		r.intPart = r.numerator / r.denominator; //sveikaskaitė dalyba!
		r.numerator = r.numerator % r.denominator;
	}
	//gal trupmena dar prastinasi?	
	for (size_t i = r.numerator; i >= 2; i--) {
		if (r.numerator % i == 0 && r.denominator % i == 0) {
			r.numerator /= i;
			r.denominator /= i;
		}
	}
	return r;
}

CommonFraction multiplication(CommonFraction f1, CommonFraction f2) {

	// r = f1 * f2

	CommonFraction r;
	//
	f1.numerator = f1.sign * (f1.numerator + f1.intPart * f1.denominator);
	f2.numerator = f2.sign * (f2.numerator + f2.intPart * f2.denominator);
	r.numerator = f1.numerator * f2.numerator;
	r.denominator = f1.denominator * f2.denominator;
	//
	r.sign = +1;
	if (r.numerator < 0) {
		r.sign = -1;
		r.numerator *= -1;
	}
	r.intPart = 0;
	if (r.numerator > r.denominator) {
		r.intPart = r.numerator / r.denominator; //sveikaskaitė dalyba!
		r.numerator = r.numerator % r.denominator;
	}
	//gal trupmena dar prastinasi?	
	for (size_t i = r.numerator; i >= 2; i--) {
		if (r.numerator % i == 0 && r.denominator % i == 0) {
			r.numerator /= i;
			r.denominator /= i;
		}
	}
	return r;
}

CommonFraction division(CommonFraction f1, CommonFraction f2) {

	// r = f1 / f2

	CommonFraction r;
	//
	f1.numerator = f1.sign * (f1.numerator + f1.intPart * f1.denominator);
	f2.numerator = f2.sign * (f2.numerator + f2.intPart * f2.denominator);
	r.numerator = f1.numerator * f2.denominator;
	r.denominator = f1.denominator * f2.numerator;
	//
	r.sign = +1;
	if (r.numerator < 0 && r.denominator>0 || 
r.numerator > 0 && r.denominator < 0)
		r.sign = -1;
	r.denominator = abs(r.denominator);
	r.numerator = abs(r.numerator);
	//
	r.intPart = 0;
	if (r.numerator > r.denominator) {
		r.intPart = r.numerator / r.denominator; //sveikaskaitė dalyba!
		r.numerator = r.numerator % r.denominator;
	}
	//gal trupmena dar prastinasi?	
	for (size_t i = r.numerator; i >= 2; i--) {
		if (r.numerator % i == 0 && r.denominator % i == 0) {
			r.numerator /= i;
			r.denominator /= i;
		}
	}
	return r;
}
