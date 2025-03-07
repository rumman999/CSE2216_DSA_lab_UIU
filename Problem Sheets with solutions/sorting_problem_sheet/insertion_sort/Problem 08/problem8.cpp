#include <iostream>
using namespace std;


void insertion_sort_by_frequency(int arr[], int n){
    int freq[10] = {0};

    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }

    for(int i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;

        while(j>=0 && (freq[arr[j]]<freq[key] || (freq[arr[j]]==freq[key] && arr[j]>key))){
            arr[j+1] = arr[j];
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


    insertion_sort_by_frequency(arr,n);


    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    cout << "\n";
   
}


int main(){

    solve();
    return 0;
}