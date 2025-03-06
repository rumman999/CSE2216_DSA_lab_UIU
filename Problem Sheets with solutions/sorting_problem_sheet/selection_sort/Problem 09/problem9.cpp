#include <iostream>
using namespace std;

void numSwap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }

        numSwap(&arr[i], &arr[minIndex]);
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

    selection_sort(merged_array,m+n);

    for(int i=0;i<n+m;i++){
        cout << merged_array[i] << " ";
    }

    cout << "\n";
    
}


int main(){

    solve();
    return 0;
}