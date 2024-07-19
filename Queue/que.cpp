#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    Queue(int s) // Constructor with size parameter
    {
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void enqueue(int data)
    {
        if (rear == size - 1)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            if (front == -1)
            {
                front++;
            }
            rear++;
            arr[rear] = data;
        }
    }

    int dequeue()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
        {
            int value = arr[front];
            front++;
            //if (front > rear)
            // {
            //     // Reset front and rear when the last element is dequeued
            //     front = rear = -1;
            // }
            return value;
        }
    }

    void printQueue()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue: ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void getTopRear()
    {
        cout << "The Value of Top is: " << front << endl;
        cout << "The Value of Rear is: " << rear << endl;
    }
};

int main()
{
    Queue queue(5); // Specify the size of the queue

    queue.enqueue(6);
    cout << "p1 ";
    queue.printQueue();
    queue.enqueue(12);
    cout << "p2 ";
    queue.printQueue();
    queue.enqueue(13);
    cout << "p3 ";
    queue.printQueue();
    queue.dequeue();
    cout << "p4 ";
    queue.printQueue();
    queue.dequeue();
    cout << "p5 ";
    queue.printQueue();
    queue.enqueue(19);
    queue.enqueue(21);
    cout << "p6 ";
    queue.printQueue();
    queue.enqueue(24);
    queue.enqueue(27);

    cout << "Final Queue: ";
    queue.printQueue();
    queue.getTopRear();

    return 0;
}
