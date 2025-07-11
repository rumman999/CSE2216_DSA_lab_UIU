#include <iostream>
#include <stack>
using namespace std;

class Queue{
    stack<int> st1,st2;

public:
    void enqueue(int val){
        
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }

        st2.push(val);

        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
    }

    bool isEmpty(){
        return st1.empty();
    }

    void dequeue(){
        if(!isEmpty()){
            st1.pop();
        }
    }

    int front(){
        if(!isEmpty()){
            return st1.top();
        }
        return -1;
    }

    void display(){
        stack<int> temp = st1;

        while(!temp.empty()){
            cout << temp.top() << " ";
            temp.pop();
        }

        cout << endl;
    }
};

int main(){
    Queue q;

    q.enqueue(10);
    q.enqueue(20);

    q.display();

    return 0;
}