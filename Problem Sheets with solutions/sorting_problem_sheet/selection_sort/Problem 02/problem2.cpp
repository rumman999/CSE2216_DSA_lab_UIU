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

int main(){

    int n; cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    selection_sort(arr,n);

    if(n%2==0){ 
        cout << (arr[n/2]+arr[(n/2)-1])/2 << endl;
    } else{
        cout << arr[n/2] << endl;
    }

    return 0;
}