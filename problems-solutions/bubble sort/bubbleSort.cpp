#include <iostream>
using namespace std;

int main(){


    int arr[] = {23, 1, 10, 5, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n-1;i++){
        bool swapped = false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped = true;
            }
        }

        if(!swapped){
            break;
        }
    }

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    cout << "\n";

    return 0;
}