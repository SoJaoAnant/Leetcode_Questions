#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        int ans = 0;
        unordered_map<int, int> freq;

        for (int i : nums)
        {
            freq[i]++;
        }

        for (int i : nums)
        {
            if (freq[i + 1] != 0)
            {
                ans = max(ans, freq[i + 1] + freq[i]);
            }
        }

        return ans;
    }
};

/*
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        int res = 0;

        for (int num : nums)
            freq[num]++;

        for (auto& [key, val] : freq) {
            if (freq.count(key + 1))
                res = max(res, val + freq[key + 1]);
        }

        return res;
    }
};
auto init = atexit([]() { ofstream("display_runtime.txt") << "0";});*/

int main()
{
    Solution obj;
    // vector<int> nums = {1, 1, 1, 1, 1, 1, 1};
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    // vector<int> nums = {1, 2, 2, 1};
    // vector<int> nums = {1, 2, 3, 4};
    cout << obj.findLHS(nums);

    return 0;
}