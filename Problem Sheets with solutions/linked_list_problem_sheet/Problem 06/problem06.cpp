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

void reverseLinkedList(){
    if(head == NULL || head->next == NULL){
        return;
    }
    else if(head->next->next == NULL){
        Node* temp1 = head;
        Node* temp2 = head->next;

        head = temp2;
        head->next = temp1;
        temp1->next = NULL;
    }
    else{
        
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;

        while(current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
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

    insertLast(10);
    insertLast(20);
    insertLast(30);
    insertLast(40);


    reverseLinkedList();
    printAll();

    return 0;
}