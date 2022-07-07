import <iostream>;
//
int main() {
	double r, a;
	//
	std::cout << "Iveskite apskritimo spinduli" << std::endl;
	std::cin >> r;
	std::cout << "Iveskite centrini kampa radianais" << std::endl;
	std::cin >> a;
	std::cout << "Apskritimo spindulys r = " << r << std::endl;
	std::cout << "Lanko centrinis kampas a = " << a << std::endl;
	//
	double L = 2. * r * sin(a);
	//
	std::cout << "Lanko stygos ilgis yra " << L << std::endl;
	//
}
