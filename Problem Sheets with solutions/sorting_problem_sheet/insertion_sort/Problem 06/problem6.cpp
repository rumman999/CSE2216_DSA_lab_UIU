#include <iostream>
using namespace std;

void insertion_sort_even_asc_odd_desc(int arr[], int n){
    for(int i=2;i<n;i+=2){
        int key = arr[i];
        int j = i - 2;

        while(j>=0 && arr[j]>key){
            arr[j+2] = arr[j];
            j-=2;
        }

        arr[j+2] = key;
    }

    for(int i=3;i<n;i+=2){
        int key = arr[i];
        int j = i - 2;

        while(j>=0 && arr[j]<key){
            arr[j+2] = arr[j];
            j-=2;
        }

        arr[j+2] = key;
    }
}

int main(){
    int n; cin >> n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    insertion_sort_even_asc_odd_desc(arr,n);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    cout << "\n";

    return 0;
}
