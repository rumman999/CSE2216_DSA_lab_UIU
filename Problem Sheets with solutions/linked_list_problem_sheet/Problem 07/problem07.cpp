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

void middleNode(){
    if(head == NULL){
        cout << "The list is empty" << endl;
        return;
    }

    Node* fast = head;
    Node* slow = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;   
    }

    cout << "Middle Node: " << slow->data << endl;
}


int main(){

    insertLast(10);
    insertLast(20);
    insertLast(30);
    insertLast(40);
    insertLast(50);
    
    middleNode();

    return 0;
}