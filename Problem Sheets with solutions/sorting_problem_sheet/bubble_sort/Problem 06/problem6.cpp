#include <iostream>
using namespace std;

void bubble_sort_even_asc_odd_desc(int arr[], int n){
    for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j+=2){
                if(arr[j]>arr[j+2]){
                    int temp = arr[j];
                    arr[j] = arr[j+2];
                    arr[j+2] = temp;
                }
            }

            for(int j=1;j<n-i-1;j+=2){
                if(arr[j]<arr[j+2]){
                    int temp = arr[j];
                    arr[j] = arr[j+2];
                    arr[j+2] = temp;
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

    bubble_sort_even_asc_odd_desc(arr,n);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    cout << "\n";

    return 0;
}
