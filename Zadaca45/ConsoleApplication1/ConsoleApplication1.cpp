#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string Kodiranje(string niza, int kod)
{
	for (int i = 0; i < niza.size(); i++) // funkcijata se vrsi za sekoj karakter od nizata
	{
		niza[i] = char((int(niza[i] + kod))); // se zgolemuva vrednosta na ASCII, taka shto se dodava vrednost od kod 
	}
	return niza;
}

string Dekodiranje(string niza, int kod) // na ist nacin kako i kodiranjeto samo shto ovde se namaluva vrednosta na ASCII taka shto se odzema so vrednosta na kod
{
	for (int i = 0; i < niza.size(); i++)
	{
		niza[i] = char((int(niza[i] - kod)));
	}
	return niza;
}

bool Validateinput(string niza) // vo ovoj loop se proveruva dali ima simbol vo tekstot 
{
	for (int i = 0; i < niza.size(); i++) // funkcijata se vrsi za sekoj karakter od nizata
	{

		if (!std::isdigit(niza.at(i)) && !std::isalpha(niza.at(i)) && niza.at(i) != ' ') // ovde se proveruva dali imame bukva, broj ili prazno mesto. Dokolku ne e bukva, broj ili prazno mesto znachi deka e simbol
		{
			return false; // dolkolku e simbol e false
		}
	}

	return true; // nema simboli i e vo red
}

// Ovde se presmetuva brojot na cifri, se dodeka imame cifri counter se zgolemuva
int NOD(long long number)  // NOD - NumberOfDigits
{
	int counter = 0;
	while (number != 0)
	{
		number = number / 10;
		++counter;
	}
	return counter;
}

int main()
{

	int opcija;
	cout << "Izberete opcija: " << endl;
	cout << "1. Kodiranje" << endl;
	cout << "2. Dekodiranje" << endl;
	cin >> opcija; // go zema inputot koj kje bide vnesen preku tastatura

	long long number = 0;  // koristime koga sakame da smestime broj so povekje cifri otkolku shto sobira vo int
	int kod = 0;

	// do while loopot prvo ja izvrsuva funkcijata potoa ja proveruva, vo ovoj slucaj prvo dobivame poraka deka treba da vnesime broj a potoa se proveruva dali e podolg od 10 cifri
	do
	{
		cout << "Vnesete broj ne podolg od 10 cifri: " << endl;
		cin >> number;
		kod = NOD(number); // number of digits ( broj na cifri ) 
		if (number <= 0 || kod > 10) // proveruva dali br e pogolem ili = na 0, ili dali e pogolem od 10 cifri, dokolku ne e izleguva od do while loopot
		{
			cout << "Vnesete pozitiven broj, so najmnogu 10 cifri!" << endl;
		}

	} while (number <= 0 || kod > 10);
	string niza;
	cin.ignore();
	do // ovaj do while loop go proveruva tekstot
	{
		cout << "Vnesete niza: " << endl;
		getline(cin, niza);
		if (niza.size() > 400) // proveruva dali tekstot e pomal od 400 karakteri
		{
			cout << "Vnesete niza pomala od 400 karakteri!" << endl;
		}
		else if (opcija == 1 && Validateinput(niza) == false) // go proveruva tekstot samo ako e izbrana prvata opcija  
// dokolku ne e vo red ni se ispisuva tekst, dokolku e vo red izleguvame od do while loop
		{
			cout << "Vnesete niza samo so bukvi, brojki i prazni mesta!" << endl;
		}
		else
		{
			break;
		}
	} while (true);


	if (opcija == 1)
	{
		auto rezultat = Kodiranje(niza, kod); // rezultatot avtomatski se prezema od funkcijata kodiranje
		cout << "Kodiraniot tekst e: " << rezultat << endl;
	}
	if (opcija == 2)
	{
		auto rezultat = Dekodiranje(niza, kod); // rezultatot avtomatski se prezema od funkcijata dekodiranje
		cout << "Dekodiraniot tekst e: " << rezultat << endl;
	}

	return 0;
}
