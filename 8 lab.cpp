#include <iostream>
#include <conio.h>
#include <string>

using namespace std;
int mainMenu();
int menuOfClients();

template <class T>
class Document {
	T data;
public:
	Document() {}
	Document(T dat) {
		data = dat;
	}
	void Show() {
		cout << data << endl;
	}
	void Change(T dat) {
		data = dat;
	}
	void Add(T dat) {
		data += dat;
	}
	~Document()
	{

	}
};

template <class T1>
struct Status {		//Состояние указателя
	T1* RealPtr;
	int Count;
};

template<class T1>
class SmartDocument {	//Класс-указатель
	Status<T1>* StatusPtr;
public:
	T1* operator->()const {
		if (StatusPtr) return StatusPtr->RealPtr;
		else return NULL;
	}
	SmartDocument(T1* ptr = 0) {
		if (!ptr) StatusPtr = NULL;
		else {
			StatusPtr = new Status<T1>;
			StatusPtr->RealPtr = ptr;
			StatusPtr->Count = 1;
		}
	}
	SmartDocument(const SmartDocument<T1>& p) :StatusPtr(p.StatusPtr) {
		if (StatusPtr) StatusPtr->Count++;
	}
	SmartDocument<T1>& operator=(const SmartDocument<T1>& p) {
		if (StatusPtr) {
			StatusPtr->Count--;
			if (StatusPtr->Count <= 0) {
				delete StatusPtr->RealPtr;
				delete StatusPtr;
			}
		}
		StatusPtr = p.StatusPtr;
		if (StatusPtr) StatusPtr->Count++;
		return *this;
	}
	~SmartDocument() {
		if (StatusPtr) {
			StatusPtr->Count--;
			if (StatusPtr->Count <= 0) {
				delete StatusPtr->RealPtr;
				delete StatusPtr;
			}
		}
		cout << "Указатель удален" << endl;
	}
};

int main() {
	setlocale(0, "rus");
	SmartDocument<Document<string>> pt1(new Document<string>);
	SmartDocument<Document<string>> pt2 = pt1;
	SmartDocument<Document<string>> pt3(new Document<string>);
	SmartDocument<Document<string>> pt4 = pt3;
	string str;
	bool exit;
	while (true) {
		switch (menuOfClients()) {
		case 0:
			exit = true;
			while (exit) {
				switch (mainMenu())
				{
				case 0:
					cout << "Введите информацию, которую необходимо добавить:";
					cin >> str;
					pt1->Add(str);
					break;
				case 1:
					cout << "Введите информацию, которую необходимо добавить:";
					cin >> str;
					pt3->Add(str);
					break;
				case 2:
					cout << "Введите информацию:";
					cin >> str;
					pt1->Change(str);
					break;
				case 3:
					cout << "Введите информацию:";
					cin >> str;
					pt3->Change(str);
					break;
				case 4:
					cout << "\t Документ №1" << endl;
					pt1->Show();
					cout << "\t Документ №2" << endl;
					pt3->Show();
					system("pause");
					break;
				case 5:
					exit = false;
					break;
				}
			}
			break;
		case 1:
			exit = true;
			while (exit) {
				switch (mainMenu())
				{
				case 0:
					cout << "Введите информацию, которую необходимо добавить:";
					cin >> str;
					pt2->Add(str);
					break;
				case 1:
					cout << "Введите информацию, которую необходимо добавить:";
					cin >> str;
					pt4->Add(str);
					break;
				case 2:
					cout << "Введите информацию:";
					cin >> str;
					pt2->Change(str);
					break;
				case 3:
					cout << "Введите информацию:";
					cin >> str;
					pt4->Change(str);
					break;
				case 4:
					cout << "\tДокумент №1" << endl;
					pt2->Show();
					cout << "\tДокумент №2" << endl;
					pt4->Show();
					system("pause");
					break;
				case 5:
					exit = false;
					break;
				}
			}
			break;
		case 2:
			cout << "Документ сформирован" << endl;
			return 0;
		}
	}
}


int mainMenu()
{
	int choiceButton = 0, button = 0;
	system("cls");
	while (true)
	{
		choiceButton = (choiceButton + 6) % 6;

		if (choiceButton == 0) cout << "-Добавление информации к документу №1" << endl;
		else cout << "Добавление информации к документу №1" << endl;

		if (choiceButton == 1) cout << "-Добавление информации к документу №2" << endl;
		else cout << "Добавление информации к документу №2" << endl;

		if (choiceButton == 2) cout << "-Изменение документа №1" << endl;
		else cout << "Изменение документа №1" << endl;

		if (choiceButton == 3) cout << "-Изменение документа №2" << endl;
		else cout << "Изменение документа №2" << endl;

		if (choiceButton == 4) cout << "-Просмотр всех документов" << endl;
		else cout << "Просмотр всех документов" << endl;

		if (choiceButton == 5) cout << "-Выход" << endl;
		else cout << "Выход" << endl;

		button = _getch();
		if (button == 224)
		{
			button = _getch();
			if (button == 72) choiceButton--;
			if (button == 80) choiceButton++;
		}
		if (button == 13) {
			system("cls");
			return choiceButton;
		}
		system("cls");
	}
}

int menuOfClients()
{
	int choiceButton = 0, button = 0;
	system("cls");
	while (true)
	{
		choiceButton = (choiceButton + 3) % 3;

		if (choiceButton == 0) cout << "-Сотрудник №1" << endl;
		else cout << "Сотрудник №1" << endl;

		if (choiceButton == 1) cout << "-Сотрудник №2" << endl;
		else cout << "Сотрудник №2" << endl;

		if (choiceButton == 2) cout << "-Завершить работу с документами" << endl;
		else cout << "Завершить работу с документами" << endl;

		button = _getch();
		if (button == 224)
		{
			button = _getch();
			if (button == 72) choiceButton--;
			if (button == 80) choiceButton++;
		}
		if (button == 13) {
			system("cls");
			return choiceButton;
		}
		system("cls");
	}
}
