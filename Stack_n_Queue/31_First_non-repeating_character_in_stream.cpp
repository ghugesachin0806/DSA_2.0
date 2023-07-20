// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        // Code here
        string str;
        unordered_map<char, int> mt;
        queue<char> qt;

        for (int i = 0; i < A.size(); i++)
        {
            mt[A[i]]++;
            if (mt[A[i]] == 1)
                qt.push(A[i]);

            while (!qt.empty() && mt[qt.front()] != 1)
            {
                qt.pop();
            }

            if (!qt.empty())
                str.push_back(qt.front());
            else
                str.push_back('#');
        }

        return str;
    }
};