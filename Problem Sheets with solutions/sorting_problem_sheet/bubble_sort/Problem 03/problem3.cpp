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


void solve(){
    int n; cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }


    bubble_sort(arr,n);

    int minDiff = INT_MAX;
    for(int i=0;i<n-1;i++){
        if(arr[i+1]-arr[i]<minDiff){
            minDiff = arr[i+1]-arr[i];
        }
    }

    cout << minDiff << endl;
}


int main(){

    solve();
    return 0;
}