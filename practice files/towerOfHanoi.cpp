#include <iostream>
using namespace std;

void hanoi(int n, int src, int dest, int intermediate){
    if(n==1){
        cout << n  << " -> " << dest << endl;
    } else{
        hanoi(n-1, src, intermediate, dest);
        cout << src  << " -> " << dest << endl;
        hanoi(n-1, intermediate, dest, src);
    }
}

int main(){
    hanoi(3, 1, 3, 2);
    return 0;
}
