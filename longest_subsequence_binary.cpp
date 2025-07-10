#include <bits/stdc++.h>
using namespace std;

int convert_deci(string bin)
{
    int len = bin.size() - 1;
    int deci = 0;
    for (int i = 0; i <= len; i++)
    {
        if (bin[i] == '1')
        {
            deci += pow(2, len - i);
        }
    }
    return deci;
}

/*
void subsequence(string bin, int pos)
{
if (pos == -1)
{
return;
}
cout << bin << endl;
cout << " --> " << convert_deci(bin) << endl;
subsequence(bin, pos - 1);
bin.erase(pos, 1);
subsequence(bin, pos - 1);

return;
}
*/

string reduce_msb(string bin)
{
    for (int i = 0; i < bin.size(); i++)
    {
        if (bin[i] == '1')
        {
            bin.erase(i, 1);
            break;
        }
    }
    return bin;
}

class Solution
{
public:
    int convert_deci(string bin)
    {
        int len = bin.size() - 1;
        int deci = 0;
        for (int i = 0; i <= len; i++)
        {
            if (bin[i] == '1')
            {
                deci += pow(2, len - i);
            }
        }
        return deci;
    }

    string reduce_msb(string bin)
    {
        for (int i = 0; i < bin.size(); i++)
        {
            if (bin[i] == '1')
            {
                bin.erase(i, 1);
                break;
            }
        }
        return bin;
    }

    int check_ones(string s)
    {
        int ones = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                ones += 1;
            }
        }
        return ones;
    }
    int get_highest_power(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
            {
                return s.size() - 1 - i;
            }
        }

        return 0;
    }
    int longestSubsequence(string s, int k)
    {
        int power = log10(k) / log10(2) + 1;
        // cout << power << endl;

        // cout << s << endl;
        // cout << check_ones(s) << endl;

        if (s.size() >= power + 1)
        {
            int ones = check_ones(s) - power;
            while (ones--)
            {
                s = reduce_msb(s);
            }
        }

        for (int i = 0; i < s.size(); i++)
        {
            // cout << "Checking -> " << s << endl;
            int value = get_highest_power(s);
            // int value = convert_deci(s);
            // cout << value << endl;
            if (value <= power)
            {
                value = convert_deci(s);
                if (value <= k)
                {
                    // cout << "Value found!!" << endl;
                    // cout << s << endl;
                    // cout << value << endl;
                    // cout << "Length -> " << s.size() << endl;
                    return s.size();
                }
                else
                {
                    s = reduce_msb(s);
                }
            }
            else
            {
                s = reduce_msb(s);
            }
        }

        return 0;
    }
};

int main()
{
    string bin =
        "111100010000011101001110001111000000001011101111111110111000011111011000010101110100110110001111001001011001010011010000011111101001101000000101101001110110000111101011000101";
    int numbos = 100;
    Solution obj;

    cout << obj.longestSubsequence(bin, numbos) << endl;
    // obj.longestSubsequence(bin, numbos);
    return 0;
}
