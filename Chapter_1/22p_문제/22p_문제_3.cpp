#include <iostream>

/*
문제 01-1 [C++ 기반의 데이터 입출력] 22p
*/

int main(void) {
	int num;

	std::cout << "단 입력: ";
	std::cin >> num;

	for (int i = 0; i < 9; ++i) {
		std::cout << num << " * " << i + 1 << " = " << num * (i + 1) << std::endl;
	}

	return 0;
 }