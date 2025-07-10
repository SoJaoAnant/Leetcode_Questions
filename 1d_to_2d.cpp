#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        if (m * n != original.size())
        {
            return ans;
        }
        int o = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                temp.push_back(original[o]);
                o++;
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};

int main()
{

    return 0;
}