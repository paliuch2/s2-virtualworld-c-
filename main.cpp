#pragma once

#include <iostream>
#include "Swiat.h"
#include <time.h>
#include <windows.h>
#include <conio.h>

using namespace std;

int main() {

	
	
	srand(time(NULL));

	
	Swiat* swiat = new Swiat(20, 20);

	while (true) {
		cout << " Kamil Paluszewski 180194 \n";
		swiat->rysujSwiat();
		swiat->wyswietlKomunikaty();
		swiat->wykonajTure();
		Sleep(1000);
		system("cls");
	}

	delete(swiat);

	return 0;
}
