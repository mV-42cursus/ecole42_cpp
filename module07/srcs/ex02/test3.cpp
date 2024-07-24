#include <iostream>

class Array {
private:
    int elements[10];

public:
    Array() {
        for (int i = 0; i < 10; ++i) {
            elements[i] = i * i;
        }
    }

    int& operator[](int index) {
        return elements[index];
    }

    const int& operator[](int index) const{
        return elements[index];
    }
};

void printElement(const Array& arr, int index) {
    // const 객체에 대해 [] 연산자를 사용하려고 하면 컴파일 오류 발생
    std::cout << arr[index] << std::endl;
}

int main() {
    Array arr;
    const Array arr;
    printElement(arr, 2);
    return 0;
}