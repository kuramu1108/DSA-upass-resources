#include <iostream>

using namespace std;

void convertTo4(int a);
void convertTo4(int* a);

int main(int argc, char* argv[]) {
    int* one;
    // int* one = new int;
    int int1 = 1;
    one = &int1;
    *one = 1;
    
    int two = 2;

    cout << "Normal Parameter" << "\n";
    cout << "two: " << two << "\n";
    convertTo4(two);
    cout << "After execution\n";
    cout << "two: " << two << "\n";


    cout << "Pointer Parameter" << "\n";
    cout << "one: " << *one << "\n";
    convertTo4(one);
    cout << "After execution\n";
    cout << "one: " << *one << "\n";


    return 0;
}

void convertTo4(int a) {
    a = 4;
    cout << "a: " << a << "\n";
}

void convertTo4(int* a) {
    *a = 4;
    cout << "a: " << *a << "\n";
}
