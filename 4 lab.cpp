#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

void USA();
void RUS();
void ITL();
int chooseMenu();
string writeWords();
int writeNumbers();

class Voleyball {
protected:
	string TeamName;
	string CoachName;
public:
	Voleyball(string w, string w1) {
		TeamName = w;
		CoachName = w1;
	}
	void showInf();
};

class USAMainTeam :public Voleyball {
private:
	int AmountOfPlayers;
	int AmountOfWins;
public:
	USAMainTeam(string w, string w1, int yo, int c) :Voleyball(w, w1) {
		AmountOfPlayers = yo;
		AmountOfWins = c;
	}
	void showUSAInf();
};

class RussianMainTeam :public Voleyball {
private:
	int AmountOfPlayers;
	int AmountOfLose;
public:
	RussianMainTeam(string w, string w1, int yo, int yo1) :Voleyball(w, w1) {
		AmountOfPlayers = yo;
		AmountOfLose = yo1;
	}
	void showRUSInf();
};

class ItalyMainTeam :public Voleyball {
private:
	int AmountOfPlayers;
	string nameOfTheBestPlayer;
public:
	ItalyMainTeam(string w, string w1, int yo, string p) :Voleyball(w, w1) {
		AmountOfPlayers = yo;
		nameOfTheBestPlayer = p;
	}
	void showItalyInf();
};

void Voleyball::showInf() {
	cout << "Название команды: " << TeamName << endl;
	cout << "Фамилия тренера: " << CoachName << endl;
}

void USAMainTeam::showUSAInf() {
	cout << "Количество игроков: " << AmountOfPlayers << endl;
	cout << "Количество выигранных матчей: " << AmountOfWins << endl;
}

void RussianMainTeam::showRUSInf() {
	cout << "Количество игроков: " << AmountOfPlayers << endl;
	cout << "Количество проигранных матчей: " << AmountOfLose << endl;
}

void ItalyMainTeam::showItalyInf() {
	cout << "Количество игроков: " << AmountOfPlayers << endl;
	cout << "Фамилия Топ игрока: " << nameOfTheBestPlayer << endl;
}

int main() {
	setlocale(0, "rus");
	while (true) {
		int choose = chooseMenu();
		if (choose == 0) USA();
		else
			if (choose == 1) RUS();
			else
				if (choose == 2) ITL();
				else break;
	}
	return 0;
}

string writeWords() {
	string slovo;
	while (true) {
		int Knopka;
		char sumbol;
		Knopka = _getch();
		if (Knopka == 224) {
			Knopka = _getch();
		}
		else
			if (Knopka == 8) {
				if (slovo.length() != 0) {
					cout << '\b' << " " << '\b';
					slovo.erase(slovo.length() - 1);
				}
			}
			else
				if (Knopka == 13 && slovo.length() != 0) {
					break;
				}
				else {
					sumbol = (char)Knopka;
					if ((sumbol >= 'a' && sumbol <= 'z') || (sumbol >= 'A' && sumbol <= 'Z')) {
						slovo = slovo + sumbol;
						cout << sumbol;
					}
				}
	}
	return slovo;
}

int writeNumbers() {
	string numbers;
	while (true) {
		int key;
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
				if (key == 13 && numbers.length() != 0) break;
				else
					if (key >= '0' && key <= '9') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	return stoi(numbers);
}

int chooseMenu() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню: " << endl;
		choose_menu = (choose_menu + 4) % 4;

		if (choose_menu == 0) { cout << " -> Сборная США по волейболу" << endl; }
		else { cout << " Сборная США по волейболу" << endl; }

		if (choose_menu == 1) { cout << " -> Сборная России по волейболу" << endl; }
		else { cout << " Сборная России по волейболу" << endl; }

		if (choose_menu == 2) { cout << " -> Сборная Италии по волейболу" << endl; }
		else { cout << " Сборная Италии по волейболу" << endl; }

		if (choose_menu == 3) { cout << " -> Завершить программу" << endl; }
		else { cout << " Завершить программу" << endl; }

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

void USA() {
	int AmountTeam, AmountWins;
	string NameOfTeam, CoachName;
	cout << "	Сборная США по волейболу" << endl;
	cout << "Введите название команды - ";
	NameOfTeam = writeWords();
	cout << endl;
	cout << "Введите Фамилию Тренера - ";
	CoachName = writeWords();
	cout << endl;
	cout << "Количество игроков в команде - ";
	AmountTeam = writeNumbers();
	cout << endl;
	cout << "Введите количесвто выйгрышных матчей за сезон - ";
	AmountWins = writeNumbers();
	USAMainTeam USA(NameOfTeam, CoachName, AmountTeam, AmountWins);
	system("cls");
	cout << "	Сборная США по волейболу" << endl;
	USA.showInf();
	USA.showUSAInf();
	system("pause");
	system("cls");
}

void RUS() {
	int AmountTeam, AmountLose;
	string NameOfTeam, CoachName;
	cout << "	Сборная России по волейболу" << endl;
	cout << "Введите название команды - ";
	NameOfTeam = writeWords();
	cout << endl;
	cout << "Введите Фамилию Тренера - ";
	CoachName = writeWords();
	cout << endl;
	cout << "Количество игроков в команде - ";
	AmountTeam = writeNumbers();
	cout << endl;
	cout << "Введите количесвто проигранных матчей за сезон - ";
	AmountLose = writeNumbers();
	RussianMainTeam RUS(NameOfTeam, CoachName, AmountTeam, AmountLose);
	system("cls");
	cout << "	Сборная России по волейболу" << endl;
	RUS.showInf();
	RUS.showRUSInf();
	system("pause");
	system("cls");
}

void ITL() {
	int AmountTeam;
	string NameOfTeam, CoachName, TopPlayerName;
	cout << "	Сборная Италии по волейболу" << endl;
	cout << "Введите название команды - ";
	NameOfTeam = writeWords();
	cout << endl;
	cout << "Введите Фамилию Тренера - ";
	CoachName = writeWords();
	cout << endl;
	cout << "Количество игроков в команде - ";
	AmountTeam = writeNumbers();
	cout << endl;
	cout << "Введите фамилию топ игрока команды - ";
	TopPlayerName = writeWords();
	ItalyMainTeam ITL(NameOfTeam, CoachName, AmountTeam, TopPlayerName);
	system("cls");
	cout << "	Сборная Италии по волейболу" << endl;
	ITL.showInf();
	ITL.showItalyInf();
	system("pause");
	system("cls");
}
