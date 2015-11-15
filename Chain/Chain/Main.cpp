#include <iostream>
#include "Chain.h"
int main(int argc, char **argv) {

	char c1[] = { 'h','o','l','a', '\0' };
	char c2[] = { 'm','u','n','d','o', '\0' };

	Chain ch1(c1);
	Chain ch2(c2);
	Chain ch3 = ch1 + ch2;
	ch3 += ch1;
	ch1 = ch1 + ch1;

	return 0;
}