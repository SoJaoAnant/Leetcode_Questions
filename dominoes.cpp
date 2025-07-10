#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int convert(int a, int b)
    {
        return max(a, b) * 10 + min(a, b);
    }

    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        unordered_map<int, int> map;

        for (int i = 0; i < dominoes.size(); i++)
        {
            if (map.find(convert(dominoes[i][0],dominoes[i][1])) == map.end())
            {
                map.insert({convert(dominoes[i][0],dominoes[i][1]), 1});
            }
            else
            {
                map[convert(dominoes[i][0],dominoes[i][1])] += 1;
            }
        }
        int ans = 0;
        for (auto it = map.begin(); it != map.end(); it++)
        {
            if (it->second > 1)
            {
                ans += ((it->second) * (it->second - 1)) / 2;
            }
        }

        return ans;
    }
};

int main()
{
    // [[2,1],[5,4],[3,7],[6,2],[4,4],[1,8],[9,6],[5,3],[7,4],[1,9],[1,1],[6,6],[9,6],[1,3],[9,7],[4,7],[5,1],[6,5],[1,6],[6,1],[1,8],[7,2],[2,4],[1,6],[3,1],[3,9],[3,7],[9,1],[1,9],[8,9]]
    return 0;
}