#ifndef list_INCL_GUARD
#define list_INCL_GUARD
#include"Node.h"

/* The List class is the storage Class for the project and contains
   a pointer to the head node.
   
   The List is able to create, remove and show nodes in addition to
   opening them and allowing a user to interact with the data object inside
   either a Customer or Account.
*/

class List
{

private:
	Node* head;
public:
	List();
	bool createNode(Object* newData);
	void removeNode(std::string);
	void showList();
	void openNode(std::string);
	void deleteList();	
};

#endif