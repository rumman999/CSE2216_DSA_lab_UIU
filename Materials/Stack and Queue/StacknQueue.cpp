#include<iostream>
using namespace std;

class Stack
{
    int arr[100];
    int top;

public:
    Stack()
    {
        top=-1;
    }

    bool isEmpty()
    {
        if(top==-1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if(top>=99)
            return true;
        else
            return false;
    }

    void push(int value)
    {
        if(isFull())
        {
            cout<<"Stack is Full"<<endl;
            return;
        }

        top++;
        arr[top]=value;
    }

    void pop()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty"<<endl;
            return;
        }
        top--;

    }

    int peek()
    {
        if(isEmpty())
        {
            cout<<"Stack is Empty"<<endl;
            return -1;
        }

        return arr[top];
    }


    void display()
    {
        for(int i=top; i>=0; i--)
        {
            cout<<arr[i]<<endl;
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

        if(front==rear) //Only one element is Present
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



int main()
{
//    Stack st;
//    st.push(10);
//    st.push(20);
//    st.push(30);
//    st.pop();
//    st.pop();
//    st.pop();
//    st.pop();
//    st.pop();
//
//    st.display();

     Queue q;
     q.enqueue(10);
     q.enqueue(20);
     q.enqueue(30);

     //q.display();
     q.dequeue();
     q.dequeue();
     q.dequeue();
     q.display();

}

