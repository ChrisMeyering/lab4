#ifndef LINKED_SCROLL_H
#define LINKED_SCROLL_H

#include "LinkedQueue.h"
#include <stddef.h>
#include <string>

template<class T>
class LinkedScroll : public LinkedQueue<T>
{
  public:
    bool removeLast(T& last);
};

#endif

template<class T>
bool LinkedScroll<T>::removeLast(T& last)
{ 
  bool result = false;
  if (!this->isEmpty())
  {
    Node<T> *next;
    Node<T> *p;

    if (this->backPtr == this->frontPtr){
      last = this->peekFront();
      this->dequeue();
    }
    else
    {
      for (p = this->frontPtr;
          (next = p->getNext()) != this->backPtr;
          p = next)
      {
        cout << p->getItem() << endl;
      }
      last = this->backPtr->getItem();
      p->setNext(NULL);
      delete this->backPtr;
      this->backPtr = p;
      result = true;
    }
  }
  else 
    cout << "EMPTY!\n";
  return result;
}
 
