#include <iostream>

/*
���� 01-1 [C++ ����� ������ �����] 22p
*/

int main(void) {
	int add;
	int result = 0;

	for (int i = 0; i < 5; ++i) {
		std::cout << i + 1 << "��° ���� �Է�: ";
		std::cin >> add;

		result += add;
	}

	std::cout << "�հ�: " << result;
 }