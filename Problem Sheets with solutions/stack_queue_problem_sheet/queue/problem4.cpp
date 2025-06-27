#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<string> generateBinaryNumbers(int n){
    vector<string> result;
    if(n==0) return result;

    queue<string> q;
    q.push("1");

    for(int i=0;i<n;i++){
        string current = q.front();
        q.pop();

        result.push_back(current);

        q.push(current + "0");
        q.push(current + "1");

    }

    return result;
}


int main(){
    
    vector<string> BinaryNums = generateBinaryNumbers(25);

    for(string ch: BinaryNums){
        cout << ch << endl;
    }

    return 0;
}