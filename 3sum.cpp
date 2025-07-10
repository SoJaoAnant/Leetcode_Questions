#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool exists(int key, const vector<int> &nums, int ino, int jno)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == key && i != ino && i != jno)
                return true;
        }
        return false;
    }

    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> triplet;
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;

        while (i < j)
        {
            if (exists(-nums[j] - nums[i], nums, i, j))
            {
                triplet.push_back(nums[j]);
                triplet.push_back(nums[i]);
                triplet.push_back(-nums[j] - nums[i]);
                cout << nums[i] << " " << nums[j] << " " << -nums[j] - nums[i] << endl;
                ans.push_back(triplet);
                triplet.clear();
            }
            if (abs(nums[i]) < abs(nums[j]))
                j--;
            else
                i++;
        }
        return ans;
    }
};

int main()
{

    return 0;
}