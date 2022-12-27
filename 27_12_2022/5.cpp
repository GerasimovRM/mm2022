#include <iostream>

using namespace std;

struct StackElem {
    int x;
    StackElem* next;
};

void pop(StackElem*& head) {
    if (head != NULL) {
        StackElem* elem_for_delete = head;
        head = head->next;
        delete elem_for_delete;
    }
}

void push(int value, StackElem*& head) {
    StackElem* new_node = new StackElem;
    new_node->x = value;
    new_node->next = head;
    head = new_node;
}

void show(StackElem* head) {
    cout << "start show========" << endl;
    while (head != NULL) {
        cout << head->x << "\t" << head << "\t" << head->next << endl;
        head = head->next;
    }
    cout << "end show========" << endl;
}


int main() {
    StackElem* stack = NULL;
    push(3, stack);
    push(4, stack);
    push(5, stack);
    push(4, stack);
    push(10, stack);
    // cout << stack->x << " " << stack->next->x << " " << stack->next->next->x;
    show(stack);
    pop(stack);
    show(stack);
    pop(stack);
    pop(stack);
    push(10, stack);
    show(stack);


    return 0;
}