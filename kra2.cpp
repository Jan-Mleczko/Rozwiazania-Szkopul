#include <iostream>
using namespace std;

/*#define TRACE 1*/

unsigned int wysokosc, krazki;
unsigned int *rurka;

unsigned int i, j;

unsigned int srednica, dno;

int main () {
	cin.sync_with_stdio (false);

	cin >> wysokosc;
	cin >> krazki;
#ifdef TRACE
	cout << "Wysokosc rurki: " << wysokosc
			<< "\nIlosc krazkow: " << krazki << '\n';
#endif
	
	rurka = new unsigned int[wysokosc];
	i = 0;
	do
		cin >> rurka[i];
		while (++i < wysokosc);
		
	
	srednica = *rurka;
	i = 1;
	while (i < wysokosc) {
		if (rurka[i] < srednica)
			srednica = rurka[i];
		else
			rurka[i] = srednica;
#ifdef TRACE
		cout << "Na " << i << " prog wynosi " << srednica << '\n';
#endif
		++i;
		}
	
	dno = wysokosc;
	i = krazki;
	do {
		cin >> srednica;		
#ifdef TRACE
		cout << "Krazek o srednicy " << srednica << '\n';
#endif

		while (dno && rurka[--dno] < srednica);

#ifdef TRACE
		cout << " ...wyladowal na glebokosci " << dno << '\n';
#endif
		} while (--i);
	
	delete [] rurka;
	
	if (dno)
	        ++dno;
	cout << dno;
	
	return 0;
	}
