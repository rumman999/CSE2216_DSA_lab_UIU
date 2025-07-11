#include <iostream>
#include <stack>
#include <queue>
using namespace std;

string reversedString(string str){
    string s= "";
    stack<char> st;
    for(char c: str){
        st.push(c);
    }

    while(!st.empty()){
        s+=st.top();
        st.pop();
    }

    return s;
}


int main(){
    string str = "HELLO";

    string s = reversedString(str);


    cout << s << endl;

    return 0;
}
