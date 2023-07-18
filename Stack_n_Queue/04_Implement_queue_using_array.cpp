// https://www.codingninjas.com/studio/problems/circular-queue_1170058

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
class CircularQueue
{
private:
    int front;
    int rear;
    int cnt;
    int size;
    int *arr;

public:
    // Initialize your data structure.
    CircularQueue(int n)
    {
        // Write your code here.
        this->front = 0;
        this->rear = -1;
        this->cnt = 0;
        this->size = n;
        this->arr = new int[n];
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value)
    {
        // Write your code here.
        if (cnt != size)
        {
            rear++;
            rear = rear % size;
            arr[rear] = value;
            cnt++;
            return true;
        }
        return false;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue()
    {
        // Write your code here.
        if (cnt != 0)
        {
            if (front == rear)
            {
                int temp = arr[front];
                front = 0;
                rear = -1;
                cnt--;
                return temp;
            }
            else
            {
                int temp = arr[front];
                front++;
                front = front % size;
                cnt--;
                return temp;
            }
        }
        else
            return -1;
    }
};