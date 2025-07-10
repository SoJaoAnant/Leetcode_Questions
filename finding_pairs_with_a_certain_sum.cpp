#include <bits/stdc++.h>
using namespace std;

class FindSumPairs
{
private:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> nums2_freq;

public:
    FindSumPairs(vector<int> &nums1, vector<int> &nums2)
    {
        this->nums1 = nums1;
        this->nums2 = nums2;
        freq_initialize();
    }

    void add(int index, int val)
    {
        nums2_freq[nums2[index]] -= 1;
        if (nums2_freq[nums2[index]] == 0)
        {
            nums2_freq.erase(nums2[index]);
        }

        nums2[index] += val;
        nums2_freq[nums2[index]] += 1;
    }

    int count(int tot)
    {
        for (auto it = nums2_freq.begin(); it != nums2_freq.end(); it++)
        {
            cout << it->first << ": " << it->second << endl;
        }
        cout << endl;
        int count = 0;
        for (int n1 : nums1)
        {
            int to_find = tot - n1;
            count += count_num(to_find);
        }

        return count;
    }

    void freq_initialize()
    {
        for (int i = 0; i < nums2.size(); i++)
        {
            nums2_freq[nums2[i]] += 1;
        }
    }

    int count_num(int find) { return nums2_freq[find]; }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */

int main()
{

    return 0;
}