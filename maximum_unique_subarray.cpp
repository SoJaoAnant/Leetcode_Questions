#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        unordered_set<int> hashu;

        int i = 0;
        int j = 0;
        int winsum = 0;
        int ans = 0;

        while (j < nums.size())
        {
            if (hashu.find(nums[j]) == hashu.end())
            {
                winsum += nums[j];
                hashu.insert(nums[j]);
                ans = max(ans, winsum);
                j++;
            }
            else
            {
                hashu.erase(nums[i]);
                winsum -= nums[i];
                i++;
            }
        }
        cout << ans << endl;
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {187, 470, 25, 436, 538, 809, 441, 167, 477, 110, 275, 133, 666, 345, 411, 459, 490, 266, 987, 965, 429, 166, 809, 340, 467, 318, 125, 165, 809, 610, 31, 585, 970, 306, 42, 189, 169, 743, 78, 810, 70, 382, 367, 490, 787, 670, 476, 278, 775, 673, 299, 19, 893, 817, 971, 458, 409, 886, 434};
    // vector<int> nums = {4, 2, 1, 2, 3, 5};
    // cout << nums.size() << endl;
    obj.maximumUniqueSubarray(nums);
    return 0;
}
