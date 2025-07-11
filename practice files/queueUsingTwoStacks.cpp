#include <iostream>
#include <stack>
using namespace std;


class Queue{
    stack<int> st1;
    stack<int> st2;

    void enqueue(int val){
        st1.push(val);
    }

    void dequeue(){

        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }

        if(!st2.empty()){
            st2.pop();
        }
    }
};


int main(){

    return 0;
}