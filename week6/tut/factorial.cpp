#include <iostream>

using namespace std;

int fac_re(int n) {
    if ( n != 1)
        return n *  fac_re(n - 1);  
    else 
        return 1;
}

int fac_it(int n) {
    int result = 1;
    for (int i = n; i > 0; i--) {
        result *= i;
    }
    return result;
}

int main() {
    cout << "factorial test\n";
    cout << "iteration: " << fac_it(25) << "\n";
    cout << "recursion: " << fac_re(25) << "\n";
}