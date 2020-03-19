#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <iomanip>
using std::cout; using std::endl;
using std::ostream; using std::underflow_error;

template<class T>
struct Node {
	T item; //item to be inserted into the queue
 	Node<T>* ptr; //point to the next node in the linked list

	Node(const T& newVal)                 {ptr = NULL; item = newVal;}
};

// Forward declaration of the Queue template class
template <class T>
class Queue;

// Forward declaration of the operator<< template function
template <class T>
std::ostream& operator<<(std::ostream&, const Queue<T>&);

template <class T>
class Queue {
	public:
	Queue()                              {queueSize = 0; qFront = qBack = NULL;}
	~Queue()                             {clear();}
	Queue(const Queue<T>& other);
	Queue<T>& operator=(const Queue<T>& other);
	void clear();
	size_t size()const                   {return queueSize;}
	bool empty()const;
	void push(const T& item);
	void pop();
	T& front() const;
	T& back() const;
	friend std::ostream& operator<< <>(std::ostream&, const Queue<T>&);

	private:
	Node<T>* qFront; //front of queue
	Node<T>* qBack; //back of queue
	size_t queueSize; //elements currently in array
};

/**************************************************************************************************
Function: operator<<()
Arguments: Two, a referance a a ostream object and a referance to a constant Queue object of template memeber called rhs
Purpose: To print out the queue
Returns: output
**************************************************************************************************/
template <class T>
ostream& operator<<(std::ostream& output, const Queue<T>& other) {
	Node<T>* current; //creates a new Node called current

	for(current = other.qFront; current != NULL; current = current->ptr) {
		output << current->item << "  "; //
	}
	
	return output;
}

/****************************************************
Method: empty() const
Arguments: None
Purpose: checks wether the queue is empty or not
Returns: Wether the queue is empty or not, true/false
*****************************************************/
template <class T>
bool Queue<T>::empty() const {
	if(queueSize == 0)
		return true; //queue is empty
	else
		return false; //queue it not empty
}

/****************************************************************************
Method: push()
Arguments: a constant integer of the template member called item
Purpose: Takes argument and will add it to the queue.
Returns: Nothing
*****************************************************************************/
template <class T>
void Queue<T>::push(const T& item) {
	Node<T>* newNode = new Node<T>(item); //creates a new Node and passes in the item to that Node

	if(empty()) //if empty, the front of the queue will be set to that Node
		qFront = newNode;
	else
		qBack->ptr = newNode; //else, queue is not empty, back queue will be set to that Node

	qBack = newNode; //takes qBack and sets it to the newNode
	queueSize++; //adds one to queue size
}

/************************************************************************************
Copy Constructor
Arguments: One, a referance to a constant Queue template memeber object called other
Purpose: Initialize a new Queue object to a exsiting Queue object
*************************************************************************************/
template<class T>
Queue<T>::Queue(const Queue<T>& other) {
	qFront = qBack = NULL; //sets front and back to NULL
	queueSize = 0; //sets size to 0

	Node<T>* ptr; //creates a new Node called ptr, used to point to the next node in Queue
	for(ptr = other.qFront; ptr != NULL; ptr = ptr->ptr)
		push(ptr->item); //calls push to insert the iteam into the new queue
}

/***************************************************************
Method: clear()
Arguments: None
Purpose: While the queue size is not 0,
will call pop() to remove all the items in the queue one by one
Returns: Nothing
***************************************************************/
template <class T>
void Queue<T>::clear() {
	while(queueSize != 0)
		pop();
}

/******************************************
Method: pop()
Arguments: None
Purpose: Will remove one from the queue.
         Throws exception if queue is empty
Returns: Nothing
*******************************************/
template <class T>
void Queue<T>::pop() {
	if(empty()) //if empty, throw exception
		throw underflow_error("queue underflow on pop()\n");

	Node<T>* deleteNode = qFront; //allocates memory for a new Node, that will be used to delete the desired node
	qFront = qFront->ptr; //sets the front equal to one element in front of qFront

	if(qFront == NULL) //if front is null, sets back to null
		qBack = NULL;

	delete deleteNode; //deletes the desired node
	queueSize--; //subtracts from the queue size after deletion
}

/********************************************************************
Method: operator=()
Arguments:a referance to a constant Queue object called other
Purpose: If the queues are equal to each other, will return the queue.
	 If not, will procede to copy the passed in queue to a new one
Reurns: A queue object, a member of the template parameter type, *this
********************************************************************/
template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other) {
	if(this != &other) { //if not equal,
		clear();     //will call clear.
		Node<T>* ptr; //Then create a new Node pointer
		for(ptr = other.qFront; ptr != NULL; ptr = ptr->ptr) //Procedes to copy the elements from the passed in Queue, into the new one
			push(ptr->item);
	}
	return *this; //else, if they are equal, return it
}

/****************************************************************
Method: front() const
Arguments: None
Purpose: Returns the element at the front location.
  	 If queue is empty, throws an exception
Returns: A element, the element found  at the front of the queue
****************************************************************/
template <class T>
T& Queue<T>::front() const {
	if(empty()) //if its empty, throw exception
		throw underflow_error("queue underflow on front()");
	return qFront->item; //else, return
}

/****************************************************************
Method: back() const
Arguments: None
Purpose: Returns the element at the back location.
  	 If queue is empty, throws an exception
Returns: A element, the element found  at the back of the queue
****************************************************************/
template <class T>
T& Queue<T>::back() const {
	if(empty()) //its its empty, throw exception
		throw underflow_error("queue underflow on back()");
	return qBack->item; //else, return
}

#endif
