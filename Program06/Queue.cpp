#include "Queue.h"

/*******************************************************************
Copy Constructor
Arguments: One, a referance to a constant Queue object called other
Purpose: Initialize a new Queue object to a exsiting Queue object
*******************************************************************/
Queue::Queue(const Queue& other) {
	queueCap = other.queueCap;
	queueSize = other.queueSize;
	queueAR = new int[queueCap];

	for(size_t i = 0; i < queueCap; ++i)
		queueAR[i] = other.queueAR[i];

	frontSub = other.frontSub;
	backSub = other.backSub;
}

/**************************************************************************************************
Function: operator<<()
Arguments: Two, a referance a a ostream object and a referance to a constant Queue object called rhs
Purpose: To print out the queue
Returns: output
**************************************************************************************************/
ostream& operator<<(ostream& output, const Queue& rhs) {
	size_t current, i;

	for (current = rhs.frontSub, i = 0; i < rhs.queueSize; ++i) {
   		// Print queue element at subscript i
   		output << rhs.queueAR[current] << ' ';

   		// Increment i, wrapping around to front of queue array if necessary
   		current = (current + 1) % rhs.queueCap;
   	}
	return output;
}

/******************************************************************
Method: empty() const
Arguments: None
Purpose: Checks if the queue holds any elements, if not, it is empty
Returns: True or false
*******************************************************************/
bool Queue::empty() const {
	if(queueSize == 0)
		return true;
	else
		return false;
}


/****************************************************************************
Method: push()
Arguments: a constant integer called item
Purpose: Takes argument and will add it to the queue.
         Will call reserve() if more space is needed for the item to be added
Returns: Nothing
*****************************************************************************/
void Queue::push(const int item) {
	if(queueSize == queueCap) {
		if(queueCap == 0)
			reserve(1);
		else
			reserve(queueCap * 2);
	}
	backSub = (backSub + 1) % queueCap;
	queueAR[backSub] = item; //sets backSub to the argument
	++queueSize;
}

/******************************************
Method: pop()
Arguments: None
Purpose: Will remove one from the queue.
         Throws exception if queue is empty
Returns: Nothing
*******************************************/
void Queue::pop() {
	if(empty())
		throw underflow_error("queue underflow on pop()");
	frontSub = (frontSub + 1) % queueCap;
		--queueSize;
}

/*****************************************************
Method: front() const
Arguments: None
Purpose: Returns the integer at the front sub.
  	 If queue is empty, throws an exception
Returns: A integer, the element found  at the frontSub
******************************************************/
int Queue::front() const{
	if(empty())
		throw underflow_error("queue underflow on front()");
	return queueAR[frontSub];
}

/********************************
Mehotd: back() const
Arguments: None
Purpose: Returns the integer at the backSub
	 If queue is empty, throws an exception
Returns: A integer, the element found ath the backSub
*****************************************************/
int Queue::back() const {
	if(empty())
		throw underflow_error("queue underflow on back()");
	return queueAR[backSub];
}


/********************************************************************
Method: operator=()
Arguments:a referance to a constant Queue object called other
Purpose: If the queues are equal to each other, will return the queue
	 If queue isn't NULL, will delete the queue
         Sets subs equal to object's subs
	 Sets size and capacity equal to object's size and capacity
	 Proceeds to assign the passed in object to the calling object
Reurns: A queue object, *this
********************************************************************/
Queue& Queue::operator=(const Queue& other) {
	if(this == &other)
		return *this;
	if(queueAR != NULL)
		delete[] queueAR;

	frontSub = other.frontSub;
	backSub = other.backSub;

	this->queueSize = other.queueSize;
	this->queueCap = other.queueCap;

	if(queueCap == 0)
		this->queueAR = NULL;
	else {

		this->queueAR = new int[queueCap];
		for(size_t i = 0; i < queueCap; i++)
			this->queueAR[i] = other.queueAR[i];
		}
	return *this;
}

/*********************************************************************************************
Method: reserve()
Arguments: a size_t constant called newCap
Purpose: reserves additional capacity for the queue array equal to the new capacity passed in
Returns: Nothing
*********************************************************************************************/
void Queue::reserve(const size_t newCap) {
	if(newCap > queueCap) {
		int* tempAR = new int[newCap];
		int current = frontSub;
		for(size_t i = 0; i < queueSize; i++) {
			tempAR[i] = queueAR[current];
			current = (current + 1) % queueCap;
		}
		queueCap = newCap;
		frontSub = 0;
		backSub = queueSize - 1;
		delete[] queueAR;
		queueAR = tempAR;
	}
}
