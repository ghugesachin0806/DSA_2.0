// https://leetcode.com/problems/gas-station/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int deficient = 0;
        int balance = 0;
        int temp = 0;

        for (int i = 0; i < gas.size(); i++)
        {
            balance = balance + gas[i] - cost[i];

            if (balance < 0)
            {
                deficient = deficient + balance;
                balance = 0;
                temp = i + 1;
            }
        }

        if (deficient != 0)
        {
            deficient = -deficient;
        }
        if (deficient <= balance)
            return temp;
        else
            return -1;
    }
};