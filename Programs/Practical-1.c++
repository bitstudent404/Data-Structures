// Write a program to implement singly linked list as an ADT that supports the following operations:
// 1) Insert an element x at the beginning of the singly linked list
// 2) Insert an element x at the ith position in the singly linked list.
// 3) Remove an element from the beginning of the doubly linked list.
// 4) Remove an element from the ith position in the singly linked list.
// 5) Search for an element x in the singly linked list and returns its pointer.

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Singly Linked List Class (ADT)
class SinglyLinkedList {
private:
    Node* head;

public:
    // Constructor
    SinglyLinkedList() {
        head = nullptr;
    }

    // 1. Insert element x at the beginning
    void insertAtBeginning(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = head;
        head = newNode;
    }

    // 2. Insert element x at the ith position (1-based index)
    void insertAtPosition(int x, int position) {
        if (position < 1) {
            cout << "Position should be >= 1.\n";
            return;
        }

        Node* newNode = new Node();
        newNode->data = x;

        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position out of range.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // 3. Remove element from the beginning
    void removeFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // 4. Remove element from ith position (1-based index)
    void removeFromPosition(int position) {
        if (position < 1 || head == nullptr) {
            cout << "Invalid position or empty list.\n";
            return;
        }

        if (position == 1) {
            removeFromBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of range.\n";
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    // 5. Search for an element x and return its pointer
    Node* search(int x) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == x)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    // Display list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Destructor to free memory
    ~SinglyLinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Main function to demonstrate the ADT
int main() {
    SinglyLinkedList list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtPosition(30, 2);
    cout << "List after insertions: ";
    list.display();

    list.removeFromBeginning();
    cout << "After removing from beginning: ";
    list.display();

    list.removeFromPosition(2);
    cout << "After removing 2nd element: ";
    list.display();

    Node* found = list.search(30);
    if (found)
        cout << "Element 30 found at address: " << found << endl;
    else
        cout << "Element 30 not found.\n";

    return 0;
}
