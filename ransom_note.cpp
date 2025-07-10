#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    map<char, int> freq(string s)
    {
        map<char, int> m;

        for (auto &it : s)
        {
            if (m.find(it) == m.end())
            {
                m.insert(make_pair(it, 1));
            }
            else
            {
                m[it]++;
            }
        }
        return m;
    }
    bool check(map<char, int> m, map<char, int> r)
    {
        int ans = true;
        for (auto &it : r)
        {
            if (m.find(it.first) == m.end())
            {
                ans = false;
                break;
            }
            else
            {
                if (it.second > m[it.first])
                {
                    ans = false;
                    break;
                }
            }
        }
        return ans;
    }
    bool canConstruct(string ransomNote, string magazine)
    {
        map<char, int> m = freq(magazine);
        map<char, int> r = freq(ransomNote);
        bool ans;
        ans = check(m, r);
        return ans;
    }
};

int main()
{
    Solution hehe;
    hehe.canConstruct("anant", "vaidehi");
    return 0;
}