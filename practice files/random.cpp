#include <iostream>
using namespace std;


void enqueue(int data){
    if(first=-1 && last==-1){
        first = last = 0;
        queue[last] = data;
    } else{
        int temp = (last+1)%size;
        if(first == temp) cout << "Queue overloaded" << endl;
        else{
            last = temp;
            queue[last] = data;
        }
    }
}

int main(){


    return 0;
}
