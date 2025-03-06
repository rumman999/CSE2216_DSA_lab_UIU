#include <iostream>
using namespace std;

void numSwap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void selection_sort(int arr[], int n){
    for(int i=0;i<n;i++){
        int minIndex = i;

        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }

        numSwap(&arr[minIndex], &arr[i]);
    }
}


void solve(){
    int n; cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    selection_sort(arr,n);

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