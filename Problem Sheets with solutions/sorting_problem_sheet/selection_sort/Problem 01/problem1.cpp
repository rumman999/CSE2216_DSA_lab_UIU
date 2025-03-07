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

    int k; cin >> k;

    selection_sort(arr,n);

    cout << arr[k-1] << endl;

    return 0;
}