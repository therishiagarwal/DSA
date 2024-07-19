#include<iostream>
using namespace std;

class  node{
    public:
    int data;
    node* left;
    node*right;

    node(int d){
        this-> data=d;
        this -> left=NULL;
        this -> right=NULL;
    }
};

node* buildTree(node* root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>> data;
    root =new node(data);

    if(data ==-1){
        return NULL;
    }

    cout<<"Enter data for Inseting in left of "<<data <<endl;
    root->left=buildTree(root->left);
    cout<<"Enter data for Inseting in right of "<<data << endl;
    root->right=buildTree(root->right);

    return root;
}

void inorder(node* root){
    // base case
    if(root== NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
} 

void preOrder(node* root){
    // base case
    if(root== NULL){
        return;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
} 

void postOrder(node* root){
    // base case
    if(root== NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
} 


int main(){
    node* root=NULL;

    // Creating tree
    root=buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1


    cout<<"Inorder Traversal is: ";
    inorder(root);
    
    cout<<"\nPre-order Traversal is: ";
    preOrder(root);
    cout<<"\nPost-order Traversal is: ";
    postOrder(root);
return 0;
}