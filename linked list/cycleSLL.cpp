#include <iostream>

using namespace std;

// Node structure for singly linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to detect whether a linked list contains a cycle
bool hasCycle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return false; // An empty list or a list with one node cannot contain a cycle
    }

    Node* slow = head;
    Node* fast = head;

    // Move slow pointer one step and fast pointer two steps at a time
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        // If there is a cycle, the pointers will eventually meet
        if (slow == fast) {
            return true;
        }
    }

    // If the loop exits, there is no cycle
    return false;
}

int main() {
    // Example usage:
    // Create a linked list: 1->2->3->4->5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next=head->next;


    // Test whether the linked list has a cycle
    bool result = hasCycle(head);

    if (result) {
        cout << "The linked list contains a cycle." << endl;
    } else {
        cout << "The linked list is NULL-terminated." << endl;
    }

    return 0;
}
