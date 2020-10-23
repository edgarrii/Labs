#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <cstring>
using namespace std;

class String {
	char* s = new char;
	int n;
public:
	void printString();
	int getLen();
	String& operator+=(String& str) {
		cout << s << endl;
		int n1 = strlen(s);
		int n2 = strlen(str.s);
		int j = n1;
		for (int i = 0; i < n2; i++) {
			s[j] = str.s[i];
			j++;
		}
		s[j] = '\0';
		n = j;
		return *this;
	}
	String& operator=(String& str) {
		if (this != &str) {
			n = str.n;
			s = str.s;
		}
		return *this;
	}
	String(char* s1) {
		s = s1;
		n = strlen(s);
	}
	String(const String& s1) {
		s = s1.s;
		n = s1.n;
	}
};

int String::getLen() {
	return n;
}

void String::printString() {
	cout << s;
}

int main() {
	setlocale(0, "rus");
	char* s = new char[255];
	char* s1 = new char[255];
	cout << "Введите строку = ";
	cin >> s;
	cout << "Введите вторую строку = ";
	cin >> s1;
	String str(s);
	String str1(s1);
	cout << "Первая строка = ";
	str.printString();
	cout << endl;
	cout << "Вторая строка = ";
	str1.printString();
	cout << endl;
	str += str1;
	cout << "Первая строка += Вторая строка - ";
	str.printString();
	cout << endl;
	str = str1;
	cout << "Первая строка = Вторая строка - ";
	str.printString();
	cout << endl;
	return 0;
}
