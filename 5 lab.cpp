#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

class Voleyball {
protected:
	string TeamName;
	string CoachName;
public:
	Voleyball(string w, string w1) {
		TeamName = w;
		CoachName = w1;
	}
	virtual void showInf() = 0;
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
	void showInf();
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
	void showInf();
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
	void showInf();
};

void USAMainTeam::showInf() {
	cout << "	Сборная США по волейболу" << endl;
	cout << "Название команды: " << TeamName << endl;
	cout << "Фамилия тренера: " << CoachName << endl;
	cout << "Количество игроков: " << AmountOfPlayers << endl;
	cout << "Количество выигранных матчей: " << AmountOfWins << endl;
}

void RussianMainTeam::showInf() {
	cout << "	Сборная России по волейболу" << endl;
	cout << "Название команды: " << TeamName << endl;
	cout << "Фамилия тренера: " << CoachName << endl;
	cout << "Количество игроков: " << AmountOfPlayers << endl;
	cout << "Количество проигранных матчей: " << AmountOfLose << endl;
}

void ItalyMainTeam::showInf() {
	cout << "	Сборная Италии по волейболу" << endl;
	cout << "Название команды: " << TeamName << endl;
	cout << "Фамилия тренера: " << CoachName << endl;
	cout << "Количество игроков: " << AmountOfPlayers << endl;
	cout << "Фамилия Топ игрока: " << nameOfTheBestPlayer << endl;
}

void USA(int&, int&, string&, string&);
void RUS(int&, int&, string&, string&);
void ITL(int&, string&, string&, string&);
int chooseMenu();
string writeWords();
int writeNumbers();

int main() {
	setlocale(0, "rus");
	int n = 1;
	Voleyball** Array = new Voleyball * [n];
	n--;
	while (true) {
		int choose = chooseMenu();
		if (choose == 0) {
			int AmountTeam, AmountWins;
			string NameOfTeam, CoachName;
			USA(AmountTeam, AmountWins, NameOfTeam, CoachName);
			Array[n] = new USAMainTeam(NameOfTeam, CoachName, AmountTeam, AmountWins);
			Array[n]->showInf();
			n++;
			n++;
			Voleyball** tmp = new Voleyball * [n];
			n--;
			copy(Array, Array + n, tmp);
			Array = tmp;
			tmp = NULL;
			delete[]tmp;
			system("pause");
			system("cls");
		}
		else
			if (choose == 1) { 
				int AmountTeam, AmountLose;
				string NameOfTeam, CoachName;
				RUS(AmountTeam, AmountLose, NameOfTeam, CoachName);
				Array[n] = new RussianMainTeam(NameOfTeam, CoachName, AmountTeam, AmountLose);
				Array[n]->showInf();
				n++;
				n++;
				Voleyball** tmp = new Voleyball * [n];
				n--;
				copy(Array, Array + n, tmp);
				Array = tmp;
				tmp = NULL;
				delete[]tmp;
				system("pause");
				system("cls");
			}
			else
				if (choose == 2) { 
					int AmountTeam;
					string NameOfTeam, CoachName, TopPlayerName;
					ITL(AmountTeam, NameOfTeam, CoachName, TopPlayerName);
					Array[n] = new ItalyMainTeam(NameOfTeam, CoachName, AmountTeam, TopPlayerName);
					Array[n]->showInf();
					n++;
					n++;
					Voleyball** tmp = new Voleyball * [n];
					n--;
					copy(Array, Array + n, tmp);
					Array = tmp;
					tmp = NULL;
					delete[]tmp;
					system("pause");
					system("cls");
				}
				else 
					if (choose == 3) {
						for (int i = 0; i < n; i++)
							Array[i]->showInf();
						system("pause");
						system("cls");
					}
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
		choose_menu = (choose_menu + 5) % 5;

		if (choose_menu == 0) { cout << " -> Сборная США по волейболу" << endl; }
		else { cout << " Сборная США по волейболу" << endl; }

		if (choose_menu == 1) { cout << " -> Сборная России по волейболу" << endl; }
		else { cout << " Сборная России по волейболу" << endl; }

		if (choose_menu == 2) { cout << " -> Сборная Италии по волейболу" << endl; }
		else { cout << " Сборная Италии по волейболу" << endl; }

		if (choose_menu == 3) { cout << " -> Вывод всей информации" << endl; }
		else { cout << " Вывод всей информации" << endl; }

		if (choose_menu == 4) { cout << " -> Завершить программу" << endl; }
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

void USA(int& AmountTeam, int& AmountWins, string& NameOfTeam, string& CoachName) {
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
	system("cls");
}

void RUS(int& AmountTeam, int& AmountLose, string& NameOfTeam, string& CoachName) {
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
	system("cls");
}

void ITL(int& AmountTeam, string& NameOfTeam, string& CoachName, string& TopPlayerName) {
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
	system("cls");
}
