#include <iostream>

/*
���� 01-1 [C++ ����� ������ �����] 22p
*/

int main(void) {
	char name[100];
	char number[100];

	std::cout << "�̸�: ";
	std::cin >> name;

	std::cout << "��ȭ��ȣ: ";
	std::cin >> number;

	std::cout << name << std::endl << number;

	return 0;
 }