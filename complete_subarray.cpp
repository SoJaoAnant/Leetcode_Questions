#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int count_dist(vector<int> nums)
    {
        set<int> num_set;
        for (int i = 0; i < nums.size(); i++)
        {
            num_set.insert(nums[i]);
        }
        return num_set.size();
    }
    void iter_sub_arr(vector<int> nums, int i, int j)
    {
        // printf("Iterating from %d to %d\n", i, j);
        if (i > j || j == nums.size())
        {
            return;
        }
        for (int iter = i; iter <= j; iter++)
        {
            printf("%d ", nums[iter]);
        }
        printf("\n");
        iter_sub_arr(nums, i + 1, j);
        iter_sub_arr(nums, i, j + 1);
    }
    int countCompleteSubarrays(vector<int> &nums)
    {
        int dist = count_dist(nums);
        int ans = 0;
        int iter = 0;
        vector<int> temp;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i; j < nums.size(); ++j)
            {
                cout << nums[j];
                temp.push_back(nums[j]);
                while(iter != 10)
                {
                    for (int i = 0; i < temp[iter].size(); i++)
                    {
                        
                    }
                    
                    iter++;
                }
                
            }
            if (count_dist(temp) == dist)
            {
                ans += 1;
            }
            temp.clear();
            cout << endl;
        }

        return ans;
    }
};

int main()
{
    vector<int> hehe;
    hehe.push_back(1);
    hehe.push_back(2);
    hehe.push_back(3);
    hehe.push_back(4);
    hehe.push_back(5);

    Solution obj;
    cout << obj.countCompleteSubarrays(hehe);
    return 0;
}