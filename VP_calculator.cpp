// VP_calculator.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include<fstream>
using namespace std;

int main()
{
	//Wczytanie danych z tabeli
	fstream tabela;
	tabela.open("tabela vp.txt", ios::in);
	if (tabela.good() == true) {
		cout << "Uzyskano dostep do pliku." << endl;
	}
	else {
		cout << "Brak dostepu do pliku." << endl;
	}
	string kosz;
	tabela >> kosz;
	int liczba_rozdan[10];
	for (int i = 0; i < 10; i++) {
		tabela >> liczba_rozdan[i];
	}
	cout << endl;
	float big[86][10];
	for(int imp=0; imp<86; imp++) {
		tabela >> kosz;
		for (int i = 0; i < 10; i++) {
			tabela >> big[imp][i];
		}
	}

	if (big[85][9] == 20) {
		cout << "Wczytano dane z tabeli."<<endl;
	}
	else {
		cout << "Nie wczytano danych z tabeli lub wczytano niepoprawnie." << endl;
	}
	//Wczytanie danych z konsoli
	int rozdania;
	int rozdania_id;
	bool test = 0;
	while (test != 1) {
		cout << "Podaj liczbe rozdan:" << endl;
		cin >> rozdania;
		for (int i = 0; i < 10; i++) {
			if (liczba_rozdan[i] == rozdania) {
				test = 1;
				rozdania_id = i;
			}
		}
		if (test != 1) {
			cout << "Nieprawidlowa liczba rozdan." << endl;
		}
	}
	int roznica;
	int sgn = 1;
	cout << "Podaj roznice IMPow:"<<endl;
	cin >> roznica;
	//zamiana IMP na VP
	if (roznica < 0) {
		sgn = -1;
		roznica *= -1;
	}
	if (roznica > 85) {
		roznica = 85;
	}
	if (sgn == 1) {
		cout << "VP = "<<big[roznica][rozdania_id];
	}
	else {
		cout <<"VP = "<<20.00 - big[roznica][rozdania_id];
	}
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
