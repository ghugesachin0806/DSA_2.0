// https://leetcode.com/problems/lru-cache/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    int value;
    Node *next;
    Node *prev;

    Node(int key, int value)
    {
        this->next = NULL;
        this->prev = NULL;
        this->key = key;
        this->value = value;
    }
};

class LRUCache
{
private:
    Node *head;
    Node *tail;
    int capacity;
    int size;
    unordered_map<int, pair<int, Node *>> mt;

public:
    LRUCache(int capacity)
    {
        this->head = new Node(-1, -1);
        this->tail = new Node(-1, -1);
        this->capacity = capacity;
        this->size = 0;

        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node *curr)
    {
        Node *temp = head->next;

        temp->prev = curr;
        curr->next = temp;

        head->next = curr;
        curr->prev = head;
    }

    void deleteNode(Node *curr)
    {
        Node *nxt = curr->next;
        Node *prv = curr->prev;

        curr->next = NULL;
        curr->prev = NULL;

        prv->next = nxt;
        nxt->prev = prv;
    }

    int get(int key)
    {
        if (mt.find(key) != mt.end())
        {
            Node *curr = mt[key].second;
            int ans = curr->value;

            deleteNode(curr);
            addNode(curr);

            return ans;
        }
        else
            return -1;
    }

    void put(int key, int value)
    {
        if (mt.find(key) != mt.end())
        {
            Node *curr = mt[key].second;
            curr->value = value;

            deleteNode(curr);
            addNode(curr);
        }
        else
        {
            if (size == capacity)
            {
                Node *temp = tail->prev;
                int tempkey = temp->key;

                deleteNode(temp);
                mt.erase(tempkey);
                delete temp;

                Node *curr = new Node(key, value);
                mt[key] = make_pair(value, curr);

                addNode(curr);
            }
            else
            {
                Node *curr = new Node(key, value);
                mt[key] = make_pair(value, curr);

                addNode(curr);
                size++;
            }
        }
    }
};