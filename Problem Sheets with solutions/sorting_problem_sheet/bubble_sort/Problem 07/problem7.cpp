#include <iostream>
using namespace std;

void bubble_sort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int longest_subsequence(int arr[],int n){
    int longest_sequence = 1;
    int current_sequence = 1;

    for(int i=0;i<n-1;i++){
        if(arr[i]==arr[i+1]-1){
            current_sequence++;
        } else{
            current_sequence = 1;
        }

        if(current_sequence>longest_sequence){
            longest_sequence = current_sequence;
        }
    }

    return longest_sequence;
}

void solve(){
    int n; cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }


    bubble_sort(arr,n);


    cout << longest_subsequence(arr,n) << endl;
   
}


int main(){

    solve();
    return 0;
}