#include <iostream>
using namespace std;

void bubble_sort_by_absolute_value(int arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            int a = arr[j];
            int b = arr[j+1];

            if(a<0){
                a = -1 * a;
            }

            if(b<0){
                b = -1 * b;
            }

            if(a>b){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void solve(){
    int n; cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }


    bubble_sort_by_absolute_value(arr,n);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    cout << "\n";
   
}


int main(){

    solve();
    return 0;
}