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

        arr[j+1]=key;
    }
}

int main(){

    int n; cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    insertion_sort(arr,n);

    if(n%2==0){ 
        cout << (arr[n/2]+arr[(n/2)-1])/2 << endl;
    } else{
        cout << arr[n/2] << endl;
    }

    return 0;
}