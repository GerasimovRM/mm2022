#include <iostream>

using namespace std;

struct ListNode {
    float data;
    ListNode* next;
};

ListNode* add_head(ListNode*& head, ListNode*& tail, float new_node_data) {
    ListNode* new_node = new ListNode;
    new_node->data = new_node_data;
    if (head == nullptr) {
        head = new_node;
        tail = new_node;
        new_node->next = nullptr;
    }
    else {
        new_node->next = head;
        head = new_node;
    }
    return new_node;
}

ListNode* add_tail(ListNode*& head, ListNode*& tail, float new_node_data) {
    ListNode* new_node = new ListNode;
    new_node->data = new_node_data;
    if (tail == nullptr) {
        head = new_node;
        tail = new_node;
        new_node->next = nullptr;
    }
    else {
        new_node->next = nullptr;
        tail->next = new_node;
        tail = new_node;
    }
    return new_node;
}

void delete_head(ListNode*& head, ListNode*& tail) {
    if (head == nullptr) return;
    ListNode* tmp = head;
    head = head->next;
    if (head == nullptr) {// означет что удаляем список, в котором один элемент
        tail = nullptr;
    }
    delete tmp;
}

void delete_tail(ListNode*& head, ListNode*& tail) {
    if (head == nullptr) return;
    if (head == tail) {
        delete tail;
        tail = nullptr;
        head = nullptr;
    }
    else {
        ListNode* tmp = head;
        while (tmp->next != tail) {
            tmp = tmp->next;
        }
        delete tail;
        tail = tmp;
        tail->next = nullptr;
    }
}

ListNode* add_by_address(ListNode*& head, ListNode*& tail, ListNode* address_for_add, float new_node_data) {
    ListNode* tmp = head;
    while (tmp != address_for_add) {
        if (tmp == nullptr) {
            /// Ошибка
            return nullptr;
        }
        tmp = tmp->next;
    }
    ListNode* tmp_next = tmp->next;
    ListNode* new_node = new ListNode;
    new_node->data = new_node_data;
    tmp->next = new_node;
    new_node->next = tmp_next;
    return new_node;
}


void delete_by_address(ListNode*& head, ListNode*& tail, ListNode* address_for_delete) {
    ListNode* tmp_prev = head;
    // если один элемент
    if (head == address_for_delete) {
        delete_head(head, tail);
        return;
    }
    if (tail == address_for_delete) {
        delete_tail(head, tail);
        return;
    }
    while (tmp_prev->next != address_for_delete) {
        if (tmp_prev == nullptr) {
            /// Ошибка
            return;
        }
        tmp_prev = tmp_prev->next;
    }
    ListNode* tmp_next = tmp_prev->next->next;
    delete tmp_prev->next;
    tmp_prev->next = tmp_next;
}


void show(ListNode* head) {
    cout << "start show========" << endl;
    while (head != NULL) {
        cout << head->data << "\t" << head << "\t" << head->next << endl;
        head = head->next;
    }
    cout << "end show========" << endl;
}


int main() {

    ListNode* HEAD = nullptr, * TAIL = nullptr;  // NULL
    add_head(HEAD, TAIL, 3);
    ListNode* elem = add_head(HEAD, TAIL, 4);
    add_head(HEAD, TAIL, 7);
    add_head(HEAD, TAIL, 10);
    add_tail(HEAD, TAIL, 13);
    show(HEAD);
    ListNode* elem2 = add_by_address(HEAD, TAIL, elem, 8);
    show(HEAD);
    add_tail(HEAD, TAIL, 20);
    show(HEAD);
    add_head(HEAD, TAIL, 3);
    show(HEAD);
    delete_by_address(HEAD, TAIL, elem2);
    show(HEAD);

    return 0;
}