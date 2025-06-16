#include <iostream>
using namespace std;

class Stack{
    int arr[100];
    int top;
    int min[100];
    int minTop;
public:
    Stack(){
        top=-1;
        minTop = -1;
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
            if(minTop==-1 || val<=min[minTop]){
                minTop++;
                min[minTop] = val;
            }
        } else{
            cout << "The Stack is already full." << endl;
        }
    }

    void pop(){
        if(!isEmpty()){
            if(arr[top]==min[minTop]){
                minTop--;
            }
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
            for(int i=0;i<=top;i++){
                cout << arr[i];

                if(i!=top) cout << " -> "; 
            }

            cout << endl;

        } else{
            cout << "The Stack is empty." << endl;
        }
    }

    int getMin(){
        if(minTop != -1){
            return min[minTop];
        } else{
            cout << "The Stack is empty." << endl;
            return -1;
        }
    }

};

int main(){
    Stack st;

    st.push(10);
    st.push(20);
    st.push(5);



    cout << st.getMin() << endl;

    return 0;
}