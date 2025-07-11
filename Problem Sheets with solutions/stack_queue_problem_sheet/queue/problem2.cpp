#include <iostream>
#include <stack>

using namespace std;

class Queue{

public:
    int arr[100];
    int front;
    int rear;

    Queue(){
        front= -1;
        rear = -1;
    }

    bool isEmpty(){
        return front==-1;
    }

    bool isFull(){
        return rear>=99;
    }

    void enqueue(int value){
        if(!isFull()){
            if(front == -1) front = 0;
            rear++;
            arr[rear] = value;
        } else{
            cout << "Queue is Full" << endl;
        }
    }

    void dequeue(){
        if(!isEmpty()){
            if(rear == front){
                rear =-1;
                front = -1;
            } else{
                front++;
            }
        } else{
            cout << "Queue is already Empty" << endl;
        }
    }

    int peek(){
        if(!isEmpty()){
            return arr[front];
        } else{
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
    }

    void display(){
        if(!isEmpty()){
            cout << "Queue: ";

            for(int i=front; i<=rear; i++){
                cout << arr[i];

                if(i!=rear){
                    cout << " -> ";
                }
            }

            cout << endl;
        }
    }
};


void reverse(Queue &q){
    if(q.isEmpty()) return;

    stack<int> st;

    for(int i=q.front; i<=q.rear;i++){
        st.push(q.arr[i]);
    }

    int i = q.front;

    while(!st.empty()){
        q.arr[i++] = st.top();
        st.pop();
    }

    q.display();

}

int main(){

    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();
    reverse(q);

    return 0;
}