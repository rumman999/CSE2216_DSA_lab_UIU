#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n){
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

int longest_subsequence(int arr[],int n){
    int longest_subsequence = 1;
    int current_subsequence = 1;

    for(int i=0;i<n;i++){
        if(arr[i] == arr[i-1]+1){
            current_subsequence++;
        } else {
            current_subsequence = 1;
        }

        if(current_subsequence>longest_subsequence){
            longest_subsequence = current_subsequence;
        }
    }


    return longest_subsequence;
}

void solve(){
    int n; cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }


    insertion_sort(arr,n);


    cout << longest_subsequence(arr,n) << endl;
   
}


int main(){

    solve();
    return 0;
}