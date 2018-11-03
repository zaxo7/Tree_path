#ifndef DEF_func
#define DEF_func
#include <iostream>
#include <fstream>
//#include <thread>

struct list
{
	list *prev[5];
	char member; // the leaf :D
	int branch_count; //nember of branches
	int generation; //the generation (level)
	list *next[5]; //we can put until 5 branches
};
typedef struct list list;


void permut(char* tab,int i); //permute un tableaux

class List
{
public:
	List();
	List(char first_member_value);

	bool push_after(char new_member = 'N', int branch = 0); // add after the current member // the branch is the direction (which branch)
	bool push_curr(char new_member = 'N'); // add the current member 
	bool step_back(int branch = 0); // récule avec un pas
	bool step_back_(void); // récule avec un pas //version for the spot_found

	bool step_forw(int branch = 0); // avance avec un pas


	bool push_back(char new_member = 0); // add the last member of list
	bool pop_back(void); // remove the last member of list
	bool pop_front(void); // remove the first element
	bool push_front(char new_member = 0); // add to the begining
	void rest(void); //set the current element to the first one 
	void path(char start_point, char arrival); // give the path between twoo points
	void search(char point, list* tmp = NULL, int b=0);

	void print(list* start_point = NULL, int branch = 0); // print the list
	void print_curr(void); //print current element


	bool read(std::string const path = "tree.txt"); // read the tree from the file
private:
	int element_count; //number of nodes
	list* first_member; //first node
	list* current_member; // current node
};


#endif