#include <iostream>

/*
문제 01-1 [C++ 기반의 데이터 입출력] 22p
*/

int main(void) {
	int add;
	int result = 0;

	for (int i = 0; i < 5; ++i) {
		std::cout << i + 1 << "번째 정수 입력: ";
		std::cin >> add;

		result += add;
	}

	std::cout << "합계: " << result;
 }