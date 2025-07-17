#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumLength(vector<int> &nums, int k)
    {
        vector<vector<int>> hash(k, vector<int>(k, 0));
        int maximum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] %= k;
        }

        for (int j = 0; j < nums.size(); j++)
        {
            for (int i = 0; i < k; i++)
            {
                hash[i][nums[j]] = hash[nums[j]][i] + 1;
                maximum = max(maximum, hash[i][nums[j]]);
            }
        }

        // for (int i = 0; i < k; i++)
        // {
        //     for (int j = 0; j < k; j++)
        //     {
        //         cout << hash[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        return maximum;
    }
};

int main()
{

    vector<int> nums = {1, 2, 3, 4, 5};
    Solution obj;
    cout << obj.maximumLength(nums, 2);

    return 0;
}