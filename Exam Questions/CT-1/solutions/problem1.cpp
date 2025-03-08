#include <iostream>
using namespace std;

void numSwap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int digit_sum(int n){
    int sum =0;

    while(n>0){
        sum+=n%10;
        n/=10;
    }

    return sum;
}

void selection_sort_based_on_digit_sum(int arr[], int n){

    int index[100];

    for(int i=0;i<n;i++){
        index[arr[i]] = i;
    }

    for(int i=0;i<n-1;i++){
        int minIndex = i;

        for(int j=i+1;j<n;j++){
            if(digit_sum(arr[j])==digit_sum(arr[minIndex])){
                if(index[arr[j]]<index[arr[minIndex]]){
                    minIndex = j;
                }
            } else if(digit_sum(arr[j])<digit_sum(arr[minIndex])){
                minIndex = j;
            }
        }

        numSwap(&arr[i],&arr[minIndex]);
    }
}

int main(){
    int arr[] = {19, 28, 47, 35, 92};
    int n = sizeof(arr)/sizeof(arr[0]);

    selection_sort_based_on_digit_sum(arr,n);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }


    cout << endl;


    return 0;
}