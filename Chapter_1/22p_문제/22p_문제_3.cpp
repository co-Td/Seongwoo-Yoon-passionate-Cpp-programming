#include <iostream>

/*
���� 01-1 [C++ ����� ������ �����] 22p
*/

int main(void) {
	int num;

	std::cout << "�� �Է�: ";
	std::cin >> num;

	for (int i = 0; i < 9; ++i) {
		std::cout << num << " * " << i + 1 << " = " << num * (i + 1) << std::endl;
	}

	return 0;
 }