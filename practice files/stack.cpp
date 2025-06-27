#include <iostream>
using namespace std;


class Stack{
    int arr[100];
    int top;
    int min[100];
    int minTop;

public:

    Stack(){
        top = -1;
        minTop = -1;
    }

    bool isFull(){
        return top>=99;
    }

    bool isEmpty(){
        return top==-1;
    }

    void push(int value){
        if(!isFull()){
            top++;
            arr[top] = value;
            if(minTop==-1 || value<=min[minTop]){
                minTop++;
                min[minTop]=value;
            }
        }
    }

    void pop(){
        if(!isEmpty()){
            if(peek()==min[minTop]){
                minTop--;
            }
            top--;
        }
    }

    int peek(){
        if(!isEmpty()){
            return arr[top]; 
        }

        return -1;
    }

    void display(){
        if(!isEmpty()){
            for(int i=0;i<=top;i++){
                cout << arr[i];

                if(i!=top){
                    cout << " -> ";
                }
            }

            cout << endl;
        }
    }

    void revDisplay(){
        if(!isEmpty()){
            for(int i=top;i>=0;i--){
                cout << arr[i];

                if(i!=0){
                    cout << " -> ";
                }
            }

            cout << endl;
        }
    }

    int getMin(){
        if(!isEmpty()){
           return min[minTop]; 
        }
        return -1;
    }

};

string reverseString(string str, Stack &st){

    string reverse = "";

    while(!st.isEmpty()){
        reverse += st.peek();
        st.pop();
    }

    return reverse;
}

string balancedParentheses(string str, Stack &st){
    
    for(int i=0;i<str.length();i++){
        if(str[i]=='('){
            st.push(1);
        }
        else if(str[i]==')'){
            if(!st.isEmpty()){
                st.pop();
            } else{
                return "NO";
            }
        }
    }
    if(st.isEmpty()) return "YES";
    else return "NO"; 
}

void sortStack(Stack &mainStack){
    Stack temp;

    while(!mainStack.isEmpty()){   
        int currentValue = mainStack.peek();
        mainStack.pop();

        while(!temp.isEmpty() && currentValue<temp.peek()){
            mainStack.push(temp.peek());
            temp.pop();
        }

        temp.push(currentValue);
    }

    while(!temp.isEmpty()){
        mainStack.push(temp.peek());
        temp.pop();
    }
}


int main(){

    Stack st;

    st.push(40);
    st.push(50);
    st.push(20);
    st.push(30);

    
    cout << st.getMin() << endl;

    return 0;
}