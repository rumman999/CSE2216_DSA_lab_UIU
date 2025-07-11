#include <bits/stdc++.h>
using namespace std;

int fib(int x){
    if(x<=1){
        return x;
    }

    return fib(x-1)+fib(x-2);
}

int fibPos(int x){
    if(x==0) return 0;
    if(x==1) return 1;

    int i=0,j=1,cnt=0;

    while(i<x){
        int temp = i+j;
        i=j;
        j = temp;
        cnt++;
    }


    return cnt;
}


// aPPLE
// APPLE

void solve() {
    int n,m; cin >> n >> m;
    vector<int> pass(n);
    vector<int> err(m);

    int minimumPass = INT_MAX;
    int maximumPass = INT_MIN;
    int minimumErr = INT_MAX;
    for(int i=0;i<n;i++){
        cin >> pass[i];
        if(pass[i]>maximumPass) maximumPass = pass[i];
        if(pass[i]<minimumPass) minimumPass = pass[i];
    }

    for(int i=0;i<m;i++){
        cin >> err[i];
        if(err[i]<minimumErr) minimumErr = err[i];
    }

    int TL = max(2*minimumPass, maximumPass);
    auto it = find(err.begin(), err.end(), TL);

    if(it == err.end() && minimumErr>TL){
        cout << TL << endl;
    } else cout << -1 << endl;

}

int main() {
    //int t;
    //cin >> t;
    //while (t--) {
            solve();


    //}
    return 0;
}
