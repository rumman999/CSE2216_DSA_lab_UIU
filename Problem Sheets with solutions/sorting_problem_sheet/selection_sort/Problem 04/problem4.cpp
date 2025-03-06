#include <iostream>
using namespace std;

void numSwap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void selection_sort_by_absolute_value(int arr[], int n){
    for(int i=0;i<n;i++){
        int minIndex = i;

        for(int j=i+1;j<n;j++){
            int a = arr[j];
            int b = arr[minIndex];

            if(a<0) a = -a;
            if(b<0) b = -b;
            if(a<b){
                minIndex = j;
            }
        }

        numSwap(&arr[minIndex], &arr[i]);
    }
}

void solve(){
    int n; cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }


    selection_sort_by_absolute_value(arr,n);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    cout << "\n";
   
}


int main(){

    solve();
    return 0;
}