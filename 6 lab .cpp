#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

class Voleyball {
protected:
	string name_team;
	string country;
public:
	Voleyball() {};
	Voleyball(string w1, string w2) {
		name_team = w1;
		country = w2;
	}
	void changeNameTeam(string w) {
		name_team = w;
	}
	void changeCountry(string w) {
		country = w;
	}
	string getNameTeam() {
		return name_team;
	}
	string getCountry() {
		return country;
	}
	void Show() {
		cout << "Страна команды: " << country << endl;
		cout << "Название команды: " << name_team << endl;
	}
};

class Team :virtual public Voleyball {
protected:
	int howManyPlayers;
	int howManyWins;
public:
	Team() {
		howManyPlayers = 0;
		howManyWins = 0;
	};
	Team(int w, int w1, string w2, string w3) :Voleyball(w2, w2) {
		howManyPlayers = w;
		howManyWins = w1;
	}
	void changeHowManyPlayers(int w) {
		howManyPlayers = w;
	}
	void changeHowManyWins(int w) {
		howManyWins = w;
	}
	int getHowManyPlayers() {
		return howManyPlayers;
	}
	int getHowManyWinsy() {
		return howManyWins;
	}
	void Show() {
		cout << "Кол-во игроков в команде: " << howManyPlayers << endl;
		cout << "Кол-во выигранных матчей: " << howManyWins << endl;
	}
};

class Coach :virtual public Voleyball {
protected:
	string name;
	string s_name;
public:
	Coach() {};
	Coach(string w, string w1, string w2, string w3) :Voleyball(w2, w3) {
		name = w;
		s_name = w1;
	}
	void changeName(string w) {
		name = w;
	}
	void changeSName(string w) {
		s_name = w;
	}
	string getName() {
		return name;
	}
	string getSName() {
		return s_name;
	}
	void Show() {
		cout << "Имя тренера: " << name << endl;
		cout << "Фамилия тренера: " << s_name << endl;
	}
};

class Player :public Team, public Coach {
private:
	string name_player;
	string s_name_player;
public:
	Player() {};
	Player(string w, string w1, string w2, string w3, int w4, int w5, string w6, string w7) :Voleyball(w2, w3), Team(w4, w5, w2, w3), Coach(w6, w7, w2, w3) {
		name = w;
		s_name = w1;
	}
	void changeNamePlayer(string w) {
		name_player = w;
	}
	void changeSNamePlayer(string w) {
		s_name_player = w;
	}
	string getNamePlayer() {
		return name_player;
	}
	string getSNamePlayer() {
		return s_name_player;
	}
	/*void Show() {
		Voleyball::Show();
		Team::Show();
		Coach::Show();
		cout << "Имя игрока: " << name_player << endl;
		cout << "Фамилия игрока: " << s_name_player << endl;
	}*/
};

int chooseMenu();
string writeWords();
int writeNumbers();
int chooseWhoRed(Player*&, int);
int chooseWhatRed(Player*&, int);

