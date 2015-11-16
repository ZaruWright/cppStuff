#include "Vector.h"
#include <iostream>


int main()
{
	Vector<int> vector = { 1,2,3,4 };
	/*Vector<int> vector;
	vector.pushBack(1);*/

	for (int i = 0; i < vector.length(); ++i)
	{
		std::cout << vector[i] << std::endl;
	}

	char c;
	std::cin >> c;

	return 0;
}