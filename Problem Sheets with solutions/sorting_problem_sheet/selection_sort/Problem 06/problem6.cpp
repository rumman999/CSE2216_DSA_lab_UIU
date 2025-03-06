#include <iostream>
using namespace std;

void numSwap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort_even_asc_odd_desc(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int targetIndex = i;

        if(targetIndex%2==0){
            for(int j=i+2;j<n;j+=2){
                if(arr[j]<arr[targetIndex]){
                    targetIndex = j;
                }
            }
        } else{
            for(int j=i+2;j<n;j+=2){
                if(arr[j]>arr[targetIndex]){
                    targetIndex = j;
                }
            }
        }

        numSwap(&arr[i], &arr[targetIndex]);
    }
}


int main(){
    int n; cin >> n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    selection_sort_even_asc_odd_desc(arr,n);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    cout << "\n";

    return 0;
}
