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

int find(int value){


    if(head ==  NULL){
        return -1;
    }

    int pos = 1;
    
    Node* current = head;
    while(current != NULL && current->data != value){
        pos++;
        current = current->next;
    }

    if(current == NULL){
        return -1;
    }

    return pos;
}


int main(){

    insertLast(10);
    insertLast(20);
    insertLast(30);
    insertLast(40);

    int n;
    cout << "Enter the value to search for: ";
    cin >> n;
    cout << "Position: " << find(n) << endl;

    return 0;
}