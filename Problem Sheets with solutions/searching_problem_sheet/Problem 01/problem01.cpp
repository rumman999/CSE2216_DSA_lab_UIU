#include <iostream>
using namespace std;


int linearSearch(int arr[], int n, int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key)
            return i;
    }

    return -1;
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

    cout << linearSearch(arr,n,key) << endl;


    return 0;
}