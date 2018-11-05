#include "functions.h"

extern int arrive;
extern char* paths;
extern bool rel[N][N] , b,d;

int* path_tab = NULL;

void path(int depart)
{
	static int k = 0; // pour que la variable sera pas effacer aprée le break ou return

	if(b) // b sera vrée quand on trouve le chemin vers notre destination
		return ;
	if(k == 0)
	{
		paths[0] = depart + 65; //transformer le int vs char
		k++;
	}
	
	// il faut pas metre une ville deux fois dans un chemin
	d = false;
	for(int i = 0; i < k; i++)
	{
		if(paths[i] == (char)(depart+65))
			d = true;
	}
	if(!d) 
	{
		paths[k] = depart+65;
		k++;
	}

	// si on trouve une autre relation en appelle again la function
	for(int i = 0; i < N; i++)
	{
		if(rel[depart][arrive])
		{
			d = false;
			for(int i = 0; i < k; i++)
			{
				if(paths[i] == (char)(depart+65))
					d = true;
			}
			if(!d)
			{
				paths[k] = depart+65;
				k++;
			}
			b++;
			break;
		}
		if(rel[depart][i])
		{
			rel[depart][i] = 0;
			path(i);
		}
	}

}