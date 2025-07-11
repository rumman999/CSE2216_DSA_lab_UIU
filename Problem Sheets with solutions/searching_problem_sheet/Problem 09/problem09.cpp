#include <iostream>
using namespace std;


int binarySearch(int arr[], int low, int high, int n, int key){
    
    while(low<=high){
        int mid = low +(high-low)/2;

        if(arr[mid]==key) return mid;
        else if(arr[mid]<key) low = mid+1;
        else high = mid-1;
    }


    // the code given under this comment might not work for some cases.
    if(abs(arr[low]-key)<abs(arr[high]-key)) return low;
    else return high;
    
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

    cout << arr[binarySearch(arr, 0, n-1, n, key)] << endl;


    return 0;
}