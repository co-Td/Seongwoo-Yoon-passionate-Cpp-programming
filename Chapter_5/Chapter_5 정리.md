## 1. 복사 생성자와의 첫 만남
___참조자와 생성자___ 에 대해서 잘 이해하고 있다면 매우 쉽게 공부할 수 있다.

### 1. C++ 스타일의 초기화
- 스타일1:
```C++
int num = 20;
int &ref = num;
```

- 스타일2:
```C++
int num(20);
int &ref(num);
```

- 복사 생성자 예제
```C++
class SoSimple {
private:
	int num1;
	int num2;
public:
	SoSimple(int n1, int n2) 
		: num1(n1), num2(n2) 
	{	}
  
	void ShowSimpleData() 
	{
		std::cout << num1 << std::endl;
		std::cout << num2 << std::endl;
	}
};

int main(void) {
	SoSimple sim1(15, 30);
	SoSimple sim2 = sim1;
	sim2.ShowSimpleData();
	return 0;
}
/*
결과: 
15
20
*/
```

위 소스에서 메인 함수의 두 번째 문장에 해당하는 
```C++
SomSimple sim2 = sim1;

// or

SoSimple sim2(sim1);
```
문장은 sim2 객체를 생성하고, 객체 sim1과 sim2간의 멤버 대 멤버 복사가 일어난다고 예상할 수 있다.  
sim1의 num1이 복사되어 sim2의 num1로,  
sim1의 num2이 복사되어 sim2의 num2로 멤버 대 멤버 복사가 일어난다.  

- ___복사 생성자가 없는 경우, 디폴트 복사 생성자가 자동으로 삽입된다.___  
다음 두 코드는 완전히 동일한 코드로 볼 수 있다.
```C++
class SoSimple {
private:
	int num1;
	int num2;
public:
	SoSimple(int n1, int n2) 
		: num1(n1), num2(n2) 
	{	}
  
  // 디폴트 복사 생성자가 삽입됨.
};


class SoSimple {
private:
	int num1;
	int num2;
public:
	SoSimple(int n1, int n2) 
		: num1(n1), num2(n2) 
	{	}
  
  SoSimple(const SoSimple &copy) : num1(copy.num1), num2(copy.num2) {} // 선언한 복사 생성자
};
```

### 2. explicit  
```C++
SomSimple sim2 = sim1;

// or

SoSimple sim2(sim1);
```
위 상황에서 첫 문장처럼 사용하면, 묵시적 변환이 발생하여 두 번째 문장과 동일해진다.  
하지만, explicit 키워드를 사용한다면, 묵시적 변환이 발생하지 않는다.

```C++
explicit SoSimple(const SoSimple &copy)
            : num1(copy.num1), num2(copy.num2)
        {
        
        }
``` 
더 이상 묵시적 변환이 발생하지 않아서 대입 연산자를 이용한 객체의 생성 및 초기화는 불가능하다.  

___묵시적 변환이 좋은 것만은 아니다.___
자료형이든, 문장이든 자동으로 변환되는 것이 늘 반가운 것만은 아니다.  
묵시적 변환이 많이 발생하는 코드일수록 ___코드의 결과를 예측하기가 어려워지기 때문이다.___  
따라서 키워드 explicit은 코드의 명확함을 더하기 위해서 자주 사용되는 키워드 중 하나이다.  


___복사 생성자의 매개변수는 반드시 참조형이어야 하는가?___   
복사 생성자의 매개변수 const는 필수가 아니다. 그러나 ___참조형의 선언을 의미하는 &는 반드시___  삽입해야 한다.  
___&선언이 없다면, 복사 생성자의 호출은 무한루프에 빠져버린다.___  
다행히 C++ 컴파일러는 &선언이 없다면, 컴파일 에러를 발생시킨다.   


### 3. 깊은 복사와 얕은 복사  
디폴트 복사 생성자는 멤버 대 멤버의 복사를 진행한다. 이러한 방식의 복사를 가리켜 ___얕은 복사(shallow copy)___ 라 한다.   
이는 멤버변수가 힙의 메모리 공간을 참조하는 경우에 문제가 된다.  

### 4. 디폴트 복사 생성자의 문제점
```C++
#include <iostream>
#include <cstring>

class Person{
private:
	char * name;
	int age;
public:
	Person(char * myName, int myAge)
	{
		int len = strlen(myName) + 1;
		name = new char[len];
		strcpy(name, myName);
		age = myAge;
	}
	
	void ShowPersonInfo() const
	{
		std::cout << "이름: " << name << std::endl;
		std::cout << "나이: " << age << std::endl;
	}
	
	~Person()
	{
		delete []name;
		std::cout << "called destructor!" << std::endl;
	}
};

int main(void)
{
	Person man1("Lee dong woo", 29);
	Person man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}

/*
결과:
이름: Lee dong woo
나이: 29
이름: Lee dong woo
나이: 29
called destructor! // return을 통해 프로그램이 종료되었으나, 소멸자에 선언된 called destructor! 가 한번만 출력되었다.
*/
```

위 소스의 결과에서 "called desctructor!"가 한 번만 출력된 이유는,  
___얕은 복사___ 로 멤버 대 멤버 복사가 이뤄졌기 때문이다.  
man1의 객체 name은 힙 메모리의 "called destructor!"를 포인터 참조하고 있으며,  
man2의 객체 name도 얕은 복사로, 힙 메모리의 "called destructor!"를 포인터 참조하고 있다.  
따라서 소멸자의 delete []name;는 이미 메모리가 해제된 상태라 다시 해제할 수 없어서 "called destructor!"가 한 번만 출력된것이다.   

즉, 얕은 참조는 단순한 멤버 대 멤버의 복사가 발생하므로, 포인터 참조는 포인터 참조를 그대로 복사해  
하나의 데이터를 두 포인터가 참조하는 꼴을 만들어버린다.  


### 5. 깊은 복사를 위한 복사 생성자의 정의  
얕은 복사의 문제점으로, 단순한 멤버 대 멤버 복사로 한 데이터를 두 포인터가 참조하는 경우가 있었는데,  
깊은 복사를 사용하면 객체 소멸과정에서의 문제가 발생하지 않는다.  
___깊은 복사는 멤버뿐만 아니라, 포인터로 참조하는 대상까지 깊게 복사한다는 뜻이다.___

```C++
public:
	// 얕은 복사
	person(const Person& copy)
	{
		this = copy;
	}
	// 깊은 복사 (메모리 할당해서 메모리에 값을 저장)
	person(const Person& copy) : age(copy.age)
	{
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
	}
```


## 2. 복사 생성자의 호출시점
복사 생성자의 호출횟수는 프로그램의 성능과도 관계가 있기 때문에, 호출의 시기를 이해하는 것은 매우 중요하다.  

### 1. 복사 생성자가 호출되는 시점은?
- case 1: 기존에 생성된 객체를 이용해서 새로운 객체를 초기화하는 경우
- case 2: Call-by-value 방식의 함수호출 과정에서 객체를 인자로 전달하는 경우
- case 3: ___객체를 반환하되, 참조형으로 반환하지 않는 경우___  

위 세 케이스의 공통점은 ___객체를 새로 생성해야 한다. 단, 생성과 동시에 동일한 자료형의 객체로 초기화해야 한다.___ 는 것이다.  

