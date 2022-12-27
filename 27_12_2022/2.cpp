#include <iostream>

using namespace std;

void func(int& x) {
    // cout << &x << endl;
    x = x * x;
}

int main() {
    // int - 4 bytes, short - 2 bytes (short == short int)
    int a = 10;
    a++;
    cout << a << endl;
    a--;
    cout << a << endl;
    int* b = new int[3];
    b[0] = 1;
    b[1] = 2;
    b[2] = 3;
    cout << b << " " << b + 1 << " " << b + 2 << endl;
    cout << *b << " " << *(b + 1) << " " << *(b + 2) << endl;
    // b[3] == *(b + 3)
    int*& bref = b;

    func(a);
    cout << a << endl;

    return 0;
}