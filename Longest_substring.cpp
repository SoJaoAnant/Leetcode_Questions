#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> seen;
        int maxLen = 0, i = 0, j = 0;

        while (j < s.length())
        {
            if (seen.find(s[j]) == seen.end())
            {   
                seen.insert(s[j]);
                maxLen = max(maxLen, j - i + 1);
                j++;
            }
            else
            {
                seen.erase(s[i]);
                i++;
            }
        }
        return maxLen;
    }
};

int main()
{
    string s = "abbb";
    Solution obj;
    obj.lengthOfLongestSubstring(s);
    return 0;
}
