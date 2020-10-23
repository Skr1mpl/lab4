#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

void Bel();
void Rus();
void Uk();
int chooseMenu();
string writeWords();
int writeNumbers();

class History {
protected:
	string whoAttac;
	string whoDefens;
public:
	History(string w, string w1) {
		whoAttac = w;
		whoDefens = w1;
	}
	void showData();
};

class BelarusHistory:public History {
private:
	int yearOfWarInBel;
	int yearOfEndWarInBel;
	string capital;
public:
	BelarusHistory(string w, string w1, int yo, int yo1, string c) :History(w, w1) {
		yearOfWarInBel = yo;
		yearOfEndWarInBel = yo1;
		capital = c;
	}
	void showDataBel();
};

class RussianHistory :public History {
private:
	int yearOfWarInRus;
	int yearOfEndWarInRus;
	string town;
public:
	RussianHistory(string w, string w1, int yo, int yo1, string t) :History(w, w1) {
		yearOfWarInRus = yo;
		yearOfEndWarInRus = yo1;
		town = t;
	}
	void showDataRus();
};

class UkrainHistory :public History {
private:
	int yearOfWarInUk;
	int yearOfEndWarInUk;
	string president;
public:
	UkrainHistory(string w, string w1, int yo, int yo1, string p) :History(w, w1) {
		yearOfWarInUk = yo;
		yearOfEndWarInUk = yo1;
		president = p;
	}
	void showDataUk();
};

void History::showData() {
	cout << "Агрессор - " << whoAttac << endl;
	cout << "Обороняющийся - " << whoDefens << endl;
}

void BelarusHistory::showDataBel(){
	cout << "Дата начало войны в Беларуси: " << yearOfWarInBel << endl;
	cout << "Дата окнчания войны в Беларуси: " << yearOfEndWarInBel << endl;
	cout << "Столица Беларуси: " << capital << endl;
}

void RussianHistory::showDataRus() {
	cout << "Дата начало войны в России: " << yearOfWarInRus << endl;
	cout << "Дата окнчания войны в России: " << yearOfEndWarInRus << endl;
	cout << "Горо на который напили - " << town << endl;
}

void UkrainHistory::showDataUk() {
	cout << "Дата начало войны в Украине: " << yearOfWarInUk << endl;
	cout << "Дата окнчания войны в Украине: " << yearOfEndWarInUk << endl;
	cout << "Президент - " << president << endl;
}

int main() {
	setlocale(0, "rus");
	while (true) {
		int choose = chooseMenu();
		if (choose == 0) Bel();
		else
			if (choose == 1) Rus();
			else
				if (choose == 2) Uk();
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
				if (Knopka == 13) {
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
				if (key == 13) break;
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

		if (choose_menu == 0) { cout << " -> История Беларуси" << endl; }
		else { cout << " История Беларуси" << endl; }

		if (choose_menu == 1) { cout << " -> История России" << endl; }
		else { cout << " История России" << endl; }

		if (choose_menu == 2) { cout << " -> История Украины" << endl; }
		else { cout << " История Украины" << endl; }

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

void Bel() {
	int y2, y3;
	string Attack, Defense, Capital;
	cout << "	История Беларуси" << endl;
	cout << "Введите Агрессора - ";
	Attack = writeWords();
	cout << endl;
	cout << "Введите Обороняющего - ";
	Defense = writeWords();
	cout << endl;
	cout << "Введите начало войны в Беларуси - ";
	y2 = writeNumbers();
	cout << endl;
	cout << "Введите окончание войны в Беларуси - ";
	y3 = writeNumbers();
	cout << endl;
	cout << "Введите столицу Беларуси - ";
	Capital = writeWords();
	BelarusHistory bel(Attack, Defense, y2, y3, Capital);
	system("cls");
	bel.showDataBel();
	bel.showData();
	system("pause");
	system("cls");
}

void Rus() {
	int y2, y3;
	string Attack, Defense, Town;
	cout << "	История России" << endl;
	cout << "Введите Агрессора - ";
	Attack = writeWords();
	cout << endl;
	cout << "Введите Обороняющего - ";
	Defense = writeWords();
	cout << endl;
	cout << "Введите начало войны в России - ";
	y2 = writeNumbers();
	cout << endl;
	cout << "Введите окончание войны в России - ";
	y3 = writeNumbers();
	cout << endl;
	cout << "Введите город на который напали - ";
	Town = writeWords();
	RussianHistory rus(Attack, Defense, y2, y3, Town);
	system("cls");
	rus.showDataRus();
	rus.showData();
	system("pause");
	system("cls");
}

void Uk() {
	int y2, y3;
	string Attack, Defense, President;
	cout << "	История Украины" << endl;
	cout << "Введите Агрессора - ";
	Attack = writeWords();
	cout << endl;
	cout << "Введите Обороняющего - ";
	Defense = writeWords();
	cout << endl;
	cout << "Введите начало войны в Украине - ";
	y2 = writeNumbers();
	cout << endl;
	cout << "Введите окончание войны в Украине - ";
	y3 = writeNumbers();
	cout << endl;
	cout << "Введите фамилию президента - ";
	President = writeWords();
	UkrainHistory uk(Attack, Defense, y2, y3, President);
	system("cls");
	uk.showDataUk();
	uk.showData();
	system("pause");
	system("cls");
}