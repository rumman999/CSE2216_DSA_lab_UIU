#include <iostream>
using namespace std;


int binarySearch(int arr[], int low, int high, int key){
    int a =-1;
    int b = -1; 

    int l = low;
    int h = high;

    while(l<=h){
        int mid = l+(h-l)/2;

        if(arr[mid]==key){
            a=mid;
            h = mid-1;
        }
        else if(arr[mid]>key) h = mid-1;
        else l = mid+1;
    }

    while(low<=high){
        int mid = low +(high-low)/2;

        if(arr[mid]==key){
            b=mid;
            low = mid+1;
        }
        else if(arr[mid]>key) high = mid-1;
        else low = mid+1;
    }

    return b-a+1;
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