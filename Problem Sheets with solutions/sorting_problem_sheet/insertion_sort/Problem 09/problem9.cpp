#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n){
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}


void solve(){
    int n; cin >> n;
    int a[n];

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    int m; cin >> m;
    int b[m];

    for(int i=0;i<m;i++){
        cin >> b[i];
    }

    int merged_array[n+m];
    int i=0;
    for(;i<n;i++){
        merged_array[i] = a[i];
    }

    for(;i<n+m;i++){
        merged_array[i] = b[i-n];
    }

    insertion_sort(merged_array,m+n);

    for(int i=0;i<n+m;i++){
        cout << merged_array[i] << " ";
    }

    cout << "\n";
    
}


int main(){

    solve();
    return 0;
}