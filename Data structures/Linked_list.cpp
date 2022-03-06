#include <bits/stdc++.h>

using namespace std;


class Node {
public:
    int val;
    Node *next;

    Node(int x) : val(x), next(nullptr) {}

    Node(int x, Node *next) : val(x), next(next) {}
};


class MyLinkedList {
public:
    Node *head;

    MyLinkedList() {
        head = nullptr;
    }

    explicit MyLinkedList(vector<int> &arr) {
        Node **current = &this->head;
        for (int &x: arr) {
            *current = new Node{x, *current};
            current = &(*current)->next;
        }
    }

    Node *get_node(int index) {
        Node **current = &this->head;
        while (index > 0 && *current != nullptr) {
            index--;
            current = &(*current)->next;
        }
        return *current;
    }

    int get(int index) {
        Node *found_node = get_node(index);
        if (found_node != nullptr) {
            return found_node->val;
        }
        return -1;
    }

    void addAtHead(int val) {
        Node *new_head = new Node(val, this->head);
        this->head = new_head;
    }

    void addAtTail(int val) {
        if (head == nullptr) {
            head = new Node(val);
            return;
        }
        Node **current = &this->head;
        while (*current != nullptr) {
            current = &(*current)->next;
        }
        (*current)->next = new Node(val);
    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }
        Node *found_node = get_node(index - 1);
        if (found_node != nullptr) {
            found_node->next = new Node(val, found_node->next);
        }
    }

    void deleteAtIndex(int index) {
        if (index == 0) {
            head = head->next;
            return;
        }
        Node *found_node = get_node(index - 1);
        if (found_node != nullptr && found_node->next != nullptr) {
            found_node->next = found_node->next->next;
        }
    }

    friend ostream &operator<<(ostream &os, const MyLinkedList &list) {
        for (Node *current = list.head; current != nullptr; current = current->next) {
            os << current->val << " -> ";
        }
        return os << "nullptr";
    }

};


class DoubleLinkedList {

};

int main() {
    MyLinkedList ls;
    ls.addAtHead(1);
    ls.get_node(0);

    return 0;
}