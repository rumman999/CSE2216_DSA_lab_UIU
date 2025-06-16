#include <bits/stdc++.h>
using namespace std;

class Stack{
    int arr[100];
    int top;

public:
    Stack(){
        top = -1;
    }

    bool isEmpty(){
        if(top == -1) return true;
        else return false;
    }

    bool isFull(){
        if(top >=99) return true;
        else return false;
    }

    void push(int value){
        if(!isFull()){
            top++;
            arr[top] = value;
        } else{
            cout << "The Stack is Full" << endl;
        }
    }

    void pop(){
        if(!isEmpty()){
            top--;
        } else{
            cout << "The Stack is already Empty" << endl;
        }
    }

    int peek(){
        if(!isEmpty()){
            return arr[top];
        } else{
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
    }

    void display(){
        for(int i=top;i>=0;i--){
            cout << arr[i] << endl;
        }
    }

};



int main(){
    Stack st;

    cout << st.isEmpty() << endl;

    st.push(10);

    cout << st.isEmpty() << endl;
    cout << st.isFull() << endl;
    st.push(60);
    st.push(5);
    st.push(550);
    
    st.pop();
    st.pop();

    st.display();
}