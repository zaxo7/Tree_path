#include <iostream>
#include "functions.h"

using namespace std;

int main(int argc, char const *argv[])
{
	
	List tree;

	tree.read(); // read the tree from the file

    tree.rest();

    char arrive,depart;

    cout << "Donner la ville de départ :";
    cin >> depart;
    cout << "Donner la ville de d'arrivé :";
    cin >> arrive;

    tree.path(depart,arrive);

    cout << endl;
    while(1);

	/*int br;
	string input;
	while(1)
	{
		cin >> input >> br;
		if(input == "print")
		{
			tree.print_curr();
		}
		else if(input =="forw")
		{
			tree.step_forw(br);
			tree.print_curr();
		}
		else if(input == "back")
		{
			tree.step_back(br);
			tree.print_curr();
		}
		else if(input == "rest")
		{
			tree.rest();
		}

	}*/
	return 0;
}