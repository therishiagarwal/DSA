// write a function to print square of first n natural numbers.

#include <iostream>
using namespace std;

int square(int n){
    return n*n;
}

void nNatural(int n){
    for(int i=0;i<n;i++){
        cout<<square(i)<<endl;
    }
}

int main(){
    int n;
    cin >>n;
    nNatural(n);
}