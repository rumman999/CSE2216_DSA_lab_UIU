#include <iostream>
using namespace std;

class Stack{
    char arr[100];
    int top;
public:
    Stack(){
        top=-1;
    }

    bool isFull(){
        return top>=99;
    }

    bool isEmpty(){
        return top==-1;
    }

    void push(char val){
        if(!isFull()){
            top++;
            arr[top] = val;
        } else{
            cout << "The Stack is already full." << endl;
        }
    }

    void pop(){
        if(!isEmpty()){
            top--;
        } else{
            cout << "The Stack is already empty." << endl;
        }
    }

    char peek(){
        if(!isEmpty()){
            return arr[top];
        } else{
            cout << "The Stack is empty." << endl;
            return -1;
        }
    }

    void display(){
        if(!isEmpty()){
            for(int i=0;i<=top;i++){
                cout << arr[i];

                if(i!=top) cout << " -> "; 
            }

            cout << endl;

        } else{
            cout << "The Stack is empty." << endl;
        }
    }

    void revDisplay(){
        while(!isEmpty()){
            cout << peek();
            pop();
        }
        cout << endl;
    }

};

int main(){
    Stack st;
    string str = "HELLO";

    for(char ch: str){
        st.push(ch);
    }

    st.display();
    st.revDisplay();

    return 0;
}