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


void detectRemoveCycle(){
    Node* slow = head;
    Node* fast = head;

    bool flag = false;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            flag = true;
            break;
        }
    }

    if(flag){
        slow = head;
        while(slow->next != fast->next){
            slow = slow->next;
            fast = fast->next;
        }

        fast->next = NULL;

    } else{
        cout << "No Cycle was found";
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

    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);

    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second;

    head = first;
    

    detectRemoveCycle();
    printAll();

    return 0;
}