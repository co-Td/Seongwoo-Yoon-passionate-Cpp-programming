#include <iostream>

typedef struct __Point {
private:	
	int xPos;
	int yPos;

public:
	__Point(int x, int y) {
		this->xPos = x;
		this->yPos = y;
	}

	__Point sumPoint( __Point& p2 ) {
		this->xPos += p2.getX();
		this->yPos += p2.getY();

		return *this;
	}

	int getX() {
		return this->xPos;
	}

	int getY() {
		return this->yPos;
	}
} Point;

int main(void) {
	int x1 = 5;
	int x2 = 10;
	int y1 = 10;
	int y2 = 15;

	Point* p1 = new Point(x1, y1);
	Point* p2 = new Point(x2, y2);

	*p1 = p1->sumPoint(*p2);

	std::cout << "xPos: " << p1->getX() << std::endl;
	std::cout << "yPos: " << p1->getY() << std::endl;

	delete(p1, p2);
}