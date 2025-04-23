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

void merge(){
    if(head == NULL || head->next == NULL){
        return;
    }

    Node* temp1 = head;
    Node* temp2 = head->next->next;
    Node* current = head->next;
    while(temp2 != NULL){
        // incompelte; too hard TwT will do it later...
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

    int n;
    cout << "Enter the value to search for: ";
    cin >> n;
    cout << "Position: " << find(n) << endl;

    return 0;
}