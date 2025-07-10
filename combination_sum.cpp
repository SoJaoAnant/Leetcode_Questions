#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void comb_tree(int index, int target, const vector<int> &cand)
    {
        if (index == cand.size())
        {
            if (target == 0)
            {
                ans.push_back(temp);
            }
            return;
        }

        if (cand[index] <= target)
        {
            temp.push_back(cand[index]);
            comb_tree(index, target - cand[index], cand);
            temp.pop_back();
        }

        comb_tree(index + 1, target, cand);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        comb_tree(0, target, candidates);
        return ans;
    }
};

int main()
{

    return 0;
}

/*

temp = {2,}
ans = {}



*/