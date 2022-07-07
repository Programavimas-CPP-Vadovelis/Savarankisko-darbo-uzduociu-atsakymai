import <iostream>;
import <iomanip>; // funkcijai setprecision
using std::cout;
using std::cin;
using std::endl;
//
int main() {
	double y = 0., a, b; // a,b - integravimo rėžiai
	double t = 0.001;    // integravimo tikslumas
	double xk, xd, fk, fd, s; // abscisės, funkcijos reikšmės
  	  		   // ir mažos trapecijos plotas
	//
	cout << "Iveskite integravimo rezius\n";
	cin >> a >> b;
	cout << "Integravimo reziai: " << a << "  " << b << endl;
	if (a > b) {
		cout << "Netinkami integravimo reziai. Stop\n";
		system("pause");
		exit(-1);
	}
	//
	for (xk = a; xk <= b - t; xk += t) {
	//for( xk=a; abs(xk-b)>1.e-10; xk+=t ){ //alternatyva: 
// įvertinant realių skaičių aritmetikos ypatybes
		xd = xk + t;
		fk = xk * xk;
		fd = xd * xd;
		s = (fk + fd) * t / 2.;
		y += s;
	}
	//
	cout << "Apytikre integralo reiksme esant integravimo zingsniui " << t
		<< " yra " << std::setprecision(7) << y << endl; 
// setprecision nurodo išvedamų skaitmenų kiekį
//
}
