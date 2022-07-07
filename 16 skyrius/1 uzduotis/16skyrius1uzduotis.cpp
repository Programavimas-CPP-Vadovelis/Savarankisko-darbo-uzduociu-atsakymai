import <iostream>;
import <format>;
using std::cout;
using std::cin;
using std::endl;
//
template <typename arrayType, typename indexType>
void minmax(arrayType* a, indexType n, indexType& imax, indexType& imin);
//
int main() {
	//
	try {
		double* a; //a - pradinis masyvas
		size_t n, imax, imin;   //n - masyvo matas
		//
		cout << "Iveskite masyvo mata\n";
		cin >> n;
		cout << "Masyvo elementu skaicius " << n << endl;
		//
		a = new double[n];
		//
		cout << "Iveskite " << n << " masyvo elementu\n";
		for (size_t i = 0; i < n; i++)
			cin >> a[i];
		cout << "\nPradinis masyvas:\n";
		for (size_t i = 0; i < n; i++)
			cout << std::format("{:12.2f} ", a[i]);
		cout << endl;
		//
		minmax(a, n, imax, imin); //funkcija realizuojama double ir int formatams
		//
		cout << "\nRezultatai\nMax elementas " << a[imax] << " yra "
			<< imax + 1 << "-s" << endl << "Min elementas " 
<< a[imin] << " yra " << imin + 1 << "-s" << endl;
		//
		delete[] a;
	}
	catch (std::bad_alloc) {
		cout << "Dinamines atminties skyrimo klaida. Stop\n";
	}
	//
}
//
template <typename arrayType, typename indexType>
void minmax(arrayType* a, indexType n, indexType& imax, indexType& imin) {
	//
	imax = 0;
	imin = 0;
	//
	for (indexType i = 1; i < n; i++) {
		if (a[imax] < a[i])
			imax = i;
		if (a[imin] > a[i])
			imin = i;
	}
	//
}
