#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root, int d) {
    if (root == NULL) {
        return new Node(d);
    }

    if (d > root->data) {
        root->right = insertIntoBST(root->right, d);
    }
    else {
        root->left = insertIntoBST(root->left, d);
    }

    return root;
}

Node* takeInput() {
    int data;
    cin >> data;

    Node* root = NULL;

    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
    
    return root;
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

bool SearchInBST(Node* root, int x) {
    // Base case: If the tree is empty 
    if (root == NULL) {
        return false;  
    }
    if(root->data == x){
        return true;
    }
    // Recursive case: Search in the left or right subtree based on the x
    if (x < root->data) {
        return SearchInBST(root->left, x);
    } else {
        return SearchInBST(root->right, x);
    }

    // while(root !=NULL){
    //     if(root->data==x){
    //         return true;
    //     }
    //     if(root->data>x){
    //         root=root->left;
    //     }
    //     else{
    //         root=root->right;
    //     }
    // }
    // return false;
}

Node* minValue(Node* root){
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

Node* maxValue(Node* root){
    Node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

Node* deletion(Node*root, int val){
     if(root==NULL){
        return root;
     }
     if(root->data==val){

        // 0 child 
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        // 1 Child 

        // left child
        if( root->left !=NULL && root->right==NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // right child
        if( root->left ==NULL && root->right!=NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if( root->left ==NULL && root->right!=NULL){
            int mini =minValue(root->right)->data;
            root->data=mini;
            root->right=deletion(root->right , mini);
        }
            return root;


     }
     else if ( root-> data >val){
        root->left = deletion(root->left ,val );
        return root;
     }
     else{
        root->right = deletion(root->right ,val );
        return root;
     }
}

int main() {
    cout << "Enter Data to create BST (enter -1 to stop): " << endl;
    Node* root = takeInput();

    // 7 10 15 17 9 5 16 19 -1

    // 10 8 21 7 27 5 4 3 -1

    cout << "\nIn-order traversal of the constructed tree is: ";
    inorder(root);

    cout << "\nPre-order traversal of the constructed tree is: ";
    preOrder(root);

    cout << "\nPost-order traversal of the constructed tree is: ";
    postOrder(root);
    cout <<endl;


    // int x;
    // cout<<"Enter the number to be searched:\n";
    // cin>> x;
    // if(SearchInBST(root,x ))
    //     cout<<"Found"<<endl;
    // else   
    //     cout<<"Not FOund"<<endl;


    cout <<"The Min VAlue is "<<minValue(root)->data <<endl;
    cout <<"The Max VAlue is "<<maxValue(root)->data <<endl;

    int key;
    cout <<"Enter a value for which you want to delete : \n";
    cin>>key;
    deletion(root, key);


    cout << "\nIn-order traversal of the constructed tree is: ";
    inorder(root);

    cout << "\nPre-order traversal of the constructed tree is: ";
    preOrder(root);

    cout << "\nPost-order traversal of the constructed tree is: ";
    postOrder(root);
    cout <<endl;
    return 0;
}
