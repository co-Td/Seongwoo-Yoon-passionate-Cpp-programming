# Chapter_2 정리

## 1. C언어 복습을 유도하는 확인학습
- 키워드 const의 의미
```C++
1. const int num = 10             // 변수 num을 선언하고 10으로 상수화
2. const int * ptr1=&val1;        // val2의 주소를 가리키는 상수 포인터 ptr1 선언 ( ptr1로 val1의 값을 변경 가능 )
3. int * const ptr2=&val2;        // val2의 주소를 가리키는 포인터 상수 ptr2 선언 ( ptr2로 val2의 값을 변경 불가능, 주소 변경 가능 )
4. const int * const ptr3=&val3;  // val3의 주소를 가리키는 상수 포인터 상수 ptr3 선언 ( ptr3로 val3의 값 변경 불가능, 주소 변경 불가능 )
```

- 실행중인 프로그램의 메모리 공간
1. 데이터        : 전역 변수가 저장되는 영역
2. 스택          : 지역변수 및 매개변수가 저장되는 영역
3. 힙            : malloc 함수호출에 의해 프로그램이 실행되는 과정에서 _동적_으로 할당이 이뤄지는 영역
4. malloc & free : malloc 함수호출에 의해 할당된 메모리 공간은 free 함수호출을 통해서 소멸하지 않으면 해제되지 않는다.

- Call-by-value vs Call-by-reference
```C++
// Call-by-value
void swap( int num1, int num2 ) {
  int temp = num1;
  num1 = num2;
  num2 = temp;
}

// Call-by-reference
void swap( int* num1, int* num2 ) {
  int temp = num1;
  *num1 = *num2;
  *num2 = temp;
}
```
1. Call-by-value
값을 인자로 전달하는 함수의 호출방식

2. Call-by-reference
주소 값을 인자로 전달하는 함수의 호출방식
주소 값을 전달받아서, 함수 외부에 선언된 변수에 접근하는 형태의 함수호출


## 2. 새로운 자료형 bool
- bool 자료형은 0과 1이 아닌, false와 true를 표현하기 위한 자료형이다.
- 사이즈는 1bit가 아닌, 1byte이다.


## 3. 참조자(Reference)의 이해
- 변수는 할당된 메모리에 붙이는 이름이다. 참조자는 변수에 붙이는 별명과 같다.
- 참조자는 자신이 참조하는 변수를 대신할 수 있는 또 하나의 이름이다.
- 자료형 뒤에 나오는 &는 참조자를 의미하며, 이미 선언된 변수앞에 붙는 &는 주소를 반환하는것을 의미한다.
- 참조자의 연산은 참조하는 변수의 연산과 동일하다.
- _함수 내 선언된 참조자는 지역변수와 마찬가지로 함수를 벗어나면 소멸한다._
- 참조자의 수에는 제한이 없으며, 참조자를 대상으로 참조자를 선언할 수 있다.
- _참조자는 선언과 동시에 변수를 참조해야 한다._
- 
