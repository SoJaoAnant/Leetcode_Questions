#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int all_eve(vector<int> &nums)
    {
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
            {
                count += 1;
            }
        }

        return count;
    }
    int all_odd(vector<int> &nums)
    {
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 != 0)
            {
                count += 1;
            }
        }

        return count;
    }
    int alter(vector<int> &nums)
    {
        int count = 0;
        int max_count = 0;
        int want = 0;

        int ieve = 0;
        int iodd = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
            {
                ieve = i;
                break;
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 != 0)
            {
                iodd = i;
                break;
            }
        }

        want = 1;
        // cout << ieve << " " << iodd << endl;
        for (int i = ieve + 1; i < nums.size(); i++)
        {
            if (nums[i] % 2 == want)
            {
                count += 1;
                if (want == 1)
                {
                    want = 0;
                }
                else
                {
                    want = 1;
                }
            }
        }
        max_count = count + 1;
        count = 0;
        want = 0;
        for (int i = iodd + 1; i < nums.size(); i++)
        {
            if (nums[i] % 2 == want)
            {
                count += 1;
                if (want == 1)
                {
                    want = 0;
                }
                else
                {
                    want = 1;
                }
            }
        }

        // cout << max_count << " " << count + 1 << endl;
        return max(max_count, count + 1);
    }

    int maximumLength(vector<int> &nums)
    {
        int c1 = all_eve(nums);
        int c2 = all_odd(nums);
        int c3 = alter(nums);
        cout << c1 << endl
             << c2 << endl
             << c3 << endl;
        return max(max(c1, c2), c3);
    }
};

int main()
{
    Solution obj;
    // vector<int> nums = {3, 7, 6};
    vector<int> nums = {8, 8, 1};
    // 4 3 4
    obj.maximumLength(nums);

    return 0;
}