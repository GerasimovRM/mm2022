#include <iostream>

using namespace std;



int main() {
    // ���������� ���������
    int a = 10;
    int* const ptr = &a;
    int b = 15;
    // ptr = &b; // ��� ������
    //cout << ptr << endl;
    *ptr = 30;
    a = 30;
    cout << a << endl;





    return 0;
}