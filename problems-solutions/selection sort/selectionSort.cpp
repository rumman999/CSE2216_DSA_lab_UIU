#include <iostream>
using namespace std;

int main(){


    int arr[] = {23, 1, 10, 5, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++){
        int minIndex = i;

        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    cout << "\n";

    return 0;
}