import <iostream>;
using namespace std;
//
int main() {
	double Ax, Ay, Az, Bx, By, Bz;
	//
	cout << "Iveskite 1-ojo tasko koordinates" << endl;
	cin >> Ax >> Ay >> Az;
	cout << "Iveskite 2-ojo tasko koordinates" << endl;
	cin >> Bx >> By >> Bz;
	cout << "1-ojo tasko koordinates: "
		<< Ax << "  " << Ay << "  " << Az << endl;
	cout << "2-ojo tasko koordinates: "
		<< Bx << "  " << By << "  " << Bz << endl;
	//
	double L = sqrt((Ax - Bx) * (Ax - Bx) +
		(Ay - By) * (Ay - By) +
		(Az - Bz) * (Az - Bz));
	//
	cout << "Atstumas tarp tasku yra " << L << endl;
	//
}
