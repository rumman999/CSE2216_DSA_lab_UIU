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

    void preorder(Node* root){
        if(root == NULL) return;
        cout << root->data << " ";
        if(root->left != NULL) preorder(root->left);
        if(root->right != NULL)preorder(root->right);
    }

    void inorder(Node* root){
        if(root == NULL) return;
        if(root->left != NULL) inorder(root->left);
        cout << root->data << " ";
        if(root->right != NULL)inorder(root->right);
    }

    void postorder(Node* root){
        if(root == NULL) return;
        if(root->left != NULL) postorder(root->left);
        if(root->right != NULL)postorder(root->right);
        cout << root->data << " ";
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

    cout << "Inorder Traversal: "; 
    tree.inorder(tree.root);
    cout << endl;

    cout << "Preorder Traversal: "; 
    tree.preorder(tree.root);
    cout << endl;

    cout << "Postorder Traversal: "; 
    tree.postorder(tree.root);
    cout << endl;

    return 0;
}