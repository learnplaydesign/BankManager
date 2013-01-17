#include"List.h"
#include<iostream>
#include<string>

List::List()
{
	head = NULL;
}

/* Creates a node with a pointer to an object on the heap at the top of the list */

bool List::createNode(Object* newData)
{
	// Create a pointer to a pointer of a node
	Node** headref = &head;

	Node* newNode = new Node();
	newNode->data = newData;
	newNode->next = *headref; // Dereference so that it points at the head
	*headref = newNode; 
	std::cout << "object added" << std::endl;
	return true;
}

/*
	Remove a chosen Node from the List 
	problem : cant delete from empty list or delete an object that doesnt exist
*/

void List::removeNode(std::string name)
{
	/*
		Removes a node from the list by calling it's destructor.
	*/
	Node* current = head;
	Node* previousNode = new Node();
	Node* nextNode = new Node();
	bool itemFound = false;

	/*
		Check list isn't empty
	*/

	if(head != NULL)
	{
		/* 
			While there is a next node and current isn't NULL
		*/

		while(current != NULL)
		{
			previousNode = current;
			
			if(current->data->getName() == name)
			{
				// Item found, set to true
				itemFound = true;
				std::cout << "Object Found" << std::endl;
				break;
			}

			// If there is more then one object in the list
			if(current->next != NULL)
			{
				std::cout << "new current" << std::endl;
				current = current->next;
			}
			else
			{
				break;
			}
		}

		// If the item was found

		if(itemFound)
		{
			//If the node isn't the head of the list

			if(current->data->getName() != head->data->getName())
			{
				nextNode = current->next;
				previousNode->next = nextNode;
				delete current;
			}

			// Is the current the head and are there oter objects in the list

			if(current->next != NULL && current == head)
			{
				nextNode = current->next;
				delete head->data;
				head->data = nextNode->data;
				head->next = nextNode->next;
				std::cout << "object removed" << std::endl;
			}

			// The object is the only object in the list

			else
			{
				delete current;
				head = NULL;
				std::cout << "object removed" << std::endl;
			}

		}

		else
		{
			std::cout << "ERROR: No such object" << std::endl;
		}

	}

	else
	{
		std::cout << "ERROR: Empty list" << std::endl;
	}
}

/* Print a list of the objects stored in the list */

void List::showList()
{
	// Iterate through the list and call the print of each data object.
	Node* current = head;
	int count = 1;
	while(current != NULL)
	{
		std::cout << count << ":";
		if(current->data == NULL)
		{
			std::cout << "No Data to show" << std::endl;
			break;
		}
		current->data->print(std::cout);
		current = current->next;
		count++;

	}

	if(current == NULL)
	{
		std::cout << "empty list" << std::endl;
	}
}

/* Open and allow interaction with an object in the list */

void List::openNode(std::string name)
{
	// Iterate through the list
	Node* current = head;
	std::string currentID;

	while(current != NULL)
	{
		// Compare input name to the ID of the data
		//std::cout << "setting ID";
		currentID = current->data->getName();

		if(currentID == name)
		{
			//std::cout << "match";
			current->data->displayOptions();
		}
		current = current->next;


	}

	if(current == NULL)
	{
		std::cout << "error no such object" << std::endl;
	}
}

/*
	Delete the entire list starting with the head and then storing the next node
*/

void List::deleteList()
{
	Node* current = head;
	Node* nextNode = NULL;

	while(current != NULL)
	{	
		// Is there a next node
		if(current->next != NULL)
		{
			nextNode = current->next;
		}

		// Is current NULL
		if(current != NULL)
		{
			delete current;
		}


		if(nextNode != NULL)
		{
			current = nextNode;
			nextNode = NULL;
		}

		else
		{
			head = NULL;
			current = NULL;
		}


	}
}
