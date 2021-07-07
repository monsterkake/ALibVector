#pragma once

template <typename T>
class Node
{
public:
	T* value = new T;
	Node<T>* prevNode = nullptr;
	Node<T>* nextNode = nullptr;
	~Node();
};

