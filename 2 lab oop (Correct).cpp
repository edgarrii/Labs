#include <time.h>
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

int  chooseFillArr();
int  chooseMenu();

class workWithArray {
	int** mas;
	int n, m, id;
	static int count;
public:
	void fillArray();
	void swapMaxAndMin();
	void swapStrArray();
	void printArray() const;
	workWithArray(int ValueN, int ValueM);
	~workWithArray();
};

workWithArray::workWithArray(int ValueN, int ValueM) {
	n = ValueN; m = ValueM;
	mas = new int* [n];
	for (int i = 0; i < n; i++)
		mas[i] = new int[m];
	count++;
	id = count;
}

workWithArray::~workWithArray() {
	for (int i = 0; i < n; i++)
		delete[]mas[i];
	delete[]mas;
}

void workWithArray::printArray() const {
	system("cls");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << mas[i][j] << " ";
		cout << endl;
	}
	system("pause");
	system("cls");
}

void workWithArray::fillArray() {
	int choose = chooseFillArr();
	if (choose == 0) {
		system("cls");
		cout << "Enter MIN element of array: ";
		int l = 0, r = 0;
		cin >> l;
		cout << "Enter MAX element of array: ";
		cin >> r;
		srand(time(NULL));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				mas[i][j] = rand() % (r - l + 1) + l;
	}
	else {
		cout << "Enter the elements of array: " << endl;
		for (int i = 0; i < n; i++) {
			cout << i + 1 << " - line from " << m << " symbols: ";
			for (int j = 0; j < m; j++)
				cin >> mas[i][j];
		}
	}
}

void workWithArray::swapMaxAndMin() {
	int min = mas[0][0], max = mas[0][0];
	int mini = 0, minj = 0, maxi = 0, maxj = 0;
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (mas[i][j] > max) {
				max = mas[i][j];
				maxi = i;
				maxj = j;
			}
			if (mas[i][j] < min) {
				min = mas[i][j];
				mini = i;
				minj = j;
			}
		}
	int swap = 0;
	swap = mas[maxi][maxj];
	mas[maxi][maxj] = mas[mini][minj];
	mas[mini][minj] = swap;
}

void workWithArray::swapStrArray() {
	int swap = 0;
	for (int i = 0; i < n - 1; i = i + 2)
		for (int j = 0; j < m; j++) {
			swap = mas[i][j];
			mas[i][j] = mas[i + 1][j];
			mas[i + 1][j] = swap;
		}
}

int workWithArray::count = 0;

int main()
{
	setlocale(0, "rus");
	int n = 0, m = 0;
	cout << "Enter the size of array for creating: " << endl;
	cout << "N - ";
	cin >> n;
	cout << "M - ";
	cin >> m;
	system("cls");
	workWithArray Array(n, m);
	while (true) {
		int choose = chooseMenu();
		if (choose == 0) {
			Array.fillArray();
			system("cls");
		}else
			if (choose == 1) {
				Array.swapMaxAndMin();
				cout << "The MAX and MIN elements of the matrix have been changed." << endl;
				system("pause");
				system("cls");
			}else
				if (choose == 2) {
					Array.swapStrArray();
					cout << "Lines have been changed in pairs." << endl;
					system("pause");
					system("cls");
				}
				else
					if (choose == 3) {
						Array.printArray();
					}
					else
							break;
	}
	return 0;
}

int chooseMenu() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Use the UP and DOWN arrows to select the menu item: " << endl;
		choose_menu = (choose_menu + 6) % 6;

		if (choose_menu == 0) {  cout << " - Fill matrix" << endl;  }
		else { cout << " Fill matrix" << endl; }

		if (choose_menu == 1) {  cout << " - Swap between MAX and MIN elements" << endl;  }
		else { cout << " Swap between MAX and MIN elements" << endl; }

		if (choose_menu == 2) {  cout << " - Change the lines in pairs" << endl;  }
		else { cout << " Change the lines in pairs" << endl; }

		if (choose_menu == 3) {  cout << " - Show matrix" << endl;  }
		else { cout << " Show matrix" << endl; }

		if (choose_menu == 5) {  cout << " - End the program" << endl;  }
		else { cout << " End the program" << endl; }

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

int chooseFillArr() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Use the UP and DOWN arrows to select what do u want: " << endl;
		choose_menu = (choose_menu + 2) % 2;

		if (choose_menu == 0) {  cout << " - Through the random" << endl;  }
		else { cout << " Through the random" << endl; }

		if (choose_menu == 1) {  cout << " - Through the keyboard" << endl;  }
		else { cout << " Through the keyboard" << endl; }

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

void setColor(int text, int background) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
