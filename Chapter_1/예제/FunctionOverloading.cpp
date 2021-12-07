#include <iostream>

void MyFunction( void ) {
	std::cout << "MyFunction(void) called" << std::endl;
}

void MyFunction( char c ) {
	std::cout << "MyFunction( char c ) called" << std::endl;
}

void MyFunction( int a, int b) {
	std::cout << "MyFunction( int a, int b) called" << std::endl;
}

int main(void) {
	MyFunction();
	MyFunction( 'A' );
	MyFunction( 12, 13 );

	return 0;
}