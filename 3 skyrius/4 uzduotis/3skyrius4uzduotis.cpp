import <iostream>;
import <iomanip>; 
using std::cout;
using std::cin;
using std::endl;
//
int main() {
	double tol;    // skaičiavimo tolerancija
	double ys, yn; // integralai: prie grubesnio ir smulkesnio integravimo žingsnių
	double a, b;   // a,b - integravimo rėžiai
	double xk, xd, fk, fd, s; // abscisės, funkcijos reikšmės ir mažos trapecijos plotas
	//
	cout << "Iveskite skaiciavimo tiksluma\n";
	cin >> tol;
	cout << "Skaiciavimo tikslumas " << tol << endl;
	cout << "Iveskite integravimo rezius\n";
	cin >> a >> b;
	cout << "Integravimo reziai: " << a << "  " << b << endl;
	//
	if (a > b) {
		cout << "Netinkami integravimo reziai. Stop\n";
		system("pause");
		return -1;
	}
	//
	double t = 5. * (b - a) / 1000.; // pradinis integravimo žingsnis - cikle bus padaugintas iš 5 
	//
	ys = 0.;    // =0 - kad prasisuktų bent viena iteracija
	for (; ; ) { // begalinis ciklas tikslumui pasiekti
		t /= 5.;
		yn = 0.;
		for (xk = a; xk <= b - t; xk += t) { // ciklas integralui skaičiuoti
		//for( xk=a; abs(xk-b)>1.e-10; xk+=t ){ // alternatyvus ciklas
			xd = xk + t;
			fk = xk * xk;
			fd = xd * xd;
			s = (fk + fd) * t / 2.;
			yn += s;
		}
		if (abs(yn - ys) < tol)  // jei tikslumas pasiektas - 
			break;       // baigti išorinį ciklą;
		else                     // jei ne - kartoti ciklą
			ys = yn;  
	}  // išorinio ciklo pabaiga
	//
	cout << "Apytikre integralo reiksme esant integravimo zingsniui " << t
		<< " yra " << std::setprecision(15) << yn << endl;
	//
}
