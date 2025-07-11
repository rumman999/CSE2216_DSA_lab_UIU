#include <iostream>
using namespace std;

class Queue{
    int* arr;
    int front;
    int rear;
    int capaticty;
public:
    Queue(int size){
        front= -1;
        rear = -1;
        arr = new int[size];
        capaticty = size;
    }

    bool isEmpty(){
        return front==-1;
    }

    bool isFull(){
        return (front==(rear+1)%capaticty);
    }

    void enqueue(int value){
        if(isEmpty()){
            front=rear=0;
        } else{
            rear = (rear+1)%capaticty;
            if(front==rear) front=(front+1)%capaticty;
        }

        arr[rear] = value;
    }

    void dequeue(){
        if(!isEmpty()){
            if(front==rear){
                front = rear = -1;
            } else{
                front = (front+1)% capaticty;
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

            int i = front;

            while(true){
                cout << arr[i];
                if(i==rear) break;
                cout << " -> ";
                i = (i+1)%capaticty;
            }

            cout << endl;
        }
    }
};

int main(){

    Queue q(3);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    

    q.display();

    return 0;
}