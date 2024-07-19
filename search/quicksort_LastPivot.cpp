#include <iostream>
#include<vector>
using namespace std;

int partition(vector<int>&arr,int low,int high){
    int pivot=arr[low];
    int i=low+1;
    for(int j=low+1;j<=high;j++){
        if(arr[j]<pivot){
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[low],arr[i-1]);
    return i-1;

}

void quicksort(vector<int>& arr, int low, int high){
    if(low<high){
       int pivotIndex= partition(arr,low,high);
        quicksort(arr,low,pivotIndex-1);
        quicksort(arr,pivotIndex+1,high);
    }
}
int main(){
    vector<int>arr={3,1,4,5,2};
    int n=arr.size();
    quicksort(arr,0,n-1);
    for(int i:arr){
        cout<<i<<" ";
    }

}