#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <iomanip>
using std::cout; using std::endl;
using std::ostream; using std::underflow_error;

class Queue { //Class declaration
	public:
	Queue()                      {queueSize = queueCap = 0; queueAR = NULL; backSub = queueCap - 1;} //default constructor, sets intital values
	Queue(const Queue& other);
	~Queue()                     {queueAR = NULL;} //destructor that deletes the dynamic memory for the queue array
	Queue& operator=(const Queue& other);
	friend ostream& operator<<(ostream& output, const Queue& rhs);
	void clear()                 {queueSize = 0; frontSub = 0; backSub = queueCap - 1;} //sets the queue back to the empty state
	size_t size()const           {return queueSize;} //returns the number of elements in the queue
	size_t capacity() const      {return queueCap;} //returns the total size of the queue
	bool empty() const;
	int front() const;
	int back() const;
	void push(const int item);
	void pop();
	void reserve(const size_t newCap);

	private:
	int* queueAR;
	size_t queueCap, //Capacity of queue
			queueSize; //number of elements in queue
	int frontSub, //front and back subscripts
			backSub;
};
#endif
