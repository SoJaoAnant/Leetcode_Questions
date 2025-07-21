#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumDifference(vector<int> &nums)
    {
        priority_queue<int> max_heap;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int n = nums.size() / 3;
        vector<long long> suffix;
        vector<long long> prefix;
        // fill the suffix array
        long long sum = 0;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            min_heap.push(nums[i]);
            sum += nums[i];
            if (min_heap.size() > n)
            {
                sum -= min_heap.top();
                min_heap.pop();
            }
            suffix.push_back(sum);
            // cout << sum << endl;
        }

        // fill the prefix array
        sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            max_heap.push(nums[i]);
            sum += nums[i];
            if (max_heap.size() > n)
            {
                sum -= max_heap.top();
                max_heap.pop();
            }
            prefix.push_back(sum);
            // cout << sum << endl;
        }

        // find the minimom from prefix - suffix
        sum = LONG_LONG_MAX;
        int i = n - 1;
        int j = (2 * n) - 1;

        while (i != 2 * n)
        {
            sum = min(sum, prefix[i] - suffix[j]);
            i += 1;
            j -= 1;
        }
        cout << sum << endl;
        return sum;
    }
};

int main()
{
    vector<int> nums = {3,1,2};
    // vector<int> nums = {1, 3, 5, 2, 7, 6, 1, 10, 7};
    // vector<int> nums = {7, 9, 5, 8, 1, 3};
    Solution obj;
    obj.minimumDifference(nums);

    return 0;
}