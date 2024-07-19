#include <iostream>
#include<queue>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "Nothing to dalete" << endl;
            return;
        }
        // step 1: put the last element into firdt index 
        arr[1] = arr[size];

        // step 2: remove last element 
        size--;

        // Step 3: take the root node to its correct position

        int i = 1;
        while(i<size){
            int leftChild=2*i;
            int rightChild=2*i+1;

            if(leftChild <size && arr[i]<arr[leftChild]){
                swap( arr[i],arr[leftChild]);
                i=leftChild;
            }
            else if(rightChild<size&& arr[i]<arr[rightChild]){
                swap(arr[i],arr[rightChild]);
                i=rightChild;
            }
            else{
                return;
            }
        }
    }
};

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left]) { 
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[],int n){
    int size=n;

    while(size>1){
        swap(arr[size],arr[1]);
        size--;

        heapify(arr,size,1); 
    }
}
int main()
{

    heap h;
    //  

    // heapify 
    int arr[6]={-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    cout<< "Printing the array after heapify"<<endl;
    for(int i=1;i<=n;i++){
        cout<< arr[i]<<" ";
    }
    cout <<endl;

    heapSort(arr,n);
    cout<< "Printing the array after heap Short"<<endl;
    for(int i=1;i<=n;i++){
        cout<< arr[i]<<" ";
    }
    cout<<endl;

    cout<<"Using priority Queue here"<<endl;
    // max heap by-default 
    priority_queue<int>pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout<<"Elements at Top " << pq.top()<<endl;
    pq.pop();
    cout<<"Elements at Top " << pq.top()<<endl;
    cout<<"Size is "<<pq.size()<<endl;
    if(pq.empty())
        cout<<"pq is empty"<<endl;
    else
        cout<<"pq is not empty"<<endl;


    // min heap 
    priority_queue< int, vector<int>,greater<int>> minheap;
    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);

    cout<<"For Min heap Using Priority Queue"<<endl;
    cout<<"Elements at Top " << minheap.top()<<endl;
    minheap.pop();
    cout<<"Elements at Top " << minheap.top()<<endl;
    cout<<"Size is "<<minheap.size()<<endl;
    if(minheap.empty())
        cout<<"minheap is empty"<<endl;
    else
        cout<<"minheap is not empty"<<endl;

    return 0;
}