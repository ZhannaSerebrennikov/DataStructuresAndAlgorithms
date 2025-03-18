#include <iostream>
#include "LinkedList.h"
#include "QueueLL.h"

int main()
{
	QueueLL myQueue;
	myQueue.enQueue(10);
	myQueue.enQueue(20);

	std::cout << "Queue front: " << myQueue.getFront() << std::endl;
	std::cout << "Queue rear: " << myQueue.getRear() << std::endl;
	
	myQueue.deQueue();
	myQueue.deQueue();

	myQueue.enQueue(30);
	myQueue.enQueue(40);
	myQueue.enQueue(50);

	std::cout << "Queue front: " << myQueue.getFront() << std::endl;
	std::cout << "Queue rear: " << myQueue.getRear() << std::endl;

	return 0;
}