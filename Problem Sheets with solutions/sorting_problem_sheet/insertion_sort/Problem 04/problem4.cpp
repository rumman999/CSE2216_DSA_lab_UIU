#include <iostream>
using namespace std;

void insertion_sort_by_absolute_value(int arr[], int n){
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;

        int a = key;
        int b = arr[j];

        if(a<0) a = -1 * a;
        if(b<0) b = -1 *b;

        while(j>=0 && b>a){
            arr[j+1] = arr[j];
            j--; 
            if(j<0){
                break;
            } else{
                b = arr[j];
                if(b<0) b = -1 *b;
            }
        }

        arr[j+1] = key;

    }
}

void solve(){
    int n; cin >> n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }


    insertion_sort_by_absolute_value(arr,n);

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    cout << "\n";
   
}


int main(){

    solve();
    return 0;
}