#include <iostream>
using namespace std;

class Stack{
public:
    int arr[100];
    int top;
    Stack(){
        top=-1;
    }

    bool isFull(){
        return top>=99;
    }

    bool isEmpty(){
        return top==-1;
    }

    void push(int val){
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

    int peek(){
        if(!isEmpty()){
            return arr[top];
        } else{
            cout << "The Stack is empty." << endl;
            return -1;
        }
    }

    void display(){
        if(!isEmpty()){
            for(int i=top;i>=0;i--){
                cout << arr[i];

                if(i!=0) cout << " -> "; 
            }

            cout << endl;

        } else{
            cout << "The Stack is empty." << endl;
        }
    }

};

void sortArray(Stack &st){
        Stack temp;

        while(!st.isEmpty()){
            int currentValue = st.peek();
            st.pop();

            while(!temp.isEmpty() && currentValue<temp.peek()){
                st.push(temp.peek());
                temp.pop();
            }
            
            temp.push(currentValue);
        }


        while(!temp.isEmpty()){
            st.push(temp.peek());
            temp.pop();
        }
}

int main(){
    Stack st;

    st.push(30);
    st.push(10);
    st.push(20);
    st.push(50);
    st.push(40);

    sortArray(st);

    st.display();

    return 0;
}