/*
 * LinkedList.h
 *
 *  Created on: Sep 5, 2015
 *      Author: lonefish
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
struct node {
	int x;
	node *next;
};
class LinkedList {
public:
	int main();
	node *root; //first node
	node *conductor; //looping pointer
	node *end; //end of list
	void createNewNodeAtEnd(int i);
	void insertNodeAt(int i, int x);
	void insertNodeAtBeginning(int x);
	void printList();
	LinkedList();
	virtual ~LinkedList();
};

#endif /* LINKEDLIST_H_ */
