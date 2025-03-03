#include <iostream>
using namespace std;

int string_length(string s){
    int count=0;

    for(int i=0;s[i]!='\0';i++){
        count++;
    }

    return count;
}

void bubble_sort_strings_by_length(string arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(string_length(arr[j])>string_length(arr[j+1])){
                string temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void solve(){
    int n; cin >> n;

    string arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }


    bubble_sort_strings_by_length(arr,n);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    cout << "\n";
   
}


int main(){

    solve();
    return 0;
}