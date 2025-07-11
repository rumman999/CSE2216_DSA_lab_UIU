#include <iostream>
#include <queue>
using namespace std;

class Stack{
    queue<int> q1,q2;

public:
  
    void push(int val){
        q2.push(val);

        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1,q2);
    }

    bool isEmpty(){
        return q1.empty();
    }

    void pop(){
        if(!isEmpty()){
            q1.pop();
        }
    }

    int top(){
        return q1.front();
    }

    void display(){
        q2 = q1;

        while(!q2.empty()){
            cout << q2.front() << endl;
            q2.pop();
        }
    }
};

int main(){

    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    st.pop();

    st.display();
    return 0;
}