#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int v) { data = v; next = NULL; }
};

class LinkedList {
    Node* head;
public:
    LinkedList() { head = NULL; }

    void insert(int v) {
        Node* n = new Node(v);
        if (!head) head = n;
        else {
            Node* t = head;
            while (t->next) t = t->next;
            t->next = n;
        }
    }

    void mid() {
        Node* s = head;
        Node* f = head;
        while (f && f->next) {
            s = s->next;
            f = f->next->next;
        }
        cout << "Middle: " << s->data << endl;
    }
};

int main() {
    LinkedList l;
    l.insert(1); l.insert(2); l.insert(3); l.insert(4); l.insert(5);
    l.mid();
}
