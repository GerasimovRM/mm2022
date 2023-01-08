#include <iostream>

using namespace std;

struct TreeNode {
    float data;
    TreeNode* left;
    TreeNode* right;
};

void add_lkr(TreeNode*& head, float new_data) {
    if (head == nullptr) {
        TreeNode* new_node = new TreeNode;
        new_node->data = new_data;
        new_node->left = nullptr;
        new_node->right = nullptr;
        head = new_node;
    }
    else {
        if (new_data < head->data) {
            add_lkr(head->left, new_data);
        }
        else {
            add_lkr(head->right, new_data);
        }
    }
}

void print_tree_lkr(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    print_tree_lkr(root->left);
    cout << root->data << "\t";
    print_tree_lkr(root->right);
}

void sort_tree_lkr(TreeNode* root, float* mas, int* index = nullptr) {
    bool is_first = false;
    if (index == nullptr) {
        index = new int;
        *index = 0;  // index[0] == *index
        is_first = true;
    }

    if (root == nullptr) {
        return;
    }
    sort_tree_lkr(root->left, mas, index);
    mas[*index] = root->data;
    (*index)++;
    sort_tree_lkr(root->right, mas, index);

    if (is_first) {
        delete index;
    }
}

void sort_tree_lkr2(TreeNode* root, float* mas, int& index) {
    if (root == nullptr) {
        return;
    }
    sort_tree_lkr2(root->left, mas, index);
    mas[index] = root->data;
    index++;
    sort_tree_lkr2(root->right, mas, index);
}


void clear_tree(TreeNode*& root) {
    if (root == nullptr) {
        return;
    }
    clear_tree(root->left);
    clear_tree(root->right);
    delete root;
    root = nullptr;
}


int main() {
    TreeNode* HEAD = nullptr;
    const int count = 6;
    float mas[count] = {5, 2, 7, 13, 4, 9};
    for (int i = 0; i < count; ++i) {
        add_lkr(HEAD, mas[i]);
    }
    int c = 0;
    sort_tree_lkr2(HEAD, mas, c);
    cout << c << endl;
    for (int i = 0; i < count; ++i) {
        cout << mas[i] << "\t";
    }
    clear_tree(HEAD->left);
    return 0;
}