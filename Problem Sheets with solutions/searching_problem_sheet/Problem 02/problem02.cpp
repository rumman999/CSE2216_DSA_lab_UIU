#include <iostream>
using namespace std;


void linearSearch(int arr[], int match[], int n, int key){
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            match[cnt++] = i;
        }
    }
    match[cnt] = -1;
}


int main(){
    int n; 
    cout << "How many elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter all the elements seperated by a space: ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int key;
    cout << "Enter the target value: ";
    cin >> key;

    int match[n] = {-1};

    linearSearch(arr, match, n, key);


    for(int i=0;i<n;i++){
        if(match[i]==-1){
            break;
        }
        cout << match[i] << " ";
    }

    cout << endl;

    return 0;
}