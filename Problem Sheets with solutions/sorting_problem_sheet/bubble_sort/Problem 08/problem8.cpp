#include <iostream>
using namespace std;

void bubble_sort_by_frequency(int arr[], int n){
    int freq[10] = {0};

    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(freq[arr[j]]<freq[arr[j+1]]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            } else if ((freq[arr[j]] == freq[arr[j+1]]) && (arr[j]>arr[j+1])){
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


    bubble_sort_by_frequency(arr,n);


    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    cout << "\n";
   
}


int main(){

    solve();
    return 0;
}