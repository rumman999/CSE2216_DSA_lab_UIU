#include <iostream>
using namespace std;

class Stack{
    char arr[100];
    int top;
    bool hasBalancedParentheses = true;

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
            hasBalancedParentheses = false;
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

    void checkForBalancedParentheses(string str){

        for(char ch: str){
          if(ch=='(') push(ch);
           else if(ch==')') pop();
         }
        
         if(hasBalancedParentheses && isEmpty()) cout << "Yes" << endl;
         else cout << "No" << endl;
    }

    

};

int main(){
    Stack st;
    string str = "(a+b)*(c+d)";

    st.checkForBalancedParentheses(str);

    return 0;
}