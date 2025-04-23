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

void deleteValue(int value){


    if(head ==  NULL){
        cout << "Nothing to delete" << endl;
        return;
    } else if(head->data == value){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    
    Node* current = head;

    while(current->next != NULL && current->next->data != value){
        current = current->next;
    }

    if(current->next == NULL){
        cout << "Value doesn't exist" << endl;
        return;
    }

    Node* temp = current->next;

    current->next = current->next->next;
    delete temp;
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
    insertLast(40);

    int n;
    cout << "Enter the value that needs to be deleted: ";
    cin >> n;
    deleteValue(n);
    printAll();

    return 0;
}