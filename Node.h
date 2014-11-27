#ifndef NODE_H
#define NODE_H

#include <cstddef>
#include <string>

template<class T>
class Node
{
  protected:
    T item;
    Node<T>* next;
  public:
    Node();
    Node(const Node<T>& aNode);
    Node(const T& anItem);
    Node(const T& anItem, Node<T>* nextNodePtr);
    void setItem(const T& anItem);
    void setNext(Node<T>* nextNodePtr);
    T getItem() const;
    Node<T>* getNext() const;

    Node<T>& operator=(const Node<T>& aNode)
    {
      item = aNode.item;
      next = aNode.next;
      return *this;
    }

    virtual ~Node() {};

};

#endif

template<class T>
Node<T>::Node() : item(T()), next(NULL) {}

template<class T>
Node<T>::Node(const Node<T>& aNode): item(aNode.item),
  next(aNode.next? new Node(*aNode.next) : NULL) {}

template<class T>
Node<T>::Node(const T& anItem): item(anItem), next(NULL){}

template<class T>
Node<T>::Node(const T& anItem, Node<T>* nextNodePtr):
  item(anItem), next(nextNodePtr){}

template<class T>
void Node<T>::setItem(const T& anItem)
{
  item = anItem;
}

template<class T>
void Node<T>::setNext(Node<T>* nextNodePtr)
{
  next = nextNodePtr;
}

template<class T>
T Node<T>::getItem() const
{
  return item;
}

template<class T>
Node<T>* Node<T>::getNext() const
{
  return next;
}
