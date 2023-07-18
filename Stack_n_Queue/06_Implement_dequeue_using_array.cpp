// https://leetcode.com/problems/design-circular-deque/

#include <bits/stdc++.h>
using namespace std;

class MyCircularDeque
{
private:
    int front;
    int rear;
    int size;
    int cnt;
    int *arr;

public:
    MyCircularDeque(int k)
    {
        this->front = 0;
        this->rear = -1;
        this->size = k;
        this->cnt = 0;
        this->arr = new int[k];
    }

    bool insertFront(int value)
    {

        if (cnt != size)
        {
            if (cnt == 0)
            {
                arr[front] = value;
                rear = front;
                cnt++;
                return true;
            }

            front--;
            if (front < 0)
                front = size - 1;
            arr[front] = value;
            cnt++;
            return true;
        }
        else
            return false;
    }

    bool insertLast(int value)
    {

        if (cnt != size)
        {
            if (cnt == 0)
            {
                arr[front] = value;
                rear = front;
                cnt++;
                return true;
            }
            rear++;
            rear = rear % size;
            arr[rear] = value;
            cnt++;
            return true;
        }
        else
            return false;
    }

    bool deleteFront()
    {
        if (cnt != 0)
        {
            if (front == rear)
            {
                front = 0;
                rear = -1;
                cnt--;
                return true;
            }
            else
            {
                front++;
                front = front % size;
                cnt--;
                return true;
            }
        }
        else
            return false;
    }

    bool deleteLast()
    {

        if (cnt != 0)
        {
            if (front == rear)
            {
                front = 0;
                rear = -1;
                cnt--;
                return true;
            }
            else
            {
                rear--;
                if (rear < 0)
                    rear = size - 1;
                cnt--;
                return true;
            }
        }
        else
            return false;
    }

    int getFront()
    {

        if (cnt != 0)
            return arr[front];
        else
            return -1;
    }

    int getRear()
    {
        if (rear != -1)
            return arr[rear];
        else
            return -1;
    }

    bool isEmpty()
    {
        if (cnt == 0)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if (cnt == size)
            return true;
        else
            return false;
    }
};
