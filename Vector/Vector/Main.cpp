//#include "Vector.h"
#include <iostream>
# include "Vector.h"


int main()
{
	Vector<int> vector = { 1,2,3,4 };

	for (int i = 0; i < vector.length(); ++i)
	{
		std::cout << vector[i] << std::endl;
	}

	return 0;
}