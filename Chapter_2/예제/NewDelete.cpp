#include <iostream>
#include <string.h>

char* MakeStrAdr(int len) {
	// char* str = (char*)malloc(sizeof(char) * len);
	char* str = new char[len];
	return str;
}

int main(void) {
	char* str = MakeStrAdr(20);
	strcpy(str, "I am so happy~");
	std::cout << str << std::endl;
	//free(str);
	delete[]str;
	return 0;
}