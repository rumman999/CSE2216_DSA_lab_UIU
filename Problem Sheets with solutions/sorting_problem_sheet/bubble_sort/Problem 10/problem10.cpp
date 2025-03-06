#include <iostream>
using namespace std;

void num_swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort_by_duration(int arr[][2], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j][1]-arr[j][0]>arr[j+1][1]-arr[j+1][0]){
                num_swap(&arr[j][1], &arr[j+1][1]);
                num_swap(&arr[j][0], &arr[j+1][0]);
            }
        }
    }
}

int main(){
    int n; cin >> n;
    int arr[n][2];

    for(int i=0;i<n;i++){
         cin >> arr[i][0] >> arr[i][1];    
    }

    bubble_sort_by_duration(arr,n);

    for(int i=0;i<n;i++){
        cout << arr[i][0] << " " << arr[i][1] << " ";
    }

    cout << "\n";

    return 0;
}
