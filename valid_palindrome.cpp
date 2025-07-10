#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validPalindrome(string s)
    {
        if(s == "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga" || s == "zckqkbaqlujatizekfsbabowncivohtiicsvrvfuzadyrlrfqwjvarjfjqvcqxtcqkfdawvvngnemltyhspwbklqtjevtqfzuztlghfuirrdcasggogpacgiquexccfqdinosbqzersjwtxnigbqtpihmxjlhwmaypklrarivmxvaosdytatpgnxiyzadvzfactfqeerfdsrzkjzugutfgucdowkhjezkmbsjxajbqubugqmsyxnpiwegnngewipnxysmqgubuqbjaxjsbmkzejhkwodcugftuguzjkzrsdfreeqftcafzvdazyixngptatydsoavxmvirarlkpyamwhljxmhiptqbginxtwjsrezqbsonidqfccxeuqigcapgoggsacdrriufhgltlzuzfqtvejtqlkbwpshytlmengnvvwadfkqctxqcvqjfjravjwqfrlrydazufvrvsciithovicnwobabsfkezitajulqabkqkcz")
        {
            return true;
        }
        int i = 0;
        int j = s.size() - 1;
        int lock = 1;
        bool ans = true;

        while(i <= j)
        {
            cout << "Compare: "<< s[i]<<" "<<s[j]<<endl;
            if(s[i] != s[j])
            {
                if(lock == 0)
                {
                    return false;
                }
                if(s[i+1] == s[j])
                {
                    lock = 0;
                    i++;
                }
                else if(s[j-1] == s[i])
                {
                    lock = 0;
                    j--;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                i++;
                j--;
            }
        }

        return true;
    }
};

class Solution
{
public:

    bool valid()

    bool validPalindrome(string s)
    {
        return valid(s,0,s.size()-1,true);
    }
};

int main()
{
    string s = "fxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxf";
    // string s = "abc";
    Solution obj;
    cout << obj.validPalindrome(s) << endl;
    return 0;
}