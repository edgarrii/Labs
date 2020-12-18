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
	void show() {
		cout << "Ñòðàíà êîìàíäû: " << country << endl;
		cout << "Íàçâàíèå êîìàíäû: " << name_team << endl;
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
	void show() {
		cout << "Êîë-âî èãðîêîâ â êîìàíäå: " << howManyPlayers << endl;
		cout << "Êîë-âî âûèãðàííûõ ìàò÷åé: " << howManyWins << endl;
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
	void show() {
		cout << "Èìÿ òðåíåðà: " << name << endl;
		cout << "Ôàìèëèÿ òðåíåðà: " << s_name << endl;
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
	void show() {
		Voleyball::show();
		Team::show();
		Coach::show();
		cout << "Èìÿ èãðîêà: " << name_player << endl;
		cout << "Ôàìèëèÿ èãðîêà: " << s_name_player << endl;
	}
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
							cout << "Ââåäèòå íàçâàíèå êîìàíäû: ";
							ptr1 = writeWords();
							players[choose1].changeNameTeam(ptr1);
							system("cls");
						}
						else
							if (choose2 == 1) {
								cout << "Ââåäèòå ñòðàíó êîìàíäû: ";
								ptr1 = writeWords();
								players[choose1].changeCountry(ptr1);
								system("cls");
							}
							else
								if (choose2 == 2) {
									cout << "Ââåäèòå êîë-âî èãðîêîâ: ";
									int ptr = writeNumbers();
									players[choose1].changeHowManyPlayers(ptr);
									system("cls");
								}
								else
									if (choose2 == 3) {
										cout << "Ââåäèòå êîë-âî âûèãðàííûõ ìàò÷åé: ";
										ptr = writeNumbers();
										players[choose1].changeHowManyWins(ptr);
										system("cls");
									}
									else
										if (choose2 == 4) {
											cout << "Ââåäèòå èìÿ òðåíåðà: ";
											ptr1 = writeWords();
											players[choose1].changeName(ptr1);
											system("cls");
										}
										else
											if (choose2 == 5) {
												cout << "Ââåäèòå ôàìèëèþ òðåíåðà: ";
												ptr1 = writeWords();
												players[choose1].changeSName(ptr1);
												system("cls");
											}
											else
												if (choose2 == 6) {
													cout << "Ââåäèòå èìÿ èãðîêà: ";
													ptr1 = writeWords();
													players[choose1].changeNamePlayer(ptr1);
													system("cls");
												}
												else
													if (choose2 == 7) {
														cout << "Ââåäèòå ôàìèëèþ èãðîêà: ";
														ptr1 = writeWords();
														players[choose1].changeSNamePlayer(ptr1);
														system("cls");
													}
					}
				}
			}
			else {
				cout << "Âû åùå íå äîáàâèëè èñòîðèé" << endl;
				system("pause");
				system("cls");
			}
		}
		else
			if (choose == 0) {
				Player sum;
				cout << "Ââåäèòå íàçâàíèå êîìàíäû: ";
				string ptr1 = writeWords();
				sum.changeNameTeam(ptr1);
				system("cls");
				cout << "Ââåäèòå ñòðàíó êîìàíäû: ";
				ptr1 = writeWords();
				sum.changeCountry(ptr1);
				system("cls");
				cout << "Ââåäèòå êîë-âî èãðîêîâ: ";
				int ptr = writeNumbers();
				sum.changeHowManyPlayers(ptr);
				system("cls");
				cout << "Ââåäèòå êîë-âî âûèãðàííûõ ìàò÷åé: ";
				ptr = writeNumbers();
				sum.changeHowManyWins(ptr);
				system("cls");
				cout << "Ââåäèòå èìÿ òðåíåðà: ";
				ptr1 = writeWords();
				sum.changeName(ptr1);
				system("cls");
				cout << "Ââåäèòå ôàìèëèþ òðåíåðà: ";
				ptr1 = writeWords();
				sum.changeSName(ptr1);
				system("cls");
				cout << "Ââåäèòå èìÿ èãðîêà: ";
				ptr1 = writeWords();
				sum.changeNamePlayer(ptr1);
				system("cls");
				cout << "Ââåäèòå ôàìèëèþ èãðîêà: ";
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
						players[i].show();
						cout << endl;
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
		cout << "Èñïîëüçóÿ ñòðåëî÷êè Up è Down âûáåðèòå íåîáõîäèìûé ïóíêò ìåíþ: " << endl;
		choose_menu = (choose_menu + 4) % 4;

		if (choose_menu == 0) { cout << " -> Äîáàâèòü èãðîêà" << endl; }
		else { cout << " Äîáàâèòü èãðîêà" << endl; }

		if (choose_menu == 1) { cout << " -> Ðåäàêòèðîâàòü èãðîêîâ" << endl; }
		else { cout << " Ðåäàêòèðîâàòü èãðîêîâ" << endl; }

		if (choose_menu == 2) { cout << " -> Ïðîñìîòð âñåõ èãðîêîâ" << endl; }
		else { cout << " Ïðîñìîòð âñåõ èãðîêîâ" << endl; }

		if (choose_menu == 3) { cout << " -> Çàâåðøèòü ïðîãðàììó" << endl; }
		else { cout << " Çàâåðøèòü ïðîãðàììó" << endl; }

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
		cout << "Ñòðåëî÷êàìè ÂÂÅÐÕ è ÂÍÈÇ âûáåðèòå ïóíêò ìåíþ" << endl;
		choose_menu = (choose_menu + (nPlayer + 1)) % (nPlayer + 1);

		for (int i = 0; i < nPlayer; i++)
			if (i == choose_menu) { cout << " -> " << i + 1 << " - " << players[i].getName() << endl; }
			else { cout << " " << i + 1 << " - " << players[i].getName() << endl; }

		if (choose_menu == nPlayer) { cout << " -> Âûéòè ñ âûáîðà èãðîêà" << endl; }
		else cout << " Âûéòè ñ âûáîðà èãðîêà" << endl;

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
		cout << "Ñòðåëî÷êàìè ÂÂÅÐÕ è ÂÍÈÇ âûáåðèòå ïóíêò ìåíþ" << endl;
		choose_menu = (choose_menu + 9) % 9;

		if (choose_menu == 0) { cout << " -> Íàçâàíèå êîìàíäû: " << players[choose].getNameTeam() << endl; }
		else cout << " Íàçâàíèå êîìàíäû: " << players[choose].getNameTeam() << endl;

		if (choose_menu == 1) { cout << " -> Ñòðàíà: " << players[choose].getCountry() << endl; }
		else cout << " Òèï Ñòðàíà: " << players[choose].getCountry() << endl;

		if (choose_menu == 2) { cout << " -> Êîë-âî èãðîêîâ: " << players[choose].getHowManyPlayers() << endl; }
		else cout << " Êîë-âî èãðîêîâ: " << players[choose].getHowManyPlayers() << endl;

		if (choose_menu == 3) { cout << " -> Êîë-âî âûèãðàííûõ ìàò÷åé: " << players[choose].getHowManyWinsy() << endl; }
		else cout << " Êîë-âî âûèãðàííûõ ìàò÷åé: " << players[choose].getHowManyWinsy() << endl;

		if (choose_menu == 4) { cout << " -> Èìÿ òðåíåðà: " << players[choose].getName() << endl; }
		else cout << " Èìÿ òðåíåðà: " << players[choose].getName() << endl;

		if (choose_menu == 5) { cout << " -> Ôàìèëèÿ òðåíåðà: " << players[choose].getSName() << endl; }
		else cout << " Ôàìèëèÿ òðåíåðà: " << players[choose].getSName() << endl;

		if (choose_menu == 6) { cout << " -> Èìÿ èãðîêà: " << players[choose].getNamePlayer() << endl; }
		else cout << " Èìÿ èãðîêà: " << players[choose].getNamePlayer() << endl;

		if (choose_menu == 7) { cout << " -> Ôàìèëèÿ èãðîêà: " << players[choose].getSNamePlayer() << endl; }
		else cout << " Ôàìèëèÿ èãðîêà: " << players[choose].getSNamePlayer() << endl;

		if (choose_menu == 8) { cout << " -> Âûéòè â ìåíþ âûáîðà " << endl; }
		else cout << " Âûéòè â ìåíþ âûáîðà " << endl;


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
