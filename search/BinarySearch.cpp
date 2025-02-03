#include<iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x) {
    while(l<=r){
    int m=l+(r-l)/2; 
        // (l=start and r=end)
        if(arr[m]==x){
            return m;
        }
        else if(arr[m]<x){
            l=m+1;
        }
        else{
            r=m-1;
        }
    }
        return -1;
}

int main(){
    int arr[]={2,4,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    int y=binarySearch(arr,0,n-1,6);
    (y==-1)
        ? cout<<"No. not found"<<endl
        : cout<<"No. found";
    return 0;
}
