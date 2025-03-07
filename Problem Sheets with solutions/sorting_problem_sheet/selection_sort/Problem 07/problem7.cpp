#include <iostream>
using namespace std;

void numSwap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int minIndex = i;

        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }

        numSwap(&arr[i], &arr[minIndex]);
    }
}

int longest_subsequence(int arr[],int n){
    int longest_sequence = 1;
    int current_sequence = 1;

    for(int i=0;i<n-1;i++){
        if(arr[i]+1==arr[i+1]){
            current_sequence++;
        } else{
            current_sequence = 1;
        }

        if(current_sequence>longest_sequence){
            longest_sequence = current_sequence;
        }
    }

    return longest_sequence;
}

void solve(){
    int n; cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    selection_sort(arr,n);

    cout << longest_subsequence(arr,n) << endl;

   
}


int main(){

    solve();
    return 0;
}