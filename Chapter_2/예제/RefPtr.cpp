#include <iostream>

int main(void) {
	int num = 12;
	int* ptr = &num;
	int** dptr = &ptr;

	int& ref = num;
	int* (&pref) = ptr;
	int** (&dpref) = dptr;

	std::cout << ref << std::endl;
	std::cout << *pref << std::endl;
	std::cout << **dpref << std::endl;

	return 0;
}