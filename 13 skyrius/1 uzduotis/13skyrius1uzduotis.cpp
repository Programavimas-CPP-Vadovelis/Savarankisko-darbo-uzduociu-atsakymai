import <iostream>;
using std::cout;
using std::cin;
using std::endl;
//
class Shape {
protected:
	double a, b, c; //figūros kraštinės
	  //kvadrato atveju b ir c - nenaudojama
	  //stačiakampio atveju c - nenaudojama
public:
	Shape() : a(0.), b(0.), c(0) { }
	Shape(double a, double b, double c) {
		this->a = a; this->b = b; this->c = c;
	}
	~Shape() { }
	
	void showSides() { }

};
//
class Square : public Shape {
public:
	Square() : Shape() {}
	Square(double a) : Shape(a, a, a) {
		if (a < 0.) {
			cout << "Netinkama krastines reiksme. Stop\n";
			exit(-1);
		}
	}
	void showSides() {
		cout << "Kvadrato krastine " << a << endl;
	}
	double perimeter() {
		return 4. * a;
	}
	double area() {
		return a * a;
	}
};
//
class Rectangle : public Shape {
public:
	Rectangle() : Shape() {}
	Rectangle(double a, double b) : Shape(a, b, b) {
		if (a < 0. || b < 0.) {
			cout << "Netinkama krastines reiksme. Stop\n";
			exit(-2);
		}
	}
	void showSides() {
		cout << "Staciakampio krastines " << a << "  " << b << endl;
	}
	double perimeter() {
		return 2. * a + 2. * b;
	}
	double area() {
		return a * b;
	}
};
//
class Triangle : public Shape {
public:
	Triangle() : Shape() {}
	Triangle(double a, double b, double c) : Shape(a, b, c) {
		if (a < 0. || b < 0. || c < 0.) {
			cout << "Netinkama krastines reiksme. Stop\n";
			exit(-3);
		}
	}
	void showSides() {
		cout << "Trikampio krastines " << a << "  " << b << "  " 
<< c << endl;
	}
	double perimeter() {
		return a + b + c;
	}
	double area() {
		double s = (a + b + c) / 2.;
		return sqrt(s * (s - a) * (s - b) * (s - c)); //Herono formulė
	}
};
//
int main() {
	Square s(10.);
	Rectangle r(10., 10.);
	Triangle t(10., 10., 10.);
	//
	s.showSides();
	r.showSides();
	t.showSides();
	//
	cout << "Kvadrato perimetras " << s.perimeter() << ", plotas "
		<< s.area() << endl;
	cout << "Staciakampio perimetras " << r.perimeter() << ", plotas "
		<< r.area() << endl;
	cout << "Trikampio perimetras " << t.perimeter() << ", plotas "
		<< t.area() << endl;
	//

}
