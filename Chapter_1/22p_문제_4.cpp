#include <iostream>

/*
���� 01-1 [C++ ����� ������ �����] 22p
*/

int main(void) {
	int sell;

	while (1) {
		std::cout << "�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end): ";
		std::cin >> sell;

		if (sell == -1) {
			break;
		}
		else {
			std::cout << "�̹� �� �޿�: " << 50 + (sell * 0.12) << "����" << std::endl;
		}
	}

	std::cout << "���α׷��� �����մϴ�." << std::endl;

	return 0;
 }