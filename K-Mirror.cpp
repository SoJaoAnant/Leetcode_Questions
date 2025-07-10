#include <bits/stdc++.h>
using namespace std;

int ten_power(int pow)
{
    int ret = 1;
    while (pow--)
    {
        ret *= 10;
    }
    return ret;
}

long long to_int(string num)
{
    long long ret = 0;
    for (int i = 0; i < num.size(); i++)
    {
        ret += num[i] - '0';
        ret *= 10;
        // cout << num[i] - '0'<<endl;
    }
    ret /= 10;
    return ret;
}

long long oddpal(int n)
{
    string num = to_string(n);
    for (int i = num.size() - 2; i >= 0; i--)
    {
        num.push_back(num[i]);
    }

    return to_int(num);
}

long long evepal(int n)
{
    string num = to_string(n);
    for (int i = num.size() - 1; i >= 0; i--)
    {
        num.push_back(num[i]);
    }

    return to_int(num);
}

int is_pallin(string s)
{
    int i = 0;
    int j = s.size() - 1;

    while (i < j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

long long pallindromes(int base, int till)
{
    long long ans = 0;
    for (int length = 1; length < 19; length++)
    {
        int half = length / 2;
        if (length % 2 == 0)
        {
            for (long long i = ten_power(half - 1); i < ten_power(half); i++)
            {
                string conv;
                long long orig = evepal(i);
                long long num = orig;
                while (num > 0)
                {
                    conv.push_back('0' + (num % base));
                    num /= base;
                }

                if (is_pallin(conv) == 1)
                {
                    cout << till << " Found K-mirror " << orig << " and " << conv << endl;
                    ans += orig;
                    till -= 1;
                }

                if(till == 0)
                {
                    break;
                }
            }
        }
        else
        {
            for (long long i = ten_power(half); i < ten_power(half + 1); i++)
            {
                string conv;
                long long orig = oddpal(i);
                long long num = orig;
                while (num > 0)
                {
                    conv.push_back('0' + (num % base));
                    num /= base;
                }

                if (is_pallin(conv) == 1)
                {
                    cout << till << " Found K-mirror " << orig << " and " << conv << endl;
                    ans += orig;
                    till -= 1;
                }

                if(till == 0)
                {
                    break;
                }
            }
        }

        
    }
    cout << "Total Sum is " << ans << endl;
    return ans;
}

int main()
{
    pallindromes(5, 20);

    return 0;
}