int main() {
	setlocale(0, "rus");
	int nPlayer = 0;
	Player* players = new Player[nPlayer];
	while (true) {
		int choose = chooseMenu();
		if (choose == 1) {
			if (nPlayer != 0) {
				while (true) {
					int choose1 = chooseWhoRed(players, nPlayer);
					if (choose1 == nPlayer) break;
					while (true) {
						int choose2 = chooseWhatRed(players, choose1);
						if (choose2 == 8) break;
						string ptr1; int ptr;
						if (choose2 == 0) {
							cout << "Введите название команды: ";
							ptr1 = writeWords();
							players[choose1].changeNameTeam(ptr1);
							system("cls");
						}
						else
							if (choose2 == 1) {
								cout << "Введите страну команды: ";
								ptr1 = writeWords();
								players[choose1].changeCountry(ptr1);
								system("cls");
							}
							else
								if (choose2 == 2) {
									cout << "Введите кол-во игроков: ";
									int ptr = writeNumbers();
									players[choose1].changeHowManyPlayers(ptr);
									system("cls");
								}
								else
									if (choose2 == 3) {
										cout << "Введите кол-во выигранных матчей: ";
										ptr = writeNumbers();
										players[choose1].changeHowManyWins(ptr);
										system("cls");
									}
									else
										if (choose2 == 4) {
											cout << "Введите имя тренера: ";
											ptr1 = writeWords();
											players[choose1].changeName(ptr1);
											system("cls");
										}
										else
											if (choose2 == 5) {
												cout << "Введите фамилию тренера: ";
												ptr1 = writeWords();
												players[choose1].changeSName(ptr1);
												system("cls");
											}
											else
												if (choose2 == 6) {
													cout << "Введите имя игрока: ";
													ptr1 = writeWords();
													players[choose1].changeNamePlayer(ptr1);
													system("cls");
												}
												else
													if (choose2 == 7) {
														cout << "Введите фамилию игрока: ";
														ptr1 = writeWords();
														players[choose1].changeSNamePlayer(ptr1);
														system("cls");
													}
					}
				}
			}
			else {
				cout << "Вы еще не добавили историй" << endl;
				system("pause");
				system("cls");
			}
		}
		else
			if (choose == 0) {
				Player sum;
				cout << "Введите название команды: ";
				string ptr1 = writeWords();
				sum.changeNameTeam(ptr1);
				system("cls");
				cout << "Введите страну команды: ";
				ptr1 = writeWords();
				sum.changeCountry(ptr1);
				system("cls");
				cout << "Введите кол-во игроков: ";
				int ptr = writeNumbers();
				sum.changeHowManyPlayers(ptr);
				system("cls");
				cout << "Введите кол-во выигранных матчей: ";
				ptr = writeNumbers();
				sum.changeHowManyWins(ptr);
				system("cls");
				cout << "Введите имя тренера: ";
				ptr1 = writeWords();
				sum.changeName(ptr1);
				system("cls");
				cout << "Введите фамилию тренера: ";
				ptr1 = writeWords();
				sum.changeSName(ptr1);
				system("cls");
				cout << "Введите имя игрока: ";
				ptr1 = writeWords();
				sum.changeNamePlayer(ptr1);
				system("cls");
				cout << "Введите фамилию игрока: ";
				ptr1 = writeWords();
				sum.changeSNamePlayer(ptr1);
				system("cls");
				nPlayer++;
				Player* ptrr = new Player[nPlayer];
				for (int i = 0; i < nPlayer - 1; i++)
					ptrr[i] = players[i];
				players = ptrr;
				ptrr = NULL;
				delete[]ptrr;
				players[nPlayer - 1] = sum;
			}
			else
				if (choose == 2) {
					for (int i = 0; i < nPlayer; i++) {
						players[i].Voleyball::Show();
						cout << endl;
					}
					system("pause");
					system("cls");
				}
				else
					if (choose == 3) break;
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
					if ((sumbol >= 'a' && sumbol <= 'z') || (sumbol >= 'A' && sumbol <= 'Z') || (sumbol == ' ')) {
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
		cout << "Используя стрелочки Up и Down выберите необходимый пункт меню: " << endl;
		choose_menu = (choose_menu + 4) % 4;

		if (choose_menu == 0) { cout << " -> Добавить игрока" << endl; }
		else { cout << " Добавить игрока" << endl; }

		if (choose_menu == 1) { cout << " -> Редактировать игроков" << endl; }
		else { cout << " Редактировать игроков" << endl; }

		if (choose_menu == 2) { cout << " -> Просмотр всех игроков" << endl; }
		else { cout << " Просмотр всех игроков" << endl; }

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

int chooseWhoRed(Player*& players, int nPlayer) {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
		choose_menu = (choose_menu + (nPlayer + 1)) % (nPlayer + 1);

		for (int i = 0; i < nPlayer; i++)
			if (i == choose_menu) { cout << " -> " << i + 1 << " - " << players[i].getName() << endl; }
			else { cout << " " << i + 1 << " - " << players[i].getName() << endl; }

		if (choose_menu == nPlayer) { cout << " -> Выйти с выбора игрока" << endl; }
		else cout << " Выйти с выбора игрока" << endl;

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

int chooseWhatRed(Player*& players, int choose) {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите пункт меню" << endl;
		choose_menu = (choose_menu + 9) % 9;

		if (choose_menu == 0) { cout << " -> Название команды: " << players[choose].getNameTeam() << endl; }
		else cout << " Название команды: " << players[choose].getNameTeam() << endl;

		if (choose_menu == 1) { cout << " -> Страна: " << players[choose].getCountry() << endl; }
		else cout << " Тип Страна: " << players[choose].getCountry() << endl;

		if (choose_menu == 2) { cout << " -> Кол-во игроков: " << players[choose].getHowManyPlayers() << endl; }
		else cout << " Кол-во игроков: " << players[choose].getHowManyPlayers() << endl;

		if (choose_menu == 3) { cout << " -> Кол-во выигранных матчей: " << players[choose].getHowManyWinsy() << endl; }
		else cout << " Кол-во выигранных матчей: " << players[choose].getHowManyWinsy() << endl;

		if (choose_menu == 4) { cout << " -> Имя тренера: " << players[choose].getName() << endl; }
		else cout << " Имя тренера: " << players[choose].getName() << endl;

		if (choose_menu == 5) { cout << " -> Фамилия тренера: " << players[choose].getSName() << endl; }
		else cout << " Фамилия тренера: " << players[choose].getSName() << endl;

		if (choose_menu == 6) { cout << " -> Имя игрока: " << players[choose].getNamePlayer() << endl; }
		else cout << " Имя игрока: " << players[choose].getNamePlayer() << endl;

		if (choose_menu == 7) { cout << " -> Фамилия игрока: " << players[choose].getSNamePlayer() << endl; }
		else cout << " Фамилия игрока: " << players[choose].getSNamePlayer() << endl;

		if (choose_menu == 8) { cout << " -> Выйти в меню выбора " << endl; }
		else cout << " Выйти в меню выбора " << endl;


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
