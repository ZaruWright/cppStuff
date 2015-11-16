#pragma once
#ifndef VECTOR_H
#define VECTOR_H
#include <initializer_list>

template <typename T>
class Vector
{
public:
	Vector(int defaultSize = 10, int defaultGrow = 2); // Default constructor
	Vector(const Vector&);
	Vector(const std::initializer_list<T>&);

	void pushBack(const T&);
	T getElement(const size_t) const;

	T operator [](const size_t) const;

	const bool isEmpty() const;
	const bool isFull() const;
	const int length() const;
	
	~Vector();

private:
	void grow(const int);


	T* _vector;
	int _size;
	int _length;
	int _growNumber;
};

template<typename T>
inline Vector<T>::Vector(int defaultSize = 10, int defaultGrow = 2) : _size(defaultSize), _length(0), _growNumber(defaultGrow)
{
	_vector = new T[_size];
}

template<typename T>
inline Vector<T>::Vector(const Vector & other)
{
	this->_length = other._length;
	this->_size = other._size;
	this->_vector = new T[this->_size];
	for (int i = 0; i < this->_length; ++i) 
	{
		this->_vector[i] = other._vector[i];
	}
}

template<typename T>
inline Vector<T>::Vector(const std::initializer_list<T>& init)
{
	_length = 0;
	_growNumber = 2;
	_size = init.size();
	_vector = new T[_size];
	for (auto value : init)
		this->pushBack(value);
}

template<typename T>
inline void Vector<T>::pushBack(const T & value)
{
	if (this->isFull()) 
	{
		this->grow(_growNumber);
	}
	this->_vector[this->_length++] = value;
}

template<typename T>
inline const bool Vector<T>::isEmpty() const
{
	return this->_length == 0;
}

template<typename T>
inline const bool Vector<T>::isFull() const
{
	return this->_length == this->_size;
}

template<typename T>
inline const int Vector<T>::length() const
{
	return this->_length;
}

template<typename T>
inline T Vector<T>::getElement(const size_t position) const
{
	return this->_vector[position];
}

template<typename T>
inline T Vector<T>::operator[](const size_t position) const
{
	return getElement(position);
}

template<typename T>
inline Vector<T>::~Vector()
{
}


template<class T>
inline void Vector<T>::grow(const int valueToGrow)
{
	int sizeAux = valueToGrow * _size;
	T* beginAux = new T[sizeAux];
	for (int i = 0; i < _size; ++i)
	{
		beginAux[i] = _vector[i];
	}
	delete[] _vector;
	_vector = beginAux;
	_size = sizeAux;
}

#endif