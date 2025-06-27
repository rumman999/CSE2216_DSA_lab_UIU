#include <iostream>
using namespace std;

class Stack{
    int arr[100];
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
            for(int i=0;i<=top;i++){
                cout << arr[i];

                if(i!=top) cout << " -> "; 
            }

            cout << endl;

        } else{ 
            cout << "The Stack is empty." << endl;
        }
    }

};


class Queue
{
    int front;
    int rear;
    int arr[100];

public:
    Queue()
    {
        front=-1;
        rear=-1;
    }

    bool isEmpty()
    {
        if(front==-1)
        {
            return true;
        }

        else return false;
    }

    bool isFull()
    {
        if(rear>=99)
        {
            return true;
        }
        else return false;
    }


    void enqueue(int value)
    {
        if(isFull())
        {
            cout<<"Queue is Full"<<endl;
            return;
        }

        if(front==-1)
        {
            front=0;
        }

        rear++;
        arr[rear]=value;

    }

    void dequeue()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty"<<endl;
            return;
        }

        if(front==rear) 
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front++;
        }
    }

    int peek()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty"<<endl;
            return -1;
        }

        return arr[front];
    }


    void display()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty"<<endl;
            return;
        }

        for(int i=front; i<=rear; i++)
        {
            cout<<arr[i]<<endl;
        }
    }
};

void palindromeCheck(string str){

Stack st;
 Queue q;
for(char ch: str){
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')){
            st.push(tolower(ch));
            q.enqueue(tolower(ch));
        }
  }
  
    while(!st.isEmpty()){
        if( st.peek() != q.peek()){
            cout << "Not a palindrome" << endl;
            return;
        }
        else{
        st.pop();
        q.dequeue();
        }
    }
    
    cout << "Is a palindrome" << endl;
}

int main(){
  string str1 = "madam";
  string str2 = "hello";
  
  palindromeCheck(str1);
  palindromeCheck(str2);

 return 0;
}