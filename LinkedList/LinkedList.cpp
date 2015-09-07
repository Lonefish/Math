#include <iostream>
#include "LinkedList.h"
#include <string.h>


int main() {
	std::string s = "123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456123456";
	LinkedList *l = new LinkedList(s.at(0) - '0');
	for(int i = 1; i < s.length(); i++) {
		l->createNewNodeAtEnd(s.at(i) - '0');
	}
	l->printList();
	return 0;
}


/*
 * Insert node at index 'i'.
 * Root node counts as index 0.
 * Inserting a node at index 1 would mean it pushes the node at index 1 to index 2.
 */
void LinkedList::insertNodeAt(int i, int x) {
	if(i == 0) {
		insertNodeAtBeginning(x);
		return;
	}
	conductor = root;
	node *temp = new node();
	temp->x = x;
	if (conductor != 0) {
		while (conductor->next != 0 && i > 1) {
			i--;
			//goto next item
			conductor = conductor->next;
		}
		temp->next = conductor->next;
		conductor->next = temp;
	}
}

void LinkedList::insertNodeAtBeginning(int x) {
	node *temp = new node();
	temp->x = x;
	temp->next = root;
	root = temp;
}


void LinkedList::createNewNodeAtEnd(int i) {
	end->next = new node;  // Creates a node at the end of the list
	end = end->next; // Points to that node
	end->next = 0;         // Prevents it from going any further
	end->x = i;
}

void LinkedList::printList() {
	conductor = root;
	//looping function to the end
	if (conductor != 0) {
		while (conductor->next != 0) {
			std::cout << conductor-> x << "\n";

			//goto next item
			conductor = conductor->next;
		}
		std::cout << conductor->x;
	}
}


LinkedList::LinkedList(int x) {
	// TODO Auto-generated constructor stub
	root = new node; // Now root points to a node struct
	root->next = 0;  // The node root points to has its next pointer
					 //  set equal to a null pointer
	root->x = x;     // By using the -> operator, you can modify the node
					 //  a pointer (root in this case) points to.

	conductor = root;
	end = root;
}

LinkedList::~LinkedList() {
	// TODO Auto-generated destructor stub
}

