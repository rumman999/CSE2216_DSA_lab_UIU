#include <iostream>
using namespace std;


int binarySearch(int arr[], int low, int high){
    
    while(low<=high){
        int mid = low +(high-low)/2;

        // might not always work
        if(arr[mid]>=arr[mid-1] && arr[mid]>=arr[mid+1]) return mid;
        else if(arr[mid]<arr[mid+1]) low = mid+1;
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


    cout << binarySearch(arr, 0, n-1) << endl;


    return 0;
}