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

    int findMin(Node* root){
        if(root == NULL) return -1;
    
        while(root->left != NULL) root = root->left;
        return root->data;
    }

    int findMax(Node* root){
        if(root == NULL) return -1;
    
        while(root->right != NULL) root = root->right;
        return root->data;
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

    int min = tree.findMin(tree.root);
    cout << min << endl;

    int max = tree.findMax(tree.root);
    cout << max << endl;

    return 0;
}