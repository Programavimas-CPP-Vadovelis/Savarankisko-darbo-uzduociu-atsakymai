import <iostream>;
using std::cout;
using std::cin;
using std::endl;
//
class Person {
protected:
	char firstName[100];
	char lastName[100];
	char birthDate[100];
	char address[100];
	char phoneNo[100];
public:
	Person() {
		strcpy_s(firstName, "  ");
		strcpy_s(lastName, "  ");
		strcpy_s(birthDate, "  ");
		strcpy_s(address, "  ");
		strcpy_s(phoneNo, "  ");
	}
	Person(char fN[], char lN[], char bD[], char a[], char pN[]) {
		strcpy_s(firstName, fN);
		strcpy_s(lastName, lN);
		strcpy_s(birthDate, bD);
		strcpy_s(address, a);
		strcpy_s(phoneNo, pN);
	}
	~Person() {}
	void getData() {
	    cout << "Iveskite varda, pavarde, gimimo data, adresa ir tel Nr.\n";
	    cin >> firstName >> lastName >> birthDate >> address >> phoneNo;
	}
	void showData() {
		cout << "Info apie asmeni:\n";
		cout << firstName << "  " << lastName << endl << birthDate
			<< endl << address << endl << phoneNo << endl;
	}
};
//
class Studies {
protected:
	char faculty[100];
	char studyProgram[100];
	char groupID[100];
public:
	Studies() {
		strcpy_s(faculty, "  ");
		strcpy_s(studyProgram, "  ");
		strcpy_s(groupID, "  ");
	}
	Studies(char f[], char sP[], char gID[]) {
		strcpy_s(faculty, f);
		strcpy_s(studyProgram, sP);
		strcpy_s(groupID, gID);
	}
	~Studies() {}
	void getData() {
	   cout << "Iveskite fakulteto, studiju programos ir grupes info\n";
	   cin >> faculty >> studyProgram >> groupID;
	}
	void showData() {
	   cout << "Info apie studijas\n";
	   cout << faculty << endl << studyProgram << endl << groupID << endl;
	}
};
//
class Student : public Person, public Studies {
public:
	Student() : Person(), Studies() { }
	Student(char fN[], char lN[], char bD[], char a[], char pN[],
		char f[], char sP[], char gID[]) :
		Person(fN, lN, bD, a, pN), Studies(f, sP, gID) { }
	~Student() {}
	void getData() {
		Person::getData();
		Studies::getData();
	}
	void showData() {
		cout << endl;
		Person::showData();
		cout << endl;
		Studies::showData();
		cout << endl;
	}
};
//
int main() {
	//
	Student s;
	s.getData();
	s.showData();
	//
}
