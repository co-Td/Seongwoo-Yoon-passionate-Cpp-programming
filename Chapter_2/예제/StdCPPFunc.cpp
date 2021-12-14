#include <iostream>
#include <cstdio>
#include <cstring>

int main(void) {
	char str1[] = "Result";
	char str2[30];

	strcpy_s(str2, str1);
	printf_s("%s: %f \n", str1, sin(0.14));
	printf_s("%s: %f \n", str1, abs(-1.25));
	return 0;
}