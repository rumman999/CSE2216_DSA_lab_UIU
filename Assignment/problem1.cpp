#include <iostream>
#include <stack>

using namespace std;


int main(){

    stack<int> st;
    string str = "5 1 2 + 4 * + 3 -";

    string s = "";
    for(char ch: str){
        
        if(ch>='0' && ch<='9'){
            s+=ch;
        } else if(ch == ' '){
            if(s!=""){
                st.push(stoi(s));
                s = "";
            }
        }
        else{
            int a,b;
            if(!st.empty()){
                a = st.top();
                st.pop();
            } else{
                cout << "Not Possible" << endl;
                return 0;
            }

            if(!st.empty()){
                b = st.top();
                st.pop();
            } else{
                cout << "Not Possible" << endl;
                return 0;
            }

            if(ch=='+'){
                st.push(b+a);
            } else if(ch=='-'){
                st.push(b-a);
            } else if(ch=='/'){
                st.push(b/a);
            } else{
                st.push(b*a);
            }
        }
    }

    cout << st.top() << endl;

    return 0;
}