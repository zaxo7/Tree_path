#include <iostream>
#include "functions.h"

using namespace std;

int arrive = D;
bool b = false;

bool rel[N][N] = {
		0, 1, 0, 0, 0, 0,
		1, 0, 1, 1, 0, 0,
		0, 1, 0, 0, 1, 1,
		0, 1, 0, 0, 0, 0,
		0, 0, 1, 0, 0, 0,
		0, 0, 1, 0, 0, 0,
	};

int main(int argc, char const *argv[])
{

	int depart;


	char tmp;

	cout << "Donner la ville de depart :";
    cin >> tmp;
    depart=tmp - 65;

    cout << "Donner la ville de d'arrive :";
	cin >> tmp;
	arrive=tmp - 65;

	path(depart);
	if(!b)
		cout << "no way ;D" << endl;



	return 0;
}