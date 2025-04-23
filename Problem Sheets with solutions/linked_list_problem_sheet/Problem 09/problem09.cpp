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
Node* headA = NULL;
Node* headB = NULL;



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


void sortedMergedList(Node* list1, Node* list2){
    if(list1 == NULL || list2 == NULL){
        cout << "List(s) is/are empty" << endl;
        return;
    }

    Node* a = list1;
    Node* b = list2;

    if(a->data<b->data){
        head = list1;
        a = a->next;
    } else{
        head = list2;
        b = b->next;
    }

    
    Node* current = head;

    while(a !=NULL && b != NULL){
 
        if(a->data<b->data){
            current->next = a;
            a = a->next;
            current = current-> next;
        } else{
            current->next = b;
            b = b->next;
            current = current-> next;
        }
    }

    if(a != NULL) current->next = a;
    else if(b != NULL) current->next = b;


}

void printAll(Node* start){
    Node* current = start;

    cout << "Linked List: ";
    while(current != NULL){
        cout << current->data << " —> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}


int main(){

    Node* firstA = new Node(10);
    Node* secondA = new Node(30);
    Node* thirdA = new Node(50);

    firstA->next = secondA;
    secondA->next = thirdA;

    headA = firstA;

    Node* firstB = new Node(20);
    Node* secondB = new Node(40);
    Node* thirdB = new Node(60);

    firstB->next = secondB;
    secondB->next = thirdB;

    headB = firstB;

    sortedMergedList(headA,headB);
    printAll(head);

    return 0;
}