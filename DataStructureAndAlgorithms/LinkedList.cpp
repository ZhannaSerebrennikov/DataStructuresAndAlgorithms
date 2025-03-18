#include "LinkedList.h"

LinkedList::LinkedList(int _data)
{
	Node* newNode = new Node(_data);
	head = newNode;
	tail = newNode;
}

Node* LinkedList::Head()
{
	return head;
}

Node* LinkedList::Tail()
{
	return tail;
}

void LinkedList::AddNodeToTheTail(int _data)
{
	Node* newNode = new Node(_data);
	if (head == nullptr)
	{
		head = newNode;
	}
	Node* temp = head;
	while (temp->ptrNext != nullptr)
	{
		temp = temp->ptrNext;
	}
	temp->ptrNext = newNode;
	tail = newNode;
}

void LinkedList::PrintLinkedList()
{
	Node* temp = head;
	while (temp)
	{
		std::cout << temp->data << std::endl;
		temp = temp->ptrNext;
	}
}

void LinkedList::DeleteMiddleNode()
{
	//Given a singly linked list. The task is to delete the middle node o the list
	Node* temp = head;
	int length = 0;

	if (head == nullptr)
	{
		return;
	}
	while (temp)
	{
		temp = temp->ptrNext;
		length++;
	}
	temp = head;
	for (int i = 0; i < (length / 2) - 1; i++)
	{
		temp = temp->ptrNext;
	}
	Node* nodeToDelete = temp->ptrNext;
	temp->ptrNext = temp->ptrNext->ptrNext;
	delete nodeToDelete;
}

void LinkedList::Merge(LinkedList& _secondLL)
{
	Node* temp1 = this->head;
	Node* temp2 = _secondLL.head;

	while (temp1 != nullptr || temp2 != nullptr)
	{
		Node* temp1Next = temp1->ptrNext;
		Node* temp2Next = temp2->ptrNext;
		temp1->ptrNext = temp2;
		temp1 = temp1Next;
		temp2->ptrNext = temp1Next;
		temp2 = temp2Next;
	}

	if (temp2 == nullptr)
	{
		_secondLL.head = temp1->ptrNext;
		temp1->ptrNext = nullptr;	
	}
}

void LinkedList::TraverceCircularList()
{
	if (head == nullptr)
	{
		return;
	}
	Node* curr = head;
	do {
		std::cout << curr->data << std::endl;
		curr = curr->ptrNext;
	} while (curr != head);
}

void LinkedList::DeleteFirstNodeFromCircularList()
{
	if (head == nullptr)
	{
		return;
	}
	Node* temp = head;
	if (head == tail)
	{
		head = nullptr;
		tail = nullptr;
		delete temp;
		return;
	}
	head = head->ptrNext;
	tail->ptrNext = head;
	temp->ptrNext = nullptr;
	delete temp;
}

void LinkedList::DeleteLastNodeFromCircularList()
{
	if (head == nullptr)
	{
		return;
	}
	Node* temp = tail;
	if (head == tail)
	{
		head = nullptr;
		tail = nullptr;
		delete temp;
		return;
	}
	temp = head;
	while (temp->ptrNext != tail)
	{
		temp = temp->ptrNext;
	}
	tail = temp;
	temp = temp->ptrNext;
	tail->ptrNext = head;
	temp->ptrNext = nullptr;
	delete temp;
}

void LinkedList::DeleteSpecificNodFromCircularList(int data)
{
	if (head->data == data)
	{
		DeleteFirstNodeFromCircularList();
	}
	Node* prev = nullptr;
	Node* temp = head;
	while (temp->data != data && temp != nullptr)
	{
		prev = temp;
		temp = temp->ptrNext;
	}
	if (temp == nullptr)
	{
		return;
	}
	else if (temp->ptrNext == nullptr)
	{
		DeleteLastNodeFromCircularList();
	}
	else {
		prev->ptrNext = temp->ptrNext;
		temp->ptrNext = nullptr;
		delete temp;
	}
}

void LinkedList::DeleteNodeWithoutHead(Node* node)
{
	Node* temp = node;
	Node* nextNode = node->ptrNext;
	if (temp->ptrNext == nullptr)
	{
		temp = nullptr;
	}
	else
	{
		temp->data = nextNode->data;
		temp->ptrNext = nextNode->ptrNext;
		nextNode->ptrNext = nullptr;
		delete nextNode;
	}
}