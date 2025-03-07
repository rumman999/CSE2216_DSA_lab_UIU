#include <iostream>
using namespace std;

int stringLen(string s){
    int count =0;

    for(int i=0;s[i]!='\0';i++){
        count++;
    }

    return count;
}

void stringSwap(string *a, string *b){
    string temp = *a;
    *a = *b;
    *b = temp;
}


void selection_sort_strings_by_length(string arr[],int n){
    for(int i=0;i<n-1;i++){
        int minIndex = i;

        for(int j=i+1;j<n;j++){
            if(stringLen(arr[j])<stringLen(arr[minIndex])){
                minIndex = j;
            }
        }

        stringSwap(&arr[minIndex], &arr[i]);
    }
}


void solve(){
    int n; cin >> n;

    string arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }


    selection_sort_strings_by_length(arr,n);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    cout << "\n";
   
}


int main(){

    solve();
    return 0;
}