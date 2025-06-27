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

    void inorder(Node* root){
        if(root == NULL) return;
        if(root->left != NULL) inorder(root->left);
        cout << root->data << " ";
        if(root->right != NULL)inorder(root->right);
    }

    Node* deleteNode(Node* root, int key){
        if(root == NULL) return NULL;

        if(key < root->data) root->left = deleteNode(root->left, key);
        else if(key> root->data) root->right = deleteNode(root->right, key);
        else{
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }

            else if(root->left == NULL){
                Node* temp = root->right;
                delete root;
                return temp;
            }

            else if(root->right == NULL){
                Node* temp = root->left;
                delete root;
                return temp;
            }

            else{
                int minVal = findMin(root->right);
                root->data = minVal;

                root->right = deleteNode(root->right, minVal);
            }
        }

        return root;
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
    tree.root = tree.insert(tree.root, 80);

    tree.root = tree.deleteNode(tree.root, 70);

    cout << "Inorder Traversal: "; 
    tree.inorder(tree.root);
    cout << endl;

    return 0;
}