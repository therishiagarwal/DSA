#include <iostream>

using namespace std;

// Node structure for singly linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to reverse a singly linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        // Save the next node
        next = current->next;

        // Reverse the link
        current->next = prev;

        // Move to the next nodes
        prev = current;
        current = next;
    }

    // The new head is the previous node after the loop
    head = prev;
    return head;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Example usage:
    // Create a linked list: 2->3->4->5->6->7
    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(6);
    head->next->next->next->next->next = new Node(7);
    cout<< head->data <<endl;

    cout << "Original linked list: ";
    printList(head);

    // Reverse the linked list
    head = reverseList(head);

    cout << "Reversed linked list: ";
    printList(head);

    return 0;
}
