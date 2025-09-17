#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) { data = val; next = NULL; }
};

class LinkedList {
    Node* head;
public:
    LinkedList() { head = NULL; }

    void insert(int val) {
        Node* n = new Node(val);
        if (head == NULL) head = n;
        else {
            Node* t = head;
            while (t->next != NULL) t = t->next;
            t->next = n;
        }
    }

    void countAndDelete(int key) {
        int c = 0;
        Node* t = head;
        Node* p = NULL;
        while (t != NULL) {
            if (t->data == key) {
                c++;
                if (t == head) {
                    head = head->next;
                    delete t;
                    t = head;
                } else {
                    p->next = t->next;
                    delete t;
                    t = p->next;
                }
            } else {
                p = t;
                t = t->next;
            }
        }
        cout << "Count: " << c << endl;
    }

    void display() {
        Node* t = head;
        while (t != NULL) {
            cout << t->data << " -> ";
            t = t->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList l;
    l.insert(1); l.insert(2); l.insert(1); l.insert(2);
    l.insert(1); l.insert(3); l.insert(1);
    l.display();
    l.countAndDelete(1);
    l.display();
}
