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

int main(){

    int n; cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    bubble_sort(arr,n);

    if(n%2==0){ 
        cout << (arr[n/2]+arr[(n/2)-1])/2 << endl;
    } else{
        cout << arr[n/2] << endl;
    }

    return 0;
}