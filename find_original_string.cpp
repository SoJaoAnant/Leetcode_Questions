#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    void repetitions(vector<int> &freq,string word)
    {
        int count = 1;
        for (int i = 0; i < word.size(); i++)
        {
            if(word[i] == word[i+1])
            {
                count += 1;
            }
            else
            {
                freq.push_back(count);
                count = 1;
            }
        }
    }

    int possibleStringCount(string word)
    {
        vector<int> freq;
        repetitions(freq,word);

        int ans = 1;
        for (int i: freq)
        {
            if (i > 1)
            {
                ans += i - 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    cout << obj.possibleStringCount("ecee");
    return 0;
}