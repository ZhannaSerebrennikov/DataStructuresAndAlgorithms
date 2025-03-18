#pragma once
#include <iostream>

class Node {
public:
	int data;
	Node* ptrNext;

	Node(int _data)
	{
		this->data = _data;
		ptrNext = nullptr;
	}
};

class LinkedList {
private:
	Node* head;
	Node* tail;
public:
	LinkedList(int _data);
	Node* Head();
	Node* Tail();
	void AddNodeToTheTail(int _data);
	void PrintLinkedList();

	void DeleteMiddleNode();
	void Merge(LinkedList& _secondLL);
	void  TraverceCircularList();
	void DeleteFirstNodeFromCircularList();
	void DeleteLastNodeFromCircularList();
	void DeleteSpecificNodFromCircularList(int data);
	void DeleteNodeWithoutHead(Node* node);
};
