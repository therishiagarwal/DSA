#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    // Constructor
    Node(int data){
        this ->data=data;
        this -> next=NULL;
    }
    //destructor
    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

void insertAtHead(Node* &head, int d) {

    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d) {
     // new node create
    Node* temp = new Node(d);
    tail -> next = temp;
    tail  = temp;
}

void print(Node* head) {

    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void deleteNode(Node* &tail, Node* &head, int position){
    if(position==1){
        Node* temp=head;
        head=head->next;
        temp ->next=NULL;
        delete temp;
    }
    else{
        Node* curr=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev ->next=curr->next;
        if(curr->next==NULL){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }
}

int main(){

    Node* node1=new Node(10);

    Node* head=node1;
    Node* tail=node1;
    //print(head);

    //insertAtHead(head ,12);
    insertAtTail(tail,12);
    //print(head);

    //insertAtHead(head ,15);
    insertAtTail(tail,15);
    insertAtTail(tail,22);
    print(head);

    deleteNode(tail,head,2);
    print(head);

    cout <<"head "<<head->data<<endl;
    cout <<"tail "<<tail->data<<endl;
return 0;
}