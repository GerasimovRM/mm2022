#include <iostream>

using namespace std;
int main() {
    // ”казатель на константу
    const int a = 10;
    const int* ptr = &a;
    const int b = 15;
    cout << ptr << endl;
    ptr = &b;
    cout << ptr << endl;




    return 0;
}