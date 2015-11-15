#include "Chain.h"

Chain::Chain(const char buf[]) {
	_lenght = strlen(buf);
	_string = new char[_lenght + 1];
	std::memcpy(_string, buf, _lenght + 1);
}

Chain::Chain(const Chain& c)
{
	_lenght = c._lenght;
	_string = new char[_lenght + 1];
	std::memcpy(_string, c._string, _lenght + 1);
}

Chain Chain::operator+(const Chain & other) const
{
	Chain tmp;
	tmp._lenght = this->_lenght + other._lenght;
	tmp._string = new char[tmp._lenght + 1];
	std::memcpy(tmp._string, this->_string, this->_lenght);
	std::memcpy(tmp._string + (this->_lenght * sizeof(char)), other._string, other._lenght + 1);
	return tmp;
}

Chain& Chain::operator=(const Chain & other)
{
	_lenght = other._lenght;
	_string = new char[_lenght + 1];
	std::memcpy(_string, other._string, _lenght + 1);
	return *this;
}

Chain& Chain::operator+=(const Chain & other)
{
	char* bufAux;
	int length;
	length = _lenght + other._lenght;
	bufAux = new char[length + 1];
	std::memcpy(bufAux, this->_string, this->_lenght);
	std::memcpy(bufAux + (this->_lenght * sizeof(char)), other._string, other._lenght + 1);
	_string = bufAux;
	_lenght = length;
	return *this;
}

Chain::~Chain() {
	if (_string != nullptr)
	{
		delete[] _string;
		_string = nullptr;
	}
}
