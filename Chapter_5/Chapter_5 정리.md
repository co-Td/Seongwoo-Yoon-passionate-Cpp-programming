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

