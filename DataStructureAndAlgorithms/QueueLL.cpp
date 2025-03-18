#include "QueueLL.h"

QueueLL::QueueLL() : front(nullptr), rear(nullptr)
{
}

void QueueLL::enQueue(int value_)
{
	QNode* temp = new QNode(value_);
	if (isEmpty())
	{
		front = temp;
		rear = temp;
		return;
	}
	rear->ptrNext = temp;
	rear = rear->ptrNext;
}

void QueueLL::deQueue()
{
	if (isEmpty())
	{
		return;
	}
	QNode* temp = front;
	front = front->ptrNext;
	if (front == nullptr)
	{
		rear = nullptr;
	}
	temp->ptrNext = nullptr;
	delete(temp);
}

bool QueueLL::isEmpty()
{
	if (front == nullptr)
	{
		return true;
	}
	return false;
}

int QueueLL::getFront()
{
	if (isEmpty())
	{
		return INT_MIN;
	}
	return front->value;
}

int QueueLL::getRear()
{
	if (isEmpty())
	{
		return INT_MIN;
	}
	return rear->value;
}

void QueueLL::print()
{
	QNode* temp = front;
	while (temp)
	{
		std::cout << temp->value << std::endl;
		temp = temp->ptrNext;
	}
}