#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> temp = nums1;
        nums1.clear();
        if (n == 0)
        {
            int i = 0;
            while (m--)
            {
                nums1.push_back(temp[i]);
                i++;
            }
        }
        else if (m == 0)
        {
            nums1 = nums2;
        }
        else
        {
            int i = 0;
            while (m--)
            {
                nums1.push_back(temp[i]);
                i++;
            }
            i = 0;
            while (n--)
            {
                nums1.push_back(nums2[i]);
                i++;
            }
            sort(nums1.begin(), nums1.end());
        }
    }
};

int main()
{

    return 0;
}