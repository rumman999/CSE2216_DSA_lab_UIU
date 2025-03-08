#include <iostream>
using namespace std;

void numSwap(float *a, float *b){
    float temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(float arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                numSwap(&arr[j],&arr[j+1]);
            }
        }
    }
}



int main(){

    float arr[] = {3.14, 2.71, 1.41, 4.67, 2.98};
    int n = sizeof(arr)/sizeof(arr[0]);

    bubble_sort(arr,n);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}