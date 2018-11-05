#include <iostream>
#include "functions.h"

using namespace std;

int arrive = F;
char* paths = new char[1];
bool b = false,d = false;

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

	/*cout << "Donner la ville de depart :";
    cin >> tmp;
    depart=tmp - 65;

    cout << "Donner la ville de d'arrive :";
	cin >> tmp;
	arrive=tmp - 65;*/

	path(1);
	// si b false il n ya pas de chemain 
	if(!b)
		cout << "no way ;D" << endl;

	cout << paths[0] ;
	int j = 1;
	while(/*paths[j] >= 65 && paths[j] < 65+27*/j < 10)
	{
		cout << " > " << paths[j] ;
		j++;
	}



	return 0;
}