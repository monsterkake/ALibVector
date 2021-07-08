#pragma once

#include <exception>
#include <stdexcept>
#include <iostream>

namespace ALib 
{
	template <typename T>
	class Node
	{
	public:
		T* value = new T;
		Node<T>* prevNode = nullptr;
		Node<T>* nextNode = nullptr;
		~Node();
	};

	template <typename T>
	Node<T>::~Node()
	{
		delete value;
		delete prevNode;
		delete nextNode;
	}

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
		void pushFront(T value);
		T& operator [](int index);


		Vector();
		~Vector();
	};

	template <typename T>
	inline Vector<T>::Vector()
	{

	}

	template<typename T>
	inline Vector<T>::~Vector()
	{

	}

	template <typename T>
	inline unsigned int Vector<T>::size()
	{
		return length;
	}

	template <typename T>
	inline void Vector<T>::pushBack(T value)
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
	inline void Vector<T>::popBack()
	{
		lastNode = lastNode->prevNode;
		delete lastNode->nextNode;
		lastNode->nextNode = nullptr;
		length--;
	}

	template<typename T>
	inline void Vector<T>::pushFront(T value)
	{
		if (firstNode != nullptr) 
		{
			firstNode->prevNode = new Node<T>;
			firstNode->prevNode->nextNode = firstNode;
			firstNode = firstNode->prevNode;
			length++;
		}
		else
		{
			firstNode = new Node<T>;
			lastNode = firstNode;
		}
		*firstNode->value = value;
		
	}

	template <typename T>
	inline T& Vector<T>::operator[](int index)
	{
		return at(index);
	}

	template <typename T>
	inline T& Vector<T>::at(int index)
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
}