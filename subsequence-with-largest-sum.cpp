#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> vals;  // auxiliary array
        for (int i = 0; i < n; ++i) {
            vals.emplace_back(i, nums[i]);
        }
        sort(vals.begin(), vals.end(),
             [&](auto x1, auto x2) { return x1.second > x2.second; });
        sort(vals.begin(), vals.begin() + k);
        vector<int> res; 
        for (int i = 0; i < k; ++i) {
            res.push_back(vals[i].second);
        }
        return res;
    }
};


int main()
{
    Solution obj;
    vector<int> nums = {-1, -2, 3, 4};
    int k = 3;
    nums = obj.maxSubsequence(nums, k);
    for(int a: nums)
    {
    cout << a << " ";
    }
    return 0;
}

/*
-1 -2 3 4
 0  1 2 3

4 -1 -2 3
3  0  1 2


*/