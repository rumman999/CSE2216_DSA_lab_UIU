#include <iostream>
#include <queue>
using namespace std;


class Stack{
    queue<int> q1;
    queue<int> q2;

    void push(int val){
        q1.push(val);
    }

    void pop(){
        if(!q1.empty()){
            while(q1.size()>1){
                q2.push(q1.front());
                q1.pop();
            }
            q1.pop();
            swap(q1,q2);
        }
    }
};


int main(){

    return 0;
}