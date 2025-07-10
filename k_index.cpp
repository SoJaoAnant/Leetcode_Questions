#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
    {
        vector<int> store;
        set<int> temp;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == key)
            {
                store.push_back(i);
            }
        }

        for (int i = 0; i < store.size(); i++)
        {
            for (int j = store[i] - k; j <= store[i] + k; j++)
            {
                if(j >= 0 && j < nums.size())
                {
                    temp.insert(j);
                }
            }
        }

        store.clear();

        for (int i : temp)
        {
            store.push_back(i);
        }

        return store;
    }
};

int main()
{

    vector<int> nums = {3, 4, 9, 1, 3, 9, 5};
    Solution obj;
    obj.findKDistantIndices(nums, 9, 1);
    return 0;
}