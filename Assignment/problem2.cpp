#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void modifyQueue(queue<int> &Queue, int k){
    stack<int> Stack;

    for(int i=0;i<k;i++){
        Stack.push(Queue.front());
        Queue.pop();
    }

    while(!Stack.empty()){
        Queue.push(Stack.top());
        Stack.pop();
    }

    for(int i=0;i<Queue.size()-k;i++){
        Queue.push(Queue.front());
        Queue.pop();
    }
}


void printQueue(queue<int> &Queue){
    while(!Queue.empty()){
        cout << Queue.front() << " ";
        Queue.pop();
    }
    cout << endl;
}

int main(){

    queue<int> Queue;
    
    Queue.push(1);
    Queue.push(2);
    Queue.push(3);
    Queue.push(4);
    Queue.push(5);

    int k = 3;

    modifyQueue(Queue, k);
    printQueue(Queue);

    return 0;
}