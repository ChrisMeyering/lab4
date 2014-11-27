#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include "Node.h"
#include "PrecondViolatedExcep.h"
#include <stddef.h>
#include <string>
#include <iostream>

using namespace std;

template<class T>
class LinkedQueue : public Node<T>
{
  protected:
    Node<T>* frontPtr;
    Node<T>* backPtr;
 public: 
    LinkedQueue(); 
    LinkedQueue(const LinkedQueue& aQueue);
    
    bool isEmpty() const;
    bool enqueue(const T& newEntry);
    bool dequeue();
    T peekFront();

    LinkedQueue<T>& operator=(LinkedQueue<T> aLinkedQueue){} ///////////////////////////////////////////////////

    ~LinkedQueue<T>();
};

#endif

//@pre: none
//@post: Queue object initialized with default values
//purpose: default constructor
template<class T>
LinkedQueue<T>::LinkedQueue() : Node<T>(), frontPtr(NULL), backPtr(NULL) {}

//@pre: none
//@post: new Queue object contains same data as parameter
//puspose: copy constructor
template<class T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue& aQueue) : Node<T>(), frontPtr(NULL), backPtr(NULL)
{
  LinkedQueue<T>* newLinkedQueue = new LinkedQueue<T>();
  if (aQueue.isEmpty())
  {
    frontPtr = NULL;
    backPtr = NULL;
  } else {
    for (Node<T>* p = aQueue.frontPtr;; p = p->getNext())
    {
      newLinkedQueue->enqueue(p->getItem());
      if (p == aQueue.backPtr)
	break;
    }
    frontPtr = newLinkedQueue->frontPtr;
    backPtr = newLinkedQueue->backPtr;
  }
}

//@pre: none
//@post: return true if stack is empty, false if not
//purpose: determine whether given stack is empty or not.
template<class T>
bool LinkedQueue<T>::isEmpty() const
{
  return (frontPtr == NULL && backPtr == NULL);
}


//@pre: none
//@post: push new top element
//purpose: stack size increased by one, add newEntry as top element of queue
template<class T>
bool LinkedQueue<T>::enqueue(const T& newEntry){
  Node<T>* newNodePtr = new Node<T>(newEntry);
  if (isEmpty())
    frontPtr = newNodePtr;
  else
    backPtr->setNext(newNodePtr);
  backPtr = newNodePtr;
  return true;
}

//@pre: !isEmpty
//@post: pop bottom element
//purpose: stack size decreased by one, bottom deleted, new bottom = frontPtr->getNext()
template<class T>
bool LinkedQueue<T>::dequeue()
{
  bool result = false;
  if (!isEmpty())
  {
    Node<T>* nodeToDeletePtr = frontPtr;
    if (frontPtr == backPtr)
    {
      frontPtr = NULL;
      backPtr = NULL;
    }
    else
      frontPtr = frontPtr->getNext();
    nodeToDeletePtr->setNext(NULL);
    delete nodeToDeletePtr;
    nodeToDeletePtr = NULL;
    result = true;
  }
  return result;
}

//@pre: !isEmpty
//@post: return  element
//purpose: throw if queue is empty, otherwise return front element
template<class T>
T LinkedQueue<T>::peekFront() 
{
  if (isEmpty())
    throw PrecondViolatedExcep("peekFront() called with empty queue.");
  return frontPtr->getItem();
}

//destructor
template<class T>
LinkedQueue<T>::~LinkedQueue<T>()
{
  while (!isEmpty())
  {
    dequeue();
  }
}
