#include <iostream>
using namespace std;

int main()
{
	int x = 42;
	int* p1 = &x;           					 // p1은 x의 메모리 주소를 가리키는 포인터
	void* p2 = reinterpret_cast<void*>(p1); 	 // p2는 p1과 동일한 메모리 주소를 가리키지만, void* 형식으로 해석됩니다.
	int* p3 = reinterpret_cast<int*>(p2);   	 // p3는 p2와 동일한 메모리 주소를 가리키지만, int* 형식으로 해석됩니다.
	int x = 0x12345678;
	char* p = reinterpret_cast<char*>(&x);
	return 0;
}

/* 
	직렬화를 하지 않으면 여러 가지 문제가 발생할 수 있습니다.

	메모리 주소 문제 객체 내부에 포인터 멤버가 있다면, 단순히 객체를 전송하거나 저장할 경우 포인터 값이 의미 없는 값이 됩니다. 왜냐하면 메모리 주소는 프로세스나 실행 환경마다 다르기 때문입니다.
	패딩 문제 대부분의 컴퓨터 구조에서는 메모리 정렬을 위해 구조체/클래스에 패딩(padding)을 삽입합니다. 이 패딩 크기는 시스템마다 다를 수 있기 때문에, 다른 시스템에서 복원할 경우 문제가 발생할 수 있습니다.
	엔디안 문제 서로 다른 엔디안(endian) 방식을 사용하는 시스템 간에 데이터를 직접 교환하면, 데이터가 깨질 수 있습니다. 엔디안 변환 과정이 필요합니다.
	가상 함수 테이블 문제 객체를 직접 복사할 경우, 가상 함수 테이블 포인터도 그대로 복사됩니다. 이로 인해 잘못된 가상 함수가 호출될 수 있습니다.
	이러한 이유로 직렬화 과정을 반드시 거쳐야 합니다. 직렬화를 통해 플랫폼 독립적인 데이터 스트림으로 변환한 후에야 안전하게 데이터를 전송, 저장, 로드할 수 있습니다.
*/