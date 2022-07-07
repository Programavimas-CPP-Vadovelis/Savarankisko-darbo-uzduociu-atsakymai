import <iostream>;
using std::cout;
using std::cin;
using std::endl;
//
void bubbleSort(const char**, int);
//
int main() {
	//
//Programa rikiuos eilutes tik pagal pirmuosius eilučių simbolius
//
	const int DAYS = 7;
	const char* pDays[DAYS] = { "Monday", "Tuesday", "Wednesday",
			 "Thursday","Friday", "Saturday", "Sunday" };
	//
	cout << "Pradinis masyvas\n\n";
	for (size_t i = 0; i < DAYS; i++)
		cout << *(pDays + i) << endl;
	cout << endl << endl;
	//
	bubbleSort(pDays, DAYS);
	//
	cout << "Rezultatai: isrikiuotas masyvas\n\n";
	for (size_t i = 0; i < DAYS; i++)
		cout << *(pDays + i) << endl;
	cout << endl;
	//
}
//
void bubbleSort(const char** p, int n) {
	//
	void sort2Pointers(const char**, const char**);
	//
	for (size_t i = 0; i < n - 1; i++)
		for (size_t j = i + 1; j < n; j++)
			sort2Pointers(p + i, p + j);
}
//
void sort2Pointers(const char** p1, const char** p2) {
	if (**p1 > **p2) {   //rikiuojama tik pagal pirmuosius eilutės simbolius
		const char* temp = *p1;
		*p1 = *p2;
		*p2 = temp;
	}
}
