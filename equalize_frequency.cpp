#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check_all_conditions(int n1, int n2, int s1, int s2)
    {
        if(n1 == 1 || n2 == 1 || s1 == 1 || s2 == 1)
        {
            return true;
        }
        if(abs(n1 - n2) == 1 && (s1 > s2) && (n2 > n1))
        {
            return true;
        }
        if(abs(n1 - n2) == 1 && (s1 < s2) && (n1 > n2))
        {
            return true;
        }

        return false;
    }

    bool equalFrequency(string word)
    {
        unordered_map<char, int> freq;
        set<int> equalize;

        for (char c : word)
        {
            freq[c]++;
        }

        for (auto it : freq)
        {
            equalize.insert(it.second);
        }

        if(equalize.size() == 1)
        {
            if(*equalize.begin() == 1 || freq.size() == 1)
            {
                cout << "Possible" << endl;
                return true;
            }
            cout << "Un-Possible" << endl;
            return false;
        }
        if (equalize.size() == 2)
        {
            int nums[2];
            int i = 0;
            for (auto it : equalize)
            {
                nums[i] = it;
                i += 1;
            }

            int n1 = nums[0];
            int n2 = nums[1];
            int s1 = 0;
            int s2 = 0;

            for (auto it : freq)
            {
                if (it.second == n1)
                {
                    s1 += 1;
                }
                else
                {
                    s2 += 1;
                }
            }

            // cout << n1 << " " << s1 << endl;
            // cout << n2 << " " << s2 << endl;

            if (check_all_conditions(n1, n2, s1, s2))
            {
                cout << "Possible" << endl;
                return true;
            }
        }

        cout << "Un-Possible" << endl;
        return false;
    }
};

int main()
{
    Solution obj;
    obj.equalFrequency("aab");
    obj.equalFrequency("aabcd");
    obj.equalFrequency("abcd");
    obj.equalFrequency("abbccdd");
    obj.equalFrequency("abbccddd");
    obj.equalFrequency("abbcccddd");
    obj.equalFrequency("abbbcccddd");
    obj.equalFrequency("aabbbcccddd");
    obj.equalFrequency("aaabbbcccddd");
    obj.equalFrequency("aaaabbbcccddd");
    return 0;
}