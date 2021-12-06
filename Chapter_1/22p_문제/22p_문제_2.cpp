#include <iostream>

/*
문제 01-1 [C++ 기반의 데이터 입출력] 22p
*/

int main(void) {
	char name[100];
	char number[100];

	std::cout << "이름: ";
	std::cin >> name;

	std::cout << "전화번호: ";
	std::cin >> number;

	std::cout << name << std::endl << number;

	return 0;
 }