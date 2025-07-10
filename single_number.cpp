#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        map<int, int> m;
        int ans;
        for (auto &it : nums)
        {
            if (m.find(it) == m.end())
            {
                m.insert(make_pair(it, 1));
            }
            else
            {
                m[it]++;
            }
        }
        for (auto &it : m)
        {
            cout << it.first << " " << it.second << endl;
            if (it.second == 1)
            {
                ans = it.first;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}