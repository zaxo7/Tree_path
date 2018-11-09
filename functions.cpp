#include "functions.h"

list* spot_found = NULL;
list* spot_check = NULL;


//////////// Liste chainée

List::List()
{
	first_member = new list;


	first_member->next[0] == NULL;
	first_member->prev[0] == NULL;
	first_member->branch_count == 0;
	first_member->generation == 0;

	element_count = 1;


		
	current_member = first_member;
}
List::List(char first_member_value)
{
	first_member = new list;

	first_member->member = first_member_value;

	first_member->next[0] == NULL;
	first_member->prev[0] == NULL;
	first_member->branch_count == 0;
	first_member->generation == 0;

	element_count = 1;


		
	current_member = first_member;
}

List::~List()
{
	rest();
	for(int i = 0; i < 5; i++)
	{
		
	}
}

bool List::push_after(char new_member, int branch) 
{
	if (first_member == NULL)
		return 0;

	static int g = 0; // generation helps when we print the tree

	current_member->next[branch] = new list;

	current_member->next[branch]->member = new_member;
	current_member->next[branch]->branch_count = 0;


	current_member->next[branch]->prev[0] = current_member;
	for(int i = branch; i < 5; i++) // set all the branches of the new node to NULL
	{
		current_member->next[branch]->next[i] = NULL;
	}
	


	element_count++; 
	current_member = current_member->next[branch];

	if(branch == 0)
	{
		g++;
		current_member->generation = g;
	}
	else
	{
		current_member->prev[0]->branch_count++;
		current_member->generation = g;
	}

	return 1;
}
bool List::push_curr(char new_member) 
{
	if (first_member == NULL)
		return 0;

	current_member->member = new_member;
	current_member->branch_count = 0;
	current_member->generation = 0;

	return 1;
}

bool List::step_back(int branch)
{
	if(current_member == NULL)
		return 0;

	current_member = current_member->prev[branch];

	return 1;
}
bool List::step_back_(void) 
{
	spot_found = spot_found->prev[0];
	return 1;
}
bool List::step_forw(int branch)
{
	if(current_member == NULL)
		return 0;
	else if(current_member->next[branch] == NULL)
	{
		std::cout << "it's NULL" << std::endl;
		return 0;
	}

	current_member = current_member->next[branch];

	return 1;
}
void List::rest(void)
{	
	current_member = first_member;

}


void List::print_curr(void)
{
	std::cout << current_member->member << current_member->branch_count << std::endl;
}



// read from file the tree

bool List::read(std::string const path)
{
	std::ifstream F(path.c_str());

	if(!F)
		return 0;

	int Branch = 0;
	char c(0);

	c=F.get();

	push_curr(c);
	char branch_div;
	do
	{

		if(c == '>')
		{
			c=F.get();
			push_after(c,Branch);
			Branch = 0;
		}
		else if(c == '<')
		{
			c=F.get();
			if(c == branch_div)
			{
				Branch=2;
			}
			else
			{
				Branch++;
			}
			branch_div = c; //store and find the begin of branch
			step_back(); //step back until we reach the branch begin 
			while(current_member->member != branch_div)
			{
				step_back();
			}
		}

		c=F.get();

	}while(c != EOF);
	current_member->next[0] = NULL;

	return 1;
}

void List::path(char start_point, char arrival)
{
	bool s = false;
	if(start_point > arrival)
	{
		char t = start_point;
		start_point = arrival;
		arrival = t;
		s = true;
	}
	//find the start spot 
	search(start_point,first_member,0);
	if(spot_found == NULL)
	{
		std::cout << "start point not found" << std::endl;
		return ;
	}
	spot_check = spot_found;
	spot_found = NULL;
	//find the arrival spot with
	search(arrival,first_member,0);
	if(spot_found == NULL)
	{
		std::cout << "arrival point not found" << std::endl;
		return ;
	}

	//go back until we reach the start spot at the same time we fill the table of path
	char* path = new char[1];
	int i = 0;
	while(spot_found->member != start_point)
	{
		path[i] = spot_found->member;
		step_back_();
		i++;
	}
	path[i] = spot_found->member;
	path[i+1] = '\0';
	//if the start and arrival not switched
	if(!s)
		permut(path,i); //reverse the table of path

	//print the table of path

	std::cout << path[0] ;

	for(int j = 1; j <= i; j++)
	{
		std::cout << " > "<< path[j] ;
	}
}
void List::search(char point, list* tmp, int b)
{
	if(tmp == NULL)
	{
		tmp = first_member;
	}
	if(spot_found != NULL) // ignore all the other functions when we find the spot
		return ;


	if(tmp->member == point)
	{
		spot_found = tmp;
		return ;
	}
	else if(tmp->next[0] != NULL)
	{
		//std::cout << "i am in " << tmp->member << " " << tmp->branch_count << std::endl;
		//check all the branches
		search(point,tmp->next[0],0);
		if(tmp->next[1] != NULL)
		{
			search(point,tmp->next[1],1);
		}
		if(tmp->next[2] != NULL)
		{
			search(point,tmp->next[2],2);
		}
		if(tmp->next[3] != NULL)
		{
			search(point,tmp->next[3],3);
		}
	}
	else
	{
		//std::cout << "i am in " << tmp->member << " " << tmp->branch_count << std::endl;
		return ;
	}
}

void List::print(list* start_point, int branch)
{
	if(start_point == NULL)
	{
		current_member = first_member;
	}
	else
	{
		current_member = current_member->next[branch];
	}
		loop:if(current_member->next[branch] == NULL)
		{
			std::cout << current_member->member << " with " << current_member->branch_count << " with " << current_member->generation << " < ";
		}
		else
		{
			std::cout << current_member->member << " with " << current_member->branch_count << " with " << current_member->generation << " < ";
			if(current_member->branch_count > 0)
			{
				for(int i = branch; i <= current_member->branch_count; i++)
				{
					print(current_member,i+1);
					branch = 0;
				}
			}
			current_member = current_member->next[branch];
			goto loop;
		}

	std::cout << std::endl;
}

void permut(char* tab , int i)
{
	int j = 0;
	char t;
	while(j < i)
	{
		t = tab[i];
		tab[i] = tab[j];
		tab[j] = t;
		i--;
		j++;
	}
}