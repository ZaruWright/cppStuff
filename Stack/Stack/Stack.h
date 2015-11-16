#ifndef STACK_H
#define STACK_H

#include <memory>
#include <iostream>

template <class T>
class Stack {
public:
	Stack(int defaultSize = 10); // Default Constructor
	~Stack();
	Stack(const Stack&); // Copy constructor
	Stack<T>& operator = (const Stack&);

	T pop();
	void push(const T&);
	T top() const;

	const bool isEmpty() const;
	const bool isFull() const;


private:
	void growStack(int valueToGrow);

	T* _begin; // It points to the first element of the stack

	int _length; // Elements in the stack at the moment
	int _size; // Size of the stack
};


/*
The template class cannot be split in another cpp file. for this reason I implement this here.
I read that there are some method to split, but I don't want to complicate more on this.
*/

template<class T>
inline Stack<T>::Stack(int defaultSize = 10) : _length(0), _size(defaultSize)
{
	_begin = new T[_size];
}

template<class T>
inline Stack<T>::~Stack()
{
	delete[] _begin;
	_begin = nullptr;
}

template<class T>
inline Stack<T>::Stack(const Stack &)
{
	this->_length = other._length;
	this->_size = other._size;
	this->_begin = new T[_size];
	std::memcpy(this->_begin, , other->_begin, this->_length);
}

template<class T>
inline Stack<T>& Stack<T>::operator=(const Stack &)
{
	this->_length = other._length;
	this->_size = other._size;
	this->_begin = other._begin;
	return *this;
}

template<class T>
inline T Stack<T>::pop()
{
	if (this->isEmpty())
	{
		std::cerr << "You can't pop an element because the stack is empty.";
		exit(-1);
	}

	return _begin[--_length];
}

template<class T>
inline void Stack<T>::push(const T & value)
{
	if (this->isFull()) 
	{
		growStack(2);
	}

	_begin[_length++] = value;
}

template<class T>
inline T Stack<T>::top() const
{
	if (this->isEmpty())
	{
		std::cerr << "You can't see the top of the stack beacuse it is empty.";
		exit(-1);
	}

	return _begin[_length];
}

template<class T>
inline const bool Stack<T>::isEmpty() const
{
	return this->_length == 0;
}

template<class T>
inline const bool Stack<T>::isFull() const
{
	return this->_length == this->_size;
}

template<class T>
inline void Stack<T>::growStack(const int valueToGrow)
{
	int sizeAux = valueToGrow * _size;
	T* beginAux = new T[sizeAux];
	for (int i = 0; i < _size; ++i)
	{
		beginAux[i] = _begin[i];
	}
	delete [] _begin;
	_begin = beginAux;
	_size = sizeAux;
}

#endif