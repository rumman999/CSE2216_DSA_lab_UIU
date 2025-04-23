#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = NULL;
    }
};

Node* head = NULL;



void insertFirst(int value){
    Node* newItem = new Node(value);
    newItem->next = head;
    
    head = newItem;
}



void printAll(){
    Node* current = head;

    cout << "Linked List: ";
    while(current != NULL){
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main(){

    insertFirst(40);
    insertFirst(30);
    insertFirst(20);

    int n;
    cout << "Enter the value of the new node: ";
    cin >> n;
    insertFirst(n);
    printAll();

    return 0;
}