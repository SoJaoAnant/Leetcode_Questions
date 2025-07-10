#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hash[999] = {0};
    int numTrees(int n)
    {
        hash[0] = 1;
        hash[1] = 1;
        hash[2] = 2;
        hash[3] = 5;
        int count = 0;

        if (hash[n] != 0)
        {
            return hash[n];
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                count += numTrees(i - 1) * numTrees(n - i);
            }
        }
        hash[n] = count;
        return count;
    }
};

int main()
{

    return 0;
}