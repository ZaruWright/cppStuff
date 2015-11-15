#ifndef CHAIN_H
#define CHAIN_H

#include <memory>

class Chain {
public:
	// Default Constructor
	Chain() : _lenght(0), _string(nullptr) {};

	Chain(const char[]);

	Chain(const Chain&);

	Chain operator + (const Chain &other) const;

	Chain &operator = (const Chain &other);

	Chain &operator += (const Chain &other);

	~Chain();
private:

	int _lenght;
	char* _string;
};
#endif