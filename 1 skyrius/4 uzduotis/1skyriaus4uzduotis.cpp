import <iostream>;
using namespace std;
//
int main() {
	double x;
	//
	cout << "Iveskite  kampa radianais" << endl;
	cin >> x;
	cout << "Kampas x = " << x << endl;
	//
	double suma = sin(x) * sin(x) + cos(x) * cos(x);
	//
	cout << "sin(x)*sin(x) + cos(x)*cos(x) = " << suma << endl;
	//
}
