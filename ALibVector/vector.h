#pragma once

#include "node.h"
#include <exception>
#include <stdexcept>
#include <iostream>

template <typename T>
class Vector
{
private:
	unsigned int length = 0;
	Node<T>* firstNode = nullptr;
	Node<T>* lastNode = nullptr;
	T& at(int index);
public:
	unsigned int size();
	void pushBack(T value);
	void popBack();
	T& operator [](int index);


	Vector();
};

template <typename T>
Vector<T>::Vector()
{

}

template <typename T>
unsigned int Vector<T>::size()
{
	return length;
}

template <typename T>
void Vector<T>::pushBack(T value)
{
	if (lastNode != nullptr)
	{
		lastNode->nextNode = new Node<T>;
		lastNode->nextNode->prevNode = lastNode;
		lastNode = lastNode->nextNode;
		length++;
	}
	else
	{
		lastNode = new Node<T>;
		firstNode = lastNode;
	}
	*lastNode->value = value;
}

template <typename T>
void Vector<T>::popBack()
{
	lastNode = lastNode->prevNode;
	delete lastNode->nextNode;
	lastNode->nextNode = nullptr;
	length--;
}

template <typename T>
T& Vector<T>::operator[](int index)
{
	return at(index);
}

template <typename T>
T& Vector<T>::at(int index)
{
	if (index < 0 || index > length)
	{
		std::cout << std::endl << "vector subscript is out of range!";
		exit(0);
	}

	Node<T>* temp = firstNode;
	for (int i = 0; i < index; i++)
	{
		temp = temp->nextNode;
	}
	return *temp->value;
}