#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void repetitions(vector<int> &freq, string word)
    {
        int count = 1;
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == word[i + 1])
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

    int possibleStringCount(string word, int k)
    {
        vector<int> freq;
        repetitions(freq, word);
        long long possible = 1;
        int mod = 1e9 + 7;

        for (int a : freq)
        {
            possible *= a % mod;
        }
        possible %= mod;

        if (k <= freq.size())
        {
            return possible;
        }

        vector<int64_t> dp(k, 0);
        dp[0] = 1;
        for (int c : freq)
        {
            for (int i = 1; i < k; i++)
                dp[i] = (dp[i] + dp[i - 1]) % mod;
            for (int i = k - 1; i > c; i--)
                dp[i] = (dp[i] - dp[i - c - 1] + mod) % mod;
        }
        for (int i = 1; i < k; i++)
            dp[i] = (dp[i] + dp[i - 1]) % mod;
        return (possible - dp[k - 1] + mod) % mod;
    }
};

class Solution
{
public:
    int possibleStringCount(string word, int k)
    {
        vector<int> cnt;
        int64_t total = 1, mod = 1e9 + 7;
        for (int i = 0; i < word.size();)
        {
            int j = i;
            while (++i < word.size())
                if (word[i] != word[j])
                    break;
            if (i > j + 1)
            {
                cnt.push_back(i - j - 1);
                total = total * (i - j) % mod;
            }
            k--;
        }
        if (k <= 0)
            return total;

        for (int c : cnt)
        {
            cout << c << " ";
        }
        cout << endl;
        return total;
        // vector<int64_t> dp(k, 0);
        // dp[0] = 1;
        // for (int c : cnt)
        // {
        //     for (int i = 1; i < k; i++)
        //         dp[i] = (dp[i] + dp[i - 1]) % mod;
        //     for (int i = k - 1; i > c; i--)
        //         dp[i] = (dp[i] - dp[i - c - 1] + mod) % mod;
        // }
        // for (int i = 1; i < k; i++)
        //     dp[i] = (dp[i] + dp[i - 1]) % mod;
        // return (total - dp[k - 1] + mod) % mod;
    }
};

int main()
{
    Solution obj;
    cout << obj.possibleStringCount("aabbccdd", 7);

    return 0;
}