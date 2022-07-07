// Eilutėms kopijuoti yra vidinė C++ funkcija strcpy, tačiau šioje programoje eilutes kopijuojame po vieną simbolį, kad prisimintume eilutės sandarą.
import <iostream>;
using std::cout;
using std::cin;
using std::endl;
//
class String {
private:
	char* s; // eilutė
public:
	// konstruktorius be argumentų
	String() : s(nullptr) { }
	// konstruktoriai su argumentais
	String(char* sp) {
		this->s = new char[strlen(sp) + 1];
		size_t i = 0;
		for (; i < strlen(sp); i++)
			this->s[i] = sp[i];
		this->s[i] = '\0'; //:"strlen" neįskaičiuoja
			       //pabaigos simbolio
	}
	String(size_t n) { //tokio reikia dinaminei atminčiai skirti
		this->s = new char[n]; // metode „+“
	}
	// destruktorius
	~String() {
		delete[] s;
	}
	// kopijuojantysis konstruktorius
	String(const String& sSource) {
		this->s = new char[strlen(sSource.s) + 1];
		size_t i = 0;
		for (; i < strlen(sSource.s); i++)
			this->s[i] = sSource.s[i];
		this->s[i] = '\0';
	}
	// metodai
	void showString() {
		char* ss = s;            //išsaugome adresą
		while (*s) cout << *s++; //cikle rodyklė perstumiama
		s = ss;                  //rodyklę grąžiname į pradinį adresą
		cout << endl;
	}
	//
	String* operator+(String& str) { //"&"-kad nereikėtų kopijuoti
		//
		// (*r).s = <darbinis objektas.s> + str.s
		//
		size_t n = strlen(this->s) + strlen(str.s) + 1;
		String* sp = new String(n);
		size_t i = 0;
		for (; i < strlen(this->s); i++)
			(*sp).s[i] = this->s[i];
		int ii = -1;
		for (i = strlen(this->s); i < n; i++) {
			ii++;
			(*sp).s[i] = str.s[ii];
		}
		(*sp).s[n] = '\0';
		return sp;
	}
	//
};
//
//
int main() {
	char c1[] = "Pirmoji eilute   ir    ";
	char c2[] = "antroji eilute";
	String s1(c1), s2(c2);
	//
	//String s1("Pirmoji eilute     ir    "),
	//	s2("antroji eilute"); 
	//        Taip negalima: konkreti eilutės reikšmė
	// automatiškai yra const char*, o konstruktoriaus
	// argumentas yra kitokio formato: char*
//
	String* r(nullptr);
	//
	s1.showString();
	s2.showString();
	//
	r = s1 + s2;
	cout << "\n\nRezultatas:\n";
	(*r).showString();
	//
}
