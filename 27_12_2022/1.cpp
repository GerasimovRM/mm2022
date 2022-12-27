#include <iostream>

using namespace std;

int main() {
    int a = 4;
    int* b = NULL; //nullptr // 0
    cout << a << " " << b << endl;
    b = new int[3];
    // ...
    delete[] b;
    b = &a;

    cout << *b << endl;
    
    int* c = new int;
    delete c;


    return 0;
}