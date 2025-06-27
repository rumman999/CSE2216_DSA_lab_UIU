#include <iostream>
#include <stack>
using namespace std;

class Queue{
    stack<int> s1, s2;
public:
    void enqueue(int x) {
        s1.push(x);
    }

    void dequeue() {
        if (s2.empty()) {
            if (s1.empty()) {
                cout << "Queue is Empty" <<endl;
                return;
            }
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }

    int front() {
        if (s2.empty()) {
            if (s1.empty()) {
                cout << "Queue is Empty" <<endl;
                return -1;
            }
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << q.front() << endl;
    q.dequeue();
    cout << q.front() << endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    
    return 0;
}