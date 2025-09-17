#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int v) { data = v; next = NULL; }
};

class List {
    Node* head;
public:
    List() { head = NULL; }

    void add(int v) {
        Node* n = new Node(v);
        if (!head) head = n;
        else {
            Node* t = head;
            while (t->next) t = t->next;
            t->next = n;
        }
    }

    void rev() {
        Node* p = NULL, *c = head, *n = NULL;
        while (c) {
            n = c->next;
            c->next = p;
            p = c;
            c = n;
        }
        head = p;
    }

    void show() {
        Node* t = head;
        while (t) {
            cout << t->data << " -> ";
            t = t->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    List l;
    l.add(1); l.add(2); l.add(3); l.add(4);
    cout << "Original: "; l.show();
    l.rev();
    cout << "Reversed: "; l.show();
}
