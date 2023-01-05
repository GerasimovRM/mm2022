#include <iostream>
#include <float.h>

using namespace std;

struct ListNode {
    float data;
    ListNode* next;
    ListNode* prev;
};

ListNode* add_head(ListNode*& head, ListNode*& tail, float new_node_data) {
    ListNode* new_node = new ListNode;
    new_node->data = new_node_data;
    // cписок пуст
    if (head == nullptr) {
        new_node->next = nullptr;
        new_node->prev = nullptr;
        head = new_node;
        tail = new_node;
    }
    else {
        new_node->next=head;
        new_node->prev= nullptr;
        head->prev = new_node;
        head = new_node;
    }
    return new_node;
}

ListNode* add_prev_index(ListNode*& head, ListNode*& tail, float new_node_data, unsigned index) {
    ListNode* tmp = head;
    for (int i = 0; i < index; ++i) {
        tmp = tmp->next;
        if (tmp == nullptr) {
            // ошибка
            return nullptr;
        }
    }
    ListNode* tmp_prev = tmp->prev;
    if (tmp_prev == nullptr) {
        return add_head(head, tail, new_node_data);
    }
    else {
        ListNode* new_node = new ListNode;
        new_node->data = new_node_data;
        tmp_prev->next = new_node;
        tmp->prev = new_node;
        new_node->prev = tmp_prev;
        new_node->next = tmp;
        return new_node;
    }

}
ListNode* add_tail(ListNode*& head, ListNode*& tail, float new_node_data) {
    ListNode* new_node = new ListNode;
    new_node->data = new_node_data;
    // cписок пуст
    if (head == nullptr) {
        new_node->next = nullptr;
        new_node->prev = nullptr;
        head = new_node;
        tail = new_node;
    }
    else {
        new_node->next = nullptr;
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
    return new_node;
}
float delete_head(ListNode*& head, ListNode*& tail) {
    if (head == nullptr) {
        return FLT_MAX;
    }
    else if (head == tail) {
        float data = head->data;
        delete head;
        head = nullptr;
        tail = nullptr;
        return data;
    }
    else {
        ListNode* tmp = head;
        float data = tmp->data;
        head = head->next;
        head->prev = nullptr;
        delete tmp;
        return data;
    }
}

// TODO: добавить удаление с хвоста
// TODO: добавть добавление по индексу после элемента

float delete_by_index(ListNode*& head, ListNode*& tail, unsigned index) {
    if (head == nullptr) {
        return FLT_MAX;
    }
    else if (head == tail) { // если элемент 1
        if (index == 0) {
            return delete_head(head, tail); // если индекс верный
        }
        else {
            return FLT_MAX; // если индекс неверный
        }
    }
    else {
        ListNode* tmp = head;
        for (int i = 0; i < index; ++i) {
            tmp = tmp->next;
            if (tmp == nullptr) {
                // ошибка
                return FLT_MAX;
            }
        }
        if (tmp->prev == nullptr) {
            return delete_head(head, tail);
        }
        else if (tmp->next == nullptr) {
            // return delete_tail(head, tail);
        }
        else {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            float data = tmp->data;
            delete tmp;
            return data;
        }
    }
}

void show_from_head(ListNode* head) {
    cout << "start show from head ========" << endl;
    int index = 0;
    while (head != NULL) {
        cout << index << "\t" << head->data << "\t" << head->prev << "\t" << head << "\t" << head->next << endl;
        head = head->next;
        index++;
    }
    cout << "end show from head ========" << endl;
}

void show_from_tail(ListNode* tail) {
    cout << "start show from tail ========" << endl;
    while (tail != NULL) {
        cout << tail->data << "\t" << tail->prev << "\t" << tail << "\t" << tail->next << endl;
        tail = tail->prev;
    }
    cout << "end show from tail ========" << endl;
}

int main() {
    ListNode* HEAD = nullptr, *TAIL = nullptr;
    add_tail(HEAD, TAIL, 2);
    add_head(HEAD, TAIL, 3);
    add_tail(HEAD, TAIL, 13);
    add_head(HEAD, TAIL, 6);
    add_tail(HEAD, TAIL, 10);
    show_from_head(HEAD);
//    add_prev_index(HEAD, TAIL, 20, 0);
//    show_from_head(HEAD);
//    add_prev_index(HEAD, TAIL, 27, 3);
//    show_from_head(HEAD);
    add_prev_index(HEAD, TAIL, 30, 4);
    show_from_head(HEAD);
    /*cout << delete_head(HEAD, TAIL) << "\t";
    cout << delete_head(HEAD, TAIL) << "\t";
    cout << delete_head(HEAD, TAIL) << "\t";
    cout << endl;
    show_from_head(HEAD);
    show_from_tail(TAIL);
    cout << delete_head(HEAD, TAIL) << "\t";
    cout << delete_head(HEAD, TAIL) << "\t";
    cout << endl;
    show_from_head(HEAD);
    show_from_tail(TAIL);*/
    delete_by_index(HEAD, TAIL, 4);
    show_from_head(HEAD);
    delete_by_index(HEAD, TAIL, 0);
    show_from_head(HEAD);
    return 0;
}