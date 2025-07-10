#include <bits/stdc++.h>
using namespace std;

int ones_count(string binary)
{
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        if (binary[i] == '1')
        {
            count += 1;
        }
    }
    return count;
}

int main()
{
    // for (int i = 0; i < 27; i++)
    // {
        // string binary = bitset<8>(i).to_string();
        // cout << i << " --> " << binary << " [" << ones_count(binary) << "] " << endl;
    // }

    vector<int> nums = {2,4,6,8,10};

    if(find(nums.begin(),nums.end(),3) == nums.end())
    {
        cout << "not present" << endl;
    }
    else
    {
        cout << "present" << endl;
    }

    return 0;
}