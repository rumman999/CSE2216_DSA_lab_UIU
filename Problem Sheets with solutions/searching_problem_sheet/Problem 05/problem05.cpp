#include <iostream>
using namespace std;


int binarySearch(int arr[], int low, int high, int key){
    
    while(low<=high){
        int mid = low +(high-low)/2;

        if(arr[mid]==key) return mid;
        else if(arr[mid]>key) low = mid+1;
        else high = mid-1;
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

    cout << binarySearch(arr, 0, n-1,key) << endl;


    return 0;
}