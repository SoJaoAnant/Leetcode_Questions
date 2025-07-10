#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int to_str(string s)
    {
        int zero = 0;
        for (int i = 0; i < s.length(); i++)
        {
            zero = ((zero * 10) + (s[i] - '0'));
        }
        return zero;
    }
    int myAtoi(string s)
    {
        int sp = 0;
        while (s[sp] == ' ')
        {
            sp++;
        }
        string str;
        for (int i = sp; i < s.length(); i++)
        {
            str += s[i];
        }
        cout << s << endl;
        cout << str << endl;

        double ans;
        int max = INT_MAX;
        int min = INT_MIN;
        string to_conv;
        int ascii;
        if (s[0] == '-')
        {
            // negative
            for (int i = 1; i < s.length(); i++)
            {
                ascii = int(s[i]);
                if (ascii >= 48 && ascii <= 57)
                {
                    to_conv += s[i];
                }
                else
                {
                    break;
                }
            }
            ans = -to_str(to_conv);
            if (ans < min)
            {
                return min;
            }
            return int(ans);
        }
        else if (s[0] == '+')
        {

            for (int i = 1; i < s.length(); i++)
            {
                ascii = int(s[i]);
                if (ascii >= 48 && ascii <= 57)
                {
                    to_conv += s[i];
                }
                else
                {
                    break;
                }
            }
            ans = to_str(to_conv);
            if (ans > max)
            {
                return max;
            }
            return int(ans);
        }
        else
        {
            // positive
            for (int i = 0; i < s.length(); i++)
            {
                ascii = int(s[i]);
                if (ascii >= 48 && ascii <= 57)
                {
                    to_conv += s[i];
                }
                else
                {
                    break;
                }
            }
            ans = to_str(to_conv);
            if (ans > max)
            {
                return max;
            }
            return int(ans);
        }
    }
};

// 0 48
// 9 57

int main()
{
    Solution test;
    cout << test.myAtoi("   42") << endl;
    return 0;
}