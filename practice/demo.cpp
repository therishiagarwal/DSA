#include <iostream>
using namespace std;

class SimpleQueue
{
    int queue[100];
    int n = 100, front = -1, rear = -1;

public:
    bool isEmpty()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue Underflow" << endl;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if (rear == n - 1)
        {
            cout << "Queue is Full" << endl;
            return true;
        }
        else
        {
            return false;
        }
    }

    int enqueue(int data)
    {
        if (isFull())
            return 0;
        else
        {
            rear++;
            queue[rear] = data;
            if (front == -1)
                front = 0;
            return 1;
        }
    }

    int dequeue()
    {
        if (isEmpty())
            return 0;
        else
        {
            cout << "Element deleted is: " << queue[front] << endl;
            front++;
            return 1;
        }
    }

    int print(){
        if (isEmpty())
            return 0;
        else
        {
            for (int i = front; i <= rear; i++){
                cout<< queue[i]<<" ";
            }
            cout<<endl;
        }
        return 0;
    }
};

int main()
{
    SimpleQueue myQueue;

    myQueue.enqueue(5);
    myQueue.enqueue(10);
    myQueue.enqueue(15);

    myQueue.print();

    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();

    myQueue.print();
   
    return 0;
}
