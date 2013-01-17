#ifndef node_INCL_GUARD
#define node_INCL_GUARD

#include"Object.h"

class Node
{

public:
	Object* data;
	Node* next;
	Node(){data = NULL; next = NULL;};
	~Node(){delete data;};
};
#endif