#include <iostream>
#include <climits>
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


void solve(){
    int n; cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }


    insertion_sort(arr,n);

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