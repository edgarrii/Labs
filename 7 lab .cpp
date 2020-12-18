#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

double writeNumbers();
int chooseMainMenu();
int chooseEquation(string*, int);

template <typename T>
class Equation {
private:
	T a, b, c;
	T D;
	T x1;
	T x2;
public:
	Equation() {
		a = b = c = x1 = x2 = D = 0;
	}
	Equation(T a1, T b1, T c1) {
		a = a1;
		b = b1;
		c = c1;
		D = b * b - 4 * a * c;
		x1 = (-b + sqrt(D)) / (2 * a);
		x2 = (-b - sqrt(D)) / (2 * a);
	}
	void show() {
		D = b * b - 4 * a * c;
		x1 = (-b + sqrt(D)) / (2 * a);
		x2 = (-b - sqrt(D)) / (2 * a);
		cout << a << "x^2";
		if (b < 0) cout << b << "x";
		else cout << "+" << b << "x";
		if (c < 0) cout << c;
		else cout << "+" << c;
		cout << endl;
		cout << "D = b^2-4ac" << endl;
		T rav = 4 * a * c;
		if (rav < 0) cout << "D = " << b * b << "+" << -rav;
		else cout << "D = " << b * b << "-" << rav;
		cout << " = " << D << endl;
		cout << "x1,2 = (-b + sqrt(D))/2a" << endl;
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
	}
	Equation<T>& operator*=(int abc) {
		a *= abc;
		b *= abc;
		c *= abc;
		return*this;
	}
	Equation<T>& operator-(Equation<T>& ur) {
		a = a - ur.a;
		b = b - ur.b;
		c = c - ur.c;
		return*this;
	}
	string getUrav() {
		string s;
		s = to_string(a) + "x^2";
		if (b < 0) s = s + to_string(b) + "x";
		else s = s + "+" + to_string(b) + "x";
		if (c < 0) s = s + to_string(c);
		else s = s + "+" + to_string(c);
		return s;
	}
	friend void operator>><T>(istream&, Equation<T>&);
};


template <typename T> void operator>>(istream& in, Equation<T>& ur) {
	cout << "Введите коэффицент a: ";
	ur.a = writeNumbers();
	system("cls");
	cout << "Введите коэффицент b: ";
	ur.b = writeNumbers();
	system("cls");
	cout << "Введите коэффицент c: ";
	ur.c = writeNumbers();
	system("cls");
}


int main() {
	setlocale(0, "rus");
	int nEquation = 0;
	Equation<double>* equation = new Equation<double>[1];
	while (true) {
		int choose = chooseMainMenu();
		if (choose == 0) {
			nEquation++;
			Equation<double>* ptr = new Equation<double>[nEquation];
			for (int i = 0; i < nEquation - 1; i++)
				ptr[i] = equation[i];
			equation = ptr;
			ptr = NULL;
			delete[]ptr;
			cin >> equation[nEquation - 1];
		}
		else
			if (choose == 1) {
				for (int i = 0; i < nEquation; i++) {
					equation[i].show();
					cout << endl;
				}
				system("pause");
				system("cls");
			}
			else
				if (choose == 2) {
					string* aa = new string[nEquation];
					for (int i = 0; i < nEquation; i++)
						aa[i] = equation[i].getUrav();
					int choose1 = chooseEquation(aa, nEquation);
					delete[]aa;
					if (choose1 == nEquation) break;
					cout << "Введите число на которое умножить коэффиценты: ";
					double a = writeNumbers();
					equation[choose1] *= a;
				}
				else
					if (choose == 3) {
						string* aa = new string[nEquation];
						for (int i = 0; i < nEquation; i++)
							aa[i] = equation[i].getUrav();
						int choose1 = chooseEquation(aa, nEquation);
						if (choose1 == nEquation) break;
						int choose2 = chooseEquation(aa, nEquation);
						if (choose2 == nEquation) break;
						equation[choose1] = equation[choose1] - equation[choose2];
						delete[]aa;
						cout << "Вычетание прошло успешно!" << endl;
						system("pause");
						system("cls");
					}
					else
						break;
	}
}

int chooseMainMenu() {
	int choose_menu = 0, key = 0;
	system("cls");
	while (true) {
		choose_menu = (choose_menu + 5) % 5;

		if (choose_menu == 0) cout << "-> Добавить уравнение" << endl;
		else cout << " Добавить уравнение" << endl;

		if (choose_menu == 1) cout << "-> Посмотреть уравнения и решить" << endl;
		else cout << " Посмотреть уравнения и решить" << endl;

		if (choose_menu == 2) cout << " -> Умножить коэфиценты на число" << endl;
		else cout << " Умножить коэфиценты на число" << endl;

		if (choose_menu == 3) cout << " -> Вычесть коэфиценты одного уравнение от другого" << endl;
		else cout << " Вычесть коэфиценты одного уравнение от другого" << endl;

		if (choose_menu == 4) cout << " -> Выход" << endl;
		else cout << " Выход" << endl;

		key = _getch();
		if (key == 224) {
			key = _getch();
			if (key == 72) choose_menu--;
			if (key == 80) choose_menu++;
		}
		if (key == 13) {
			system("cls");
			return choose_menu;
		}
		system("cls");
	}
}

double writeNumbers() {
	string numbers;
	while (true) {
		double key;
		key = _getch();
		if (key == 224) {
			key = _getch();
		}
		else
			if (key == 8) {
				if (numbers.length() != 0) {
					cout << '\b' << " " << '\b';
					numbers.erase(numbers.length() - 1);
				}
			}
			else
				if (key == 13 && numbers.length() != 0 && numbers != "-") break;
				else
					if ((key >= '0' && key <= '9') || (key == '-'  && numbers.length() == 0) || (key==',')) {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	cout << endl;
	return stof(numbers);
}

int chooseEquation(string* a, int nEquation) {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
		choose_menu = (choose_menu + (nEquation + 1)) % (nEquation + 1);

		for (int i = 0; i < nEquation; i++)
			if (i == choose_menu) { cout << " -> " << i + 1 << " - " << a[i] << endl; }
			else { cout << " " << i + 1 << " - " << a[i] << endl; }

		if (choose_menu == nEquation) { cout << " -> Выйти с выбора" << endl; }
		else cout << " Выйти с выбора" << endl;

		keyboard_button = _getch();
		if (keyboard_button == 224) {
			keyboard_button = _getch();
			if (keyboard_button == 72) choose_menu--;
			if (keyboard_button == 80) choose_menu++;
		}
		if (keyboard_button == 13) { system("cls"); return choose_menu; }
		system("cls");
	}
}
