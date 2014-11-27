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

template<class T>
LinkedQueue<T>::LinkedQueue() : frontPtr(NULL), backPtr(NULL){}

template<class T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue& aQueue)
{
  LinkedQueue<T>* newLinkedQueue = new LinkedQueue<T>();
  for (Node<T>* p = aQueue.frontPtr;; p = p->getNext())
  {
    cout << p->getItem() << endl;
    newLinkedQueue->enqueue(p->getItem());
    if (p == aQueue.backPtr)
      break;
  }
  frontPtr = newLinkedQueue->frontPtr;
  backPtr = newLinkedQueue->backPtr;

}

template<class T>
bool LinkedQueue<T>::isEmpty() const
{
  return (frontPtr == NULL && backPtr == NULL);
}

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

template<class T>
T LinkedQueue<T>::peekFront() 
{
  if (isEmpty())
    throw PrecondViolatedExcep("peekFront() called with empty queue.");
  return frontPtr->getItem();
}

template<class T>
LinkedQueue<T>::~LinkedQueue<T>()
{
  while (!isEmpty())
  {
    dequeue();
  }
}
