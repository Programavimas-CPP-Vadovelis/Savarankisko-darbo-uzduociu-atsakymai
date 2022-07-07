import <iostream>;
using std::cout;
using std::cin;
using std::endl;
//
class Toy {
protected:
	char name[100];
	size_t forAge;
	double price;
public:
	Toy() : forAge(0), price(0.0) { strcpy_s(name, "  "); }
	//
	Toy(char n[], size_t f, double p) : forAge(f), price(p) {
		strcpy_s(name, n);
	}
	//
	virtual ~Toy() { }
	//
	size_t returnAge() { return forAge; }
	//
	double returnPrice() { return price; }
	//
	void getBaseData() {
		cout << "Iveskite vaiko, kuriam skirtas zaislas, amziu\n";
		cin >> forAge;
		cout << "Iveskite zaislo kaina\n";
		cin >> price;
	}
	//
	void showBaseData() {
		cout << "Vaiko amzius: " << forAge << endl;
		cout << "Kaina: " << price << endl;
	}
	//
	virtual void getData() = 0;
	virtual void showData() = 0;
};
//
//
class Doll : public Toy {
public:
	Doll() : Toy() { }
	Doll(char n[], size_t f, double p) : Toy(n, f, p) { }
	~Doll() {}
	void getData() {
		cout << "\nIveskite leles varda\n";
		cin >> name;
		Toy::getBaseData();
	}
	void showData() {
		cout << "\nLeles vardas: " << name << endl;
		Toy::showBaseData();
	}
};
//
//
class Soldier : public Toy {
public:
	Soldier() : Toy() { }
	Soldier(char n[], size_t f, double p) : Toy(n, f, p) { }
	~Soldier() {}
	void getData() {
		cout << "\nIveskite zaislo-kareivio varda\n";
		cin >> name;
		Toy::getBaseData();
	}
	void showData() {
		cout << "\nKareivelio vardas: " << name << endl;
		Toy::showBaseData();
	}
};
//
//
int main() {
	//
	size_t n; //žaislų skaičius krepšelyje
	char choice; //vėliavėlė: 'd' - lėlė,
		 // 's' - kareivėlis
	cout << "Kiek perkate zaislu?\n";
	cin >> n;
	//
	Toy* toys[100];
	//
	for (size_t i = 0; i < n; i++) {
		cout << "Iveskite " << i + 1 << " zaislo koda: d arba s\n";
		cin >> choice;
		switch (choice) {
		case 'd':
			toys[i] = new Doll;
			break;
		case 's':
			toys[i] = new Soldier;
			break;
		default:
			cout << "Ivestas netinkamas simbolis\n";
		}
	}
	//
	//Nuo čia operuojama vien tik baziniu tipu
	//
	double averageAge = 0., totalPrice = 0.;
	for (size_t i = 0; i < n; i++) {
		toys[i]->getData();
		toys[i]->showData();
		averageAge += toys[i]->returnAge();
		totalPrice += toys[i]->returnPrice();
	}
	//
	cout << "\nPirkiniu krepselis:\n" << "Visa kaina " << totalPrice
	     << " Vidutine zaislo kaina " << totalPrice / n << endl
	     << "Krepselis skirtas vaikui " << averageAge / n << endl;
	//
}
