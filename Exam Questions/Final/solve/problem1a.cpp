#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;

    Node(int value){
        data = value;
        right = NULL;
        left = NULL;
    }
};


class BST{
public:
    Node* root;
    BST(){
        root = NULL;
    }

    Node* insert(Node* root, int value){
        if(root == NULL) return new Node(value);

        if(value < root->data) root->left = insert(root->left, value);
        if(value > root->data) root->right = insert(root->right, value);


        return root;
    }


    void inorder(Node* root){
        if(root == NULL) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    bool search(Node* root, int key){
        if(root == NULL) return false;

        if(root->data == key) return true;
        else if(root->data > key) return search(root->left, key);
        else return search(root->right, key);
    }
};

int main(){
    BST tree;

    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);
    
    
    cout << "40: ";
    if(tree.search(tree.root, 40)){
        cout << "Found" << endl;
    } else{
        cout << "Not Found" << endl;
    }

    cout << "90: ";
    if(tree.search(tree.root, 90)){
        cout << "Found" << endl;
    } else{
        cout << "Not Found" << endl;
    }

    // tree.inorder(tree.root);

    return 0;
}