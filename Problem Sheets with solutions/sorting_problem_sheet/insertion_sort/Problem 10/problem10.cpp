#include <iostream>
using namespace std;

void num_swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort_by_duration(int arr[][2], int n){
    for(int i=1;i<n;i++){
        int keyStart = arr[i][0] ;
        int keyEnd = arr[i][1] ;

        int b = keyEnd - keyStart;

        int j = i-1;

        while(j>=0 && arr[j][1]-arr[j][0]>b){
            arr[j+1][0] = arr[j][0];
            arr[j+1][1] = arr[j][1];
            j--;
        }

        arr[j+1][0] = keyStart;
        arr[j+1][1] = keyEnd;
    }
}

int main(){
    int n; cin >> n;
    int arr[n][2];

    for(int i=0;i<n;i++){
        cin >> arr[i][0] >> arr[i][1]; 
    }

    insertion_sort_by_duration(arr,n);

    for(int i=0;i<n;i++){
        cout << arr[i][0] << " " << arr[i][1] << " ";
    }

    cout << "\n";

    return 0;
}
