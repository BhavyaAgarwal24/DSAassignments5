#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
    Node* head;

public:
    LinkedList() { head = NULL; }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }

    void insertBefore(int key, int val) {
        if (head == NULL) return;
        if (head->data == key) {
            insertAtBeginning(val);
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != key) temp = temp->next;
        if (temp->next == NULL) {
            cout << "Key not found\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertAfter(int key, int val) {
        Node* temp = head;
        while (temp != NULL && temp->data != key) temp = temp->next;
        if (temp == NULL) {
            cout << "Key not found\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List Empty!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List Empty!\n";
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL) temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }

    void deleteNode(int key) {
        if (head == NULL) return;
        if (head->data == key) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != key) temp = temp->next;
        if (temp->next == NULL) {
            cout << "Key not found\n";
            return;
        }
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    void search(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Not found\n";
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    int choice, val, key;
    while (1) {
        cout << "\n1.InsertBeg 2.InsertEnd 3.InsertBefore 4.InsertAfter";
        cout << " 5.DelBeg 6.DelEnd 7.DelNode 8.Search 9.Display 10.Exit\n";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; list.insertAtBeginning(val); break;
            case 2: cout << "Enter value: "; cin >> val; list.insertAtEnd(val); break;
            case 3: cout << "Enter key and new value: "; cin >> key >> val; list.insertBefore(key, val); break;
            case 4: cout << "Enter key and new value: "; cin >> key >> val; list.insertAfter(key, val); break;
            case 5: list.deleteFromBeginning(); break;
            case 6: list.deleteFromEnd(); break;
            case 7: cout << "Enter key: "; cin >> key; list.deleteNode(key); break;
            case 8: cout << "Enter key: "; cin >> key; list.search(key); break;
            case 9: list.display(); break;
            case 10: return 0;
            default: cout << "Invalid choice\n";
        }
    }
}
