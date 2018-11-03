#include "functions.h"

extern int arrive;
extern bool rel[N][N] , b;

int* path_tab = NULL;

void path(int depart)
{
	if(b)
		return ;
	switch(depart)
	{
		case A:
		std::cout << "A > " ;
		break;
		case B:
		std::cout << "B > " ;
		break;
		case C:
		std::cout << "C > " ;
		break;
		case D:
		std::cout << "D > " ;
		break;
		case E:
		std::cout << "E > " ;
		break;
		case F:
		std::cout << "F > " ;
		break;
	}
	for(int i = 0; i < N; i++)
	{
		if(rel[depart][arrive])
		{
			switch(arrive)
			{
				case A:
				std::cout << "A" ;
				break;
				case B:
				std::cout << "B" ;
				break;
				case C:
				std::cout << "C" ;
				break;
				case D:
				std::cout << "D" ;
				break;
				case E:
				std::cout << "E" ;
				break;
				case F:
				std::cout << "F" ;
				break;
			}
			b++;
			break;
		}
		if(rel[depart][i])
		{
			path(i);
		}
	}

}