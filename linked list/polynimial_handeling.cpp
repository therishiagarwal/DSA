#include<iostream>
using namespace std;

class Node {
public:
    int coef;
    int exp;
    Node* next;

    Node(int coef, int exp) {
        this->coef = coef;
        this->exp = exp;
        this->next = NULL;
    }
};

void insertAtTail(Node* &tail, int coef, int exp) {
    Node* temp = new Node(coef, exp);
    if (tail == NULL) {
        // If the list is empty, set both head and tail to the new node
        tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void print(Node* head) {
    if (head == NULL) {
        cout << "List is empty " << endl;
        return;
    }

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->coef << "x^" << temp->exp;
        temp = temp->next;
        if (temp != NULL) {
            cout << "+";
        }
    }
    cout << endl;
}

int main() {
    Node* node1 = new Node(4, 3);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 9, 2);
    print(head);

    return 0;
}
