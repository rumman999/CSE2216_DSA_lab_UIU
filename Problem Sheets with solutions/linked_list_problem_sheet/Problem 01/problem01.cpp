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

void insert(int n){
    for(int i=0;i<n;i++){
        int value;
        cin >> value;

        insertLast(value);
    }
}

void printAll(){
    Node* current = head;

    cout << "Linked List: ";
    while(current != NULL){
        cout << current->data << " —> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main(){

    int n;
    cout << "Enter the number of elements you want to add: ";
    cin >> n;

    insert(n);
    printAll();

    return 0;
}