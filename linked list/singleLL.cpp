#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    // Destructor
    ~Node() {
        int value = this->data;
        // Memory free
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

void insertAtHead(Node*& head, int d) {
    // New node creation
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node*& tail, int d) {
    // New node creation
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void print(Node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteNode(Node*& tail, Node*& head, int position) {
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    } else {
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while (cnt < position) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        if (curr->next == NULL) {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

Node* traverseToPosition(Node* head, int position) {
    Node* temp = head;
    int count = 1;

    // Traverse the list until the desired position or the end
    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    // If position is out of bounds
    if (temp == NULL) {
        cout << "Position out of bounds!" << endl;
        return NULL;
    }

    return temp; // Return the node at the desired position
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int n, data;
    cout << "Enter the number of nodes to create the linked list: ";
    cin >> n;

    if (n > 0) {
        cout << "Enter data for node 1: ";
        cin >> data;
        head = new Node(data);
        tail = head;

        for (int i = 2; i <= n; i++) {
            cout << "Enter data for node " << i << ": ";
            cin >> data;
            insertAtTail(tail, data);
        }
    }

    // Print the linked list
    cout << "Linked List after creation: ";
    print(head);

    // Traverse to a particular position
    int positionToTraverse;
    cout << "Enter the position you want to traverse to: ";
    cin >> positionToTraverse;

    Node* resultNode = traverseToPosition(head, positionToTraverse);
    if (resultNode != NULL) {
        cout << "Node at position " << positionToTraverse << " contains data: " << resultNode->data << endl;
    }

    // Deleting a node
    int positionToDelete;
    cout << "Enter the position of the node to delete: ";
    cin >> positionToDelete;

    if (positionToDelete > 0 && positionToDelete <= n) {
        deleteNode(tail, head, positionToDelete);
        n--; // Adjust the size after deletion
    } else {
        cout << "Invalid position!" << endl;
    }

    // Print the linked list after deletion
    cout << "Linked List after deletion: ";
    print(head);

    // Display head and tail data if the list is not empty
    if (head != NULL) 
        cout << "Head: " << head->data << endl;
    else 
        cout << "Head: NULL" << endl;
    

    if (tail != NULL) {
        cout << "Tail: " << tail->data << endl;
    } else {
        cout << "Tail: NULL" << endl;
    }

    return 0;
}


// int main(){

//     Node* node1=new Node(10);

//     Node* head=node1;
//     Node* tail=node1;
//     //print(head);

//     //insertAtHead(head ,12);
//     insertAtTail(tail,12);
//     //print(head);

//     //insertAtHead(head ,15);
//     insertAtTail(tail,15);
//     insertAtTail(tail,22);
//     print(head);

//     deleteNode(tail,head,2);
//     print(head);

//     cout <<"head "<<head->data<<endl;
//     cout <<"tail "<<tail->data<<endl;
// return 0;
// }