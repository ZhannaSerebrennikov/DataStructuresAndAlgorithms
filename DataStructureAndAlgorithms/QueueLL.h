#pragma once
#include <iostream>

class QNode {
public:
	int value;
	QNode* ptrNext;

	QNode(int value_) {
		value = value_;
		ptrNext = nullptr;
	}
};
class QueueLL {
private:
	QNode* front;
	QNode* rear;

public:
	QueueLL();
	void enQueue(int value_);
	void deQueue();
	bool isEmpty();
	int getFront();
	int getRear();
	void print();
 };