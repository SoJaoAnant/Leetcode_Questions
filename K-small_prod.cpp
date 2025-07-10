#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long count_pos(vector<int> &b, int a, long long mid)
    {
        int low = 0;
        int high = b.size();

        while (low < high)
        {
            int m = (low + high) / 2;
            if (1LL * a * b[m] <= mid)
            {
                low = m + 1;
            }
            else
            {
                high = m;
            }
        }

        return low;
    }

    long long count_neg(vector<int> &b, int a, long long mid)
    {
        int low = 0;
        int high = b.size();

        while (low < high)
        {
            int m = (low + high) / 2;
            if (1LL * a * b[m] <= mid)
            {
                high = m;
            }
            else
            {
                low = m + 1;
            }
        }

        return b.size() - low;
    }

    long long count_prods(vector<int> &a, vector<int> &b, long long mid)
    {
        long long count = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] >= 0)
            {
                count += count_pos(b, a[i], mid);
            }
            else
            {
                count += count_neg(b, a[i], mid);
            }
        }
        return count;
    }

    long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, long long k)
    {
        long long low = -10000000000LL;
        long long high = 10000000000LL;

        while (low < high)
        {
            long long mid = low + (high - low) / 2;
            long long count = count_prods(nums1, nums2, mid);
            if (count < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }
};

int main()
{
    Solution obj;
    vector<int> nums1 = {-2, -1, 0, 1, 2};
    vector<int> nums2 = {-3, -1, 2, 4, 5};
    cout << obj.kthSmallestProduct(nums1, nums2, 3);
    return 0;
}
