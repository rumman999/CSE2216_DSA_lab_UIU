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

    int findMin(Node* root){
        if(root == NULL) return -1;
        while(root->left != NULL) root = root->left;
        return root->data;
    }

    Node* deleteNode(Node* root, int key){
        if(root == NULL) return NULL;

        if(key < root->data) root->left = deleteNode(root->left, key);
        else if(key > root->data) root->right = deleteNode(root->right, key);
        else{
            if(root->right == NULL && root->left == NULL){
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
                int minRight = findMin(root->right);
                root->data = minRight;

                root->right = deleteNode(root->right, minRight);
            }
        }

        return root;
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
    
    tree.deleteNode(tree.root, 70);

    tree.inorder(tree.root);
    cout << endl;

    return 0;
}