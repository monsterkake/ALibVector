#include "node.h"

template <typename T>
Node<T>::~Node()
{
	delete value;
	delete prevNode;
	delete nextNode;
}