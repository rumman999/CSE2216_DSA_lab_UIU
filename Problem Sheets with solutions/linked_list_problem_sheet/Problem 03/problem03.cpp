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


void insertLast(int value){
    Node* newItem = new Node(value);

    if(head ==  NULL){
        head = newItem;
        return;
    }
    
    Node* current = head;
    while(current->next != NULL){
        current = current->next;
    }

    current->next = newItem;
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

    insertLast(10);
    insertLast(20);
    insertLast(30);

    int n;
    cout << "Enter the value of the new node: ";
    cin >> n;
    insertLast(n);
    printAll();

    return 0;
}