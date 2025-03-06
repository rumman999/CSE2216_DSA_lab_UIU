#include <iostream>
using namespace std;

void numSwap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort_by_frequency(int arr[], int n){
    int freq[10] = {0};

    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }

    for(int i=0;i<n-1;i++){
        int targetIndex = i;

        for(int j=i+1;j<n;j++){
            if(freq[arr[j]]>freq[arr[targetIndex]]){
                targetIndex = j;
            } else if(freq[arr[j]]==freq[arr[targetIndex]]){
                if(arr[j]<arr[targetIndex]){
                    targetIndex = j;
                }
            }
            
        }

        numSwap(&arr[i], &arr[targetIndex]);
    }

}



void solve(){
    int n; cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }


    selection_sort_by_frequency(arr,n);


    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    cout << "\n";
   
}


int main(){

    solve();
    return 0;
}