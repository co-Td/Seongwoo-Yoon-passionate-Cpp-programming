#include <iostream>

int main(void) {
	const int num = 12;
	const int* pNum = &num;
	const int& refNum = num;

	std::cout << "const pointer num: " << *pNum << std::endl;
	std::cout << "const referencer num: " << refNum << std::endl;
}
