#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        int mod = 1e9 + 7;
        vector<int> pow2(nums.size());
        pow2[0] = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            pow2[i] = (pow2[i - 1] * 2) % mod;
        }

        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            int j = upper_bound(nums.begin() + i, nums.end(), target - nums[i]) - nums.begin() - 1;

            if (i <= j)
            {
                ans += pow2[j - i] % mod;
            }
        }
        ans = ans % mod;

        return ans;
    }
};

int main()
{

    vector<int> nums = {2, 3, 3, 4, 6, 7};
    // vector<int> nums = {6, 8};
    int tar = 12;

    Solution obj;
    cout << obj.numSubseq(nums, tar);

    return 0;
}