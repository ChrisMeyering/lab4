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

//@pre: !isEmpty
//@post: pop top element
//purpose: return true 
template<class T>
bool LinkedScroll<T>::removeLast(T& last)
{ 
  bool result = false;
  if (!this->isEmpty())
  {

    if (this->backPtr == this->frontPtr){
      last = this->peekFront();
      this->dequeue();
    } 
    else
    {
      Node<T> *next_;
      Node<T> *p;
      for (p = this->frontPtr;
          (next_ = p->getNext()) != this->backPtr;
          p = next_)
      {
      }
      last = this->backPtr->getItem();
      p->setNext(NULL);
      delete this->backPtr;
      this->backPtr = p;
    }
    result = true;
  }
  return result;
}
 
