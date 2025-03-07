#include <iostream>
using namespace std;

int string_length(string s){
    int i=0;
    while(s[i]!= '\0'){
        i++;
    }

    return i;
}

void insertion_sort_strings_by_length(string arr[], int n){
    for(int i=1;i<n;i++){
        string key = arr[i];
        int j = i-1;

        while(j>=0 && string_length(arr[j])>string_length(key)){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

void solve(){
    int n; cin >> n;

    string arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }


    insertion_sort_strings_by_length(arr,n);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    cout << "\n";
   
}


int main(){

    solve();
    return 0;
}