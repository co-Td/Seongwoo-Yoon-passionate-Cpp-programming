#include <iostream>

int Increase(int& num) {
	++num;
	return num;
}

int ReverseSymbol(int& num) {
	num *= -1;
	return num;
}

int main(void) {
	int num = 10;
	int* num2 = &num;

	Increase(num);
	std::cout << "Increase: " << num << std::endl;
	ReverseSymbol(num);
	std::cout << "ReverseSymbol: " << num << std::endl;
}