#include <iostream>
using namespace std;

void rowSwap(int arr[][2], int i, int minIndex){
    int temp =0;
    for(int z=0;z<2;z++){
        temp = arr[i][z];
        arr[i][z] = arr[minIndex][z];
        arr[minIndex][z] = temp;
    }    
}

void selection_sort(int arr[][2], int n){
    for(int i=0;i<n-1;i++){
        int minIndex = i;

        for(int j=i+1;j<n;j++){
            if(arr[j][1]-arr[j][0]<arr[minIndex][1]-arr[minIndex][0]){
                minIndex = j;
            }
        }

        rowSwap(arr, i, minIndex);
    }
}


int main(){
    int n; 
    cin >> n;

    int arr[n][2];

    for(int i=0;i<n;i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    selection_sort(arr,n);

    for(int i=0;i<n;i++){
        cout << arr[i][0] << " " << arr[i][1] << " ";
    }

    cout << "\n";


    return 0;
}
