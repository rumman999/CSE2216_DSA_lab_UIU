#include <iostream>
using namespace std;


struct Node{
    int data;
    Node* left;
    Node* right;

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
        if(root==NULL) return new Node(value);

        if(value<root->data) root->left = insert(root->left, value);
        if(value>root->data) root->right = insert(root->right, value);

        return root;
    }

    bool search(Node* root, int key){
        if(root == NULL) return false;

        if(root->data == key) return true;
        if(key<root->data) return search(root->left, key);
        else return search(root->right, key);
    }

};

int main(){

    BST tree;

    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 70);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 60);

    if(tree.search(tree.root, 40)){
        cout << 40 << " is Found!" << endl;
    } else{
        cout << 40 << " is not Found!" << endl;
    }

    if(tree.search(tree.root, 90)){
        cout << 90 << " is Found!" << endl;
    } else{
        cout << 90 << " is not Found!" << endl;
    }

    return 0;
}