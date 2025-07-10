#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int to_find;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            to_find = target - nums[i];
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] == to_find)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}