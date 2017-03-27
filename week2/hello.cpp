#include <iostream>

using namespace std;

int main() {
    int* foo = new int;
    *foo = 1;

    cout << *foo << endl;
    cout << foo << endl;
    return 0;
}